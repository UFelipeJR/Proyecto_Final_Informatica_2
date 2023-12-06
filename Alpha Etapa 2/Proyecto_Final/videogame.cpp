#include "videogame.h"
#include "ui_videogame.h"

videogame::videogame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::videogame)
{

    //Cursor personalizado
    QCursor cursor(QPixmap(resources::cursor));

    //Vainas de la escena para hacer pruebas previas antes de definir clase escenario
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    //Personajes
    Rick = new rick;

    bat = new weapon;
    ability = new particle(20);


    //Sectores de vision
    listConeVision.append(new coneVision(260,740,726,342,0));
    listConeVision.append(new coneVision(260,1100,726,400,0));
    listConeVision.append(new coneVision(1014,740,1197,750,0));
    listConeVision.append(new coneVision(1800,750,1023,741,0));
    listConeVision.append(new coneVision(1500,170,822,620,0));
    listConeVision.append(new coneVision(1000,150,952,578,0));
    listConeVision.append(new coneVision(1486,751,660,747,0));

    //Timers
    timerControllers = new QTimer(this);
    timerRotation = new QTimer(this);
    timerParticle = new QTimer(this);
    timerDeath = new QTimer(this);
    timerFinishPowerUp = new QTimer(this);
    timerMenu = new QTimer(this);


    //Textos
    listText.append(new text("Kinetic Energy: 0%",24,"Arcadepix"));
    listText.append(new text("Press R to restart", 24,"Arcadepix"));
    listText.append(new text("0 Pts", 24,"Arcadepix"));
    listText.append(new text("Level Clear", 58,"Arcadepix"));

    //Mezeeks

    listMezeek.append(new mezeek());
    listMezeek.append(new mezeek());
    listMezeek.append(new mezeek());
    listMezeek.append(new mezeek());
    listMezeek.append(new mezeek());
    listMezeek.append(new mezeek());
    listMezeek.append(new mezeek());


    //Escenarios
    maps.append(new scenery(resources::map1Path,resources::maskMap1Path,3.0));
    maps.append(new scenery(resources::map2Path,resources::map2PathMask,3.0));

    //Resto de inicializaciones
    ui->setupUi(this);
    this->setWindowTitle("Intruder");
    this->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);

    //Cambio de cursor e Icono
    setWindowIcon(QIcon(resources::icon));
    setCursor(cursor);

    //Pantalla completa de manera automatica
    showFullScreen();
    ui->label->setStyleSheet("border: none;");

    //Entidades
    Entities = new entities(Rick,view,scene);

    keyStates['W'] = false;
    keyStates['A'] = false;
    keyStates['S'] = false;
    keyStates['D'] = false;

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    contEnergy = 0;
    percentage = 0;
    level = 0;

    setCustomBackgroundColor(QColor(93, 163, 208), "grey");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(initVideoGame()));

    OST = new QSoundEffect(this);
    OST->setVolume(0.25);

    ui->label->setStyleSheet("QLabel { background-color : lightblue; border: 0px solid black; }");
    ui->label->show();
    n = 0;

    heads.append(new headMezeek(-800,80,20,10));
    heads.append(new headMezeek(-500,120,20,-10));
    heads.append(new headMezeek(-400,80,30,10));
    heads.append(new headMezeek(140,-390,-30,-10));
    timerMenu->start(10);

    connect(timerMenu, SIGNAL(timeout()), this, SLOT(menuAnimation()));

    ui->main_scene->setScene(scene);
    ui->main_scene->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->main_scene->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->addItem(heads[0]);
    scene->addItem(heads[1]);
    scene->addItem(heads[2]);
    scene->addItem(heads[3]);

    rectangleScreen = new QGraphicsRectItem(0, 0, 4098,2304);
    opacityEffect = new QGraphicsOpacityEffect;
    animationOF = new QPropertyAnimation(opacityEffect, "opacity");
    rectangleScreen->setGraphicsEffect(opacityEffect);

    connect(this, SIGNAL(changeLevel()), this, SLOT(level2()));

}

videogame::~videogame()
{
    delete ui;
    delete Rick;
    delete Entities;
    delete timerControllers;
    delete timerRotation;
    delete timerParticle;
    delete Mezeek;
    delete timerDeath;
    delete OST;
    delete timerFinishPowerUp;
    delete timerMenu;
    delete rectangleScreen;
    delete opacityEffect;
    delete animationOF;


    for (text* element : listText) {
        delete element;
    }

    for (mezeek* element : listMezeek) {
        delete element;
    }

    for (coneVision* element : listConeVision) {
        delete element;
    }

    for (scenery* element : maps) {
        delete element;
    }

    for (headMezeek* element : heads) {
        delete element;
    }

}

void videogame::initVideoGame()
{
    timerControllers->start(16);
    timerRotation->start(0.01);
    timerParticle->start(30);
    timerDeath->start(200);
    timerFinishPowerUp->setSingleShot(true);
    timerFinishPowerUp->setInterval(3000);


    setCentralWidget(view);
    connect(this,SIGNAL(punch()),Rick, SLOT(punchRick()));
    connect(timerControllers, SIGNAL(timeout()), this, SLOT(game()));
    connect(timerControllers, SIGNAL(timeout()), this, SLOT(throwWeapon()));
    connect(timerParticle, SIGNAL(timeout()), this, SLOT(powerUp()));
    connect(timerFinishPowerUp, SIGNAL(timeout()), this, SLOT(finish()));


    for (int i = 0; i < listMezeek.size(); ++i) {
        connect(timerDeath, SIGNAL(timeout()), this, SLOT(killrick()));
    }

    scene->addItem(listConeVision[0]);
    scene->addItem(listConeVision[1]);
    scene->addItem(listConeVision[2]);
    scene->addItem(listConeVision[3]);
    scene->addItem(listConeVision[4]);
    scene->addItem(listConeVision[5]);
    scene->addItem(listConeVision[6]);

    scene->addItem(listMezeek[0]);
    scene->addItem(listMezeek[1]);
    scene->addItem(listMezeek[6]);

    scene->addItem(Rick);
    scene->addItem(listText[0]);
    scene->addItem(listText[2]);

    scene->removeItem(heads[0]);
    scene->removeItem(heads[1]);
    scene->removeItem(heads[2]);
    scene->removeItem(heads[3]);

    Rick->setZValue(3);
    level1();
}



void videogame::setCustomBackgroundColor(QString color)
{
    QString comando = "background-color: "+color+";";
    setStyleSheet(comando);
}

void videogame::setCustomBackgroundColor(QColor startColor, QColor endColor)
{
    QString comando = QString("background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 %1, stop:1 %2);")
        .arg(startColor.name())
        .arg(endColor.name());

    setStyleSheet(comando);
}


void videogame::keyPressEvent(QKeyEvent *event)
{
    char key = event->key();
    if (key == Qt::Key_W){
        keyStates['W'] = true;
    }
    else if (key == Qt::Key_A){
        keyStates['A'] = true;
    }
    else if (key == Qt::Key_S){
        keyStates['S'] = true;
    }
    else if (key == Qt::Key_D){
        keyStates['D'] = true;
    }
    else if(key == Qt::Key_R){
        checkPoint();
    }
    else if(key == Qt::Key_Space){
        activePowerUp();
    }

}

void videogame::keyReleaseEvent(QKeyEvent* event){

    char key = event->key();
    if (key == Qt::Key_W){
        keyStates['W'] = false;
        Rick->setMovementActive(false);
    }
    else if (key == Qt::Key_A){
        keyStates['A'] = false;
        Rick->setMovementActive(false);
    }
    else if (key == Qt::Key_S){
        keyStates['S'] = false;
        Rick->setMovementActive(false);
    }
    else if (key == Qt::Key_D){
        keyStates['D'] = false;
        Rick->setMovementActive(false);
    }

}

void videogame::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButton button = event->button();
    if (button == Qt::LeftButton && Rick->getAlive()) {
        rightButton();
        Rick->setMovementActive(true);
        scene->removeItem(bat);
        bat->setVel(0);
        emit punch();
        if(!Rick->detectCollision()){
            Rick->emitSound(1);
        }
        else{
            Rick->emitSound(2);
        }
    }
    else if (button == Qt::RightButton) {
        leftButton();
        bat->setLaunchActive(true);
        bat->setVel(10);
        bat->setPos(Rick->pos());
    }
}


void videogame::updateMove(int numMap)
{
    short int cantPix = 7;
    short int cantPixCombi = 5;


    if (keyStates['W'] && keyStates['A'] && Rick->getAlive()) {
        if (!maps[numMap]->detectCollision(Rick,-cantPixCombi, -cantPixCombi)) {
            Rick->moveBy(-cantPixCombi, -cantPixCombi);
            loadKineticEnergy(cantPixCombi);
            yCamera -= cantPixCombi;
            xCamera -= cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['W']&&keyStates['D'] && Rick->getAlive()){
        if (!maps[numMap]->detectCollision(Rick,cantPixCombi, -cantPixCombi)) {
            Rick->moveBy(cantPixCombi, -cantPixCombi);
            loadKineticEnergy(cantPixCombi);
            yCamera -= cantPixCombi;
            xCamera += cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['A']&&keyStates['S'] && Rick->getAlive()){
        if (!maps[numMap]->detectCollision(Rick,-cantPixCombi, cantPixCombi)) {
            loadKineticEnergy(cantPixCombi);
            Rick->moveBy(-cantPixCombi, cantPixCombi);
            yCamera += cantPixCombi;
            xCamera -= cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['S']&&keyStates['D'] && Rick->getAlive()){
        if (!maps[numMap]->detectCollision(Rick,cantPixCombi, cantPixCombi)) {
            loadKineticEnergy(cantPixCombi);
            Rick->moveBy(cantPixCombi, cantPixCombi);
            yCamera += cantPixCombi;
            xCamera += cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if (keyStates['W'] && Rick->getAlive()) {
        if (!maps[numMap]->detectCollision(Rick,0,-cantPix)) {
            loadKineticEnergy(cantPix);
            Rick->moveBy(0, -cantPix);
            yCamera -= cantPix;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['A'] && Rick->getAlive()){
        if (!maps[numMap]->detectCollision(Rick,-cantPix, 0)) {
            loadKineticEnergy(cantPix);
            Rick->moveBy(-cantPix, 0);
            xCamera -= cantPix;
            Rick->setMovementActive(true);
        }

    }
    else if(keyStates['S'] && Rick->getAlive()){
        if (!maps[numMap]->detectCollision(Rick,0, cantPix)) {
            loadKineticEnergy(cantPix);
            Rick->moveBy(0, cantPix);
            yCamera += cantPix;
            Rick->setMovementActive(true);
        }

    }
    else if(keyStates['D'] && Rick->getAlive()){
        if (!maps[numMap]->detectCollision(Rick,cantPix, 0)) {
            loadKineticEnergy(cantPix);
            Rick->moveBy(cantPix, 0);
            xCamera += cantPix;
            Rick->setMovementActive(true);
        }

    }
}


void videogame::rotateRick()
{
    if(Rick->getAlive()){
        Rick->setTransformOriginPoint(pointRotationX, pointRotationY);
        Rick->setRotation(Entities->getAngleCursor());
    }

}

void videogame::rotateMezeeks(int numMezeek)
{
    listMezeek[numMezeek]->setTransformOriginPoint(pointRotationX, pointRotationY);

    if(listMezeek[numMezeek]->getAlive() && listConeVision[numMezeek]->checkIntersection(Rick) && !listMezeek[numMezeek]->getLying()){
        listMezeek[numMezeek]->setRotation(Entities->getAngleEnemy(Rick,listMezeek[numMezeek]));
    }
    else if(!listMezeek[numMezeek]->getAlive() && !listMezeek[numMezeek]->getConfirmation()){
        listMezeek[numMezeek]->setConfirmation(true);
    }


}

void videogame::checkPoint()
{
    if(!Rick->getAlive()){
        if(level == 1){
            listMezeek[0]->setPos(341,995);
            listMezeek[1]->setPos(868,1400);
            listMezeek[2]->setPos(1652,1056);
            listMezeek[3]->setPos(2426,1175);
            listMezeek[4]->setPos(2263,171);
            listMezeek[5]->setPos(1136,308);
            listMezeek[6]->setPos(1782,751);
            scene->addItem(listMezeek[0]);
            scene->addItem(listMezeek[1]);
            scene->addItem(listMezeek[6]);
            Rick->setPos(2769,1388);
            Rick->setAlive(true);
            listMezeek[0]->setAlive(true);
            listMezeek[1]->setAlive(true);
            listMezeek[2]->setAlive(true);
            listMezeek[3]->setAlive(true);
            listMezeek[4]->setAlive(true);
            listMezeek[5]->setAlive(true);
            listMezeek[6]->setAlive(true);
            xCamera = 2100;
            yCamera = 1000;
            listMezeek[0]->setLying(false);
            listMezeek[1]->setLying(false);
            listMezeek[2]->setLying(false);
            listMezeek[3]->setLying(false);
            listMezeek[4]->setLying(false);
            listMezeek[6]->setLying(false);
            OST->play();
            contEnergy = 0;
            scene->removeItem(listMezeek[2]);
            scene->removeItem(listMezeek[3]);
            scene->removeItem(listMezeek[4]);
            scene->removeItem(listMezeek[5]);
        }

    }
    else{
        qDebug() << "No se puede restablecer ahora";
    }
}

void videogame::activePowerUp()
{
    if(percentage >= 100){
        scene->addItem(ability);
        timerFinishPowerUp->start(5000);
    }
}


void videogame::viewText()
{
    if(!Rick->getAlive()){
        listText[1]->setPos(xCamera+20,yCamera+700);
        scene->addItem(listText[1]);
    }
    else{
        scene->removeItem(listText[1]);
    }
}

void videogame::level1()
{
    animation();
    level = 1;
    OST->setSource(QUrl::fromLocalFile(resources::ostLevel1));
    xCamera = 2100;
    yCamera = 1000;
    setCustomBackgroundColor(QColor(185,0,255),QColor(8,61,100));
    scene->addItem(maps[0]);
    maps[0]->setPos(0,0);
    listMezeek[0]->setPos(341,995);
    listMezeek[1]->setPos(868,1400);
    listMezeek[2]->setPos(1652,1056);
    listMezeek[3]->setPos(2426,1175);
    listMezeek[4]->setPos(2263,171);
    listMezeek[5]->setPos(1136,308);
    listMezeek[6]->setPos(1782,751);
    maps[0]->stackBefore(scene->items().last());
    Rick->setPos(2769,1388);
    OST->play();
}


void videogame::level2()
{
    animation();
    level = 2;
    scene->removeItem(maps[0]);
    scene->removeItem(listText[3]);

    removeAllCones();
    removeAllMezeeks();
    OST->setSource(QUrl::fromLocalFile(resources::ostLevel2));
    Rick->setMovementActive(false);
    xCamera = 1200;
    yCamera = 1500;
    Rick->setPos(1891,1996);
    setCustomBackgroundColor(QColor(185,0,255),QColor(8,61,100));
    maps[1]->setPos(0,0);
    scene->addItem(maps[1]);
    maps[1]->stackBefore(scene->items().last());
    OST->play();
}

void videogame::loadKineticEnergy(float vel)
{

    QString text;

    contEnergy += Rick->getkineticEnergy(vel);
    percentage = (100*contEnergy)/11036010;

    if(percentage <= 100 ){
        text = "Kinetic Energy: " + QString::number(percentage) + "%";
    }
    else if(percentage > 100){
        text = "Kinetic Energy: 100%";
    }

    listText[0]->changeText(text);


}

void videogame::detectKill(int numMezeek)
{
    if (Rick->detectCollision(listMezeek[numMezeek]) && Rick->getActiveWeapon() || ability->detectCollision(listMezeek[numMezeek])) {
        listMezeek[numMezeek]->setAlive(false);
        listMezeek[numMezeek]->setLying(false);
        Rick->emitSound(2);
    }
    else if(bat->detectCollision(listMezeek[numMezeek]) && listMezeek[numMezeek]->getAlive()){
        listMezeek[numMezeek]->setLying(true);
    }

}


void videogame::moveMezeeks(rick *Rick, mezeek *Mezeek, int numCone, int numMap){


    float speed = (Mezeek->getAX() * Mezeek->getT())*0.5;
    qreal angle = Entities->getAngleEnemy(Rick,Mezeek);
    double deltaX = speed * qCos(qDegreesToRadians(angle));
    double deltaY = speed * qSin(qDegreesToRadians(angle));


    if(Entities->distancetoEnemy(Mezeek) > 10 && listConeVision[numCone]->checkIntersection(Rick)
        && Rick->getAlive() && !Mezeek->getLying() && scene->items().contains(Mezeek)){
        if(!maps[numMap]->detectCollision(Mezeek,deltaX,deltaY)){
            Mezeek->setAcelerationActive(true);
            Mezeek->setMovementActive(true);
        }
    }
    else{
        Mezeek->setAcelerationActive(false);
        Mezeek->setMovementActive(false);
    }


    if(!Rick->detectCollision(Mezeek) && Mezeek->getAlive() && Mezeek->getAcelerationActive()){
        Mezeek->moveBy(deltaX,deltaY);
    }
    else{
        Mezeek->setAcelerationActive(false);
    }

}

void videogame::straighten()
{
    scene->setSceneRect(xCamera,yCamera,Entities->getDimScreen().width(),Entities->getDimScreen().height());
    listText[0]->setPos(xCamera+915,yCamera+700);
    listText[2]->setPos(xCamera,yCamera);
}


void videogame::killrick()
{
    for(int i = 0; i< listMezeek.size(); i++){
        if(listMezeek[i]->getAlive() && Entities->possibilityPunch()
            && !listMezeek[i]->getLying() && listMezeek[i]->detectCollision()){
            Rick->setAlive(false);
            OST->stop();
            listMezeek[i]->moveBy(-5,5);
        }

    }
}

void videogame::finish()
{

    scene->removeItem(ability);
    ability->setPos(Rick->pos());
    contEnergy = 0;

}

void videogame::menuAnimation()
{
    float x, y, t, T = 0.01, k = 2;

    t = k * n * T;
    heads[0]->setPos(heads[0]->posX(t), heads[0]->posY(t));
    heads[1]->setPos(heads[1]->posX(t), heads[1]->posY(t));
    heads[2]->setPos(heads[2]->posX(t), heads[2]->posY(t));
    heads[3]->setPos(heads[3]->posX(t), heads[3]->posY(t));
    n++;
}


void videogame::throwWeapon()
{
    qreal angle = Entities->getAngleCursor();
    double deltaX;
    double deltaY;
    if(level == 1){
        if(bat->getLaunchActive()){
            if(!maps[0]->detectCollision(bat,deltaX,deltaY)){
                scene->addItem(bat);
                deltaX = (bat->getVel()) * qCos(qDegreesToRadians(angle));
                deltaY = (bat->getVel()) * qSin(qDegreesToRadians(angle));

                bat->moveBy(deltaX,deltaY);
                if(maps[0]->detectCollision(bat,deltaX,deltaY)){
                    bat->moveBy(-deltaX, -deltaY);
                    qDebug() << "Detenido debido a colisión";
                }
            }
            else{
                return;
            }
        }
    }
    else{
        if(bat->getLaunchActive()){
            if(!maps[1]->detectCollision(bat,deltaX,deltaY)){
                scene->addItem(bat);
                deltaX = (bat->getVel()) * qCos(qDegreesToRadians(angle));
                deltaY = (bat->getVel()) * qSin(qDegreesToRadians(angle));

                bat->moveBy(deltaX,deltaY);
                if(maps[1]->detectCollision(bat,deltaX,deltaY)){
                    bat->moveBy(-deltaX, -deltaY);
                    qDebug() << "Detenido debido a colisión";
                }
            }
            else{
                return;
            }
        }

    }

}


void videogame::powerUp()
{
    if(scene->items().contains(ability)){
        ability->updatePosition(Rick->x(),Rick->y());
    }
}

void videogame::spawnMezeeks()
{
    if(!listMezeek[0]->getAlive() && !listMezeek[1]->getAlive()){
        scene->addItem(listMezeek[2]);
        scene->addItem(listMezeek[3]);
        scene->addItem(listMezeek[4]);
        scene->addItem(listMezeek[5]);
    }
}

void videogame::removeAllMezeeks()
{
    for(int i = 0; i<listMezeek.size(); i++){
        scene->removeItem(listMezeek[i]);
        listMezeek[i]->setAlive(true);
    }
}

void videogame::removeAllCones()
{
    for(int i = 0; i<listConeVision.size(); i++){
        scene->removeItem(listConeVision[i]);
    }
}

void videogame::animation()
{
    rectangleScreen->setBrush(Qt::black);
    rectangleScreen->setZValue(5);
    scene->addItem(rectangleScreen);
    animationOF->setDuration(3000);
    animationOF->setStartValue(1.5);
    animationOF->setEndValue(0.0);
    animationOF->start();

}

bool videogame::thereMezeeks()
{
    for(int i = 0; i < listMezeek.size();i++){
        if(listMezeek[i]->getAlive()){
            return false;
        }
    }
    return true;

}

void videogame::rightButton()
{
    Rick->setMovementActive(true);
    scene->removeItem(bat);
    bat->setVel(0);
    emit punch();
    if(!Rick->detectCollision()){
        Rick->emitSound(1);
    }
}

void videogame::leftButton()
{
    bat->setLaunchActive(true);
    bat->setVel(10);
    bat->setPos(Rick->pos());
}

void videogame::game()
{
    straighten();

    updateMove(level-1);

    rotateRick();

    for(int i = 0; i< listMezeek.size();i++){
        rotateMezeeks(i);
        detectKill(i);
        moveMezeeks(Rick,listMezeek[i],i,level-1);
    }

    viewText();
    spawnMezeeks();
    qDebug() << Rick->pos();

    if(thereMezeeks() && level == 1){
        listText[3]->setPos(Rick->x()-200,Rick->y()-200);
        scene->addItem(listText[3]);
        if(Rick->x() > 2760 && Rick->y() > 1402){
            emit changeLevel();
        }
    }

}








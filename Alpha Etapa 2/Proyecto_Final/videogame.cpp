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
    Mezeek = new mezeek;
    bat = new weapon;
    circleVision = new coneVision(80,400,1000,400);

    //Timers
    timerControllers = new QTimer();
    timerRotation = new QTimer();

    //Escenarios
    map1 = new scenery(resources::map1Path,resources::maskMap1Path);

    //Resto de inicializaciones
    ui->setupUi(this);
    this->setWindowTitle("Intruder");
    this->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);

    //Cambio de cursor e Icono
    setWindowIcon(QIcon(resources::icon));
    setCursor(cursor);

    //Agregar en escena por ahora

    scene->addItem(circleVision);
    scene->addItem(Mezeek);
    scene->addItem(Rick);

    //Pantalla completa de manera automatica
    showFullScreen();
    setCentralWidget(view);

    //Entidades
    Entities = new entities(Rick,view,scene);
    timerControllers->start(16);
    timerRotation->start(0.01);

    connect(timerControllers, SIGNAL(timeout()), this, SLOT(game()));

    keyStates['W'] = false;
    keyStates['A'] = false;
    keyStates['S'] = false;
    keyStates['D'] = false;

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(this,SIGNAL(punch()),Rick, SLOT(punchRick()));
    connect(Mezeek,SIGNAL(killRick()),this,SLOT(killrick()));

    connect(timerControllers, SIGNAL(timeout()), this, SLOT(throwWeapon()));


    QSurfaceFormat format;
    format.setSwapInterval(0);
    QSurfaceFormat::setDefaultFormat(format);

    QFont customFont;
    customFont.setPointSize(24);
    customFont.setFamily("Arcadepix");


    textReset = new QGraphicsTextItem("Press R to restart");
    combo = new QGraphicsTextItem("Combo: 0");
    points = new QGraphicsTextItem("0 pts");

    points->setFont(customFont);
    textReset->setFont(customFont);
    points->setDefaultTextColor(Qt::white);
    textReset->setDefaultTextColor(Qt::white);

    scene->addItem(points);

    level = 1;
    level1();



}

videogame::~videogame()
{
    delete ui;
    delete Rick;
    delete Entities;
    delete timerControllers;
    delete timerRotation;
    delete Mezeek;
    delete map1;
    delete textReset;
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
        Rick->setMovementActive(true);
        scene->removeItem(bat);
        bat->setVel(0);
        emit punch();
    }
    else if (button == Qt::RightButton) {
        bat->setLaunchActive(true);
        bat->setVel(10);
        bat->setPos(Rick->pos());
    }
}


void videogame::updateMove()
{
    const short int cantPix = 7;
    const short int cantPixCombi = 5;


    if (keyStates['W'] && keyStates['A'] && Rick->getAlive()) {
        if (!map1->detectCollision(Rick,-cantPixCombi, -cantPixCombi)) {
            Rick->moveBy(-cantPixCombi, -cantPixCombi);
            yCamera -= cantPixCombi;
            xCamera -= cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['W']&&keyStates['D'] && Rick->getAlive()){
        if (!map1->detectCollision(Rick,cantPixCombi, -cantPixCombi)) {
            Rick->moveBy(cantPixCombi, -cantPixCombi);
            yCamera -= cantPixCombi;
            xCamera += cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['A']&&keyStates['S'] && Rick->getAlive()){
        if (!map1->detectCollision(Rick,-cantPixCombi, cantPixCombi)) {
            Rick->moveBy(-cantPixCombi, cantPixCombi);
            yCamera += cantPixCombi;
            xCamera -= cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['S']&&keyStates['D'] && Rick->getAlive()){
        if (!map1->detectCollision(Rick,cantPixCombi, cantPixCombi)) {
            Rick->moveBy(cantPixCombi, cantPixCombi);
            yCamera += cantPixCombi;
            xCamera += cantPixCombi;
            Rick->setMovementActive(true);
        }
    }
    else if (keyStates['W'] && Rick->getAlive()) {
        if (!map1->detectCollision(Rick,0,-cantPix)) {
            Rick->moveBy(0, -cantPix);
            yCamera -= cantPix;
            Rick->setMovementActive(true);
        }
    }
    else if(keyStates['A'] && Rick->getAlive()){
        if (!map1->detectCollision(Rick,-cantPix, 0)) {
            Rick->moveBy(-cantPix, 0);
            xCamera -= cantPix;
            Rick->setMovementActive(true);
        }

    }
    else if(keyStates['S'] && Rick->getAlive()){
        if (!map1->detectCollision(Rick,0, cantPix)) {
            Rick->moveBy(0, cantPix);
            yCamera += cantPix;
            Rick->setMovementActive(true);
        }

    }
    else if(keyStates['D'] && Rick->getAlive()){
        if (!map1->detectCollision(Rick,cantPix, 0)) {
            Rick->moveBy(cantPix, 0);
            xCamera += cantPix;
            Rick->setMovementActive(true);
        }

    }


    if (Rick->detectCollision() && Rick->getActiveWeapon()) {
        Mezeek->setAlive(false);
        Mezeek->setLying(false);
    }
    else if(bat->detectCollision() && Mezeek->getAlive()){
        Mezeek->setLying(true);
    }
}


void videogame::rotateRick()
{
    if(Rick->getAlive()){
        Rick->setTransformOriginPoint(pointRotationX, pointRotationY);
        Rick->setRotation(Entities->getAngleCursor());
    }

}

void videogame::rotateMezeeks()
{
    Mezeek->setTransformOriginPoint(pointRotationX, pointRotationY);
    if(Mezeek->getAlive() && circleVision->checkIntersection(Rick) && !Mezeek->getLying()){
        Mezeek->setRotation(Entities->getAngleEnemy(Rick,Mezeek));
    }
    else if(!Mezeek->getAlive() && !Mezeek->getConfirmation()){
        //Mezeek->setRotation(Entities->getAngleCursor()+30);
        Mezeek->setConfirmation(true);
    }
}

void videogame::checkPoint()
{
    if(!Rick->getAlive()){
        if(level == 1){
            qDebug() << "Restablecido";
            Mezeek->setPos(142,602);
            Rick->setPos(1263,1058);
            Rick->setAlive(true);
            Mezeek->setAlive(true);
            xCamera = 500;
            yCamera = 500;
            Mezeek->setLying(false);
            scene->addItem(circleVision);
        }

    }
    else{
        qDebug() << "No se puede restablecer ahora";
    }
}


void videogame::viewText()
{
    if(!Rick->getAlive()){
        textReset->setPos(xCamera+20,yCamera+630);
        scene->addItem(textReset);
    }
    else{
        scene->removeItem(textReset);
    }
}


void videogame::level1()
{
    setCustomBackgroundColor(QColor(185,0,255),QColor(8,61,100));
    scene->addItem(map1);
    map1->setPos(0,0);
    Mezeek->setPos(142,602);
    map1->stackBefore(scene->items().last());
    Rick->setPos(1263,1058);
    xCamera = 500;
    yCamera = 500;

}

void videogame::moveMezeeks(rick *Rick, mezeek *Mezeek){
    float speed = (Mezeek->getAX() * Mezeek->getT())*0.5;
    qreal angle = Entities->getAngleEnemy(Rick,Mezeek);
    double deltaX = speed * qCos(qDegreesToRadians(angle));
    double deltaY = speed * qSin(qDegreesToRadians(angle));

    if(Entities->distancetoEnemy(Mezeek) > 10 && circleVision->checkIntersection(Rick)
        && Rick->getAlive() && !Mezeek->getLying()){
        if(!map1->detectCollision(Mezeek,deltaX,deltaY)){
            Mezeek->setAcelerationActive(true);
            Mezeek->setMovementActive(true);
        }
    }
    else{
        Mezeek->setAcelerationActive(false);
        Mezeek->setMovementActive(false);
    }


    if(!Rick->detectCollision() && Mezeek->getAlive() && Mezeek->getAcelerationActive()){
        Mezeek->moveBy(deltaX,deltaY);
    }
    else{
        Mezeek->setAcelerationActive(false);
    }


}

void videogame::updateCircleVision()
{
    if(!Mezeek->getAlive()){
        scene->removeItem(circleVision);
    }
}

void videogame::straighten()
{
    scene->setSceneRect(xCamera,yCamera,Entities->getDimScreen().width(),Entities->getDimScreen().height());
    points->setPos(xCamera,yCamera);
}


void videogame::killrick()
{
    if(Entities->possibilityPunch() && Mezeek->getAlive() && !Mezeek->getLying()){
        Rick->setAlive(false);
        Mezeek->moveBy(-5,5);
    }
}


void videogame::throwWeapon()
{

    qreal angle = Entities->getAngleCursor();
    double deltaX;
    double deltaY;

    if(bat->getLaunchActive()){
        if(!map1->detectCollision(bat,deltaX,deltaY)){
            scene->addItem(bat);
            deltaX = (bat->getVel()) * qCos(qDegreesToRadians(angle));
            deltaY = (bat->getVel()) * qSin(qDegreesToRadians(angle));
            bat->moveBy(deltaX,deltaY);

        }

    }
}


void videogame::game()
{
    straighten();
    updateCircleVision();
    updateMove();
    rotateRick();
    rotateMezeeks();
    moveMezeeks(Rick,Mezeek);
    viewText();
}








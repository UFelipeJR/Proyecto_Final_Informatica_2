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
    circleVision = new coneVision(300,90,400,400);

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

    //Inicialización del color de fondo
    setCustomBackgroundColor("grey");

    //Agregar en escena por ahora
    scene->addItem(map1);
    scene->addItem(circleVision);
    scene->addItem(Mezeek);
    scene->addItem(Rick);


    map1->setPos(0,0);
    Mezeek->setPos(500,250);
    Rick->setPos(500,431);

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


    xCamera = 0;
    yCamera = 0;
    connect(this,SIGNAL(punch()),Rick, SLOT(punchRick()));
    connect(Mezeek,SIGNAL(killRick()),this,SLOT(killrick()));
    connect(this, SIGNAL(emitShake()), this, SLOT(shake()));

    //Prueba animación
    QPropertyAnimation *animation = new QPropertyAnimation;
    animation->setDuration(1000);

    QSurfaceFormat format;
    format.setSwapInterval(0);
    QSurfaceFormat::setDefaultFormat(format);


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
    delete animation;
}


void videogame::setCustomBackgroundColor(QString color)
{
    QString comando = "background-color: "+color+";";
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
        emit punch();
    }
    else if (button == Qt::RightButton) {
    }
}


void videogame::updateMove()
{
    const short int cantPix = 7;
    const short int cantPixCombi = 5;
    const short int cantPixCamera = 7;

    if(keyStates['W']&&keyStates['A'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(-cantPixCombi, -cantPixCombi);
        yCamera -= cantPixCombi;
        xCamera -= cantPixCombi;
        Rick->setMovementActive(true);
    }
    else if(keyStates['W']&&keyStates['D'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(cantPixCombi, -cantPixCombi);
        yCamera -= cantPixCombi;
        xCamera += cantPixCombi;
        Rick->setMovementActive(true);
    }
    else if(keyStates['A']&&keyStates['S'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(-cantPixCombi, cantPixCombi);
        yCamera += cantPixCombi;
        xCamera -= cantPixCombi;
        Rick->setMovementActive(true);
    }
    else if(keyStates['S']&&keyStates['D'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(cantPixCombi, cantPixCombi);
        yCamera += cantPixCombi;
        xCamera += cantPixCombi;
        Rick->setMovementActive(true);
    }
    else if(keyStates['W'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(0, -cantPix);
        yCamera -= cantPixCamera;
        Rick->setMovementActive(true);
    }
    else if(keyStates['A'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(-cantPix, 0);
        xCamera -= cantPixCamera;
        Rick->setMovementActive(true);
    }
    else if(keyStates['S'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(0, cantPix);
        yCamera += cantPixCamera;
        Rick->setMovementActive(true);
    }
    else if(keyStates['D'] && !Rick->detectCollision()
    && !map1->detectCollision(Rick) && Rick->getAlive()){
        Rick->moveBy(cantPix, 0);
        xCamera += cantPixCamera;
        Rick->setMovementActive(true);
    }


    if(Rick->detectCollision() && Rick->getActiveWeapon()){
        Mezeek->setAlive(false);
        emit emitShake();
    }
    repairCollision();
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
    if(Mezeek->getAlive()){
        Mezeek->setRotation(Entities->getAngleEnemy(Rick,Mezeek));
    }
    else if(!Mezeek->getAlive() && !Mezeek->getConfirmation()){
        Mezeek->setRotation(Entities->getAngleCursor()+30);
        Mezeek->setConfirmation(true);
    }
}

void videogame::checkPoint()
{
    if(!Rick->getAlive()){
        qDebug() << "Restablecido";
        Mezeek->setPos(500,250);
        Rick->setPos(500,431);
        Rick->setAlive(true);
        Mezeek->setAlive(true);
        xCamera = 0;
        yCamera = 0;
    }
    else{
        qDebug() << "No se puede restablecer ahora";
    }
}

void videogame::moveMezeeks(rick *Rick, mezeek *Mezeek)
{

    float speed = (Mezeek->getAX() * Mezeek->getT())*0.5;
    qreal angle = Entities->getAngleEnemy(Rick,Mezeek);
    double deltaX = speed * qCos(qDegreesToRadians(angle));
    double deltaY = speed * qSin(qDegreesToRadians(angle));

    if(Entities->distancetoEnemy(Mezeek) > 10 && circleVision->checkIntersection(Rick) && Rick->getAlive()){
        Mezeek->setAcelerationActive(true);
        Mezeek->setMovementActive(true);
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

void videogame::repairCollision()
{
    const short int cantPix = 7;
    const short int cantPixCombi = 5;
    const short int cantPixCamera = 7;

    if(map1->detectCollision(Rick) && !Rick->getMovementActive() &&map1->direction(Rick) == 3){
        Rick->moveBy(0, cantPix);
        yCamera += cantPixCamera;
    }
    else if(map1->detectCollision(Rick) && !Rick->getMovementActive() &&map1->direction(Rick) == 4){
        Rick->moveBy(0, -cantPix);
        yCamera -= cantPixCamera;
    }
    else if(map1->detectCollision(Rick) && !Rick->getMovementActive() &&map1->direction(Rick) == 1){
        Rick->moveBy(cantPix, 0);
        xCamera += cantPixCamera;
    }
    else if(map1->detectCollision(Rick) && !Rick->getMovementActive() &&map1->direction(Rick) == 2){
        Rick->moveBy(-cantPix, 0);
        xCamera -= cantPixCamera;
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
    //view->setSceneRect(xCamera,yCamera,Entities->getDimScreen().width(),Entities->getDimScreen().height());
    //view->setFixedSize(Entities->getDimScreen().width(),Entities->getDimScreen().height());
}


void videogame::killrick()
{
    if(Entities->possibilityPunch() && Mezeek->getAlive()){
        Rick->setAlive(false);
        Mezeek->moveBy(-5,5);
    }
}

void videogame::shake()
{
    qDebug() << "Se sacude ejecuta animación";

}

void videogame::game()
{
    straighten();
    updateCircleVision();
    updateMove();
    rotateRick();
    rotateMezeeks();
    moveMezeeks(Rick,Mezeek);
}








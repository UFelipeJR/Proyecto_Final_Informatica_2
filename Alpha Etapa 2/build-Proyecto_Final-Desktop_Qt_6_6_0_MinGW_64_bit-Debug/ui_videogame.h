/********************************************************************************
** Form generated from reading UI file 'videogame.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOGAME_H
#define UI_VIDEOGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videogame
{
public:
    QWidget *centralwidget;
    QGraphicsView *main_scene;

    void setupUi(QMainWindow *videogame)
    {
        if (videogame->objectName().isEmpty())
            videogame->setObjectName("videogame");
        videogame->resize(1366, 768);
        videogame->setMinimumSize(QSize(1366, 768));
        videogame->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(videogame);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1024, 576));
        centralwidget->setMaximumSize(QSize(1920, 1080));
        main_scene = new QGraphicsView(centralwidget);
        main_scene->setObjectName("main_scene");
        main_scene->setGeometry(QRect(0, 0, 1366, 800));
        main_scene->setMinimumSize(QSize(1366, 768));
        main_scene->setMaximumSize(QSize(1920, 1080));
        videogame->setCentralWidget(centralwidget);

        retranslateUi(videogame);

        QMetaObject::connectSlotsByName(videogame);
    } // setupUi

    void retranslateUi(QMainWindow *videogame)
    {
        videogame->setWindowTitle(QCoreApplication::translate("videogame", "videogame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class videogame: public Ui_videogame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOGAME_H

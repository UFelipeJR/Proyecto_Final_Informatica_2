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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videogame
{
public:
    QWidget *centralwidget;
    QGraphicsView *main_scene;
    QPushButton *pushButton;
    QLabel *label;

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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(650, 230, 80, 24));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arcadepix")});
        pushButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(570, 140, 241, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arcadepix")});
        font1.setPointSize(28);
        label->setFont(font1);
        label->setCursor(QCursor(Qt::CrossCursor));
        videogame->setCentralWidget(centralwidget);

        retranslateUi(videogame);

        QMetaObject::connectSlotsByName(videogame);
    } // setupUi

    void retranslateUi(QMainWindow *videogame)
    {
        videogame->setWindowTitle(QCoreApplication::translate("videogame", "videogame", nullptr));
        pushButton->setText(QCoreApplication::translate("videogame", "Play", nullptr));
        label->setText(QCoreApplication::translate("videogame", "INTRUDER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class videogame: public Ui_videogame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOGAME_H

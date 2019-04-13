/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *connectM;
    QAction *exitM;
    QWidget *centralWidget;
    QFrame *frame;
    QPushButton *cmdB;
    QPushButton *fileB;
    QPushButton *connectB;
    QTableWidget *pc_table;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(731, 377);
        connectM = new QAction(MainWindow);
        connectM->setObjectName(QString::fromUtf8("connectM"));
        exitM = new QAction(MainWindow);
        exitM->setObjectName(QString::fromUtf8("exitM"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 731, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cmdB = new QPushButton(frame);
        cmdB->setObjectName(QString::fromUtf8("cmdB"));
        cmdB->setEnabled(false);
        cmdB->setGeometry(QRect(210, 10, 71, 71));
        fileB = new QPushButton(frame);
        fileB->setObjectName(QString::fromUtf8("fileB"));
        fileB->setEnabled(false);
        fileB->setGeometry(QRect(120, 10, 71, 71));
        connectB = new QPushButton(frame);
        connectB->setObjectName(QString::fromUtf8("connectB"));
        connectB->setEnabled(true);
        connectB->setGeometry(QRect(30, 10, 71, 71));
        pc_table = new QTableWidget(centralWidget);
        if (pc_table->columnCount() < 4)
            pc_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        pc_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        pc_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        pc_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        pc_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        pc_table->setObjectName(QString::fromUtf8("pc_table"));
        pc_table->setGeometry(QRect(20, 90, 691, 251));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(connectM);
        menu->addAction(exitM);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\345\231\250", nullptr));
        connectM->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
#ifndef QT_NO_SHORTCUT
        connectM->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_NO_SHORTCUT
        exitM->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_SHORTCUT
        exitM->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        cmdB->setText(QApplication::translate("MainWindow", "\345\221\275\344\273\244", nullptr));
        fileB->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        connectB->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem = pc_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = pc_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = pc_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "cpu", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = pc_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\345\206\205\345\255\230", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

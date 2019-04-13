/********************************************************************************
** Form generated from reading UI file 'sendfiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDFILEDIALOG_H
#define UI_SENDFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SendFileDialog
{
public:
    QLineEdit *path;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *SendFileDialog)
    {
        if (SendFileDialog->objectName().isEmpty())
            SendFileDialog->setObjectName(QString::fromUtf8("SendFileDialog"));
        SendFileDialog->resize(340, 175);
        SendFileDialog->setModal(true);
        path = new QLineEdit(SendFileDialog);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(40, 70, 271, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        path->setFont(font);
        label = new QLabel(SendFileDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 131, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        label->setFont(font1);
        pushButton = new QPushButton(SendFileDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 122, 75, 31));

        retranslateUi(SendFileDialog);

        QMetaObject::connectSlotsByName(SendFileDialog);
    } // setupUi

    void retranslateUi(QDialog *SendFileDialog)
    {
        SendFileDialog->setWindowTitle(QApplication::translate("SendFileDialog", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        label->setText(QApplication::translate("SendFileDialog", "\347\233\256\346\240\207\345\234\260\345\235\200", nullptr));
        pushButton->setText(QApplication::translate("SendFileDialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendFileDialog: public Ui_SendFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDFILEDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'sendcmddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDCMDDIALOG_H
#define UI_SENDCMDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SendCmdDialog
{
public:
    QLineEdit *cmd;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *SendCmdDialog)
    {
        if (SendCmdDialog->objectName().isEmpty())
            SendCmdDialog->setObjectName(QString::fromUtf8("SendCmdDialog"));
        SendCmdDialog->resize(340, 167);
        cmd = new QLineEdit(SendCmdDialog);
        cmd->setObjectName(QString::fromUtf8("cmd"));
        cmd->setGeometry(QRect(40, 70, 271, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        cmd->setFont(font);
        label = new QLabel(SendCmdDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 131, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        label->setFont(font1);
        pushButton = new QPushButton(SendCmdDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 122, 75, 31));

        retranslateUi(SendCmdDialog);

        QMetaObject::connectSlotsByName(SendCmdDialog);
    } // setupUi

    void retranslateUi(QDialog *SendCmdDialog)
    {
        SendCmdDialog->setWindowTitle(QApplication::translate("SendCmdDialog", "\346\214\207\344\273\244", nullptr));
        label->setText(QApplication::translate("SendCmdDialog", "\346\214\207\344\273\244", nullptr));
        pushButton->setText(QApplication::translate("SendCmdDialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendCmdDialog: public Ui_SendCmdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDCMDDIALOG_H

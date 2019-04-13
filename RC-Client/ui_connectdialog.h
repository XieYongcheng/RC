/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *ip_l;
    QLineEdit *ip_e;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QString::fromUtf8("ConnectDialog"));
        ConnectDialog->resize(335, 175);
        ConnectDialog->setModal(true);
        buttonBox = new QDialogButtonBox(ConnectDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 110, 281, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ip_l = new QLabel(ConnectDialog);
        ip_l->setObjectName(QString::fromUtf8("ip_l"));
        ip_l->setGeometry(QRect(40, 40, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        ip_l->setFont(font);
        ip_e = new QLineEdit(ConnectDialog);
        ip_e->setObjectName(QString::fromUtf8("ip_e"));
        ip_e->setGeometry(QRect(100, 39, 161, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        ip_e->setFont(font1);

        retranslateUi(ConnectDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "\350\277\236\346\216\245", nullptr));
        ip_l->setText(QApplication::translate("ConnectDialog", "IP:", nullptr));
#ifndef QT_NO_TOOLTIP
        ip_e->setToolTip(QApplication::translate("ConnectDialog", "<html><head/><body><p>\350\276\223\345\205\245\346\240\274\345\274\217\357\274\232000.000.000.000</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H

#include "sendcmddialog.h"
#include "ui_sendcmddialog.h"

SendCmdDialog::SendCmdDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SendCmdDialog) {
	ui->setupUi(this);
}

SendCmdDialog::~SendCmdDialog() {
	delete ui;
}

void SendCmdDialog::on_pushButton_clicked() {
	accept();
}

QString SendCmdDialog::getCmd() {
	return ui->cmd->text();
}

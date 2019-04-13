#include "sendfiledialog.h"
#include "ui_sendfiledialog.h"

SendFileDialog::SendFileDialog(QWidget *parent, QString path) :
    QDialog(parent),
	ui(new Ui::SendFileDialog) {
	ui->setupUi(this);
	ui->path->setText(path);
}

SendFileDialog::~SendFileDialog() {
	delete ui;
}

void SendFileDialog::on_pushButton_clicked() {
	p = ui->path->text();
	accept();
}

QString SendFileDialog::getPath() {
	return p;
}

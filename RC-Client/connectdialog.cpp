#include "connectdialog.h"
#include "ui_connectdialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConnectDialog), ip(""), is_ok(false) {
	ui->setupUi(this);
}

ConnectDialog::~ConnectDialog() {
	delete ui;
}

void ConnectDialog::on_buttonBox_accepted() {
	QString t = ui->ip_e->text();
	auto p = t.split('.');
	QRegExp r("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
	if (r.indexIn(t) != -1) {
		ip = t.toStdString();
		is_ok = true;
		accept();
		return;
	}
	QMessageBox::information(this, "error", "ip格式错误");
}

std::string ConnectDialog::getIp() {
	if (ip.empty() && is_ok) {
		throw std::exception();
	}
	return ip;
}

#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <qmessagebox.h>

namespace Ui {
	class ConnectDialog;
}

class ConnectDialog : public QDialog {
	Q_OBJECT

public:
	explicit ConnectDialog(QWidget *parent = nullptr);
	~ConnectDialog();
	std::string getIp();

private slots:
	void on_buttonBox_accepted();

public:
	bool is_ok;
private:
	Ui::ConnectDialog *ui;
	std::string ip;
};

#endif // CONNECTDIALOG_H

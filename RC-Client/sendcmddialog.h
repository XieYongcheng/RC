#ifndef SENDCMDDIALOG_H
#define SENDCMDDIALOG_H

#include <QDialog>

namespace Ui {
	class SendCmdDialog;
}

class SendCmdDialog : public QDialog {
	Q_OBJECT

public:
	explicit SendCmdDialog(QWidget *parent = nullptr);
	~SendCmdDialog();
	QString getCmd();

private slots:
	void on_pushButton_clicked();

private:
	Ui::SendCmdDialog *ui;
};

#endif // SENDCMDDIALOG_H

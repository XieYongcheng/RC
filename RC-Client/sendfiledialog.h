#ifndef SENDFILEDIALOG_H
#define SENDFILEDIALOG_H

#include <QDialog>

namespace Ui {
	class SendFileDialog;
}

class SendFileDialog : public QDialog {
	Q_OBJECT

public:
	explicit SendFileDialog(QWidget *parent = nullptr, QString path = "");
	~SendFileDialog();
	QString getPath();

private slots:
	void on_pushButton_clicked();

private:
	Ui::SendFileDialog *ui;
	QString p;
};

#endif // SENDFILEDIALOG_H

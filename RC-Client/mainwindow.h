#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qfiledialog.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_exitM_clicked();
	void on_connectM_clicked();

	void on_connectB_clicked();
	void on_fileB_clicked();
	void on_cmdB_clicked();

private:
	Ui::MainWindow *ui;
	// if 0 disconnected, if 1 connected
	int is_connected = 0;
};


#endif // MAINWINDOW_H

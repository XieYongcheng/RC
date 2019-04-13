#include "mainwindow.h"
#include <QApplication>
#include "main.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return client_run([&] {return a.exec(); });
}

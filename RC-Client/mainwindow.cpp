#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectdialog.h"
#include "sendfiledialog.h"
#include "sendcmddialog.h"
#include "main.h"
#include <qtimer.h>
#include <qthread.h>

extern tcp::socket sock;

class FunctionTransfer : public QObject {
public:
	explicit FunctionTransfer(QObject* parent = 0);
public:
	static void execinmain(std::function<void()> f);
	Qt::HANDLE mid;
signals:
	void comming(std::function<void()> f);
public slots:
	void exec(std::function<void()> f);
} main_thread_forward;

void FunctionTransfer::execinmain(std::function<void()> f) {
	main_thread_forward.exec(f);
}

FunctionTransfer::FunctionTransfer(QObject* parent) :
	QObject(parent) {
	connect(this, SIGNAL(comming(std::function<void()>)), this, SLOT(exec(std::function<void()>)), Qt::BlockingQueuedConnection);
	mid = QThread::currentThreadId();
}

void FunctionTransfer::comming(std::function<void()> f) {}

void FunctionTransfer::exec(std::function<void()> f) {
	if (mid == QThread::currentThreadId()) {
		f();
	} else {
		emit this->comming(f);
	}
}

namespace xxx {
	Close_Connect close;

	void disconnect() {
		close.disconnect();
	}

	bool connect(string ip) {
		close.connect(ip);
		return close.is_connected;
	}

	void send_file(std::string filename, std::string path) {
		::send_file(sock, filename, path);
	}

	std::string send_cmd(std::string cmd) {
		return *::send_cmd(sock, cmd);
	}

	std::string getfilename(std::string path) {
		boost::filesystem::path p(path);
		return p.filename().string();
	}
}

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::MainWindow),
	is_connected(0) {
	ui->setupUi(this);
	connect(ui->connectM, SIGNAL(triggered()), this, SLOT(on_connectM_clicked()));
	connect(ui->exitM, SIGNAL(triggered()), this, SLOT(on_exitM_clicked()));
	setFixedSize(731, 377);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_connectM_clicked() {
	if (is_connected) {
		xxx::disconnect();
		is_connected = 0;
		ui->connectM->setText("连接");
		ui->connectB->setText("连接");
		ui->fileB->setEnabled(false);
		ui->cmdB->setEnabled(false);
	} else {
		std::string ip;
		while (true) {
			ConnectDialog d(this);
			d.exec();
			try {
				if (d.is_ok) {
					ip = d.getIp();
					break;
				}
			}
			catch (const std::exception&) {
				continue;
			}
			break;
		}
		if (!ip.empty()) {
			if (xxx::connect(ip)) {
				is_connected = 1;
				ui->connectM->setText("断开");
				ui->connectB->setText("断开");
				ui->fileB->setEnabled(true);
				ui->cmdB->setEnabled(true);
			} else {
				QMessageBox::information(this, "连接失败", "连接失败");
			}
		}
	}
}

void MainWindow::on_exitM_clicked() {
	if (is_connected) {
		xxx::disconnect();
	}
	exit(0);
}

void MainWindow::on_connectB_clicked() {
	on_connectM_clicked();
}

void MainWindow::on_fileB_clicked() {
	std::string filename;
	QString str("请选择文件");
	filename = (QFileDialog::getOpenFileName(this, str)).toStdString();
	SendFileDialog d(this, xxx::getfilename(filename).c_str());
	d.exec();
	std::string path = d.getPath().toStdString();
	xxx::send_file(filename, path);
	qDebug(filename.c_str());
	qDebug(path.c_str());
}

void MainWindow::on_cmdB_clicked() {
	SendCmdDialog d(this);
	d.exec();
	std::string cmd = d.getCmd().toStdString();
	QString r(QString::fromLocal8Bit(xxx::send_cmd(cmd).c_str()));
	QMessageBox::information(this, "返回信息", r);
}

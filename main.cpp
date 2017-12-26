#include "mainwindow.h"
#include <QApplication>

int main(int argc, char **argv)
{

	QApplication app(argc, argv);

	MainWindow w;
	w.setGeometry(0, 0, 500, 300);
	w.show();

	return app.exec();
}

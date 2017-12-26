#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "VTKmain.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class MainWindow : public QMainWindow {
	Q_OBJECT
      public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

      private:
	VTKmain *vtkMain;
	QVBoxLayout *verticalLayout;
	QHBoxLayout *horizintalLayout;
	QLabel *infoLabel;
	QPushButton *clickedTimeButton;
	QWidget *centeralWidget;
	int clickedTimes;
      signals:

      public slots:
	void buttonClicked();
};

#endif // MAINWINDOW_H

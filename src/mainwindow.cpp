#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), clickedTimes(0)
{
	vtkMain = new VTKmain(this);
	verticalLayout = new QVBoxLayout();
	horizintalLayout = new QHBoxLayout();
	infoLabel = new QLabel(this);
	infoLabel->setText("QVTKWidget insede a QMainWindow with QLabel and "
	           "QPushButton . Clicked time : " +
	           QString::number(clickedTimes));
	clickedTimeButton = new QPushButton(this);
	clickedTimeButton->setText("Click me ");
	verticalLayout->addWidget(infoLabel);
	verticalLayout->addWidget(clickedTimeButton);
	horizintalLayout->addWidget(vtkMain);
	horizintalLayout->addLayout(verticalLayout);
	centeralWidget = new QWidget(this);
	centeralWidget->setLayout(horizintalLayout);
	setCentralWidget(centeralWidget);
	connect(clickedTimeButton, &QPushButton::clicked, this,
	    &MainWindow::buttonClicked);
}
MainWindow::~MainWindow()
{

	delete verticalLayout;
	delete horizintalLayout;
}

void MainWindow::buttonClicked()
{
	++clickedTimes;
	infoLabel->setText("QVTKWidget insede a QMainWindow with QLabel and "
	           "QPushButton . Clicked time : " +
	           QString::number(clickedTimes));
}

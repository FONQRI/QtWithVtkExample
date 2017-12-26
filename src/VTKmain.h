/**
base of vtk widget
VTKmain.h
Purpose: managr vtk widget
last Change: documented
@author behnam sabaghi
@version 1.0 10/7/1396
*/

#pragma once
#include "qobject.h"
#include "vtkCubeSource.h"
#include "vtkOrientationMarkerWidget.h"
#include <QVTKWidget.h>
#include <vtkActor.h>
#include <vtkAxesActor.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkIdFilter.h>
#include <vtkOBJReader.h>
#include <vtkPLYReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
class VTKmain : public QVTKWidget {
      public:
	VTKmain(QWidget *parent = nullptr);
	~VTKmain();

	// vtk renderer
	vtkSmartPointer<vtkRenderer> renderer;
	vtkSmartPointer<vtkPolyDataMapper> mapper;
	vtkSmartPointer<vtkActor> actor;
      public slots:
};

/**
base of vtk widget
VTKmain.cpp
Purpose: managr vtk widget
last Change: documented
@author behnam sabaghi
@version 1.0 10/7/1396
*/
#include "VTKmain.h"
#include <vtkCamera.h>

VTKmain::VTKmain(QWidget *parent) : QVTKWidget(parent)
{

	resize(1920, 1000);
	setMinimumSize(400, 200);
	renderer = vtkSmartPointer<vtkRenderer>::New();

	renderer->SetBackground(0, 0, 0);
	GetRenderWindow()->AddRenderer(renderer);

	vtkSmartPointer<vtkCubeSource> cube =
	    vtkSmartPointer<vtkCubeSource>::New();

	// Visualize
	mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(cube->GetOutputPort());

	actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetPointSize(1000);
	actor->GetProperty()->SetColor(1, 1, 0); //(R,G,B)
	renderer->AddActor(actor);

	// to vtkPolyData
	vtkSmartPointer<vtkDataSetSurfaceFilter> surfaceFilter =
	    vtkSmartPointer<vtkDataSetSurfaceFilter>::New();
	surfaceFilter->SetInputConnection(cube->GetOutputPort());
	surfaceFilter->Update();

	vtkSmartPointer<vtkAxesActor> axes =
	    vtkSmartPointer<vtkAxesActor>::New();

	vtkSmartPointer<vtkOrientationMarkerWidget> axesViewPort =
	    vtkOrientationMarkerWidget::New();

	axesViewPort->SetOutlineColor(0.9300, 0.5700, 0.1300);
	axesViewPort->SetOrientationMarker(axes);
	axesViewPort->SetInteractor(GetRenderWindow()->GetInteractor());
	axesViewPort->SetViewport(0.9, 0.0, 1.0, 0.1);
	axesViewPort->SetEnabled(1);
	axesViewPort->InteractiveOff();

	renderer->GetActiveCamera()->SetPosition(1000, 2500, 1000);
	renderer->Render();
	renderer->ResetCamera();
}

VTKmain::~VTKmain() {}

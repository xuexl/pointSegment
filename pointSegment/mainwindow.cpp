#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>

#include<pcl/visualization/pcl_visualizer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include<pcl/visualization/cloud_viewer.h>


#include <vtkSmartPointer.h>
#include <vtkOBJReader.h>

#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNamedColors.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    viewer(new pcl::visualization::PCLVisualizer("viewer", false))
{
    ui->setupUi(this);

        
    init();
    bindEvent();
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->txt_radio_1->setText("0.1");
    ui->txt_radio_2->setText("0.2");
    ui->txt_radio_3->setText("0.4");
    ui->txt_radio_4->setText("0.6");
    ui->txt_radio_5->setText("0.8");
    
    
    viewer->setBackgroundColor (0.1, 0.1, 0.1);
    ui->vtk->SetRenderWindow(viewer->getRenderWindow());
    ui->vtk->update();
    
}

void MainWindow::bindEvent()
{
    
    connect(ui->btn_compress, SIGNAL(clicked()), this, SLOT(compress()));
    connect(ui->btn_view, SIGNAL(clicked()), this, SLOT(view()));
    
    connect(ui->btn_1, SIGNAL(clicked()), this, SLOT(view()));
    connect(ui->btn_vtk, SIGNAL(clicked()), this, SLOT(vtk()));
    
}

void MainWindow::compress()
{
    pcl::TextureMesh mesh;
    pcl::io::loadOBJFile("H:/src1/Tile_+000_+005/Tile_+000_+005.obj", mesh);
    
    
    pcl::PointCloud<pcl::PointXYZ> pointCloud;
    auto pointCloud2 = mesh.cloud;
    pcl::fromPCLPointCloud2(pointCloud2, pointCloud);
    
    
    pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloudPtr(new pcl::PointCloud<pcl::PointXYZ>);
    *pointCloudPtr = pointCloud;

    
    viewer->addPointCloud(pointCloudPtr, "cc");
    viewer->resetCamera();
                
    ui->vtk->update();
    
    
}

void MainWindow::view()
{
    
    pcl::TextureMesh mesh;
    pcl::io::loadPolygonFileOBJ("H:/study/test/pcl/pointHandle/data/level_1_0_0.obj", mesh);
  
            
    pcl::TextureMesh mesh2;
    pcl::io::loadOBJFile("H:/study/test/pcl/pointHandle/data/level_1_0_0.obj", mesh2);
    
    mesh.tex_materials= mesh2.tex_materials;
    
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("viewer"));
    viewer->addTextureMesh(mesh,"mesh");
    
    
    ui->vtk->SetRenderWindow(viewer->getRenderWindow());
    ui->vtk->update();
    
    
}

void MainWindow::vtk()
{
    
    auto reader = vtkSmartPointer<vtkOBJReader>::New();
    reader->SetFileName("H:/study/test/pcl/pcllib/pclobj/data/level_4_0_0.obj");
    reader->Update();
    
    
    
    
    
    
    
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>

#include<pcl/visualization/pcl_visualizer.h>
#include <vtkGenericOpenGLRenderWindow.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    init();
    
    connect(ui->btn_compress, SIGNAL(clicked()), this, SLOT(compress()));
    connect(ui->btn_view, SIGNAL(clicked()), this, SLOT(view()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->txt_radio->setText("0.1");
    
}

void MainWindow::compress()
{
    
    
    
    
    
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

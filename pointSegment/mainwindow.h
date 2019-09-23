#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include  <pcl/visualization/pcl_visualizer.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    
    pcl::visualization::PCLVisualizer::Ptr viewer;
    
    
private:
    void init();
    void bindEvent();
    
private slots:
    void view();
    void compress();
    void vtk();
    
};

#endif // MAINWINDOW_H

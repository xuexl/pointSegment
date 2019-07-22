#ifndef MESHHANDLER_H
#define MESHHANDLER_H

#include<istream>
#include<QString>
#include<vector>



class MeshHandler
{
public:
    MeshHandler();
    ~MeshHandler();
    
public:
    
//    void getPointCloud(pcl::PointCloud<pcl::PointXYZ> &cloud);
    void loadOBJFile(QString file);    
    
    
private:
    QString mtlFile;
    std::vector<QString> vertices;
    std::vector<QString> texcoords;
    std::vector<QString> triangles;
    
};

#endif // MESHHANDLER_H

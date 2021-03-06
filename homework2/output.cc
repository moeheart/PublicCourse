// Copyright @2018 Pony AI Inc. All rights reserved.

#include <iostream>
#include <fstream>
#include <iomanip>

#include "homework2/pointcloud.h"

int main() {
  // ATTENTION!!! : please use absolute path for reading the data file.
  const PointCloud pointcloud = ReadPointCloudFromTextFile(
      "/home/ubuntu/PublicCourse/homework2/sample_data/VelodyneDevice32c/0.txt");
  std::cout << "Total points read: " << pointcloud.points.size() << std::endl;
  std::cout << "Rotation: " << std::endl;
  std::cout << pointcloud.rotation << std::endl;
  std::cout << "Translation: " << std::endl;
  std::cout << pointcloud.translation.transpose() << std::endl;
  std::ofstream fout("/home/ubuntu/PublicCourse/homework2/p1.txt");
  
  fout<<"Range"<<std::endl;
  for (Eigen::Vector3d p : pointcloud.points) {
      fout<<sqrt(p(0)*p(0)+p(1)*p(1)+p(2)*p(2))<<std::endl;
  }
  fout<<"Height"<<std::endl;
  for (Eigen::Vector3d p : pointcloud.points) {
      fout<<p(2)<<std::endl;
  }
  return 0;
}

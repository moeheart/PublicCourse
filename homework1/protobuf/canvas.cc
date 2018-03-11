// Copyright @2018 Pony AI Inc. All rights reserved.

#include "homework1/protobuf/canvas.h"

#include <iostream>
#include <glog/logging.h>

namespace homework1 {

using homework1::geometry::Point3D;
using homework1::geometry::Polyline;

void BuildLine(){
  Polyline line_;
  int i = 0;
  for (const auto& p : polygon_.point()) {
    i++
    auto* line_.add_point();
    point->CopyFrom(p);
    if (i==2)
        break;
  }
}

double CalLength(){
  Point3D p1, p2;
  p1 = line.GetPoint(0);
  p2 = line.GetPoint(1);
  double d;
  d = (p1.x() - p2.x())*(p1.x() - p2.x()) + (p1.y() - p2.y())*(p1.y() - p2.y()) + (p1.y() - p2.y())*(p1.y() - p2.y());
  return sqrt(d);
}

void Canvas::Draw() const {
  for (const auto& p : polygon_.point()) {
    std::cout << "Point:" << p.x() << ", " << p.y() << ", " << p.z() << std::endl;
  }
}

void Canvas::AddPoint(double x, double y, double z) {
  Point3D point;
  point.set_x(x);
  point.set_y(y);
  point.set_z(z);
  AddPoint(point);
}

void Canvas::AddPoint(const Point3D& p) {
  auto* point = polygon_.add_point();
  point->CopyFrom(p);
}

const Point3D& Canvas::GetPoint(int index) const {
  return polygon_.point(index);
}

void Canvas::ParseFromString(const std::string& serialzation) {
  polygon_.ParseFromString(serialzation);
}

const std::string Canvas::SerializeToString() const {
  std::string serialzation;
  CHECK(polygon_.SerializeToString(&serialzation)) << "Canvas serialization failed.";
  return serialzation;
}

}  // namespace homework1

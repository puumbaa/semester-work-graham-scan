//
// Created by user on 15.05.2021.
//
#pragma once
#ifndef SEMESTER_WORK_TEMPLATE_POINT_HPP
#define SEMESTER_WORK_TEMPLATE_POINT_HPP


#endif  //SEMESTER_WORK_TEMPLATE_POINT_HPP
struct point {

 private:
  int x;
  int y;

 public:
  point() = default;
  point(int x, int y) : x(x), y(y) {}

  void setX(int x_) {
    x = x_;
  }
  void setY(int y_) {
    y = y_;
  }
  int getX() const {
    return x;
  }
  int getY() const {
    return y;
  }
};
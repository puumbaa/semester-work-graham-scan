//
// Created by user on 15.05.2021.
//
#pragma once
#ifndef SEMESTER_WORK_TEMPLATE_VECTOR_HPP
#define SEMESTER_WORK_TEMPLATE_VECTOR_HPP
#include "point.hpp"
#endif  //SEMESTER_WORK_TEMPLATE_VECTOR_HPP
struct my_vector {
 private:
  int x;
  int y;

 public:
  my_vector(point a, point b) : x(b.getX() - a.getX()), y(b.getY() - a.getY()) {}

  int getX() const {
    return x;
  }
  void setX(int x_) {
    x = x_;
  }
  int getY() const {
    return y;
  }
  void setY(int y_) {
    y = y_;
  }
};
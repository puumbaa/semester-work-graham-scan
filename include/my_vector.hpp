//
// Created by user on 15.05.2021.
//

#ifndef SEMESTER_WORK_TEMPLATE_VECTOR_HPP
#define SEMESTER_WORK_TEMPLATE_VECTOR_HPP

#endif  //SEMESTER_WORK_TEMPLATE_VECTOR_HPP
struct my_vector {
  int x;
  int y;

  my_vector(point a, point b) {
    x = b.x - a.x;
    y = b.y - a.y;
  }
};
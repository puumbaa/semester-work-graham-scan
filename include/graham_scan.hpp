#pragma once

// Заголовочный файл с объявлением структуры данных

#include "point.hpp"
#include "my_vector.hpp"
namespace itis {

  std::vector<point> get_convex_hull(std::vector<point> points);
  int cross(my_vector a, my_vector b);
}  // namespace itis
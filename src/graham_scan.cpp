#include <vector>
#include <algorithm>
#include "point.hpp"
#include "my_vector.hpp"
#include "graham_scan.hpp"
using namespace std;

namespace itis {


  int cross(my_vector a, my_vector b) {
    return a.getX() * b.getY() - a.getY() * b.getX();
  }

  std::vector<point> get_convex_hull(std::vector<point> points) {

    //   Первый этап

    for (int i = 1; i < points.size(); ++i) {
      if (points[i].getX() < points[0].getX() || points[i].getX() == points[0].getX() && points[i].getY() < points[0].getY()) {
        swap(points[i], points[0]);
      }
    }

    sort(points.begin() + 1, points.end(),[&points](point a, point b)
         {
           return cross (my_vector(points[0], a),
                        my_vector(points[0], b)) > 0;
         });

    //   Второй этап

    std::vector<point> ch = {points[0], points[1]};

    for (int i = 2; i < points.size(); ++i) {
      while (
          ch.size() >= 2 &&
          cross(my_vector(ch[ch.size() - 2], ch[ch.size() - 1]),
                my_vector(ch[ch.size() - 1], points[i])) < 0)
      {
        ch.pop_back();
      }
      ch.push_back(points[i]);
    }
    return ch;
  }
}
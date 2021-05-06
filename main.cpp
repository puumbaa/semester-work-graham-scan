#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

namespace itis {
  struct point {
    int x;
    int y;
  };

  struct vector {
    int x;
    int y;

    vector(point a, point b) {
      x = b.x - a.x;
      y = b.y - a.y;
    }
  };

  int cross(vector a, vector b) {
    return a.x * b.y - a.y * b.x;
  }

  std::vector<point> get_convex_hull(std::vector<point> points) {

    //   Первый этап

    for (int i = 1; i < points.size(); ++i) {
      if (points[i].x < points[0].x || points[i].x == points[0].x && points[i].y < points[0].y) {
        swap(points[i], points[0]);
      }
    }

    sort(points.begin() + 1, points.end(),
         [&points](point a, point b) { return cross(vector(points[0], a), vector(points[0], b)) > 0; });

    //   Второй этап

    std::vector<point> ch = {points[0], points[1]};

    for (int i = 2; i < points.size(); ++i) {
      while (ch.size() >= 2
             && cross(vector(ch[ch.size() - 2], ch[ch.size() - 1]),
                      vector(ch[ch.size() - 1], points[i])) < 0)
      {
        ch.pop_back();
      }
      ch.push_back(points[i]);
    }
    return ch;
  }

  using namespace std;

  int main(int argc, char *argv[]) {
    //todo сделать тесты
    return 0;
  }
}
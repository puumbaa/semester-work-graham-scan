#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>
#include <graham_scan.hpp>
#include "point.hpp"

using namespace std;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  // работа с набором данных
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto input_file = ifstream(path);

  string line;
  string line_item;
  std::vector<point> testVector;

  for (int i = 1; i < 8; ++i) {
    input_file = ifstream(path + "\\dataset" + to_string(i) + ".csv");
    cout<<"dataset: " + to_string(i)<<endl;

    // Парсинг строеки и заполнение входного вектора
    while (getline(input_file, line, ';')) {
      size_t position = 0;
      string pair_item;

      auto *new_point = new point();  // Следующая точка
      position = line.find(',');
      pair_item = line.substr(0, position);
      new_point->setX(stoi(pair_item));  // спарсил координаты Х
      line.erase(0, position + 1);
      new_point->setY(stoi(line));  // спарсил координаты Y

      testVector.push_back(*new_point);
    }

    for (int j = 1; j < 11; ++j) {

      const auto time_point_before = chrono::steady_clock::now();
      itis::get_convex_hull(testVector);
      const auto time_point_after = chrono::steady_clock::now();

      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout <<to_string(j) + ") Time (ms): " << time_elapsed_ns / 1000000 << '\n';
    }
  }
  testVector.clear();
  return 0;
}

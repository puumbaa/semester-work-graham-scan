#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>
#include "point.hpp"
// подключаем вашу структуру данных


using namespace std;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main(int argc, char **argv) {

  // работа с набором данных
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;

  auto input_file = ifstream(path);

  string line;
  vector<point> vector;

  if (input_file) {
    for (int i = 0; i < 10; ++i) {
      input_file = ifstream (path + "\\data" + to_string(i) + ".csv");
      while (getline(input_file,line,';')){

      }
    }
    // чтение и обработка набора данных ...
  }

  // Контрольный тест: операции добавления, удаления, поиска и пр. над структурой данных

  // Tip 3: время работы программы (или участка кода) можно осуществить
  // как изнутри программы (std::chrono), так и сторонними утилитами

  const auto time_point_before = chrono::steady_clock::now();

  // здесь находится участок кода, время которого необходимо замерить

  const auto time_point_after = chrono::steady_clock::now();

  // переводим время в наносекунды
  const auto time_diff = time_point_after - time_point_before;
  const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

  cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';

  return 0;
}

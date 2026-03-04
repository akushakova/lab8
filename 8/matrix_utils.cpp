#include "matrix_utils.h"

bool get_matrix(string &Filename, int matr[MAT_M][MAT_N], int &m, int &n) {
  ifstream file;
  Filename = open_file(file);
  // Введення розмірності матриці
  do {
    cout << "Введіть кількість рядків (2-20): ";
    cin >> m;
    cout << "Введіть кількість стовпців (2-20): ";
    cin >> n;
  }
  // Повторне введення при невірній розмірності
  while (n < 2 || n > MAT_N || m < 2 || m > MAT_M);
  // Введення елементів матриці
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      file >> matr[i][j];
      if (cin.fail()) {
        cin.clear();
        cout << "Помилка при зчитуванні даних матриці";
        file.close();
        return false;
      }
    }
  file.close();
  return true;
}

void save_matrix(string Filename, const int matr[MAT_M][MAT_N], const int m,
                 const int n, const int odd_col) {
  ofstream file(Filename, ios::out | ios::trunc);
  if (!file.is_open()) {
    cout << "Помилка при відкритті файлу виводу";
    return;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      file << matr[i][j] << " ";
    file << "\n";
  }
  file << "\n\n";
  if (odd_col > 0)
    file << "Перший стовпець з лише непарними числами: " << odd_col;
  else
    file << "Стовпці з лише непарними числами відсутні";
  file.close();
}

int calc_matr_2(const int matr[MAT_M][MAT_N], const int m, const int n) {
  for (int j = 0; j < n; j++) {
    bool odd = true; // Непарність стовпця
    for (int i = 0; i < m; i++) {
      // Якщо знайдено парне значенняб переходимо до наступного стовпця
      if (matr[i][j] % 2 == 0) {
        odd = false;
        break;
      }
    }
    if (odd)
      return j + 1; // Якщо усі значення непарні повертаємо номер стовпця
  }
  return 0; // Повертаємо 0 якщо немає непарних стовпців
}

void task_2() {
  // Визначення змінних
  int matr[MAT_M][MAT_N];
  int row, col;
  string Filename;
  // Введення та виведення матриці
  if (!get_matrix(Filename, matr, row, col))
    return;
  // Пошук першого непарного стовпця
  int first_odd = calc_matr_2(matr, row, col);
  // Виведення результату
  save_matrix(Filename, matr, row, col, first_odd);
}

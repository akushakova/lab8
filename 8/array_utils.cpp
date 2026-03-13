#include "array_utils.h"
#include "utils.h"

// Функція введення кількості елементів
int input_N() {
  int value;
  // Повторюємо запит поки не буде введено вірне значення
  while (true) {
    cout << "Введіть кількість елементів масиву N: ";
    cin >> value;
    // Можливі помилки: стандартна cin.fail(),
    // N знаходиться за заданими межами [2;50]
    if (cin.fail() || value < 2 || value > ARR_N) {
      cin.clear();
      cout << "Помилка вводу. N має приймати значення від 2 до 50" << endl;
    } else {
      return value;
    }
  }
}

// ----------------------------------
// Робота з масивами
// ----------------------------------

// Функція введення кількості елементів
int input_array_N() {
  int value;
  // Повторюємо запит поки не буде введено вірне значення
  while (true) {
    cout << "Введіть кількість елементів масиву N: ";
    cin >> value;
    // Можливі помилки: стандартна cin.fail(),
    // N знаходиться за заданими межами [2;50]
    if (cin.fail() || value < 2 || value > ARR_N) {
      cin.clear();
      cout << "Помилка вводу. N має приймати значення від 2 до 50" << endl;
    } else {
      return value;
    }
  }
}

// Функція зчитування елементів масиву з файлу
bool get_double_array(double arr[ARR_N], int &n) {
  ifstream file;
  open_file(file);
  n = input_array_N();
  for (int i = 0; i < n; i++) {
    file >> arr[i];
    if (cin.fail()) {
      cin.clear();
      cout << "Помилка при зчитуванні даних масиву";
      file.close();
      return false;
    }
  }
  file.close();
  return true;
}

// Функція зчитування елементів масиву з файлу
void save_double_array(string Filename, double arr[ARR_N], int &n) {
  ofstream file(Filename);
  if (!file.is_open()) {
    cout << "Помилка при відкритті файлу виводу";
    return;
  }
  for (int i = 0; i < n; i++) {
    file << arr[i] << " ";
  }
  file.close();
}

// Функція зчитування елементів масиву з файлу
bool get_string_array(string arr[ARR_N], int &n) {
  ifstream file;
  open_file(file);
  n = input_array_N();
  for (int i = 0; i < n; i++) {
    file >> arr[i];
    if (cin.fail()) {
      cin.clear();
      cout << "Помилка при зчитуванні даних масиву";
      return false;
    }
  }
  return true;
}

// Функція зчитування елементів масиву з файлу
void save_string_array(string Filename, string arr[ARR_N], int &n) {
  ofstream file(Filename);
  if (!file.is_open()) {
    cout << "Помилка при відкритті файлу виводу";
    return;
  }
  for (int i = 0; i < n; i++) {
    file << arr[i] << " ";
  }
}

// ----------------------------------
// Array83
// ----------------------------------

// Розрахунок завдання Array83 для визначеного масиву
void calc_arr_1(double in_arr[ARR_N], const int n) {
  double last = in_arr[n - 1]; // Зберігаємо останній елемент
  // Циклічно замінюємо поточний елемент на попередній
  // Заміна починається з кінця масиву
  for (int i = n - 1; i > 0; i--) {
    in_arr[i] = in_arr[i - 1];
  }
  // Так як цикл не оновлює перший елемент,
  // оновлюємо його вручну
  in_arr[0] = last;
  // Виводимо результат
}

// Загальна функція завдання Array83
void task_1() {
  // Визначення змінних
  double in_arr[ARR_N];
  int n;
  if (!get_double_array(in_arr, n))
    return;              // Вводимо масив
  calc_arr_1(in_arr, n); // Проводимо розрахунки
  save_double_array("data/array_out_83.txt", in_arr,
                    n); // Зберігаємо масив у файл
}

// ----------------------------------
// Sort19
// ----------------------------------

// Сортування масиву
void calc_arr_3(string arr[ARR_N], const int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        string temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// Загальна функція завдання Sort19
void task_3() {
  // Визначення змінних
  string in_arr[ARR_N];
  int n;
  if (!get_string_array(in_arr, n))
    return;              // Вводимо масив
  calc_arr_3(in_arr, n); // Проводимо розрахунки
  save_string_array("data/array_out_19.txt", in_arr,
                    n); // Зберігаємо масив у файл
}

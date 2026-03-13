#include "utils.h"

string open_file(ifstream &file) {
  string filename;
  while (true) {
    cout << "Введіть назву файлу: ";
    cin >> filename;
    if (cin.fail()) {
      cin.clear();
      cout << "Помилка вводу. Не вдалося зчитати назву файлу" << endl;
      continue;
    }
    file.open(filename);
    if (!file.is_open()) {
      cout << "Не вдалося відкрити файл" << endl;
      continue;
    }
    return filename;
  }
}

void main_menu() {
  int n = 1;
  while (n != 0) {
    cout << endl << endl;
    cout << "[      Головне Меню      ]" << endl << endl;
    cout << "[ 1 ] Array30" << endl;
    cout << "[ 2 ] Matrix35" << endl;
    cout << "[ 3 ] Sort19" << endl;
    cout << "[ 0 ] Вихід" << endl << endl;
    cout << "Оберіть пункт меню: ";
    cin >> n;
    switch (n) {
    case 1:
      cout << endl << endl;
      cout << "[         Array30        ]" << endl << endl;
      task_1();
      break;
    case 2:
      cout << endl << endl;
      cout << "[        Matrix35        ]" << endl << endl;
      task_2();
      break;
    case 3:
      cout << endl << endl;
      cout << "[         Sort19         ]" << endl << endl;
      task_3();
      break;
    case 0:
      return;
    default:
      cout << endl << endl << "Невірно обрано пункт меню. Спробуйте знову";
      break;
    }
    // Очікування на Enter
    cout << endl << endl << "Натисніть Enter для повернення до головного меню";
    cin.ignore();
    cin.get();
  }
}

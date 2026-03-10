#pragma once
#include <string>
using namespace std;

// Максимальна кількість елементів масиву
const int ARR_N = 50;

// Функція введення кількості елементів
int input_array_N();

// Функція зчитування елементів дійсного масиву з файлу
bool get_double_array(double arr[ARR_N], int &n);

// Функція виведення елементів дійсного масиву у файл
void save_double_array(string Filename, const double arr[ARR_N], const int n);

// Функція зчитування елементів символьного масиву з файлу
bool get_string_array(string arr[ARR_N], int &n);

// Функція виведення елементів символьного масиву у файл
void save_string_array(string Filename, const string arr[ARR_N], const int n);

// ----------------------------------
// Array83
// ----------------------------------
// Дан масив розміру N.
// Здійснити циклічний зсув елементів масиву вправо на одну позицію
// (при цьому A1 перейде в A2, A2 — в A3, ..., AN — в A1)

// Розрахунок завдання Array83 для визначеного масиву
void calc_arr_1(double arr[ARR_N], const int n);

// ----------------------------------
// Sort19
// ----------------------------------
// Реалізувати бульбашкове сортування символьного масиву
// в порядку зростання

// Сортування масиву
void calc_arr_3(string arr[ARR_N], const int n);

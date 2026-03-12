#pragma once
#include "utils.h"

const int MAT_M = 20;
const int MAT_N = 20;

// Зчитування матриці з файлу
bool get_matrix(string &Filename, int matr[MAT_N][MAT_M], int &m, int &n);

// Запис матриці у файл
void save_matrix(string Filename, const int matr[MAT_N][MAT_M], const int m,
                 const int n, const int odd_col);

// ----------------------------------
// Завдання Matrix35
// ----------------------------------
// Дана матриця розміру M x N. Знайти номер першого з її рядків,
// що містить тільки непарні числа. Якщо таких рядків немає, то вивести 0

// Пошук першого непарного стовпця
int calc_matr_2(const int matr[MAT_M][MAT_N], const int m, const int n);

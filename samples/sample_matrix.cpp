// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами"
    << endl;
  cout << "Введите размерность матрицы: ";
  size_t sz = 0;
  cin >> sz;
  TDynamicMatrix<int> a(sz), b(sz), c(sz);
  int num = 0;
  cout << "Введите первую матрицу: ";
  cin >> a;
  cout << "Выберите операцию: " << endl;
  cout << "1.Матрица + матрица" << endl;
  cout << "2.Матрица * число" << endl;
  cout << "3.Матрица * матрица" << endl;
  size_t choose = 0;
  cin >> choose;
  switch (choose) 
  {
  case 1:
      cout << "Введите вторую матрицу: ";
      cin >> b;
      cout << a << endl;
      cout << "\t + " << "\n\n";
      cout << b << endl;
      cout << "\t = " << "\n\n";
      c = a + b;
      cout << c << endl;
      break;
  case 2:
      cout << "Введите число: ";
      cin >> num;
      cout << a << endl;
      cout << "\t * " << "\n\n";
      cout << "\t" << num << "\n\n";
      cout << "\t = " << "\n\n";
      c = a * num;
      cout << c << endl;
      break;
  case 3:
      cout << "Введите вторую матрицу: ";
      cin >> b;
      cout << a << endl;
      cout << "\t * " << "\n\n";
      cout << b << endl;
      cout << "\t = " << "\n\n";
      c = a * b;
      cout << c << endl;
      break;
  default:
      cout << "Неверный номер!";
      break;
  }
}
//---------------------------------------------------------------------------

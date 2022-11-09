// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include <tmatrix.h>
#include <ctime>

//---------------------------------------------------------------------------
void random_matrix(TDynamicMatrix<int>& mat, size_t sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        for (size_t j = 0; j < sz; j++)
        {
            mat[i][j] = rand() % 101 - 50;
        }
    }
}

void main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    cout << "Работа  с матрицами"<< endl;
    cout << "Введите размерность матрицы: ";
    size_t sz = 0;
    cin >> sz;
    size_t choice_input = 0;
    TDynamicMatrix<int> a(sz), b(sz), res(sz);
    TDynamicVector<int> vec(sz), vec_res(sz);
    int num = 0;
    cout << "Выберите операцию:" << endl;
    cout << "1. Матрица * число" << endl;
    cout << "2. Матрица * вектор" << endl;
    cout << "3. Матрица + матрица" << endl;
    cout << "4. Матрица - матрица" << endl;
    cout << "5. Матрица * матрица" << endl;
    size_t choice_operation = 0;
    cin >> choice_operation;
    switch (choice_operation)
    {
    case 1:
        cout << "Выберите способ ввода матрицы:" << endl;
        cout << "1.Ввод с клавиатуры" << endl;
        cout << "2.Рандомная генерация чисел" << endl;
        cin >> choice_input;
        switch (choice_input)
        {
        case 1:
            cout << "Введите матрицу: " << endl;
            cin >> a;
            cout << "Введите число: " << endl;
            cin >> num;
            break;
        case 2:
            random_matrix(a, sz);
            num = rand() % 201 - 100;
            break;
        default:
            cout << "Неверный номер!";
            break;
        }
        cout << a << endl;
        cout << "*" << endl;
        cout << num << endl;
        res = a * num;
        cout << "Результат: " << endl;
        cout << res << endl;
        break;
    case 2:
        cout << "Выберите способ ввода матрицы:" << endl;
        cout << "1.Ввод с клавиатуры" << endl;
        cout << "2.Рандомная генерация чисел" << endl;
        cin >> choice_input;
        switch (choice_input)
        {
        case 1:
            cout << "Введите матрицу: " << endl;
            cin >> a;
            cout << "Введите вектор: " << endl;
            cin >> vec;
            break;
        case 2:
            random_matrix(a, sz);
            for (size_t i = 0; i < sz; i++)
            {
                vec[i] = rand() % 101 - 50;
            }
            break;
        default:
            cout << "Неверный номер!";
            break;
        }
        cout << a << endl;
        cout << "*" << endl;
        cout << vec << endl;
        vec_res = a * vec;
        cout << "Результат: " << endl;
        cout << vec_res << endl;
        break;
    case 3:
        cout << "Выберите способ ввода матрицы:" << endl;
        cout << "1.Ввод с клавиатуры" << endl;
        cout << "2.Рандомная генерация чисел" << endl;
        cin >> choice_input;
        switch (choice_input)
        {
        case 1:
            cout << "Введите первую матрицу: " << endl;
            cin >> a;
            cout << "Введите вторую матрицу: " << endl;
            cin >> b;
            break;
        case 2:
            random_matrix(a, sz);
            random_matrix(b, sz);
            break;
        default:
            cout << "Неверный номер!";
            break;
        }
        cout << a << endl;
        cout << "+" << endl;
        cout << b << endl;
        res = a + b;
        cout << "Результат: " << endl;
        cout << res << endl;
        break;
    case 4:
        cout << "Выберите способ ввода матрицы:" << endl;
        cout << "1.Ввод с клавиатуры" << endl;
        cout << "2.Рандомная генерация чисел" << endl;
        cin >> choice_input;
        switch (choice_input)
        {
        case 1:
            cout << "Введите первую матрицу: " << endl;
            cin >> a;
            cout << "Введите вторую матрицу: " << endl;
            cin >> b;
            break;
        case 2:
            random_matrix(a, sz);
            random_matrix(b, sz);
            break;
        default:
            cout << "Неверный номер!";
            break;
        }
        cout << a << endl;
        cout << "-" << endl;
        cout << b << endl;
        res = a - b;
        cout << "Результат: " << endl;
        cout << res << endl;
        break;
    case 5:
        cout << "Выберите способ ввода матрицы:" << endl;
        cout << "1.Ввод с клавиатуры" << endl;
        cout << "2.Рандомная генерация чисел" << endl;
        cin >> choice_input;
        switch (choice_input)
        {
        case 1:
            cout << "Введите первую матрицу: " << endl;
            cin >> a;
            cout << "Введите вторую матрицу: " << endl;
            cin >> b;
            break;
        case 2:
            random_matrix(a, sz);
            random_matrix(b, sz);
            break;
        default:
            cout << "Неверный номер!";
            break;
        }
        cout << a << endl;
        cout << "*" << endl;
        cout << b << endl;
        res = a * b;
        cout << "Результат: " << endl;
        cout << res << endl;
        break;
    default:
        cout << "Неверный номер!";
        break;
    }
}
//---------------------------------------------------------------------------

#include <iostream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "=== КОНТРОЛЬНЫЕ ЗАДАНИЯ ===" << endl;

    cout << "\n--- Задание 1: Передача массива в функцию ---" << endl;

    const int n = 8;
    int testArray[n] = { 5, -2, 8, -1, 3, 10, -4, 7 };

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << testArray[i] << " ";
    }
    cout << endl;

    cout << "Сумма элементов: " << arraySum(testArray, n) << endl;
    cout << "Среднее значение: " << arrayAverage(testArray, n) << endl;
    cout << "Сумма отрицательных: " << sumNegative(testArray, n) << endl;
    cout << "Сумма положительных: " << sumPositive(testArray, n) << endl;
    cout << "Сумма с четными индексами: " << sumEvenIndex(testArray, n) << endl;
    cout << "Сумма с нечетными индексами: " << sumOddIndex(testArray, n) << endl;

    int minVal, maxVal, minIndex, maxIndex;
    findMinMax(testArray, n, minVal, maxVal, minIndex, maxIndex);
    cout << "Минимальный элемент: " << minVal << " (индекс: " << minIndex << ")" << endl;
    cout << "Максимальный элемент: " << maxVal << " (индекс: " << maxIndex << ")" << endl;
    cout << "Произведение между min и max: " << productBetweenMinMax(testArray, n) << endl;

    // Тестирование сортировки
    int sortArray[n] = { 5, -2, 8, -1, 3, 10, -4, 7 };
    cout << "\nМассив до сортировки: ";
    for (int i = 0; i < n; i++) cout << sortArray[i] << " ";

    selectionSort(sortArray, n);

    cout << "\nМассив после сортировки: ";
    for (int i = 0; i < n; i++) cout << sortArray[i] << " ";
    cout << endl;

    // Задание 2: Возврат массива из функции
    cout << "\n--- Задание 2: Возврат массива из функции ---" << endl;

    int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
    int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };
    int kc = sizeof(a) / sizeof(a[0]);

    cout << "Массив A: ";
    for (int i = 0; i < kc; i++) cout << a[i] << " ";
    cout << "\nМассив B: ";
    for (int i = 0; i < kc; i++) cout << b[i] << " ";

    int* c = max_vect(kc, a, b);

    cout << "\nРезультирующий массив C: ";
    for (int i = 0; i < kc; i++) cout << c[i] << " ";
    cout << endl;

    delete[] c;

    // Задание 3: Поиск методом транспозиции
    cout << "\n--- Задание 3: Поиск методом транспозиции ---" << endl;

    int searchArray[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
    int searchSize = sizeof(searchArray) / sizeof(searchArray[0]);

    cout << "Массив для поиска: ";
    for (int i = 0; i < searchSize; i++) cout << searchArray[i] << " ";
    cout << endl;

    int key = 40;
    int position = transpositionSearch(searchArray, searchSize, key);
    if (position != -1) {
        cout << "Элемент " << key << " найден на позиции: " << position << endl;
    }
    else {
        cout << "Элемент " << key << " не найден" << endl;
    }

    cout << "Массив после поиска: ";
    for (int i = 0; i < searchSize; i++) cout << searchArray[i] << " ";
    cout << endl;

    position = transpositionSearch(searchArray, searchSize, key);
    if (position != -1) {
        cout << "Повторный поиск элемента " << key << ": позиция " << position << endl;
    }
    else {
        cout << "Элемент " << key << " не найден при повторном поиске" << endl;
    }

    cout << "Массив после повторного поиска: ";
    for (int i = 0; i < searchSize; i++) cout << searchArray[i] << " ";
    cout << endl;

    // Задание 4: Обработка параметров командной строки
    cout << "\n--- Задание 4: Передача параметров в программу ---" << endl;
    cout << "Для тестирования запустите программу из командной строки:" << endl;
    cout << "program.exe -a 12 45  для сложения" << endl;
    cout << "program.exe -m 12 45  для умножения" << endl;

    // Эмуляция вызова с параметрами для демонстрации
    cout << "\nДемонстрация работы:" << endl;

    // Эмулируем вызов: program.exe -a 12 45
    const char* testArgs1[] = { "program.exe", "-a", "12", "45" };
    cout << "Эмуляция: program.exe -a 12 45" << endl;
    processCommandLine(4, testArgs1);
    cout << endl;

    // Эмулируем вызов: program.exe -m 12 45  
    const char* testArgs2[] = { "program.exe", "-m", "12", "45" };
    cout << "Эмуляция: program.exe -m 12 45" << endl;
    processCommandLine(4, testArgs2);
    cout << endl;

    // Эмулируем ошибочный вызов (неверный флаг)
    const char* testArgs3[] = { "program.exe", "-x", "12", "45" };
    cout << "Эмуляция: program.exe -x 12 45" << endl;
    processCommandLine(4, testArgs3);
    cout << endl;

    // Эмулируем ошибочный вызов (неверное количество параметров)
    const char* testArgs4[] = { "program.exe", "-a", "12" };
    cout << "Эмуляция: program.exe -a 12" << endl;
    processCommandLine(3, testArgs4);
    cout << endl;

    // Эмулируем ошибочный вызов (нечисловые параметры)
    const char* testArgs5[] = { "program.exe", "-a", "abc", "45" };
    cout << "Эмуляция: program.exe -a abc 45" << endl;
    processCommandLine(4, testArgs5);


    return 0;
}
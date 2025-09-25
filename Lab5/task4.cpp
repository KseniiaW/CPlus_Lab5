#include <iostream>
#include <cstring> 
#include <cstdlib>  
#include "task4.h"

using namespace std;

void printUsage(const char* programName) {
    cout << "Использование: " << programName << " [-a | -m] число1 число2" << endl;
    cout << "  -a  сложение двух чисел" << endl;
    cout << "  -m  умножение двух чисел" << endl;
    cout << "Пример: " << programName << " -a 12 45" << endl;
}

int processCommandLine(int argc, const char* argv[]) {  
    if (argc != 4) {
        cerr << "Ошибка: неверное количество параметров!" << endl;
        printUsage(argv[0]);
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) != 0 && strncmp(argv[1], "-m", 2) != 0) {
        cerr << "Ошибка: неверный флаг операции!" << endl;
        printUsage(argv[0]);
        return 1;
    }

    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    if (num1 == 0 && argv[2][0] != '0') {
        cerr << "Ошибка: первый аргумент не является числом!" << endl;
        return 1;
    }
    if (num2 == 0 && argv[3][0] != '0') {
        cerr << "Ошибка: второй аргумент не является числом!" << endl;
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) == 0) {
        cout << "Результат сложения: " << num1 + num2 << endl;
    }
    else {
        cout << "Результат умножения: " << num1 * num2 << endl;
    }

    return 0;
}
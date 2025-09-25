#include <iostream>
#include <cstring> 
#include <cstdlib>  
#include "task4.h"

using namespace std;

void printUsage(const char* programName) {
    cout << "�������������: " << programName << " [-a | -m] �����1 �����2" << endl;
    cout << "  -a  �������� ���� �����" << endl;
    cout << "  -m  ��������� ���� �����" << endl;
    cout << "������: " << programName << " -a 12 45" << endl;
}

int processCommandLine(int argc, const char* argv[]) {  
    if (argc != 4) {
        cerr << "������: �������� ���������� ����������!" << endl;
        printUsage(argv[0]);
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) != 0 && strncmp(argv[1], "-m", 2) != 0) {
        cerr << "������: �������� ���� ��������!" << endl;
        printUsage(argv[0]);
        return 1;
    }

    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    if (num1 == 0 && argv[2][0] != '0') {
        cerr << "������: ������ �������� �� �������� ������!" << endl;
        return 1;
    }
    if (num2 == 0 && argv[3][0] != '0') {
        cerr << "������: ������ �������� �� �������� ������!" << endl;
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) == 0) {
        cout << "��������� ��������: " << num1 + num2 << endl;
    }
    else {
        cout << "��������� ���������: " << num1 * num2 << endl;
    }

    return 0;
}
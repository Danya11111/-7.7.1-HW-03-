#include <iostream>
#include <algorithm>
#include "IntArray.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    IntArray<char> array1; 
    int n;
    cout << "��� ��� char. ������� 0 ��� �������� � ���� int" << endl;
    cout << " �������� ��������: " << endl;
    cout << " 1 - C������ ��������� " << endl;
    cout << " 0 - ��������� ��������� " << endl;
    do {
        cin >> n;
        if (n == 1) {
            int size;
            cout << "������� ������ ����������: "; cin >> size;
            try {
                array1.resize(size);
            }
            catch (const char* exception) {
                cout << "Exeption: " << exception << endl;
            }
            cout << "������� �������� ����������: " << endl;
            for (int i = 0; i < size; i++) {
                cout << "������� " << i + 1 << " �������: ";
                char value;
                cin >> value;
                array1[i] = value;
            }
            cout << "��� ���������: " << endl;
            array1.vivod_arr();
            cout << endl;
        }
        else if (n == 0)
            break;
        else {
            cout << " ������ �����! ���������� �����." << endl;
        }
    } while (n < 0 || n > 1);
    if (n != 0) {
        do {
            cout << " �������� ��������: " << endl;
            cout << " 1 - C���������� � ������� �� ����� ���������" << endl;
            cout << " 2 - �������� ������ � �������� ���������� �� ������� " << endl;
            cout << " 3 - �������� ������ ���������� " << endl;
            cout << " 4 - �������� ������� � ��������� " << endl;
            cout << " 5 - ������� ������� �� ���������� " << endl;
            cout << " 6 - ������� �������� � ������ ���������� " << endl;
            cout << " 7 - ������� �������� � ����� ���������� " << endl;
            cout << " 8 - ����� � ���������� �������� �� ��������  " << endl;
            cout << " 0 - ��������� ��������� � ������� � ���� int" << endl;
            cin >> n;

            switch (n)
            {
            case 1:
            {
                IntArray<char> array11{array1};
                array11 = array1;
                array11 = array11;
                array1 = array1;
                cout << "����� ���������� 1: " << endl;
                array11.vivod_arr();
                cout << endl;
                break;
            }
            case 2:
            {
                int index;
                if (array1.getLength() == 0) {
                    cout << "��� ��������� ����!" << endl;
                    break;
                }
                do {
                    cout << "������� ������ �������� ������� ������ �������� �� 1 �� " << array1.getLength() << endl;
                    cin >> index;
                    if (index < 1 || index > array1.getLength()) {
                        cout << "������ �����! ���������� ��� ���." << endl;
                    }
                } while (index < 1 || index > array1.getLength());
                cout << "������� ��� �������� - " << index << " = " << array1[index - 1] << endl;
                cout << "�������� �������� � ���� ���������: " << endl;
                int d;
                cout << " 1 - ������� ������� " << endl << " 2 - �������� ������� " << endl;
                do {
                    cin >> d;
                    if (d < 1 || d > 2) {
                        cout << "������ �����! ���������� ��� ���." << endl;
                    }
                } while (d < 1 || d > 2);
                if (d == 1) {
                    try {
                        array1.remove(index - 1);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }
                else {
                    cout << "������� �������� �� ������� ������ �������� ������� �������: " << endl;
                    char value;
                    cin >> value;
                    try {
                        array1.set_value(index - 1, value);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }

                cout << "��� ��������� ������: ";
                array1.vivod_arr();
                break;
            }
            case 3:
            {
                cout << "������� ����� ������ ����������: " << endl;
                int size;
                cin >> size;
                try {
                    array1.resize(size);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }
                cout << "��� ��������� ������: ";
                array1.vivod_arr();
                break;
            }
            case 4:
            {
                char  value;
                int index;
                cout << "������� ������ ��������, ����� �������� �� ������ �������� ����� �� 1 �� " << array1.getLength() << " : ";
                cin >> index;
                cout << "������� �������� ������ ��������: "; cin >> value;
                try {
                    array1.insertBefore(value, index);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array1.vivod_arr();
                break;
            }
            case 5:
            {
                int index;
                if (array1.getLength() == 0) {
                    cout << "��� ��������� ����!" << endl;
                    break;
                }
                cout << "������� ������ ��������, ������� �� ������ ������� �� 1 �� " << array1.getLength() << " : "; cin >> index;
                try {
                    array1.remove(index - 1);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array1.vivod_arr();
                break;
            }
            case 6:
            {
                char value;
                cout << "������� �������� ������� ����� �������� � ������: "; cin >> value;
                try {
                    array1.insertAtBeginning(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array1.vivod_arr();
                break;
            }
            case 7:
            {
                char value;
                cout << "������� �������� ������� ����� �������� � �����: "; cin >> value;
                try {
                    array1.insertAtEnd(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array1.vivod_arr();
                break;
            }
            case 8:
            {
                char prov;
                cout << "������� �����, ������� ����� ���������: "; cin >> prov;
                if (array1.prowerka(prov))
                    cout << "����� '" << prov << "' ������� � ����������!" << endl;
                else
                    cout << "����� '" << prov << "' �� ������� � ����������." << endl;
                break;
            }
            default:
                break;
            }
        } while (n != 0);
    }
    cout << "��� ��� ������� �� int." << endl;
    IntArray<int> array2;
    cout << "��� ��� int. ������� 0 ��� �������� � ���� float" << endl;
    cout << " �������� ��������: " << endl;
    cout << " 1 - C������ ��������� " << endl;
    cout << " 0 - ��������� ��������� " << endl;
    do {
        cin >> n;
        if (n == 1) {
            int size;
            cout << "������� ������ ����������: "; cin >> size;
            try {
                array2.resize(size);
            }
            catch (const char* exception) {
                cout << "Exeption: " << exception << endl;
            }
            cout << "������� �������� ����������: " << endl;
            for (int i = 0; i < size; i++) {
                cout << "������� " << i + 1 << " �������: ";
                int value;
                cin >> value;
                array2[i] = value;
            }
            cout << "��� ���������: " << endl;
            array2.vivod_arr();
            cout << endl;
        }
        else if (n == 0)
            break;
        else {
            cout << " ������ �����! ���������� �����." << endl;
        }
    } while (n < 0 || n > 1);
    if (n != 0) {
        do {
            cout << " �������� ��������: " << endl;
            cout << " 1 - C���������� � ������� �� ����� ���������" << endl;
            cout << " 2 - �������� ������ � �������� ���������� �� ������� " << endl;
            cout << " 3 - �������� ������ ���������� " << endl;
            cout << " 4 - �������� ������� � ��������� " << endl;
            cout << " 5 - ������� ������� �� ���������� " << endl;
            cout << " 6 - ������� �������� � ������ ���������� " << endl;
            cout << " 7 - ������� �������� � ����� ���������� " << endl;
            cout << " 8 - ����� � ���������� �������� �� ��������  " << endl;
            cout << " 0 - ��������� ��������� � ������� � ���� float" << endl;
            cin >> n;

            switch (n)
            {
            case 1:
            {
                
                IntArray<int> array22{array2};
                array22 = array2;
                array22 = array22;
                array2 = array2;
                cout << "����� ���������� 1: " << endl;
                array22.vivod_arr();
                cout << endl;
                break;
            }
            case 2:
            {
                int index;
                if (array2.getLength() == 0) {
                    cout << "��� ��������� ����!" << endl;
                    break;
                }
                do {
                    cout << "������� ������ �������� ������� ������ �������� �� 1 �� " << array2.getLength() << endl;
                    cin >> index;
                    if (index < 1 || index > array2.getLength()) {
                        cout << "������ �����! ���������� ��� ���." << endl;
                    }
                } while (index < 1 || index > array2.getLength());
                cout << "������� ��� �������� - " << index << " = " << array2[index - 1] << endl;
                cout << "�������� �������� � ���� ���������: " << endl;
                int d;
                cout << " 1 - ������� ������� " << endl << " 2 - �������� ������� " << endl;
                do {
                    cin >> d;
                    if (d < 1 || d > 2) {
                        cout << "������ �����! ���������� ��� ���." << endl;
                    }
                } while (d < 1 || d > 2);
                if (d == 1) {
                    try {
                        array2.remove(index - 1);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }
                else {
                    cout << "������� �������� �� ������� ������ �������� ������� �������: " << endl;
                    int value;
                    cin >> value;
                    try {
                        array2.set_value(index - 1, value);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }

                cout << "��� ��������� ������: ";
                array2.vivod_arr();
                break;
            }
            case 3:
            {
                cout << "������� ����� ������ ����������: " << endl;
                int size;
                cin >> size;
                try {
                    array2.resize(size);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }
                cout << "��� ��������� ������: ";
                array2.vivod_arr();
                break;
            }
            case 4:
            {
                int  value, index;
                cout << "������� ������ ��������, ����� �������� �� ������ �������� ����� �� 1 �� " << array2.getLength() << " : ";
                cin >> index;
                cout << "������� �������� ������ ��������: "; cin >> value;
                try {
                    array2.insertBefore(value, index);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array2.vivod_arr();
                break;
            }
            case 5:
            {
                int index;
                if (array2.getLength() == 0) {
                    cout << "��� ��������� ����!" << endl;
                    break;
                }
                cout << "������� ������ ��������, ������� �� ������ ������� �� 1 �� " << array2.getLength() << " : "; cin >> index;
                try {
                    array2.remove(index - 1);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array2.vivod_arr();
                break;
            }
            case 6:
            {
                int value;
                cout << "������� �������� ������� ����� �������� � ������: "; cin >> value;
                try {
                    array2.insertAtBeginning(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array2.vivod_arr();
                break;
            }
            case 7:
            {
                int value;
                cout << "������� �������� ������� ����� �������� � �����: "; cin >> value;
                try {
                    array2.insertAtEnd(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array2.vivod_arr();
                break;
            }
            case 8:
            {
                int prov;
                cout << "������� �����, ������� ����� ���������: "; cin >> prov;
                if (array2.prowerka(prov))
                    cout << "����� '" << prov << "' ������� � ����������!" << endl;
                else
                    cout << "����� '" << prov << "' �� ������� � ����������." << endl;
                break;
            }
            default:
                break;
            }
        } while (n != 0);
    }
    cout << "��� ��� ������� �� float." << endl;
    IntArray<float> array3;
    cout << "��� ��� int. ������� 0 ��� �������� � ���� float" << endl;
    cout << " �������� ��������: " << endl;
    cout << " 1 - C������ ��������� " << endl;
    cout << " 0 - ��������� ��������� " << endl;
    do {
        cin >> n;
        if (n == 1) {
            int size;
            cout << "������� ������ ����������: "; cin >> size;
            try {
                array3.resize(size);
            }
            catch (const char* exception) {
                cout << "Exeption: " << exception << endl;
            }
            cout << "������� �������� ����������: " << endl;
            for (int i = 0; i < size; i++) {
                cout << "������� " << i + 1 << " �������: ";
                float value;
                cin >> value;
                array3[i] = value;
            }
            cout << "��� ���������: " << endl;
            array3.vivod_arr();
            cout << endl;
        }
        else if (n == 0)
            break;
        else {
            cout << " ������ �����! ���������� �����." << endl;
        }
    } while (n < 0 || n > 1);
    if (n != 0) {
        do {
            cout << " �������� ��������: " << endl;
            cout << " 1 - C���������� � ������� �� ����� ���������" << endl;
            cout << " 2 - �������� ������ � �������� ���������� �� ������� " << endl;
            cout << " 3 - �������� ������ ���������� " << endl;
            cout << " 4 - �������� ������� � ��������� " << endl;
            cout << " 5 - ������� ������� �� ���������� " << endl;
            cout << " 6 - ������� �������� � ������ ���������� " << endl;
            cout << " 7 - ������� �������� � ����� ���������� " << endl;
            cout << " 8 - ����� � ���������� �������� �� ��������  " << endl;
            cout << " 0 - ��������� ��������� � ������� � ���� float" << endl;
            cin >> n;

            switch (n)
            {
            case 1:
            {

                IntArray<float> array33{ array3 };
                array33 = array3;
                array33 = array33;
                array3 = array3;
                cout << "����� ���������� 1: " << endl;
                array33.vivod_arr();
                cout << endl;
                break;
            }
            case 2:
            {
                int index;
                if (array3.getLength() == 0) {
                    cout << "��� ��������� ����!" << endl;
                    break;
                }
                do {
                    cout << "������� ������ �������� ������� ������ �������� �� 1 �� " << array3.getLength() << endl;
                    cin >> index;
                    if (index < 1 || index > array3.getLength()) {
                        cout << "������ �����! ���������� ��� ���." << endl;
                    }
                } while (index < 1 || index > array3.getLength());
                cout << "������� ��� �������� - " << index << " = " << array3[index - 1] << endl;
                cout << "�������� �������� � ���� ���������: " << endl;
                int d;
                cout << " 1 - ������� ������� " << endl << " 2 - �������� ������� " << endl;
                do {
                    cin >> d;
                    if (d < 1 || d > 2) {
                        cout << "������ �����! ���������� ��� ���." << endl;
                    }
                } while (d < 1 || d > 2);
                if (d == 1) {
                    try {
                        array3.remove(index - 1);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }
                else {
                    cout << "������� �������� �� ������� ������ �������� ������� �������: " << endl;
                    float value;
                    cin >> value;
                    try {
                        array3.set_value(index - 1, value);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }

                cout << "��� ��������� ������: ";
                array3.vivod_arr();
                break;
            }
            case 3:
            {
                cout << "������� ����� ������ ����������: " << endl;
                int size;
                cin >> size;
                try {
                    array3.resize(size);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }
                cout << "��� ��������� ������: ";
                array3.vivod_arr();
                break;
            }
            case 4:
            {
                float value;
                int index;
                cout << "������� ������ ��������, ����� �������� �� ������ �������� ����� �� 1 �� " << array3.getLength() << " : ";
                cin >> index;
                cout << "������� �������� ������ ��������: "; cin >> value;
                try {
                    array3.insertBefore(value, index);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array3.vivod_arr();
                break;
            }
            case 5:
            {
                int index;
                if (array3.getLength() == 0) {
                    cout << "��� ��������� ����!" << endl;
                    break;
                }
                cout << "������� ������ ��������, ������� �� ������ ������� �� 1 �� " << array3.getLength() << " : "; cin >> index;
                try {
                    array3.remove(index - 1);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array3.vivod_arr();
                break;
            }
            case 6:
            {
                float value;
                cout << "������� �������� ������� ����� �������� � ������: "; cin >> value;
                try {
                    array3.insertAtBeginning(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array3.vivod_arr();
                break;
            }
            case 7:
            {
                float value;
                cout << "������� �������� ������� ����� �������� � �����: "; cin >> value;
                try {
                    array3.insertAtEnd(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "��� ��������� ������: ";
                array3.vivod_arr();
                break;
            }
            case 8:
            {
                float prov;
                cout << "������� �����, ������� ����� ���������: "; cin >> prov;
                if (array3.prowerka(prov))
                    cout << "����� '" << prov << "' ������� � ����������!" << endl;
                else
                    cout << "����� '" << prov << "' �� ������� � ����������." << endl;
                break;
            }
            default:
                break;
            }
        } while (n != 0);
    }
    return 0;
}


#include <iostream>
#include <algorithm>
#include "IntArray.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    IntArray<char> array1; 
    int n;
    cout << "Ваш тип char. Нажмите 0 для перехода к типу int" << endl;
    cout << " Выберите действие: " << endl;
    cout << " 1 - Cоздать контейнер " << endl;
    cout << " 0 - Завершить программу " << endl;
    do {
        cin >> n;
        if (n == 1) {
            int size;
            cout << "Введите размер контейнера: "; cin >> size;
            try {
                array1.resize(size);
            }
            catch (const char* exception) {
                cout << "Exeption: " << exception << endl;
            }
            cout << "Введите элементы контейнера: " << endl;
            for (int i = 0; i < size; i++) {
                cout << "Введите " << i + 1 << " элемент: ";
                char value;
                cin >> value;
                array1[i] = value;
            }
            cout << "Ваш контейнер: " << endl;
            array1.vivod_arr();
            cout << endl;
        }
        else if (n == 0)
            break;
        else {
            cout << " Ошибка ввода! Попробуйте снова." << endl;
        }
    } while (n < 0 || n > 1);
    if (n != 0) {
        do {
            cout << " Выберите действие: " << endl;
            cout << " 1 - Cкопировать и вывести на экран контейнер" << endl;
            cout << " 2 - Получить доступ к элементу контейнера по индексу " << endl;
            cout << " 3 - Изменить размер контейнера " << endl;
            cout << " 4 - Вставить элемент в контейнер " << endl;
            cout << " 5 - Удалить элемент из контейнера " << endl;
            cout << " 6 - Вставка элемента в начало контейнера " << endl;
            cout << " 7 - Вставка элемента в конец контейнера " << endl;
            cout << " 8 - Поиск в контейнере элемента по значению  " << endl;
            cout << " 0 - Завершить программу и перейти к типу int" << endl;
            cin >> n;

            switch (n)
            {
            case 1:
            {
                IntArray<char> array11{array1};
                array11 = array1;
                array11 = array11;
                array1 = array1;
                cout << "Копия контейнера 1: " << endl;
                array11.vivod_arr();
                cout << endl;
                break;
            }
            case 2:
            {
                int index;
                if (array1.getLength() == 0) {
                    cout << "Ваш контейнер пуст!" << endl;
                    break;
                }
                do {
                    cout << "Введите индекс элемента который хотите изменить от 1 до " << array1.getLength() << endl;
                    cin >> index;
                    if (index < 1 || index > array1.getLength()) {
                        cout << "Ошибка ввода! Попробуйте ещё раз." << endl;
                    }
                } while (index < 1 || index > array1.getLength());
                cout << "Элемент под индексом - " << index << " = " << array1[index - 1] << endl;
                cout << "Выберите действие с этим элементом: " << endl;
                int d;
                cout << " 1 - удалить элемент " << endl << " 2 - изменить элемент " << endl;
                do {
                    cin >> d;
                    if (d < 1 || d > 2) {
                        cout << "Ошибка ввода! Попробуйте еще раз." << endl;
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
                    cout << "Введите значение на которое хотите изменить текущий элемент: " << endl;
                    char value;
                    cin >> value;
                    try {
                        array1.set_value(index - 1, value);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }

                cout << "Ваш контейнер теперь: ";
                array1.vivod_arr();
                break;
            }
            case 3:
            {
                cout << "Введите новый размер контейнера: " << endl;
                int size;
                cin >> size;
                try {
                    array1.resize(size);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }
                cout << "Ваш контейнер теперь: ";
                array1.vivod_arr();
                break;
            }
            case 4:
            {
                char  value;
                int index;
                cout << "Введите индекс элемента, после которого вы хотите вставить новый от 1 до " << array1.getLength() << " : ";
                cin >> index;
                cout << "Введите значение нового элемента: "; cin >> value;
                try {
                    array1.insertBefore(value, index);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array1.vivod_arr();
                break;
            }
            case 5:
            {
                int index;
                if (array1.getLength() == 0) {
                    cout << "Ваш контейнер пуст!" << endl;
                    break;
                }
                cout << "Введите индекс элемента, который вы хотите удалить от 1 до " << array1.getLength() << " : "; cin >> index;
                try {
                    array1.remove(index - 1);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array1.vivod_arr();
                break;
            }
            case 6:
            {
                char value;
                cout << "Введите значение которое нужно вставить в начало: "; cin >> value;
                try {
                    array1.insertAtBeginning(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array1.vivod_arr();
                break;
            }
            case 7:
            {
                char value;
                cout << "Введите значение которое нужно вставить в конец: "; cin >> value;
                try {
                    array1.insertAtEnd(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array1.vivod_arr();
                break;
            }
            case 8:
            {
                char prov;
                cout << "Введите букву, которую нужно проверить: "; cin >> prov;
                if (array1.prowerka(prov))
                    cout << "Буква '" << prov << "' найдена в контейнере!" << endl;
                else
                    cout << "Буква '" << prov << "' не найдена в контейнере." << endl;
                break;
            }
            default:
                break;
            }
        } while (n != 0);
    }
    cout << "Ваш тип изменен на int." << endl;
    IntArray<int> array2;
    cout << "Ваш тип int. Нажмите 0 для перехода к типу float" << endl;
    cout << " Выберите действие: " << endl;
    cout << " 1 - Cоздать контейнер " << endl;
    cout << " 0 - Завершить программу " << endl;
    do {
        cin >> n;
        if (n == 1) {
            int size;
            cout << "Введите размер контейнера: "; cin >> size;
            try {
                array2.resize(size);
            }
            catch (const char* exception) {
                cout << "Exeption: " << exception << endl;
            }
            cout << "Введите элементы контейнера: " << endl;
            for (int i = 0; i < size; i++) {
                cout << "Введите " << i + 1 << " элемент: ";
                int value;
                cin >> value;
                array2[i] = value;
            }
            cout << "Ваш контейнер: " << endl;
            array2.vivod_arr();
            cout << endl;
        }
        else if (n == 0)
            break;
        else {
            cout << " Ошибка ввода! Попробуйте снова." << endl;
        }
    } while (n < 0 || n > 1);
    if (n != 0) {
        do {
            cout << " Выберите действие: " << endl;
            cout << " 1 - Cкопировать и вывести на экран контейнер" << endl;
            cout << " 2 - Получить доступ к элементу контейнера по индексу " << endl;
            cout << " 3 - Изменить размер контейнера " << endl;
            cout << " 4 - Вставить элемент в контейнер " << endl;
            cout << " 5 - Удалить элемент из контейнера " << endl;
            cout << " 6 - Вставка элемента в начало контейнера " << endl;
            cout << " 7 - Вставка элемента в конец контейнера " << endl;
            cout << " 8 - Поиск в контейнере элемента по значению  " << endl;
            cout << " 0 - Завершить программу и перейти к типу float" << endl;
            cin >> n;

            switch (n)
            {
            case 1:
            {
                
                IntArray<int> array22{array2};
                array22 = array2;
                array22 = array22;
                array2 = array2;
                cout << "Копия контейнера 1: " << endl;
                array22.vivod_arr();
                cout << endl;
                break;
            }
            case 2:
            {
                int index;
                if (array2.getLength() == 0) {
                    cout << "Ваш контейнер пуст!" << endl;
                    break;
                }
                do {
                    cout << "Введите индекс элемента который хотите изменить от 1 до " << array2.getLength() << endl;
                    cin >> index;
                    if (index < 1 || index > array2.getLength()) {
                        cout << "Ошибка ввода! Попробуйте ещё раз." << endl;
                    }
                } while (index < 1 || index > array2.getLength());
                cout << "Элемент под индексом - " << index << " = " << array2[index - 1] << endl;
                cout << "Выберите действие с этим элементом: " << endl;
                int d;
                cout << " 1 - удалить элемент " << endl << " 2 - изменить элемент " << endl;
                do {
                    cin >> d;
                    if (d < 1 || d > 2) {
                        cout << "Ошибка ввода! Попробуйте еще раз." << endl;
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
                    cout << "Введите значение на которое хотите изменить текущий элемент: " << endl;
                    int value;
                    cin >> value;
                    try {
                        array2.set_value(index - 1, value);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }

                cout << "Ваш контейнер теперь: ";
                array2.vivod_arr();
                break;
            }
            case 3:
            {
                cout << "Введите новый размер контейнера: " << endl;
                int size;
                cin >> size;
                try {
                    array2.resize(size);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }
                cout << "Ваш контейнер теперь: ";
                array2.vivod_arr();
                break;
            }
            case 4:
            {
                int  value, index;
                cout << "Введите индекс элемента, после которого вы хотите вставить новый от 1 до " << array2.getLength() << " : ";
                cin >> index;
                cout << "Введите значение нового элемента: "; cin >> value;
                try {
                    array2.insertBefore(value, index);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array2.vivod_arr();
                break;
            }
            case 5:
            {
                int index;
                if (array2.getLength() == 0) {
                    cout << "Ваш контейнер пуст!" << endl;
                    break;
                }
                cout << "Введите индекс элемента, который вы хотите удалить от 1 до " << array2.getLength() << " : "; cin >> index;
                try {
                    array2.remove(index - 1);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array2.vivod_arr();
                break;
            }
            case 6:
            {
                int value;
                cout << "Введите значение которое нужно вставить в начало: "; cin >> value;
                try {
                    array2.insertAtBeginning(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array2.vivod_arr();
                break;
            }
            case 7:
            {
                int value;
                cout << "Введите значение которое нужно вставить в конец: "; cin >> value;
                try {
                    array2.insertAtEnd(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array2.vivod_arr();
                break;
            }
            case 8:
            {
                int prov;
                cout << "Введите число, которое нужно проверить: "; cin >> prov;
                if (array2.prowerka(prov))
                    cout << "Число '" << prov << "' найдено в контейнере!" << endl;
                else
                    cout << "Число '" << prov << "' не найдено в контейнере." << endl;
                break;
            }
            default:
                break;
            }
        } while (n != 0);
    }
    cout << "Ваш тип изменен на float." << endl;
    IntArray<float> array3;
    cout << "Ваш тип int. Нажмите 0 для перехода к типу float" << endl;
    cout << " Выберите действие: " << endl;
    cout << " 1 - Cоздать контейнер " << endl;
    cout << " 0 - Завершить программу " << endl;
    do {
        cin >> n;
        if (n == 1) {
            int size;
            cout << "Введите размер контейнера: "; cin >> size;
            try {
                array3.resize(size);
            }
            catch (const char* exception) {
                cout << "Exeption: " << exception << endl;
            }
            cout << "Введите элементы контейнера: " << endl;
            for (int i = 0; i < size; i++) {
                cout << "Введите " << i + 1 << " элемент: ";
                float value;
                cin >> value;
                array3[i] = value;
            }
            cout << "Ваш контейнер: " << endl;
            array3.vivod_arr();
            cout << endl;
        }
        else if (n == 0)
            break;
        else {
            cout << " Ошибка ввода! Попробуйте снова." << endl;
        }
    } while (n < 0 || n > 1);
    if (n != 0) {
        do {
            cout << " Выберите действие: " << endl;
            cout << " 1 - Cкопировать и вывести на экран контейнер" << endl;
            cout << " 2 - Получить доступ к элементу контейнера по индексу " << endl;
            cout << " 3 - Изменить размер контейнера " << endl;
            cout << " 4 - Вставить элемент в контейнер " << endl;
            cout << " 5 - Удалить элемент из контейнера " << endl;
            cout << " 6 - Вставка элемента в начало контейнера " << endl;
            cout << " 7 - Вставка элемента в конец контейнера " << endl;
            cout << " 8 - Поиск в контейнере элемента по значению  " << endl;
            cout << " 0 - Завершить программу и перейти к типу float" << endl;
            cin >> n;

            switch (n)
            {
            case 1:
            {

                IntArray<float> array33{ array3 };
                array33 = array3;
                array33 = array33;
                array3 = array3;
                cout << "Копия контейнера 1: " << endl;
                array33.vivod_arr();
                cout << endl;
                break;
            }
            case 2:
            {
                int index;
                if (array3.getLength() == 0) {
                    cout << "Ваш контейнер пуст!" << endl;
                    break;
                }
                do {
                    cout << "Введите индекс элемента который хотите изменить от 1 до " << array3.getLength() << endl;
                    cin >> index;
                    if (index < 1 || index > array3.getLength()) {
                        cout << "Ошибка ввода! Попробуйте ещё раз." << endl;
                    }
                } while (index < 1 || index > array3.getLength());
                cout << "Элемент под индексом - " << index << " = " << array3[index - 1] << endl;
                cout << "Выберите действие с этим элементом: " << endl;
                int d;
                cout << " 1 - удалить элемент " << endl << " 2 - изменить элемент " << endl;
                do {
                    cin >> d;
                    if (d < 1 || d > 2) {
                        cout << "Ошибка ввода! Попробуйте еще раз." << endl;
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
                    cout << "Введите значение на которое хотите изменить текущий элемент: " << endl;
                    float value;
                    cin >> value;
                    try {
                        array3.set_value(index - 1, value);
                    }
                    catch (const char* exception) {
                        cout << "Exeption: " << exception << endl;
                    }

                }

                cout << "Ваш контейнер теперь: ";
                array3.vivod_arr();
                break;
            }
            case 3:
            {
                cout << "Введите новый размер контейнера: " << endl;
                int size;
                cin >> size;
                try {
                    array3.resize(size);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }
                cout << "Ваш контейнер теперь: ";
                array3.vivod_arr();
                break;
            }
            case 4:
            {
                float value;
                int index;
                cout << "Введите индекс элемента, после которого вы хотите вставить новый от 1 до " << array3.getLength() << " : ";
                cin >> index;
                cout << "Введите значение нового элемента: "; cin >> value;
                try {
                    array3.insertBefore(value, index);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array3.vivod_arr();
                break;
            }
            case 5:
            {
                int index;
                if (array3.getLength() == 0) {
                    cout << "Ваш контейнер пуст!" << endl;
                    break;
                }
                cout << "Введите индекс элемента, который вы хотите удалить от 1 до " << array3.getLength() << " : "; cin >> index;
                try {
                    array3.remove(index - 1);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array3.vivod_arr();
                break;
            }
            case 6:
            {
                float value;
                cout << "Введите значение которое нужно вставить в начало: "; cin >> value;
                try {
                    array3.insertAtBeginning(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array3.vivod_arr();
                break;
            }
            case 7:
            {
                float value;
                cout << "Введите значение которое нужно вставить в конец: "; cin >> value;
                try {
                    array3.insertAtEnd(value);
                }
                catch (const char* exception) {
                    cout << "Exeption: " << exception << endl;
                }

                cout << "Ваш контейнер теперь: ";
                array3.vivod_arr();
                break;
            }
            case 8:
            {
                float prov;
                cout << "Введите число, которое нужно проверить: "; cin >> prov;
                if (array3.prowerka(prov))
                    cout << "Число '" << prov << "' найдено в контейнере!" << endl;
                else
                    cout << "Число '" << prov << "' не найдено в контейнере." << endl;
                break;
            }
            default:
                break;
            }
        } while (n != 0);
    }
    return 0;
}


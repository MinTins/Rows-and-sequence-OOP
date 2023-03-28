/*
* Group: K-23               *
* Name: Flakey Roman        *
* Lab-1: Rows and sequences *
*/


#include <iostream>
#include "RowsMethod.h"
#include <Windows.h>


int main() {
    SetConsoleOutputCP(1251);
    RowsMethod rm;
    char choice[3];

    std::cout << "****[ К-23 Флакей Роман | ООП | Лаб1 ]****\n";

    std::cout << "1. Пошук точного підрядка в рядку\n";
    std::cout << "2. Нечіткий пошук (близькі за відстанню, алгоритм Ландау-Вішкіна)\n";
    std::cout << "3. Перевірка на підпослідовність\n";
    std::cout << "4. Загальні підпослідовності. Відстань (алгоритм Вагнера-Фішера)\n";
    std::cout << "5. Пошук hcs, lis, his (heavest common sequence - алгоритм Джекобсона-Во, longest incremental sequence - алгоритм Робінсона-Шенстеда, heavest incremental sequence - алгоритм Джекобсона-Во)\n";
    std::cout << "6. Максимальний повторюваний підрядок (наївний алгоритм)\n";
    std::cout << "7. Загальні елементи двох масивів\n";
    std::cout << "8. Бінарний пошук\n";
    std::cout << "9. Інтерполяційний пошук\n";
    std::cout << "10. Бінарний пошук з визначенням найближчих вузлів\n";
    std::cout << "q. Вихід\n";

    while (true) {
        std::cout << "\nВведіть номер методу (1-10) або q для виходу: ";
        std::cin >> choice;

        if (choice[0] == 'q') {
            break;
        }

        int method = atoi(choice);

        if (method < 1 || method > 10) {
            std::cout << "Неправильний вибір!\n";
            continue;
        }

        int option;
        std::cout << "Виконати метод з заготовленими параметрами (1) чи ввести параметри користувача (2)? ";
        std::cin >> option;


        if (option == 1) {
            switch (method) {
            case 1: {
                std::string text = "hello world";
                std::string pattern = "world";
                int result = rm.exactSubstringSearch(text, pattern);
                std::cout << "Текст: " << text << "\n";
                std::cout << "Шаблон: " << pattern << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 2: {
                std::string text = "hello world";
                std::string pattern = "wirld";
                int result = rm.fuzzySearch(text, pattern);
                std::cout << "Текст: " << text << "\n";
                std::cout << "Шаблон: " << pattern << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 3: {
                std::string text = "hello world";
                std::string pattern = "world";
                bool result = rm.isSubsequence(text, pattern);
                std::cout << "Текст: " << text << "\n";
                std::cout << "Шаблон: " << pattern << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 4: {
                std::string text1 = "hello";
                std::string text2 = "world";
                int result = rm.editDistance(text1, text2);
                std::cout << "Текст 1: " << text1 << "\n";
                std::cout << "Текст 2: " << text2 << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 5: {
                // hcs
                std::vector<int> arr1 = { 1, 2, 3 };
                std::vector<int> arr2 = { 2, 3, 4 };
                int result1 = rm.hcs(arr1, arr2);
                // lis
                std::vector<int> arr3 = { 10, 22, 9, 33, 21, 50 };
                int result2 = rm.lis(arr3);
                // his
                std::vector<int> arr4 = { 1, 101, 2, 3, 100, 4, 5 };
                int result3 = rm.his(arr4);
                std::cout << "Масив 1: [";
                for (int i = 0; i < arr1.size(); i++) {
                    std::cout << arr1[i];
                    if (i != arr1.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Масив 2: [";
                for (int i = 0; i < arr2.size(); i++) {
                    std::cout << arr2[i];
                    if (i != arr2.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Результат hcs: " << result1 << "\n";
                std::cout << "Масив: [";
                for (int i = 0; i < arr3.size(); i++) {
                    std::cout << arr3[i];
                    if (i != arr3.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Результат lis: " << result2 << "\n";
                std::cout << "Масив: [";
                for (int i = 0; i < arr4.size(); i++) {
                    std::cout << arr4[i];
                    if (i != arr4.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Результат his: " << result3 << "\n";
                break;
            }
            case 6: {
                std::string text = "banana";
                std::string result = rm.maxRepeatedSubstring(text);
                std::cout << "Текст: " << text << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 7: {
                std::vector<int> arr1 = { 1, 2, 3 };
                std::vector<int> arr2 = { 2, 3, 4 };
                std::vector<int> result = rm.commonElements(arr1, arr2);
                std::cout << "Масив 1: [";
                for (int i = 0; i < arr1.size(); i++) {
                    std::cout << arr1[i];
                    if (i != arr1.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Масив 2: [";
                for (int i = 0; i < arr2.size(); i++) {
                    std::cout << arr2[i];
                    if (i != arr2.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Результат: [";
                for (int i = 0; i < result.size(); i++) {
                    std::cout << result[i];
                    if (i != result.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                break;
            }
            case 8: {
                std::vector<int> arr = { 1, 2, 3 };
                int target = 2;
                int result = rm.binarySearch(arr, target);
                std::cout << "Масив: [";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i];
                    if (i != arr.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Цільове значення: " << target << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 9: {
                std::vector<int> arr = { 1, 2, 3 };
                int target = 2;
                int result = rm.interpolationSearch(arr, target);
                std::cout << "Масив: [";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i];
                    if (i != arr.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Цільове значення: " << target << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 10: {
                std::vector<int> arr = { 1, 2, 4 };
                int target = 3;
                int result = rm.binarySearchClosestNodes(arr, target);
                std::cout << "Масив: [";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i];
                    if (i != arr.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "Цільове значення: " << target << "\n";
                std::cout << "Результат: " << result << "\n";
                break;
            }
            }
        }
        else if (option == 2) {
            // Введення параметрів користувача
            switch (method) {
            case 1: {
                std::string text;
                std::string pattern;
                std::cout << "Введіть текст: ";
                std::cin >> text;
                std::cout << "Введіть шаблон: ";
                std::cin >> pattern;
                int result = rm.exactSubstringSearch(text, pattern);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 2: {
                std::string text;
                std::string pattern;
                std::cout << "Введіть текст: ";
                std::cin >> text;
                std::cout << "Введіть шаблон: ";
                std::cin >> pattern;
                int result = rm.fuzzySearch(text, pattern);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 3: {
                std::string text;
                std::string pattern;
                std::cout << "Введіть текст: ";
                std::cin >> text;
                std::cout << "Введіть шаблон: ";
                std::cin >> pattern;
                bool result = rm.isSubsequence(text, pattern);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 4: {
                std::string text1;
                std::string text2;
                std::cout << "Введіть перший текст: ";
                std::cin >> text1;
                std::cout << "Введіть другий текст: ";
                std::cin >> text2;
                int result = rm.editDistance(text1, text2);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 5: {
                // hcs
                int n1;
                std::cout << "Введіть кількість елементів першого масиву: ";
                std::cin >> n1;
                std::vector<int> arr1(n1);
                std::cout << "Введіть елементи першого масиву: ";
                for (int i = 0; i < n1; i++)
                    std::cin >> arr1[i];
                int n2;
                std::cout << "Введіть кількість елементів другого масиву: ";
                std::cin >> n2;
                std::vector<int> arr2(n2);
                std::cout << "Введіть елементи другого масиву: ";
                for (int i = 0; i < n2; i++)
                    std::cin >> arr2[i];
                int result1 = rm.hcs(arr1, arr2);
                // lis
                int n3;
                std::cout << "Введіть кількість елементів масиву: ";
                std::cin >> n3;
                std::vector<int> arr3(n3);
                std::cout << "Введіть елементи масиву: ";
                for (int i = 0; i < n3; i++)
                    std::cin >> arr3[i];
                int result2 = rm.lis(arr3);
                // his
                int n4;
                std::cout << "Введіть кількість елементів масиву: ";
                std::cin >> n4;
                std::vector<int> arr4(n4);
                std::cout << "Введіть елементи масиву: ";
                for (int i = 0; i < n4; i++)
                    std::cin >> arr4[i];
                int result3 = rm.his(arr4);
                std::cout << "Результат hcs: " << result1 << "\n";
                std::cout << "Результат lis: " << result2 << "\n";
                std::cout << "Результат his: " << result3 << "\n";
                break;
            }
            case 6: {
                std::string text;
                std::cout << "Введіть текст: ";
                std::cin >> text;
                std::string result = rm.maxRepeatedSubstring(text);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 7: {int n1;
                std::cout << "Введіть кількість елементів першого масиву: ";
                std::cin >> n1;
                std::vector<int> arr1(n1);
                std::cout << "Введіть елементи першого масиву: ";
                for (int i = 0; i < n1; i++)
                    std::cin >> arr1[i];
                int n2;
                std::cout << "Введіть кількість елементів другого масиву: ";
                std::cin >> n2;
                std::vector<int> arr2(n2);
                std::cout << "Введіть елементи другого масиву: ";
                for (int i = 0; i < n2; i++)
                    std::cin >> arr2[i];
                std::vector<int> result = rm.commonElements(arr1, arr2);
                std::cout << "Результат: [";
                for (int i = 0; i < result.size(); i++) {
                    std::cout << result[i];
                    if (i != result.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                break;
            }
            case 8: {
                int n;
                std::cout << "Введіть кількість елементів масиву: ";
                std::cin >> n;
                std::vector<int> arr(n);
                std::cout << "Введіть елементи масиву: ";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                int target;
                std::cout << "Введіть цільове значення: ";
                std::cin >> target;
                int result = rm.binarySearch(arr, target);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 9: {
                int n;
                std::cout << "Введіть кількість елементів масиву: ";
                std::cin >> n;
                std::vector<int> arr(n);
                std::cout << "Введіть елементи масиву: ";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                int target;
                std::cout << "Введіть цільове значення: ";
                std::cin >> target;
                int result = rm.interpolationSearch(arr, target);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            case 10: {
                int n;
                std::cout << "Введіть кількість елементів масиву: ";
                std::cin >> n;
                std::vector<int> arr(n);
                std::cout << "Введіть елементи масиву: ";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                int target;
                std::cout << "Введіть цільове значення: ";
                std::cin >> target;
                int result = rm.binarySearchClosestNodes(arr, target);
                std::cout << "Результат: " << result << "\n";
                break;
            }
            }
        }
        else {
            std::cout << "Неправильний вибір!\n";
        }
    }
    return 0;
}
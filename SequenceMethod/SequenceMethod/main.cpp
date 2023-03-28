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

    std::cout << "****[ �-23 ������ ����� | ��� | ���1 ]****\n";

    std::cout << "1. ����� ������� ������� � �����\n";
    std::cout << "2. �������� ����� (������ �� ��������, �������� ������-³����)\n";
    std::cout << "3. �������� �� �������������\n";
    std::cout << "4. ������� �������������. ³������ (�������� �������-Գ����)\n";
    std::cout << "5. ����� hcs, lis, his (heavest common sequence - �������� ����������-��, longest incremental sequence - �������� ��������-��������, heavest incremental sequence - �������� ����������-��)\n";
    std::cout << "6. ������������ ������������ ������� (������ ��������)\n";
    std::cout << "7. ������� �������� ���� ������\n";
    std::cout << "8. �������� �����\n";
    std::cout << "9. ��������������� �����\n";
    std::cout << "10. �������� ����� � ����������� ���������� �����\n";
    std::cout << "q. �����\n";

    while (true) {
        std::cout << "\n������ ����� ������ (1-10) ��� q ��� ������: ";
        std::cin >> choice;

        if (choice[0] == 'q') {
            break;
        }

        int method = atoi(choice);

        if (method < 1 || method > 10) {
            std::cout << "������������ ����!\n";
            continue;
        }

        int option;
        std::cout << "�������� ����� � ������������� ����������� (1) �� ������ ��������� ����������� (2)? ";
        std::cin >> option;


        if (option == 1) {
            switch (method) {
            case 1: {
                std::string text = "hello world";
                std::string pattern = "world";
                int result = rm.exactSubstringSearch(text, pattern);
                std::cout << "�����: " << text << "\n";
                std::cout << "������: " << pattern << "\n";
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 2: {
                std::string text = "hello world";
                std::string pattern = "wirld";
                int result = rm.fuzzySearch(text, pattern);
                std::cout << "�����: " << text << "\n";
                std::cout << "������: " << pattern << "\n";
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 3: {
                std::string text = "hello world";
                std::string pattern = "world";
                bool result = rm.isSubsequence(text, pattern);
                std::cout << "�����: " << text << "\n";
                std::cout << "������: " << pattern << "\n";
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 4: {
                std::string text1 = "hello";
                std::string text2 = "world";
                int result = rm.editDistance(text1, text2);
                std::cout << "����� 1: " << text1 << "\n";
                std::cout << "����� 2: " << text2 << "\n";
                std::cout << "���������: " << result << "\n";
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
                std::cout << "����� 1: [";
                for (int i = 0; i < arr1.size(); i++) {
                    std::cout << arr1[i];
                    if (i != arr1.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "����� 2: [";
                for (int i = 0; i < arr2.size(); i++) {
                    std::cout << arr2[i];
                    if (i != arr2.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "��������� hcs: " << result1 << "\n";
                std::cout << "�����: [";
                for (int i = 0; i < arr3.size(); i++) {
                    std::cout << arr3[i];
                    if (i != arr3.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "��������� lis: " << result2 << "\n";
                std::cout << "�����: [";
                for (int i = 0; i < arr4.size(); i++) {
                    std::cout << arr4[i];
                    if (i != arr4.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "��������� his: " << result3 << "\n";
                break;
            }
            case 6: {
                std::string text = "banana";
                std::string result = rm.maxRepeatedSubstring(text);
                std::cout << "�����: " << text << "\n";
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 7: {
                std::vector<int> arr1 = { 1, 2, 3 };
                std::vector<int> arr2 = { 2, 3, 4 };
                std::vector<int> result = rm.commonElements(arr1, arr2);
                std::cout << "����� 1: [";
                for (int i = 0; i < arr1.size(); i++) {
                    std::cout << arr1[i];
                    if (i != arr1.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "����� 2: [";
                for (int i = 0; i < arr2.size(); i++) {
                    std::cout << arr2[i];
                    if (i != arr2.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "���������: [";
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
                std::cout << "�����: [";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i];
                    if (i != arr.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "ֳ����� ��������: " << target << "\n";
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 9: {
                std::vector<int> arr = { 1, 2, 3 };
                int target = 2;
                int result = rm.interpolationSearch(arr, target);
                std::cout << "�����: [";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i];
                    if (i != arr.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "ֳ����� ��������: " << target << "\n";
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 10: {
                std::vector<int> arr = { 1, 2, 4 };
                int target = 3;
                int result = rm.binarySearchClosestNodes(arr, target);
                std::cout << "�����: [";
                for (int i = 0; i < arr.size(); i++) {
                    std::cout << arr[i];
                    if (i != arr.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "]\n";
                std::cout << "ֳ����� ��������: " << target << "\n";
                std::cout << "���������: " << result << "\n";
                break;
            }
            }
        }
        else if (option == 2) {
            // �������� ��������� �����������
            switch (method) {
            case 1: {
                std::string text;
                std::string pattern;
                std::cout << "������ �����: ";
                std::cin >> text;
                std::cout << "������ ������: ";
                std::cin >> pattern;
                int result = rm.exactSubstringSearch(text, pattern);
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 2: {
                std::string text;
                std::string pattern;
                std::cout << "������ �����: ";
                std::cin >> text;
                std::cout << "������ ������: ";
                std::cin >> pattern;
                int result = rm.fuzzySearch(text, pattern);
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 3: {
                std::string text;
                std::string pattern;
                std::cout << "������ �����: ";
                std::cin >> text;
                std::cout << "������ ������: ";
                std::cin >> pattern;
                bool result = rm.isSubsequence(text, pattern);
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 4: {
                std::string text1;
                std::string text2;
                std::cout << "������ ������ �����: ";
                std::cin >> text1;
                std::cout << "������ ������ �����: ";
                std::cin >> text2;
                int result = rm.editDistance(text1, text2);
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 5: {
                // hcs
                int n1;
                std::cout << "������ ������� �������� ������� ������: ";
                std::cin >> n1;
                std::vector<int> arr1(n1);
                std::cout << "������ �������� ������� ������: ";
                for (int i = 0; i < n1; i++)
                    std::cin >> arr1[i];
                int n2;
                std::cout << "������ ������� �������� ������� ������: ";
                std::cin >> n2;
                std::vector<int> arr2(n2);
                std::cout << "������ �������� ������� ������: ";
                for (int i = 0; i < n2; i++)
                    std::cin >> arr2[i];
                int result1 = rm.hcs(arr1, arr2);
                // lis
                int n3;
                std::cout << "������ ������� �������� ������: ";
                std::cin >> n3;
                std::vector<int> arr3(n3);
                std::cout << "������ �������� ������: ";
                for (int i = 0; i < n3; i++)
                    std::cin >> arr3[i];
                int result2 = rm.lis(arr3);
                // his
                int n4;
                std::cout << "������ ������� �������� ������: ";
                std::cin >> n4;
                std::vector<int> arr4(n4);
                std::cout << "������ �������� ������: ";
                for (int i = 0; i < n4; i++)
                    std::cin >> arr4[i];
                int result3 = rm.his(arr4);
                std::cout << "��������� hcs: " << result1 << "\n";
                std::cout << "��������� lis: " << result2 << "\n";
                std::cout << "��������� his: " << result3 << "\n";
                break;
            }
            case 6: {
                std::string text;
                std::cout << "������ �����: ";
                std::cin >> text;
                std::string result = rm.maxRepeatedSubstring(text);
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 7: {int n1;
                std::cout << "������ ������� �������� ������� ������: ";
                std::cin >> n1;
                std::vector<int> arr1(n1);
                std::cout << "������ �������� ������� ������: ";
                for (int i = 0; i < n1; i++)
                    std::cin >> arr1[i];
                int n2;
                std::cout << "������ ������� �������� ������� ������: ";
                std::cin >> n2;
                std::vector<int> arr2(n2);
                std::cout << "������ �������� ������� ������: ";
                for (int i = 0; i < n2; i++)
                    std::cin >> arr2[i];
                std::vector<int> result = rm.commonElements(arr1, arr2);
                std::cout << "���������: [";
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
                std::cout << "������ ������� �������� ������: ";
                std::cin >> n;
                std::vector<int> arr(n);
                std::cout << "������ �������� ������: ";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                int target;
                std::cout << "������ ������� ��������: ";
                std::cin >> target;
                int result = rm.binarySearch(arr, target);
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 9: {
                int n;
                std::cout << "������ ������� �������� ������: ";
                std::cin >> n;
                std::vector<int> arr(n);
                std::cout << "������ �������� ������: ";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                int target;
                std::cout << "������ ������� ��������: ";
                std::cin >> target;
                int result = rm.interpolationSearch(arr, target);
                std::cout << "���������: " << result << "\n";
                break;
            }
            case 10: {
                int n;
                std::cout << "������ ������� �������� ������: ";
                std::cin >> n;
                std::vector<int> arr(n);
                std::cout << "������ �������� ������: ";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                int target;
                std::cout << "������ ������� ��������: ";
                std::cin >> target;
                int result = rm.binarySearchClosestNodes(arr, target);
                std::cout << "���������: " << result << "\n";
                break;
            }
            }
        }
        else {
            std::cout << "������������ ����!\n";
        }
    }
    return 0;
}
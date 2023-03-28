// RowsMethod.h
#ifndef ROWSMETHOD_H
#define ROWSMETHOD_H

#include <string>
#include <vector>

class RowsMethod {
public:
    // 1. Пошук точного підрядка в рядку
    int exactSubstringSearch(const std::string& text, const std::string& pattern);

    // 2. Нечіткий пошук (близькі за відстанню, алгоритм Ландау-Вішкіна)
    int fuzzySearch(const std::string& text, const std::string& pattern);

    // 3. Перевірка на підпослідовність
    bool isSubsequence(const std::string& text, const std::string& pattern);

    // 4. Загальні підпослідовності. Відстань (алгоритм Вагнера-Фішера)
    int editDistance(const std::string& text1, const std::string& text2);

    // 5. Пошук hcs, lis, his (heavest common sequence - алгоритм Джекобсона-Во,
    // longest incremental sequence - алгоритм Робінсона-Шенстеда,
    // heavest incremental sequence - алгоритм Джекобсона-Во)
    int hcs(const std::vector<int>& arr1, const std::vector<int>& arr2);
    int lis(const std::vector<int>& arr);
    int his(const std::vector<int>& arr);

    // 6. Максимальний повторюваний підрядок (наївний алгоритм)
    std::string maxRepeatedSubstring(const std::string& text);

    // 7. Загальні елементи двох масивів ()
    std::vector<int> commonElements(const std::vector<int>& arr1, const std::vector<int>& arr2);

    // 8. Бінарний пошук
    int binarySearch(const std::vector<int>& arr, int target);

    // 9. Інтерполяційний пошук
    int interpolationSearch(const std::vector<int>& arr, int target);

    // 10. Бінарний пошук з визначенням найближчих вузлів
    int binarySearchClosestNodes(const std::vector<int>& arr, int target);
};

#endif
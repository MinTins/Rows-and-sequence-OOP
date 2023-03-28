// RowsMethod.h
#ifndef ROWSMETHOD_H
#define ROWSMETHOD_H

#include <string>
#include <vector>

class RowsMethod {
public:
    // 1. ����� ������� ������� � �����
    int exactSubstringSearch(const std::string& text, const std::string& pattern);

    // 2. �������� ����� (������ �� ��������, �������� ������-³����)
    int fuzzySearch(const std::string& text, const std::string& pattern);

    // 3. �������� �� �������������
    bool isSubsequence(const std::string& text, const std::string& pattern);

    // 4. ������� �������������. ³������ (�������� �������-Գ����)
    int editDistance(const std::string& text1, const std::string& text2);

    // 5. ����� hcs, lis, his (heavest common sequence - �������� ����������-��,
    // longest incremental sequence - �������� ��������-��������,
    // heavest incremental sequence - �������� ����������-��)
    int hcs(const std::vector<int>& arr1, const std::vector<int>& arr2);
    int lis(const std::vector<int>& arr);
    int his(const std::vector<int>& arr);

    // 6. ������������ ������������ ������� (������ ��������)
    std::string maxRepeatedSubstring(const std::string& text);

    // 7. ������� �������� ���� ������ ()
    std::vector<int> commonElements(const std::vector<int>& arr1, const std::vector<int>& arr2);

    // 8. �������� �����
    int binarySearch(const std::vector<int>& arr, int target);

    // 9. ��������������� �����
    int interpolationSearch(const std::vector<int>& arr, int target);

    // 10. �������� ����� � ����������� ���������� �����
    int binarySearchClosestNodes(const std::vector<int>& arr, int target);
};

#endif
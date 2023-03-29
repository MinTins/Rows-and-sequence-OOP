// RowsMethod.cpp
#include "RowsMethod.h"
#include <algorithm>


int RowsMethod::exactSubstringSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;

        if (j == m)
            return i;
    }

    return -1;
}



int RowsMethod::fuzzySearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int maxErrors = 100; // Максимальна кількість допустимих помилок

    if (m > n)
        return -1;

    std::vector<int> prev(m + 1);
    std::vector<int> curr(m + 1);

    for (int i = 0; i <= m; i++)
        prev[i] = i;

    for (int i = 0; i < n; i++) {
        curr[0] = i + 1;
        int minVal = curr[0];

        for (int j = 0; j < m; j++) {
            if (text[i] == pattern[j])
                curr[j + 1] = prev[j];
            else
                curr[j + 1] = std::min({ prev[j + 1], curr[j], prev[j] }) + 1;

            minVal = std::min(minVal, curr[j + 1]);
        }

        if (minVal > maxErrors)
          return -1;

        std::swap(prev, curr);
    }

    if (prev[m] <= maxErrors)
        return prev[m];
    else
        return -1;
}


bool RowsMethod::isSubsequence(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int j = 0;

    for (int i = 0; i < n && j < m; i++)
        if (text[i] == pattern[j])
            j++;

    // return j;

    return (j == m);
}


int RowsMethod::editDistance(const std::string& text1, const std::string& text2) {
    int n = text1.length();
    int m = text2.length();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
        }
    }

    return dp[n][m];
}


int RowsMethod::hcs(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr1[i - 1] == arr2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int RowsMethod::lis(const std::vector<int>& arr) {
    int n = arr.size();

    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = std::max(dp[i], dp[j] + 1);

    return *std::max_element(dp.begin(), dp.end());
}

int RowsMethod::his(const std::vector<int>& arr) {
    int n = arr.size();

    std::vector<int> dp(n, arr[0]);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = std::max(dp[i], dp[j] + arr[i]);

    return *std::max_element(dp.begin(), dp.end());
}


std::string RowsMethod::maxRepeatedSubstring(const std::string& text) {
    int n = text.length();
    std::string result;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;
            while (text[i + k] == text[j + k])
                k++;

            if (k > result.length())
                result = text.substr(i, k);
        }
    }

    return result;
}


std::vector<int> RowsMethod::commonElements(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return result;
}



int RowsMethod::binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}


int RowsMethod::interpolationSearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target)
                return left;
            else
                return -1;
        }

        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}


int RowsMethod::binarySearchClosestNodes(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (right < 0)
        return left;
    else if (left >= arr.size())
        return right;
    else
        return (std::abs(arr[left] - target) < std::abs(arr[right] - target)) ? left : right;
}


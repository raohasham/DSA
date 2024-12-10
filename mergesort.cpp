#include<iostream>
#include<vector>
#include<random>

void Merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(mid - left + 1);
    std::vector<int> rightArr(right - mid);
    
    for (int i = 0; i < leftArr.size(); i++) {
        leftArr[i] = arr[left + i];
    }
    
    for (int i = 0; i < rightArr.size(); i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < leftArr.size()) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < rightArr.size()) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 99);

    std::vector<int> arr(100);

    for (int i = 0; i < 100; i++) {
        arr[i] = dist(gen);
    }

    MergeSort(arr, 0, arr.size() - 1);

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}

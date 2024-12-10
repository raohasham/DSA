#include<iostream>
#include<vector>
#include<random>

int Partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
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

    QuickSort(arr, 0, arr.size() - 1);

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}

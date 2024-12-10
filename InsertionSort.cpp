#include<iostream>
#include<vector>
#include<random>

void insertionSort(std::vector<int>& a)
{
    for (int i = 1; i < a.size(); ++i) {
        int key = a[i];
        int j = i - 1;

     
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
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

    insertionSort(arr);
  
for(int i : arr){
    std::cout<<i << " ";
}
    return 0;
}

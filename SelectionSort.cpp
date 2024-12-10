#include<iostream>
#include<vector>
#include<random>

void SelectionSort(std::vector<int>& a){
    for (int i = 0; i < a.size()-1; i++)
    {   int min = i;
        for (int j = i+1; j < a.size(); ++j)
        {
            if(a[j]<a[min]){
                min = j;
            }
        }
        std::swap(a[i],a[min]);
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

    SelectionSort(arr);
  
for(int i : arr){
    std::cout<<i << " ";
}
    return 0;
}

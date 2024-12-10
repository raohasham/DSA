#include<iostream>
#include<vector>
#include<random>

void BubbleSort(std::vector<int>& a){
for (int i = 0; i < a.size()-1 ; i++)
{
    for (int j = 0; j < a.size() - i ; j++)
    {
        if (a[j]>a[j+1])
        {
            std::swap(a[j],a[j+1]);
        }
        
    }
    
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

    BubbleSort(arr);
  
for(int i : arr){
    std::cout<<i << " ";
}
    return 0;
}

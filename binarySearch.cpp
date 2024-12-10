#include<iostream>
#include<vector>


int BinarySearch(std::vector<int> Arr , int a){
   int center = Arr.size()/2;

    if (Arr[center]==a)
    {  
        std::cout<<"number is present at ";
        return 0;
    }
    else if (Arr[center]>a)
    {
        std::vector<int> split_lo(Arr.begin(), Arr.begin()+center);
        if (Arr[Arr.back()]>a)
        {
            std::cout<<"number is smaller then range";
            return 0;
        }
        
            BinarySearch(split_lo,a);

    }
    else if (Arr[center]<a)
    {
        std::vector<int> split_hi(Arr.begin()+center ,Arr.end());
        if (Arr[Arr.front()] < a)
        {
            std::cout<<"number is higer than range";
            return 0;
        }
        
        BinarySearch(split_hi,a);

    }
    return 0;
}

    
int main(){
std::vector<int> arr(100);
 for (int i = 0; i < 100; i++){
    arr[i] = i;}
int toFind;
std::cout<<"what yo want  to find";
std::cin>>toFind;
BinarySearch(arr,toFind);
return 0;
}


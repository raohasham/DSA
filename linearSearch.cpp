#include<iostream>
int LinearSearch(int Arr[100],int a){
   for(int i=0;i<100;i++){

        if (Arr[i]==a){std::cout<<"your number "<< a <<"is present";
            return 0;}
        
    }
    std::cout<<"Your number is not present in the list";
    return 0;
}
int main(){
int arr[100] = {};
 for (int i = 0; i < 100; i++) {arr[i] = i;}
int toFind;
std::cout<<"what yo want  to find";
std::cin>>toFind;
LinearSearch(arr,toFind);
return 0;
}

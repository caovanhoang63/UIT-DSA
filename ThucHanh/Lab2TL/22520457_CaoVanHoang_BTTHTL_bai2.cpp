#include <iostream>

int BinarySearch(int a[],int left,int right,int x){
    if(left > right)
        return -1;
    else
    {
        int mid  = left + (right -left)/2;
        if(a[mid] == x)
            return mid;
        if(a[mid]<x)
            return BinarySearch(a,mid+1,right,x);
        else 
            return BinarySearch(a,left,mid-1,x);
    }
}

void Sort(int a[],int n){
    for(int i = 0 ; i< n -1;i++)
        for(int j = i + 1; j < n;j++)
            if(a[i]>a[j])
                std::swap(a[i],a[j]);
}

int main(){
    int a[100];
    int n;
    std::cout<<"Nhap gia tri can tim ";
    std::cin>>n;
    for(int i = 0 ; i < n;i++){
        std::cin>>a[i];
    }
    Sort(a,n);
    int x; std::cin>>x;
    int index = BinarySearch(a,0,n-1,x);
    if(index!=-1)
        std::cout<<"Vi tri phan tu can tim: "<<index;
    else   
        std::cout<<"Phan tu khong ton tai trong mang!";
    return 0;
}
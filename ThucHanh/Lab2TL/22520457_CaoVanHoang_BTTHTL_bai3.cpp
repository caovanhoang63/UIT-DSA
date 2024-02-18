#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int a){
    if(a<2)
        return 0;
    for(int i =2 ; i*i <= a;i++ ){
        if(a%i==0)
            return 0;
    }
    return 1;
}

void printPrime(vector<int>a){
    for(auto x : a)
        if(isPrime(x))
            cout<<x<<" ";
}
int main(){
    int n;
    cout<<"Nhap so phan tu cua mang: ";
    cin>>n;
    vector<int>a(n);
    cout<<"Nhap gia tri cac phan tu trong mang";
    for(auto &x : a) cin>>x;
    cout<<"Cac so nguyen to trong mang la: ";
    printPrime(a);
    return 0;
}
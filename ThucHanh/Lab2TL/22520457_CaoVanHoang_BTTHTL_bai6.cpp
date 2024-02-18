#include <iostream>
#include <vector>
using namespace std;
bool ktTang(vector<int> a,int i , int j){
    for(;i<j;i++)
        if(a[i]>a[i+1])
            return 0;
    return 1;
}
int TatCaMangConTang(vector<int>a){
    int dem = 0;
    for(int i = 0 ; i < a.size();i++){
        for(int j = i ; j < a.size();j++){
            if(ktTang(a,i,j))
                dem++;
        }
    }
    return dem;
}
int main(){
    int n;
    cout<<"Nhap do dai day ban dau:";
    cin>>n;
    vector<int>a(n);
    cout<<"Nhap cac phan tu cho mang: "<<endl;
    for(auto &x : a) cin>>x;  
    cout<<"So mang con tang trong mang la: "<<TatCaMangConTang(a);
    return 0;
}
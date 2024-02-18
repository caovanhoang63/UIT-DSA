#include <iostream>
#include <vector>
using namespace std;
void MangCon(vector<int> a, vector<int> b){
    for(int i = 0 ; i < a.size();i++){
        if(a[i]==b[0] && a.size() - i > b.size() -1){
            bool flag = 1;
            int j= 0;
            for(;j<b.size();j++)
                if(a[j+i]!=b[j])
                    flag = 0;
            if(flag) {
                cout<<"Mang con nam trong doan ("<<i<<","<<j+i-1<<")"<<endl;
                return;
            }
        }
    }
    cout<<"Mang con b khong ton tai trong a"<<endl;
}

int main(){
    int n;
    cout<<"Nhap do dai day ban dau:";
    cin>>n;
    vector<int>a(n);
    cout<<"Nhap cac phan tu cho mang: "<<endl;
    for(auto &x : a) cin>>x;
    cout<<"Nhap do dai day con: ";
    cin>>n;
    vector<int>b(n);
    cout<<"Nhap cac phan tu cho mang con: "<<endl;
    for(int &x : b) cin>>x;
    MangCon(a,b);
    return 0;
}
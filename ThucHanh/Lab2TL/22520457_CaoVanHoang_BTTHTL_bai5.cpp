#include <iostream>
#include <vector>
using namespace std;

bool ktTang(vector<int> a){
    for(int i = 0 ; i<a.size()-1;i++)
        if(a[i]>=a[i+1])
            return 0;
    return 1;
}

vector<int> MangConTangDaiNhat(vector<int> a){
    vector<int>result(0);
    for(int i = 0 ; i < a.size()-1 ; i ++){
        vector<int> temp;
        temp.push_back(a[i]);
        for(int j = i + 1 ; j <a.size(); j++){
            temp.push_back(a[j]);
            if(ktTang(temp) && temp.size()>result.size())
            {  
                result.clear();
                result=temp;
            }
        }
    }
    return result;
}

int main(){
int n;
    cout<<"Nhap do dai day ban dau:";
    cin>>n;
    vector<int>a(n);
    cout<<"Nhap cac phan tu cho mang: "<<endl;
    for(auto &x : a) cin>>x;  
    vector<int> result = MangConTangDaiNhat(a);
    if(result.empty())
        cout<<"Khong co mang con tang nao nhieu hon 1 phan tu "<<endl;
    else{
        for(auto x : result) cout<<x<<" ";
    }
    return 0;
}
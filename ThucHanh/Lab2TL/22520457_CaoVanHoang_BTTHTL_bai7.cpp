#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct Point{
    float x,y;

};
float Distance(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int Find(vector<Point>a,Point x){
    float max = 0;
    int max_index = 0;
    for(int i = 0 ; i< a.size() ; i++){
         if(Distance(x,a[i])>max){
            max = Distance(x,a[i]) ;
            max_index = i;
         }
    }
    return max_index;
}

istream& operator>>(istream& is, Point a){
    cout<<"Nhap hoanh do: ";
    is>>a.x;
    cout<<"Nhap tung do: ";
    is>>a.y;
    return is;
}
int main(){
    cout<<"Nhap toa do diem p: "<<endl;
    Point x;
    cin>>x;
    int n;
    cout<<"Nhap so luong diem cua mang: ";
    cin>>n;
    vector<Point> a(n);
    for(int i = 0 ; i < n ; i++){
        cout<<"Nhap diem thu "<<i+1<<endl;
        cin>>a[i];
    }
    
    cout<<"chi so cua diem gan p nhat la: "<<Find(a,x);
    return 0;
}


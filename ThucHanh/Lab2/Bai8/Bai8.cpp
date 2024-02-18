#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <chrono>
using namespace std;
using chrono::duration;
using chrono::duration_cast;
using chrono::high_resolution_clock;
using chrono::milliseconds;

int Linear_Search(string filename, int x)
{
    int k, i = 0;
    ifstream fi(filename);
    while (!fi.eof())
    {
        i++;
        fi >> k;
        if (k == x)
            return i;
    }
    return -1;
}

int main()
{
    int n, temp, x;
    cout << "Nhap so phan tu : ";
    cin >> n;
    ofstream fo("data.dat");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        x = rand() % 10000;
        fo << setw(7) << x;
    }
    x = rand() % 10000;
    cout << "So can tim: " << x << endl;
    auto t1 = high_resolution_clock::now();
    int index = Linear_Search("data.dat", x);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> linear_use = t2 - t1;
    if (index == -1)
        cout << "So can tim khong ton tai!" << endl;
    else
        cout << "Vi tri cua so can tim la: " << index << endl;
    cout << "Thoi gian thuc hien tim kiem : " << linear_use.count() << "ms" << endl;
    return 0;
}
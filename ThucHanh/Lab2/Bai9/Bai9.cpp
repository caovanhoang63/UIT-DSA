#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <chrono>
using namespace std;
using chrono::duration;
using chrono::duration_cast;
using chrono::high_resolution_clock;
using chrono::milliseconds;

int Linear_Search(string filename, int x, int n)
{
    pair<int, int> *a = new pair<int, int>[n];
    ifstream fi(filename);
    for (int i = 0; i < n; i++)
    {
        fi >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n - 1);
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid].first == x)
        {
            return a[mid].second;
        }
        if (a[mid].first < x)
            l = mid + 1;
        else
            r = mid - 1;
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
    for (int i = 0; i < 10000; i++)
    {
        x = rand() % 10000;
        fo << setw(7) << x;
    }
    x = rand() % 10000;
    cout << "So can tim: " << x << endl;
    auto t1 = high_resolution_clock::now();
    int index = Linear_Search("data.dat", x, n);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> binary_use = t2 - t1;

    if (index == -1)
        cout << "So can tim khong ton tai!" << endl;
    else
        cout << "Vi tri cua so can tim la: " << index << endl;
    cout << "Thoi gian thuc hien tim kiem: " << binary_use.count() << "ms" << endl;
    return 0;
}
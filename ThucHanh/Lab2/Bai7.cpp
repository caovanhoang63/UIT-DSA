#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <chrono>
using namespace std;
using chrono::duration;
using chrono::duration_cast;
using chrono::high_resolution_clock;
using chrono::milliseconds;

void KoLinhCanh(int **a, int m, int n, int x)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] == x)
            {
                cout << "Vi tri cua phan tu can tim kiem: "
                     << "(" << i << " ," << j << ")" << endl;
                return;
            }
    }
    cout << "Phan tu khong ton tai trong ma tran!" << endl;
}
// Xem mang 2 chieu la mang 1 chieu va dat phan tu linh canh o cuoi vi tri cuoi mang 1 chieu do
void LinhCanh(int **a, int m, int n, int x)
{
    a[m][0] = x;
    int i = 0;
    // duyet mang 1 chieu bang 1 vong lap va them mot phan tu cuoi cung vao ma tran co gia tri bang x
    while (a[i / n][i % n] != x)
        i++;
    if (i / n == m && i % n == 0)
        cout << "Phan tu khong ton tai trong mang!" << endl;
    else
        cout << "Vi tri cua phan tu can tim kiem: "
             << "(" << i / n << " ," << i % n << ")" << endl;
}

int main()
{
    int m, n;
    cout << "Nhap so hang : ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    srand(time(NULL));
    int **a = new int *[m + 1];
    for (int i = 0; i < m; i++)
        *(a + i) = new int[n];
    *(a + m) = new int;
    // Phat sinh ngau nhien mang
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand();
        }
    int row = rand() % m;
    int col = rand() % n;
    int k = a[row][col];

    cout << "Phan tu can tim kiem : " << k << endl;
    auto t1 = high_resolution_clock::now();
    KoLinhCanh(a, m, n, k);
    auto t2 = high_resolution_clock::now();
    auto t3 = high_resolution_clock::now();
    LinhCanh(a, m, n, k);
    auto t4 = high_resolution_clock::now();
    duration<double, milli> linhcanh = t4 - t3, kolinhcanh = t2 - t1;
    cout << "Thoi gian thuc hien cua thuat toan khi su dung linh canh: " << linhcanh.count() << "ms\n";
    cout << "Thoi gian thuc hien cua thuat toan khong su dung linh canh: " << kolinhcanh.count() << "ms\n";
    for (int i = 0; i < m; i++)
        delete[] a[i];
    delete a;
    return 0;
}
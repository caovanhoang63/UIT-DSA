#include <iostream>
using namespace std;
int so_sanh = 0;
int so_sanh_cai_tien = 0;
// Cau a: cai dat giai thuat theo cach thong thuong
int Linear_Search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        so_sanh += 2;
        if (a[i] == x)
            return i;
    }
    return -1;
}
// Cau b: cai dat giai thuat cai tien voi mang da duoc sap xep
int LinearSearch_Improve(int a[], int n, int x)
{
    a[n] = x;
    int i = 0;
    while (a[i] < x)
    {
        so_sanh_cai_tien++;
        i++;
    }
    if (i < n && a[i] == x)
    {
        so_sanh_cai_tien++;
        return i;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Nhap so phan tu cho mang: ";
    cin >> n;
    int *a = new int[n + 1];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cout << "Phan phan tu can tim kiem: ";
    cin >> x;
    Linear_Search(a, n, x);
    cout << "So phep so sanh ham cai dat thong thuong thuc hien: " << so_sanh << endl;
    LinearSearch_Improve(a, n, x);
    cout << "So phep so sanh ham cai dat cai tien thuc hien: " << so_sanh_cai_tien << endl;
    delete[] a;
    return 0;
}
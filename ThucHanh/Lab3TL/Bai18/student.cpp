#include <iostream>
#include <string>
#pragma once

using namespace std;

class Student
{
private:
    int MSSV;
    string Ho_va_ten;
    string Gioi_tinh;
    string Ten;
    string Lop;
    string HanhKiem;
    float Diem_trung_binh;

public:
    Student()
    {
    }
    Student(int MSSV, string Ho_va_ten, string Gioi_tinh, string Lop, string HanhKiem, float DiemTrungBinh)
    {
        this->MSSV = MSSV;
        this->Ho_va_ten = Ho_va_ten;
        this->Gioi_tinh = Gioi_tinh;
        this->HanhKiem = HanhKiem;
        this->Lop = Lop;
        this->Diem_trung_binh = DiemTrungBinh;
    }
    string get_Lop()
    {
        return Lop;
    }
    string get_HanhKiem()
    {
        return HanhKiem;
    }
    void set_HanhKiem(string hanhkiem)
    {
        this->HanhKiem = hanhkiem;
    }
    void set_Lop(string lop)
    {
        this->Lop = lop;
    }
    string get_Ten()
    {
        return Ten;
    }
    float get_Diem_trung_binh()
    {
        return Diem_trung_binh;
    }
    int get_MSSV()
    {
        return MSSV;
    }
    string get_Ho_va_ten()
    {
        return Ho_va_ten;
    }
    string get_Gioi_tinh()
    {
        return Gioi_tinh;
    }
    void set_MSSV(int MSSV)
    {
        this->MSSV = MSSV;
    }
    void set_Ho_va_ten(string Ho_va_ten)
    {
        this->Ho_va_ten = Ho_va_ten;
    }
    void set_Gioi_tinh(string Gioi_tinh)
    {
        this->Gioi_tinh = Gioi_tinh;
    }
    void Nhap()
    {
        cout << "Nhap MSSV: ";
        cin >> MSSV;
        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, Ho_va_ten);
        cout << "Nhap gioi tinh: ";
        getline(cin, Gioi_tinh);
        cout << "Nhap hanh kiem: ";
        cin >> HanhKiem;
        cout << "Hanh Lop: ";
        cin >> Lop;
        cout << "Nhap diem trung binh: ";
        cin >> Diem_trung_binh;
    }
};

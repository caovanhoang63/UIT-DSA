#include "Student.cpp"
#include <iomanip>

struct Node_Student
{
    Student student_data;
    Node_Student *next_student;
};

struct List_Student
{
    Node_Student *pHead;
    Node_Student *pTail;
};

void init(List_Student &list)
{
    list.pHead = list.pTail = NULL;
}

bool isEmpty(List_Student list)
{
    if (list.pHead == NULL)
        return 1;
    return 0;
}

Node_Student *GetNewNode(Student student)
{
    Node_Student *node = new Node_Student;
    if (node == NULL)
        return NULL;
    node->student_data = student;
    node->next_student = NULL;
    return node;
}
void add_Head(List_Student &list, Node_Student *node);
void Print_List(List_Student list)
{
    if (isEmpty(list))
        cout << "Khong ton tai danh sach sinh vien!\n";
    else
    {
        Node_Student *node = list.pHead;
        cout << "Danh sach cua lop IT003.N27" << endl;
        cout << "+-----------------------------------------------------------------------------------------+\n";
        cout << "| STT |   MSSV   |     Ho va Ten     | Gioi tinh |    Lop    | Hanh Kiem| Diem trung binh |\n";
        cout << "+-----------------------------------------------------------------------------------------+\n";
        int count = 1;
        while (node != NULL)
        {
            cout << "|"
                 << setw(3) << count << "  |"
                 << setw(9) << node->student_data.get_MSSV() << " |"
                 << setw(16) << node->student_data.get_Ho_va_ten() << "   "
                 << "|"
                 << setw(7) << node->student_data.get_Gioi_tinh() << "    "
                 << "|"
                 << setw(7) << node->student_data.get_Lop() << "    |"
                 << setw(6) << node->student_data.get_HanhKiem() << "    |"
                 << setw(10) << node->student_data.get_Diem_trung_binh() << "       |"
                 << endl;
            cout << "+-----------------------------------------------------------------------------------------+\n";
            count++;
            node = node->next_student;
        }
    }
}

void Delete_Node(List_Student &list, int mssv)
{
    if (mssv == list.pHead->student_data.get_MSSV())
    {
        Node_Student *temp = list.pHead;
        list.pHead = temp->next_student;
        delete temp;
    }
    else
    {
        Node_Student *node = list.pHead;
        while (node->next_student->student_data.get_MSSV() != mssv)
            node = node->next_student;
        Node_Student *temp = node->next_student;
        node->next_student = temp->next_student;
        delete temp;
    }
}

void add_Tail(List_Student &list, Node_Student *node)
{
    if (list.pHead == NULL)
        list.pHead = list.pTail = node;
    else
    {
        list.pTail->next_student = node;
        list.pTail = node;
    }
}

void Sort_MSSV(List_Student &list)
{
    if (list.pHead == list.pTail)
        return;
    List_Student list1, list2;
    init(list1);
    init(list2);
    Node_Student *tag;
    Node_Student *node;
    tag = list.pHead;
    list.pHead = list.pHead->next_student;
    tag->next_student = NULL;
    while (list.pHead != NULL)
    {
        node = list.pHead;
        list.pHead = list.pHead->next_student;
        node->next_student = NULL;
        if (node->student_data.get_MSSV() <= tag->student_data.get_MSSV())
            add_Head(list1, node);
        else
            add_Head(list2, node);
    }
    Sort_MSSV(list1);
    Sort_MSSV(list2);
    if (!isEmpty(list1))
    {
        list.pHead = list1.pHead;
        list1.pTail->next_student = tag;
    }
    else
        list.pHead = tag;
    if (!isEmpty(list2))
    {
        tag->next_student = list2.pHead;
        list.pTail = list2.pTail;
    }
    else
        list.pTail = tag;
}

void Sort_DTB(List_Student &list)
{
    if (list.pHead == list.pTail)
        return;
    List_Student list1, list2;
    init(list1);
    init(list2);
    Node_Student *tag;
    Node_Student *node;
    tag = list.pHead;
    list.pHead = list.pHead->next_student;
    tag->next_student = NULL;
    while (list.pHead != NULL)
    {
        node = list.pHead;
        list.pHead = list.pHead->next_student;
        node->next_student = NULL;
        if (node->student_data.get_Diem_trung_binh() <= tag->student_data.get_Diem_trung_binh())
            add_Head(list1, node);
        else
            add_Head(list2, node);
    }
    Sort_MSSV(list1);
    Sort_MSSV(list2);
    if (!isEmpty(list1))
    {
        list.pHead = list1.pHead;
        list1.pTail->next_student = tag;
    }
    else
        list.pHead = tag;
    if (!isEmpty(list2))
    {
        tag->next_student = list2.pHead;
        list.pTail = list2.pTail;
    }
    else
        list.pTail = tag;
}

void add_Head(List_Student &list, Node_Student *node)
{
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = node;
    }
    else
    {
        node->next_student = list.pHead;
        list.pHead = node;
    }
}

void Chen(List_Student &list, Student clone, int tt)
{
    if (tt == 1)
    {
        add_Head(list, GetNewNode(clone));
        return;
    }
    Node_Student *node = list.pHead;
    Node_Student *new_node = GetNewNode(clone);
    for (int i = 0; i < tt - 2; i++)
        node = node->next_student;
    new_node->next_student = node->next_student;
    node->next_student = new_node;
}

bool KtRong(List_Student &list)
{
    if (list.pHead == NULL)
        return 1;
    return 0;
}
int main()
{
    List_Student list;
    init(list);

    int lc;
    Student clone;
    do
    {
        cout << "____Menu____\n";
        cout << "1.Them \n";
        cout << "2.Xoa \n";
        cout << "3.Chen \n";
        cout << "4.Sap xep\n";
        cout << "_Nhan 0 de ket thuc_\n";
        cout << "Danh sach sinh vien:\n";
        Print_List(list);
        cin >> lc;
        switch (lc)
        {
        case 0:
            break;
        case 1:
        {
            cout << "_Them sinh vien_\n";
            int soluong;
            cout << "Nhap so luong sinh vien: ";
            cin >> soluong;
            for (int i = 0; i < soluong; i++)
            {
                cout << "Nhap sinh vien thu " << i + 1 << ": " << endl;
                clone.Nhap();
                add_Tail(list, GetNewNode(clone));
            }
            system("pause");
            system("cls");
            break;
        }
        case 2:
            cout << "_Xoa sinh vien_";
            cout << "Nhap MSSV can xoa: ";
            int mssv;
            cin >> mssv;
            Delete_Node(list, mssv);
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "_Chen vao danh sach_";
            cout << "\nNhap vi tri can chen: ";
            int tt;
            cin >> tt;
            clone.Nhap();
            Chen(list, clone, tt);
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "_Nhap chuc nang sap xep_\n";
            cout << "1. Sap xep theo MSSV\n";
            cout << "2. Sap xep theo ten\n";
            cout << "3. Sap xep theo diem trung binh \n";
            int stt;
            cin >> stt;
            switch (stt)
            {
            case 1:
                Sort_MSSV(list);
                system("pause");
                system("cls");
                break;
            case 2:
                system("pause");
                system("cls");
                break;
            case 3:
                Sort_DTB(list);
                system("pause");
                system("cls");
                break;
            default:
                cout << "Chuc nang khong ton tai." << endl;
            }
            break;
        default:
            cout << "Chuc nang khong ton tai. " << endl;
            cout << "Vui long nhap lai!" << endl;
            system("pause");
            system("cls");
        }
    } while (lc != 0);
    return 0;
}
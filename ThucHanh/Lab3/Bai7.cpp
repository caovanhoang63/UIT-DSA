#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void Init(List &l)
{
    l.pHead = l.pTail = NULL;
}
bool isEmpty(List l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}
Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void printList(List &l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}
void addHead(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
        return;
    }
    p->pNext = l.pHead;
    l.pHead = p;
}
void addTail(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
void Enter(List &l)
{
    int n, x;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node *p = createNode(x);
        if (p != NULL)
            addTail(l, p);
    }
}

void Tron(List &l1, List &l2, List &l3)
{
    while (!(l1.pHead == NULL && l2.pHead == NULL))
    {
        if (l2.pHead == NULL || (l1.pHead != NULL && l1.pHead->info < l2.pHead->info))
        {
            addTail(l3, l1.pHead);
            l1.pHead = l1.pHead->pNext;
        }
        else
        {
            addTail(l3, l2.pHead);
            l2.pHead = l2.pHead->pNext;
        }
    }
    l3.pTail->pNext = NULL;
}
void clearList(List &l)
{
    Node *p = l.pHead;
    while (p != nullptr)
    {
        l.pHead = p->pNext;
        delete p;
        p = l.pHead;
    }
}
int main()
{
    List l1, l2, l3;
    Init(l1);
    Init(l2);
    Init(l3);
    cout << "Nhap danh sach thu nhat: " << endl;
    Enter(l1);
    cout << "Nhap danh sach thu hai: " << endl;
    Enter(l2);
    Tron(l1, l2, l3);
    cout << "Danh sach sau khi tron: ";
    printList(l3);
    clearList(l3);
    return 0;
}
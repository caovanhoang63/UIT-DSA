#include <iostream>
using namespace std;

struct DonThuc
{
    float hang_tu;
    int mu;
};
void Enter(DonThuc &a)
{
    cout << "Nhap hang tu: ";
    cin >> a.hang_tu;
    cout << "Nhap so mu: ";
    cin >> a.mu;
}
void Print(DonThuc a)
{
    cout << a.hang_tu << "x^" << a.mu;
}
struct Node
{
    DonThuc info;
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
Node *createNode(DonThuc x)
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
        if (p->info.hang_tu >= 0)
            cout << "+";
        Print(p->info);
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
void Enter(List &l)
{
    int n;
    DonThuc a;
    cout << "Nhap so don thuc: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap don thuc thu " << i + 1 << ": " << endl;
        Enter(a);
        Node *p = createNode(a);
        if (p != NULL)
            addHead(l, p);
    }
}
void Noi(List &l1, List &l2, List &l3)
{
    l3.pHead = l1.pHead;
    l1.pTail->pNext = l2.pHead;
    l3.pTail = l2.pTail;
}
int main()
{
    List l1, l2, l3;
    Init(l1);
    Init(l2);
    Init(l3);
    cout << "Nhap da thuc thu nhat: " << endl;
    Enter(l1);
    cout << "Nhap da thuc thu hai: " << endl;
    Enter(l2);
    Noi(l1, l2, l3);
    cout << "Hai don thuc sau khi cong: " << endl;
    printList(l3);
    return 0;
}
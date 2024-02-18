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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node *p = createNode(x);
        if (p != NULL)
            addTail(l, p);
    }
}
void Tach(List &l, List &chan, List &le)
{
    while (l.pHead != NULL)
    {
        if (l.pHead->info % 2 == 0)
            addTail(chan, l.pHead);
        else
            addTail(le, l.pHead);
        l.pHead = l.pHead->pNext;
    }
    if (chan.pHead != NULL)
        chan.pTail->pNext = NULL;
    if (le.pHead != NULL)
        le.pTail->pNext = NULL;
}
int main()
{
    List l, chan, le;
    Init(l);
    Init(chan);
    Init(le);
    Enter(l);
    cout << "Danh sach ban dau: ";
    printList(l);
    Tach(l, chan, le);
    cout << "Danh sach cac so chan: ";
    printList(chan);
    cout << "Danh sach cac so le: ";
    printList(le);
    return 0;
}
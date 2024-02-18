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

void quick_sort(List &l)
{
    if (l.pHead == l.pTail)
        return;
    Node *tag = l.pHead;
    l.pHead = l.pHead->pNext;
    tag->pNext = NULL;
    List left, right;
    Init(left);
    Init(right);
    Node *temp;
    while (l.pHead != NULL)
    {
        temp = l.pHead;
        l.pHead = l.pHead->pNext;
        temp->pNext = NULL;
        if (temp->info <= tag->info)
            addHead(left, temp);
        else
            addHead(right, temp);
    }
    quick_sort(left);
    quick_sort(right);
    if (!isEmpty(left))
    {
        l.pHead = left.pHead;
        left.pTail->pNext = tag;
    }
    else
        l.pHead = tag;
    if (!isEmpty(right))
    {
        tag->pNext = right.pHead;
        l.pTail = right.pTail;
    }
    else
        l.pTail = tag;
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
            addHead(l, p);
    }
}
int main()
{
    List l;
    Init(l);
    Enter(l);
    quick_sort(l);
    printList(l);
    return 0;
}
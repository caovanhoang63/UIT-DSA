#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->next = NULL;
    return p;
}
void printList(Node *list)
{
    Node *p = list;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}
void addTail(Node *&list, Node *p)
{
    if (list == NULL)
    {
        list = p;
        return;
    }
    Node *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
}
void Enter(Node *&list)
{
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node *p = createNode(x);
        if (p != NULL)
            addTail(list, p);
    }
}
void Shuffle(Node *&list)
{
    Node *temp = NULL;
    Node *p = list;
    while (p != NULL)
    {
        Node *node = p->next;
        p->next = p->next->next;
        node->next = NULL;
        addTail(temp, node);
        p = p->next;
    }
    p = list;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
}
int main()
{
    Node *l = NULL;
    Enter(l);
    Shuffle(l);
    printList(l);
    return 0;
}
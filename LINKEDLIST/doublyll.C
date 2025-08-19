#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next, Node *prev)
    {
        data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class Node *head = NULL;
void vectoll(vector<int> &arr)
{
    head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }
}
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void deleteatbeg()
{
    Node *temp = head;
    head = head->next;
    head->prev->next = nullptr;
    // important
    head->prev = NULL;
    free(temp);
    return;
}
void deleteatlast()
{ // 1 2 3 4
    Node *temp = head;
    Node *secondlast = NULL;
    if (head == NULL)
    {
        cout << "----list is emmpty!----" << endl;
        return;
    }
    while (temp->next != NULL)
    {
        secondlast = temp;
        temp = temp->next;
    }
    temp->prev = NULL;
    secondlast->next = NULL;
    return;
}
void deleteatpos(int k)
{ // k = 1 to n
    // first traverse to kth node
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *back = temp->prev;
    Node *front = temp->next;
    // only one node present
    if (back == NULL && front == NULL)
        free(temp);
    // deleting head
    else if (back == NULL)
    {
        deleteatbeg();
        return;
    }
    // deleting last
    else if (front == NULL)
    {
        deleteatlast();
        return;
    }
    // deleting between first and last node
    back->next = front;
    front->prev = back;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}
void deletenode(Node *node)
{ // cant pass head
    // if deleting last node
    if (node->next == NULL)
    {
        node->prev->next = NULL;
        node->next = NULL;
        node->prev = NULL;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = node->prev = NULL;
    free(node);
    return;
}
void insertatbeg()
{
    // cout<<"value is inserted !" ;
    // inserted before head
    int value = 199;
    Node *newnode = new Node(value);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insertatlast()
{
    // Node x = Node(666);
    // Node* y = &x ;
    Node *y = new Node(666);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = y;
    y->prev = temp;
}
void insertatpos(int k)
{
    Node *y = new Node(5050);
    if (k == 1)
    {
        y->next = head;
        head = y;
    }
    Node *temp = head;
    for (int i = 1; i < k - 1; i++)
    {
        temp = temp->next;
    }
    y->next = temp->next;
    temp->next = y;
}
void reverse()
{
    Node *curr = head;
    Node *front = curr->next;
    while (curr != NULL)
    {
        if (curr == head)
        {
            curr->next = NULL;
            curr->prev = front;
            curr = front;
            front = front->next;
        }
        else if (front == NULL)
        {
            curr->next = curr->prev;
            curr->prev = NULL;
            head = curr;
            return;
        }
        curr->next = curr->prev;
        curr->prev = front;
        curr = front;
        front = front->next;
    }
}
int main()
{
    // vector<int> vec = {34, 54, 65, 7, 87 ,9,36,10};
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "-----ll after vector  to ll ------" << endl;
    vectoll(vec);
    display();
    // deleteatbeg();
    // cout << "-----ll after deleting head ------" <<endl ;
    // display();
    // deleteatlast();
    // cout << "-----ll after deleting last ------" <<endl ;
    // display();
    // deleteatpos(8);
    // cout << "-----ll after vector  to ll ------" << endl;
    // display();
    // deletenode(head->next->next);
    // cout << "-----ll after vector  to ll ------" << endl;
    // display();
    // insertatbeg();
    // cout << "-----ll after insertion at beg ------" <<endl ;
    // display() ;
    // insertatlast();
    // cout << "-----ll after insertion at last ------" <<endl ;
    // display() ;
    // insertatpos(4);
    // cout << "-----ll after insertion at k ------" <<endl ;
    // display() ;
    // reverse();
    // cout << "-----ll after reversal ------" << endl;
    // display();
    return 0;
}

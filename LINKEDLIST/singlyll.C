#include<bits/stdc++.h>
using namespace std ;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
class Node* head = NULL ;
void vectoll(vector<int>& arr)
{
    head = new Node(arr[0]) ;
    Node* mover = head ;
    for(int i = 1 ; i<arr.size() ; i++)
    {
        Node* temp= new Node(arr[i]) ;
        mover->next =temp ;
        mover = temp ;
    }
}
void display()
{   
    Node* temp = head ;
    while(temp!= NULL)
    {
        cout<<temp->data<< endl <<endl;
        temp = temp->next ;
    }
}
void deleteatbeg()
{
    Node* temp = head; 
    head=head->next;
    free(temp) ;
}
void deleteatlast()
{
    Node* temp = head ;
    Node* tofree=NULL ;
    if(head==NULL || head->next==NULL) cout <<"ll is empty!" << endl;
    while(temp->next->next!=NULL)
    {
        temp =temp->next ;
        tofree = temp->next ;
        
    }
    // free(temp->next) ;
    // free(tofree) ;
    delete temp->next ;
    temp->next =NULL ;
}
void deleteatpos(int k)
{
    if(k==1) head = head->next ;
    Node* temp = head ;
    for(int i =1 ; i < k - 1 ; i++)
    {
        temp = temp->next ;
    }
    // Node* tofree = temp->next ;
    // delete tofree ;
    temp ->next = temp->next->next ;
}
void insertatbeg()
{   
    //cout<<"value is inserted !" ;
    int value;
    value = 199 ;
    Node* temp=new Node(value); 
    temp->next = head ;
    head=temp;
}
void insertatlast()
{
    // Node x = Node(666);
    // Node* y = &x ;
    Node* y = new Node(666);
    Node* temp = head ;
    while(temp->next != NULL)
    {
        temp = temp->next ;
    }
    temp->next = y;
}
void insertatpos(int k)
{   
    Node* y = new Node(5050) ;
    if(k==1) 
    {
        y->next = head ;
        head = y ;
    }
    Node* temp = head ;
    for(int i =1 ; i < k - 1 ; i++)
    {
        temp = temp->next ;
    }
    y->next = temp->next;
    temp->next = y ;
}
void reverse()
{   
    Node* back = head ;
    Node* curr = head->next ;
    Node* front= curr->next ;
    while(curr!= NULL)
    {
        if(back==head) back->next =NULL ;
        curr->next =back ;
        back = curr ;
        curr = front ;
        if(front != NULL ) front = front -> next ; 
    }
    head = back ;
    // 1 2 3 4 5
}
int main()
{
    // vector<int> vec = {34, 54, 65, 7, 87 ,9,36,10};
    vector<int> vec = {1,2,3,4,5};
    vectoll(vec);
    display(); 
    // deleteatbeg();
    // cout << "-----ll after deleting head ------" <<endl ;
    // display();
    // deleteatlast();
    // cout << "-----ll after deleting last ------" <<endl ;
    // display();
    // vectoll(vec);
    // cout << "-----ll after vector  to ll ------" <<endl ;
    // display(); 
    // deleteatpos(4);
    // cout << "-----ll after vector  to ll ------" <<endl ;
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
    reverse();
    cout << "-----ll after reversal ------" << endl;
    display();
    return 0;
}




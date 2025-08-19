// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std ;

// class Node
// {
//     public:
//     int data;
//     Node *next;

//     Node(int data1)
//     {
//         data = data1;
//         next = nullptr;
//     }
// };

// class Node* head = NULL ;

// void vectoll(vector<int>& arr)
// {
//     head = new Node(arr[0]) ;
//     Node* mover = head ;
//     for(int i = 1 ; i<arr.size() ; i++)
//     {
//         Node* temp= new Node(arr[i]) ;
//         mover->next =temp ;
//         mover = temp ;
//     }
// }  
// void display(Node* head)
// {   
//     Node* temp = head ;
//     cout<< endl <<"------linked list -------" <<endl;
//     while(temp!= NULL)
//     {   
//         cout<<temp->data<< "  " ;
//         temp = temp->next ;
//     }
// }
// int main()
// {
//     // vector<int> vec = {34, 54, 65, 7, 87 ,9,36,10};
//     vector<int> vec = {1, 2, 3, 4, 5};
//     vectoll(vec) ;
//     cout << endl <<"---ll is created ---" << endl;
//     display(head);
//     return 0;
// }

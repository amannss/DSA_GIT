// this file contains basics of linked list
// L-1 CREATION

// CONSTRUCTOR AND OBJECT
// struct Node
// {
//     public:
//     int data;
//     Node *next;
//
//     Node(int data1, Node *next1)
//     {
//         data = data1;
//         next = next1;
//     }
// };
// int main()
// {
//     vector<int> vec = {34, 54, 65, 7, 87};
//
//     // Node *y = new Node(vec[2], nullptr);
//     // cout << y;
//     // 0x1167f00
//
//     // Node *y = new Node(vec[2], nullptr);
//     // cout << y.data;// it is wrong
//     // cout << y->data ;// this is right
//     // 0x1167f00
//
//     // Node x = Node(vec[2], nullptr);
//     // cout << x.data << endl;
//     // cout << x.next << endl;
//     // 65
//     // 0x0
//
//     // Node x(vec[2] , nullptr);
//     // cout << x.data << endl;
//     // cout << x.next << endl;
//     // // 65
//     // // 0x0
//     return 0;
// }

// VECTOR TO LINKEDLIST
// #include<bits/stdc++.h>
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
// void display(Node* head )
// {   Node* temp = head ;
//     while(temp->next != NULL)
//     {
//         cout<<temp->data<< endl ;
//         temp = temp->next ;
//     }
// }
// class Node* vectoll(vector<int>& arr)
// {
//     Node* head = new Node(arr[0]) ;
//     Node* mover = head ;
//     for(int i = 1 ; i<arr.size() ; i++)
//     {
//         Node* temp= new Node(arr[i]) ;
//         mover->next =temp ;
//         mover = temp ;
//     }
//     return head ;
// }
// int main()
// {
//     vector<int> vec = {34, 54, 65, 7, 87};
//     Node* head = vectoll(vec) ;
//     display(head); 
//     return 0;
// }

// L-2 DELETION AND INSERTION

// DELETE HEAD
// void deleteatbeg()
// {
//     Node* temp = head; 
//     head=head->next;
//     free(temp) ;
// }

// DELETE LAST
// {
//     Node* temp = head ;
//     while(temp->next->next!=NULL)
//     {
//         temp =temp->next ;
//     }
//     temp->next =NULL ;
// }

// DELETE AT K
// void deleteatpos(int k)
// {
//     if(k==1) head = head->next ;
//     Node* temp = head ;
//     for(int i =1 ; i < k - 1 ; i++)
//     {
//         temp = temp->next ;
//     }
//     // Node* tofree = temp->next ;
//     // delete tofree ;
//     temp ->next = temp->next->next ;
// }

// INSERT HEAD
// void insertatbeg()
// {   
//     //cout<<"value is inserted !" ;
//     int value;
//     value = 199 ;
//     Node* temp=new Node(value); 
//     temp->next = head ;
//     head=temp;
// }

// INSERT LAST
// void insertatlast()
// {
//     // Node x = Node(666);
//     // Node* y = &x ;
//     Node* y = new Node(666);
//     Node* temp = head ;
//     while(temp->next != NULL)
//     {
//         temp = temp->next ;
//     }
//     temp->next = y;
// }

// INSERT AT K
// void insertatpos(int k)
// {   
//     Node* y = new Node(5050) ;
//     if(k==1) 
//     {
//         y->next = head ;
//         head = y ;
//     }
//     Node* temp = head ;
//     for(int i =1 ; i < k - 1 ; i++)
//     {
//         temp = temp->next ;
//     }
//     y->next = temp->next;
//     temp->next = y ;
// }

// L-3 DOUBLY LINKED LIST

// BASIC
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int data1, Node *next, Node *prev)
//     {
//         data = data1;
//         this->next = nullptr;
//         this->prev = nullptr;
//     }
//     Node(int data)
//     {
//         this->data = data;
//         this->next = nullptr;
//         this->prev = nullptr;
//     }
// };
// class Node *head = NULL;

// VECTOR TO LL
// void vectoll(vector<int> &arr)
// {
//     head = new Node(arr[0]);
//     Node *mover = head;
//     for (int i = 1; i < arr.size(); i++)
//     {
//         Node *temp = new Node(arr[i]);
//         temp->prev = mover;
//         mover->next = temp;
//         mover = temp;
//     }
// }

//  DISPLAY 
// void display()
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << endl;
//         temp = temp->next;
//     }
// }

// DELETE HEAD
// void deleteatbeg()
// {
//     Node *temp = head;
//     head = head->next;
//     head->prev->next = nullptr;
//     // important
//     head->prev = NULL;
//     free(temp);
//     return;
// }

// DELETELAST
// void deleteatlast()
// { // 1 2 3 4
//     Node *temp = head;
//     Node *secondlast = NULL;
//     if (head == NULL)
//     {
//         cout << "----list is emmpty!----" << endl;
//         return;
//     }
//     while (temp->next != NULL)
//     {
//         secondlast = temp;
//         temp = temp->next;
//     }
//     temp->prev = NULL;
//     secondlast->next = NULL;
//     return;
// }

// DELETE AT K
// void deleteatpos(int k)
// { // k = 1 to n
//     // first traverse to kth node
//     int cnt = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cnt++;
//         if (cnt == k)
//             break;
//         temp = temp->next;
//     }
//     Node *back = temp->prev;
//     Node *front = temp->next;
//     // only one node present
//     if (back == NULL && front == NULL)
//         free(temp);
//     // deleting head
//     else if (back == NULL)
//     {
//         deleteatbeg();
//         return;
//     }
//     // deleting last
//     else if (front == NULL)
//     {
//         deleteatlast();
//         return;
//     }
//     // deleting between first and last node
//     back->next = front;
//     front->prev = back;
//     temp->next = NULL;
//     temp->prev = NULL;
//     delete temp;
// }

// DELETE NODE
// void deletenode(Node *node)
// { // cant pass head
//     // if deleting last node
//     if (node->next == NULL)
//     {
//         node->prev->next = NULL;
//         node->next = NULL;
//         node->prev = NULL;
//     }
//     node->prev->next = node->next;
//     node->next->prev = node->prev;
//     node->next = node->prev = NULL;
//     free(node);
//     return;
// }

// INSERT AT BEG
// void insertatbeg()
// {
//     // cout<<"value is inserted !" ;
//     // inserted before head
//     int value = 199;
//     Node *newnode = new Node(value);
//     newnode->next = head;
//     head->prev = newnode;
//     head = newnode;
// }

// INSERT AT LAST
// void insertatlast()
// {
//     // Node x = Node(666);
//     // Node* y = &x ;
//     Node *y = new Node(666);
//     Node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = y;
//     y->prev = temp;
// }

// INSERT AT K
// void insertatpos(int k)
// {
//     Node *y = new Node(5050);
//     if (k == 1)
//     {
//         y->next = head;
//         head = y;
//     }
//     Node *temp = head;
//     for (int i = 1; i < k - 1; i++)
//     {
//         temp = temp->next;
//     }
//     y->next = temp->next;
//     temp->next = y;
// }

// L-4 REVERSE DOUBLY LL

// REVERSE THE LL
// void reverse()
// {
//     Node *curr = head;
//     Node *front = curr->next;
//     while (curr != NULL)
//     {
//         if (curr == head)
//         {
//             curr->next = NULL;
//             curr->prev = front;
//             curr = front;
//             front = front->next;
//         }
//         else if (front == NULL)
//         {
//             curr->next = curr->prev;
//             curr->prev = NULL;
//             head = curr;
//             return;
//         }
//         curr->next = curr->prev;
//         curr->prev = front;
//         curr = front;
//         front = front->next;
//     }
// }

// L-5 ADD 2 NUMBERS

//  ADD 2 NUMBERS
// Node* add(Node* head1 , Node* head2 )
// {   // LC - add two numbers
//     Node* temp1 =head1 ; Node* temp2 =head2 ;Node* mover  ;
//     int carry = 0 ;int sum = 0 ;int rem = 0 ;
//     while(temp1!= NULL || temp2!= NULL)
//     {   
//         if(temp1 == NULL) sum =  temp2->data+carry ;
//         else if(temp2 ==NULL) sum = temp1->data +carry ;
//         else sum = temp1->data + temp2->data+carry ;
//         rem = sum%10 ; carry = sum/10 ;
//         Node* newnode = new Node(rem ) ;
//         if(head == NULL)  { head = newnode ; mover = head ; } 
//         // if(mover == head1) continue ;
//         mover ->next = newnode ;
//         mover = newnode;
//         if(temp1!=NULL ) temp1 = temp1->next ; 
//         if(temp2!=NULL ) temp2 = temp2->next ;
//     }
//     if( carry > 0 )
//     {   
//             Node* newnode = new Node(carry ) ;
//             mover ->next = newnode ;
//             mover = newnode;
//     }
//     return head ;
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
//     vector<int> vec1 = {2,4,6};
//     vector<int> vec2 = {3,8,7,1};
//     head1 = vectoll(vec1,head1);
//     head2 = vectoll(vec2,head2);
//     display(head1); 
//     display(head2); 
//     head = add(head1,head2);
//     cout << endl <<"after adding!" ;
//     display(head) ;
//     return 0;
// }

// L-6 ODD EVEN LINKED LIST

// LC-2
// LC - 329
// ListNode* oddEvenList(ListNode* head) {
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     ListNode* odd=head;
//     ListNode* even=head->next;
//     ListNode* evenhead=head->next;
//     while(even!=NULL && even->next!=NULL){
//         odd->next=odd->next->next;
//         even->next=even->next->next;
//         odd=odd->next;
//         even=even->next;
//     }
//      odd->next=evenhead;
//     return head;
// }

// L-7 SORT LL OF 0,1,2

// L-8 REMOVE NTH NODE FROM END

// LC-19
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode* temp = head ; int cnt = 0 ; int rem  ;
//     if(head == NULL || head->next == NULL) return NULL;
//     while(temp != NULL)
//     {   cnt++ ;
//         temp= temp->next ;    
//     }
//     temp = head ;
//     ListNode* mover = head ;
//     rem = cnt - n ; 
//     if(cnt == n )
//     {
//         head = head->next ; return head ;
//     }
//     while(rem)
//     {
//         temp =mover ;
//         if(mover) mover = mover ->next ;
//         rem--;
//     }
//     temp->next = mover->next ;
//     return head ;
// }

// L-9 REVERSE A LINKED LIST

// LC-209
// two pointe approach
// ListNode* reverseList(ListNode* head) {
//     if(head == NULL) return NULL ;
//     if(head->next == NULL) return head ;
//     ListNode* back = head ;
//     ListNode* curr = head->next ;
//     ListNode* front= curr->next ;
//     while(curr!= NULL)
//     {
//         if(back==head) back->next =NULL ;
//         curr->next =back ;
//         back = curr ;
//         curr = front ;
//         if(front != NULL ) front = front -> next ; 
//     }
//     head = back ;
//     return head ;
//     }
// reccursive approach

// L-10 CHECK IF PALINDROME OR NOT

// LC-234
// ListNode* reverseList(ListNode* head) {
// if(head == NULL) return NULL ;
// if(head->next == NULL) return head ;
// ListNode* back = head ;
// ListNode* curr = head->next ;
// ListNode* front= curr->next ;
// while(curr!= NULL)
// {
//     if(back==head) back->next =NULL ;
//     curr->next =back ;
//     back = curr ;
//     curr = front ;
// if(front != NULL ) front = front -> next ; 
// }
// head = back ;
// return head ;
// }
// bool isPalindrome(ListNode* head) {
//     ListNode* slow = head ;
//     ListNode* fast = head ;
//     while(fast->next!= NULL && fast->next->next !=NULL)
//     {
//         slow = slow ->next ;
//         fast = fast->next->next ;
//     }
//     ListNode* newhead = reverseList(slow->next) ;
//     ListNode* l = head ;
//     ListNode* r = newhead ;
//     while(r!= NULL)
//     {
//         if(l->val != r->val) 
//         {
//             reverseList(newhead);
//             return false ;
//         }
//         l=l->next ;
//         r=r->next ;
//     }
//     reverseList(newhead);
//     return true ;
// }

// L-11 ADD 1 NUMBER TO LL

// LC-0
// RECCURSION AND BACKTRACKING
// int helper(Node* temp)
//     {
//         if(temp== NULL) return 1 ;
//         int carry = helper(temp->next) ;
//         temp->data = temp->data + carry ;
//         if(temp->data < 10)
//         {
//             return 0 ;
//         }
//         temp->data = 0 ;
//         return 1 ;
//     }
//     Node* addOne(Node* head) {
//         // Your Code here
//         int carry = helper(head) ;
//         if(carry == 1)
//         {
//             Node* x =new Node(carry) ;
//             x->next = head ;
//             head = x ;
//         }
//         return head ;
//     }

// L-12 FIND INTERSECTION POINT

// LC-160
//  ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
//         if(head1==NULL || head2== NULL) return NULL ;
//         ListNode* t1 = head1 ;
//         ListNode* t2 = head2 ;
//         while(t1!=t2)
//         {   
//             t1=t1->next ; t2=t2->next ; 
//             if(t1== t2) return t1 ;
//             if(t1==NULL) {t1= head2 ; }
//             if(t2==NULL) {t2= head1 ; }
//         }
//         return t1;
//     }

// L-13 FIND MIDDLE ELEMENT OF LL

// LC-876
// ListNode* middleNode(ListNode* head) {
//     ListNode* slow=head;
//    ListNode* fast=head;
//    while(fast->next!=NULL && fast->next->next!=NULL ){
//       slow=slow->next;
//       fast=fast->next->next;
//    }
//    if(fast->next == NULL ) return slow ;
//    else return slow->next ;
// }
// L-14 DETECT A LOOP OR CYCLE

// LC-14 DETECT LOOP OR CYCLE

// LC-141
//  if(head==NULL) return false ;
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast!=NULL &&  fast->next!= NULL  )
//         {   
//             slow=slow->next ;
//             fast = fast->next->next ;
//             if(slow==fast) return true;
//         }
//         return false; 

// L-15 FIND LENGTH OF LOOP IN LL

// LC-0
// map<node*,int>mpp ;
// int timer = 0 ; 
// node* temp = head ;
// while(temp!=NULL)
// {
//     if(mpp.find(temp) != mpp.end())
//     {
//         int value = mpp[temp] ;
//         return timer - value ;
//     }
//     mpp[temp] = ++timer ;
//     temp = temp->next ;
// }
// return false ;

// L-16 DELETE MIDDLE OF LL 

// LC-2095
// MINE
// ListNode* deleteMiddle(ListNode* head) {
//     if(head == NULL || head ->next == NULL) return NULL ;
//     ListNode* slow=head; ListNode* lslow ;
//     ListNode* fast=head;
//     while(fast->next!=NULL && fast->next->next!=NULL ){
//        lslow = slow ;
//        slow=slow->next;
//        fast=fast->next->next;
//     }
//     if(fast->next == NULL ) 
//     {
//          lslow->next = slow->next ;
//          slow->next =NULL ;
//          delete slow ;
//     }
//     else 
//     {
//          slow->next = slow->next->next ;
//     }
//     return head ;
//  }
// STRIVER
// skip slow first time and move fast only

// L-17 FIND STARTING POINT OF CYLE

// LC-142
// BRUTE - HASHING , MAP
//  if(head == NULL) return NULL ;
//         ListNode* temp = head ;
//         map<ListNode* , int>  mpp;
//         while(temp!= NULL)
//         {
//             if(mpp.find(temp) != mpp.end()) return temp ;
//             mpp[temp] = 1 ;
//             temp=temp->next ;
//         }
//         return temp ;
// OPTIMAL

// L-18 DELETE ALL OCCURENCES OF A KEY

// LC-0
// temp=head ;
// while(temp!=NULL)
// {
//     if(temp->val==key)
//     {
//         if(temp==head) head = head->next ;
//         newnode = temp->next ;
//         prevnode = temp->prev ;
//         if(nextnode) nextnode->prev = prevnode ;
//         if(prevnode) prevnode->next = nextnode ;
//     }
//     else temp=temp->next ;
// }

// L-19 FIND ALL PAIRS WITH GIVEN SUM

// LC-0
// GFG 
// BRUTE TC - O(N)
//  vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
//         // code here
//         vector<pair<int,int>> vec ;
//         Node* temp1 = head; 
//         Node* temp2 = head; 
//         while(temp1!=NULL)
//         {
//             temp2= temp1->next ;
//             while(temp2!=NULL && temp1->data+temp2->data <= target)
//             {
//                 if(temp1->data+temp2->data == target) vec.push_back(temp1->data,temp2->data);
//                 temp2= temp2->next ;
//             }
//             temp1= temp1->next ;
//         }
//         return vec ;
//     }
// OPTIMAL
// TWO POINTER 
// TC - O(<N)
// Node* findtail(Node* head)
//     {
//         Node* temp = head;
//         while(temp->next!= NULL) temp = temp->next ;
//         return temp ;
//     }
//     vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
//         // code here
//         vector<pair<int,int>> vec ;
//         if(head==NULL) return vec;
//         Node* l = head; 
//         Node* r = findtail(head); 
//         while(l->data < r->data)
//         {
//             if(l->data + r->data == target)
//             {
//                 vec.push_back({l->data,r->data});
//                 l = l->next ;r= r->prev;
//             }
//             else if(l->data + r->data < target)
//             {
//                 l = l->next ;
//             }
//             else r = r->prev;
//         }
//         return vec ;
//     }

// L-20 REMOVE DUPLICATES FROM SORTED DLL

// LC-0
// GFG
// Node* removeDuplicates(Node* head) {
//         // code here
//         Node* prev = head ;
//         if(head == NULL || head->next == NULL) return NULL ;
//         Node* front = head->next ;
//         while(front!=NULL)
//         {
//             if(prev->data == front->data)
//             {
//                 front = front->next ;
//                 if(front == NULL) prev ->next = NULL ;
//             }
//             else
//             {
//                 prev->next = front ;
//                 prev = front ;
//                 front = front->next ;
//                 if(front==NULL) prev ->next = NULL;
//             }
//         }
//         return head ;
// REMOVE DUPLICATES FROM SORTED DLL
// douby linked list
// Node* removeDuplicates(Node* head) {
//     if (head == NULL || head->next == NULL) return head;
//     Node* current = head;
//     while (current->next != NULL) {
//         if (current->data == current->next->data) {
//             Node* duplicate = current->next;
//             current->next = duplicate->next;
//             if (duplicate->next != NULL) {
//                 duplicate->next->prev = current;
//             }
//             delete duplicate;
//         } else {
//             current = current->next;
//         }
//     }
//     return head;
// }

// L-21 REVERSE K NODES IN LL   

// LC-25
//  ListNode* reverse(ListNode* head)
//     {
//         if(head == NULL) return NULL ;
//         if(head->next == NULL) return head;
//         ListNode* back = head ;
//         ListNode* curr = head->next ;
//         ListNode* front= curr->next ;
//         while(curr!= NULL)
//         {
//             if(back==head) back->next =NULL ;
//             curr->next =back ;
//             back = curr ;
//             curr = front ;
//             if(front != NULL ) front = front -> next ; 
//         }
//         head = back ;
//         return head ;
//     }
//     ListNode* find_kthnode(ListNode* temp , int k)
//     {
//         k-- ;
//         while(temp!=NULL && k>0)
//         {
//             k--;temp=temp->next ;
//         }
//         return temp;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp= head ;
//         ListNode* prevnode=NULL  ;
//         while(temp!=NULL)
//         {
//             ListNode* kthnode = find_kthnode(temp , k);
//             if(kthnode== NULL)
//             {
//                 if(prevnode) prevnode->next =temp;break;  
//             }
//             ListNode* nextnode =kthnode->next ;
//             kthnode->next = NULL ;
//             reverse(temp) ;
//             if(temp==head) {head = kthnode ;}
//             else {prevnode->next = kthnode ;}
//             prevnode = temp; 
//             temp= nextnode ;
//         }
//         return head ;
//     }

// L-22 ROTATE A LINKED LIST

// LC-61
// BRUTE        
// ListNode* reverse(ListNode* head) {
//     if(head == NULL) return NULL ;
//     if(head->next == NULL) return head ;
//     ListNode* back = head ;
//     ListNode* curr = head->next ;
//     ListNode* front= curr->next ;
//     while(curr!= NULL)
//     {
//         if(back==head) back->next =NULL ;
//         curr->next =back ;
//         back = curr ;
//         curr = front ;
//         if(front != NULL ) front = front -> next ; 
//     }
//     head = back ;
//     return head ;
//     }
//     ListNode* rotateRight(ListNode* head, int k) {
//         ListNode* l =head ;
//         ListNode* r =head ;
//         ListNode* curr =NULL ;
//         ListNode* temp = head ;
//         if(head==NULL || head->next == NULL) return head ;  
//         // r at right end
//         while(temp->next !=NULL)
//         {
//             temp= temp->next ;
//             r = temp ;
//         }
//         reverse(l) ;
//         while(k)
//         {   
//             curr = r->next ;
//             r->next =NULL;
//             l->next = r ;
//             l = r ;
//             k-- ;
//             r= curr ;
//         }
//         reverse(r) ;
//         return l;
//     }
// BRUTE
//  ListNode* findit(ListNode* temp,int k){
//         int cnt=1;
//         while(temp!=NULL){
//             if(cnt==k) return temp;
//             cnt++;
//             temp=temp->next;
//         }
//         return temp;
//     }
//     ListNode* rotateRight(ListNode* head, int k)
//     {
//       if(head==NULL || k==0) return head;
//         ListNode* tail=head;
//         int n=1;
//         while(tail->next!=NULL){
//            n++;
//            tail=tail->next;
//         }
//         if(k%n==0) return head;
//          k=k%n;
//          tail->next=head;
//         ListNode* newlastnode=findit(head,n-k);
//         head=newlastnode->next;
//         newlastnode->next=NULL;
//         return head;
//     }
        
// L-23 MERGE TWO SORTED LL

// LC-21
// ListNode* temp1= head1 ;
//         ListNode* temp2= head2 ;
//         if(head1 == NULL && head2== NULL) return NULL ;
//         ListNode* temp= new ListNode(-1);ListNode* head = temp ;
//         while(temp1!=NULL && temp2!=NULL)
//         {
//             if(temp1->val <= temp2->val)
//             {
//                 temp->next = temp1 ;
//                 temp1 = temp1 -> next ;
//             }
//             else if(temp1->val > temp2->val)
//             {
//                 temp->next = temp2 ;
//                 temp2 = temp2 -> next ;
//             }
//             temp = temp->next ;
//         }
//         while(temp1!=NULL){temp->next = temp1 ;temp1 = temp1 -> next ;temp = temp->next ;}
//         while(temp2!=NULL){temp->next = temp2 ;temp2 = temp2 -> next ;temp = temp->next ;}
//         return head->next ;






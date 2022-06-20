#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

Node* createNode(int val){
    Node* new_node = new Node();
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void printList (Node* head){
    if(head == NULL){
        cout<<"the list is empty"<<endl;
        return;
    }
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

void appendNodeAtLast(Node* head,int val){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = createNode(val);
    temp->next = newNode;
}

void prependNodeAtFirst(Node** head_ref,int val){
    if(*head_ref == NULL){
        return;
    }
    Node* newNode = createNode(val);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void insertAfter(Node* prevNode , int val){
    if(prevNode == NULL){
        return;
    }
    Node* newNode = createNode(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteFromList(Node** head_ref,int valueToDelete){ // by double pointer
    if(*head_ref == NULL){
        return;
    }
    if((*head_ref)->data == valueToDelete){
        Node* temp = *head_ref;
        *head_ref = temp->next;
        delete(temp);
        return;
    }
    else{
        Node* prev = NULL;
        Node* temp = *head_ref;
        while(temp != NULL){
            if(temp->data == valueToDelete){
                prev->next = temp->next;
                delete(temp);
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"element not present in the list"<<endl;
            return;
        }
    }
}

void deleteFromListRef(Node* &head,int x){ // using reference variable
    if(head == NULL){
        cout<<"element not present in the list"<<endl;
        return;
    }
    if(head->data == x){
        Node*temp = head;
        head = head->next;
        delete(temp);
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data == x){
            prev->next = temp->next;
            delete(temp);
            return;
        }
        prev = temp;
        temp = temp->next; 
    }
    return;
}

void deleteLastFromList(Node* head){
    if(head == NULL){
        return;
    }
    Node* prev = NULL;
    Node* temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete(temp);
}

void deleteFirstFromList(Node* &head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete(temp);
}   

// delete node recursively -------------------------> to be done
void deleteRecursively(Node* &head,int x){
    if(head == NULL){
        cout<<"element not present in the list"<<endl;
        return;
    }


    if(head->data == x){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return;
    }

    deleteRecursively(head->next,x);
}

int getLength(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

int getLengthRec(Node* head){
    if(head == NULL){
        return 0;
    }
    else{
        return 1+getLengthRec(head->next);
    }
    return 0;
}

bool checkLoop(Node* head){ // floyd's cylce finding algorithm
    Node* temp1 = head;
    Node* temp2 = head;

    while(temp1 && temp2 && temp2->next){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if(temp1 == temp2){
            return 1;
        }
    }
    return 0;
}

int getCountOfLoop(Node* head){
    if(!checkLoop(head)){
        return 0;
    }

    Node* temp1 = head;
    Node* temp2 = head;
    Node* pivot = NULL;

    while(temp1 && temp2 && temp2->next){
        temp1 = temp1->next;
        temp2 = temp2->next->next;

        if(temp1 == temp2){
            pivot = temp1;
            break;
        }
    }
    
    int count = 1;
    Node* temp = pivot;
    while(temp->next != pivot){
        count++;
        temp = temp->next;
    }
    return count;
}

int intersectPointOfTwoLists(Node* head1, Node* head2){
    cout<<"in"<<endl;
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    int diff = abs(l1-l2);
    if(l1>l2){
        while(diff--){
            head1 = head1->next;
        }
    }
    else if(l2>l1){
        while(diff--){
            head2 = head2->next;
        }
    }

    while(head1!=head2){
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1->data;
}

Node* findIntersection(Node* head1, Node* head2)
{
    Node* ans = createNode(0);
    Node*temp = ans;
    
    while(head1 && head2){
        if(head1->data == head2->data){
            Node *new_node = createNode(0);
            temp->data = head1->data;
            temp->next = new_node;
            temp = temp->next;
            
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data > head2->data){
            head2 = head2->next;
        }
        else{
            head1 = head1->next;
        }
    }
    Node* temp2 = ans;
    while(temp2->next->next !=NULL ){
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    
    return ans;
}

bool checkCircularList(Node* last){
    if(last == NULL){
        return 0;
    }
    Node *temp = last;
    temp = temp->next;
    while(temp!=last && temp!= NULL){
        temp = temp->next;
    }

    if(temp == last){
        return 1;
    }
    else{
        return 0;
    }

    return 0;
}

Node* reverseList(Node* head) {
        
        if(head == NULL){
            return head;
        }
        
        Node* prev = NULL;
        Node* curr = head;
        if(head->next == NULL){
            return head;
        }
        Node* currNext = head->next;
        
        while(currNext != NULL){
            curr->next = prev;
            prev = curr;
            curr = currNext;
            currNext = currNext->next;
        }
        
        curr->next = prev;
        
        return curr;
    }


void printRev(Node* head){
    if(head == NULL){
        return;
    }

    printRev(head->next);
    cout<<head->data<<"->";
}
int main()
{   
   
    Node* head =  createNode(5);
    appendNodeAtLast(head,3);
    appendNodeAtLast(head,6);
    prependNodeAtFirst(&head,9);
    insertAfter(head,10);
    // cout<<checkCircularList(head)<<endl;
    printList(head);
    printRev(head);
    // cout<<"address of head is"<<head<<endl;
    // deleteFromList(&head,10);
    // deleteLastFromList(head);
    // printList(head);
    // deleteFirstFromList(head);
    // printList(head);
    // deleteFromList(&head,9);
    // printList(head);
    // deleteLastFromList(head);
    // printList(head);
    // deleteFirstFromList(head);
    // deleteRecursively(head,6);
    // deleteFromListRef(head,9);
    // deleteFromListRef(head,6);
    // int l = getLengthRec(head);
    // cout<<l<<endl;
    // fun(head);
    // printList(head);
    // cout<<checkLoop(head)<<endl;
    // cout<<"address of head is"<<head<<endl;

    // ----------------- to get count of loop ------------------------//
    // Node* node1 = createNode(1);
    // Node* node2 = createNode(2);
    // node1->next = node2;
    // Node* node3 = createNode(3);
    // node2->next = node3;
    // Node* node4 = createNode(4);
    // node3->next = node4;
    // Node* node5 = createNode(5);
    // node4->next = node5;
    // Node* node6 = createNode(6);
    // node5->next = node6;
    // // node6->next = node2;
    // // cout<<getCountOfLoop(node1)<<endl;
    // // --------------------------------------------------------------//
    // Node* new_node1 = createNode(10);
    // new_node1->next = node4;
    // // printList(new_node1);
    // cout<<intersectPointOfTwoLists(node1,new_node1)<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(){
            next = NULL;
            prev = NULL;
        }
};

void append(Node* &head,int data){
    
    Node* newNode = new Node();
    newNode->data = data;
    if(head == NULL){
        // cout<<"here"<<endl;
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        // head = head->next;
        return ;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    
}

void printList(Node* head){
    if(head == NULL){
        return;
    }

    while(head != NULL){
        if(head->next == NULL){
            cout<<head->data<<endl;
            break;            
        }
        cout<<head->data<<"->";
        head = head->next;
    }
}

void printReverse(Node* head){
    if(head == NULL){
        return;
    }

    while(head->next != NULL){
        head = head->next;
    }

    while(head != NULL){
        if(head->prev == NULL){
            cout<<head->data<<endl;
            return;
        }
        cout<<head->data<<"->";
        head = head->prev;
    }
}

void prepend(Node* &head,int data){
    
    Node* newNode = new Node();
    newNode->data = data;
    if(head == NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = head->prev;
    // head->prev = NULL;

}

void addNodeAfter(Node *head, int pos, int data){ // position is given by index
   if(head == NULL){
        return ;
   }
   
   while(pos != 0){
        head = head->next;
        pos--;
   }
   
    if(head->next == NULL){
        append(head,data);
        return;
    }
    // if(head->prev == NULL){
    //     prepend(head,data);
    //     return;
    // }

   Node* newNode = new Node();
   newNode->data = data;
   newNode->next = head->next;
   newNode->prev = head;
   head->next->prev = newNode;
   head->next = newNode;
}

void addNodeBefore(Node* &head, int pos, int data){ // position is given by index
   if(head == NULL){
        return ;
   }
   Node* temp = head;
   while(pos != 0){
        temp = temp->next;
        pos--;
   }
   
    if(temp->prev == NULL){
        prepend(head,data);
        return;
    }

   Node* newNode = new Node();
   newNode->data = data;
   newNode->prev = temp->prev;
   newNode->next = temp;
   temp->prev->next = newNode;
   temp->prev = newNode;
   
}

void deleteFirst(Node* &head){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    temp->next->prev = NULL;
    head = head->next;
    delete(temp);
}

void deleteFromLast(Node* &head){
    
    if(head == NULL){
        return;
    }
    if(head->next == NULL && head->prev == NULL){
        
        Node*  temp = head;
        head = NULL; //alag memory
        delete(temp); //NULL pointer cannot be deleted
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
   
    temp->prev->next = NULL;
    delete(temp);
}

void deleFromList(Node* &head,int data){
    if(head == NULL){
        return;
    }
    Node* temp = head;

    if(temp->data == data){
        // cout<<"here"<<endl;
        return deleteFirst(head);
    }
    // cout<<"dasdada"<<endl;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp->data == data){
            cout<<"data is present"<<endl;
            if(temp->next == NULL){
                return deleteFromLast(head);
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete(temp);
            return;
        }
    }

    cout<<"value not present in the list"<<endl;;
}


void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* currNext = head->next;
     
    while(currNext!=NULL){
        curr->prev = currNext;
        curr->next = prev;

        prev = curr;
        curr = currNext;
        currNext = currNext->next;
    }

    curr->next = prev;
    curr->prev = NULL;

    head = curr;
}

int main()
{
    // Node* head = NULL;
    // // cout<<head<<endl;
    // append(head,5);
    // // cout<<head<<endl;;
    // append(head,6);
    // append(head,7);
    // append(head,8);
    // append(head,9);
    // append(head,10);
    // append(head,11);
    // prepend(head,1);
    // addNodeAfter(head,3,1231223);
    // addNodeBefore(head,1,12312);
    // addNodeAfter(head,9,0);
    // addNodeBefore(head,0,0);
    // deleteFirst(head);
    // deleteFirst(head);
    // deleteFirst(head);
    // deleteFirst(head);
    // deleteFromLast(head);
    // deleFromList(head,7);
    // // Node* head = NULL;
    // // append(head,1);
    // // cout<<head<<endl;
    // // deleteFromLast(head); 
    // // cout<<head<<endl;
    // // append(head,2);
    // // cout<<head<<endl;
    // printList(head);
    // // cout<<head<<endl;
    // reverse(head);
    // printList(head);
    // // cout<<head<<endl;
    // // printReverse(head);


    Node* head = NULL;
    append(head,5);
    append(head,6);
    printList(head);
    reverse(head);
    printList(head);
    return 0;
}
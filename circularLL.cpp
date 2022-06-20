#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void createNodeInEmptyList(Node* &last,int val){
    if(last != NULL){
        return;
    }

    Node * new_node = new Node();
    new_node->data = val;
    last = new_node;
    last->next = new_node;
}

void printList(Node *last){
    if(last->next == last){
        cout<<"here"<<endl;
        cout<<last->data<<endl;
        return;
    }
    else{
        Node* temp = last;
        temp = temp->next;
    while(temp != last){
        if(temp->next == last){
            cout<<temp->data<<" "<<temp->next->data<<endl;
        }
        else{
            cout<<temp->data<<" ";
        }

        temp = temp->next;
        }
 
    }
}

void appendNode(Node* &last,int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = last->next;
}

void prependNode(Node* last,int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
}

void insertAfter(Node* &last,int refData,int data){
    if(last == NULL){
        return;
    }

    if(last->data == refData){
        appendNode(last,data);
    }
    else{
        Node* newNode = new Node();
        newNode->data = data;
        Node *temp = last;
        while(temp->next != last){
        // cout<<temp->data<<endl;
            if(temp->data == refData){
                break;
            }
            temp = temp->next;
        }
        if(temp->data == refData){
            newNode->next = temp->next;
            temp->next = newNode;   
        }
        else{
            cout<<"reference data not fond in the list ar data value :"<<refData<<endl;
            return;
        }
    }
    return;
}

void deleteFromLast(Node* &last){
    Node* temp = last;
    Node* prev = NULL;

    while(temp->next != last){
        temp = temp->next;
    }

    prev = temp;
    temp = last;
    prev->next = last->next;
    last = prev;
    delete(temp);
}

void deleteFromFirst(Node* &last){
    Node* prev = last;
    Node* curr = last->next;

    prev->next = curr->next;
    last->next = curr->next;

    delete(curr);
}

void deleteFromListAtValue(Node* &last,int data){
    if(last->data == data){
        return deleteFromLast(last);
    }
    else if(last->next->data == data){
        return deleteFromFirst(last);
    }
    else{
        Node* temp = last;
        Node* prev = NULL;
        while(temp->data != data && temp->next != last){
            prev = temp;
            temp = temp->next;
            // cout<<prev->data<<" "<<temp->data<<endl;
        }
        if(temp->data == data){
            cout<<"here"<<endl;
            prev->next = temp->next;
            delete(temp);
        }
        else{
            cout<<"Node of this value is not present in the list"<<endl;
            return;
        }
    }
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


int countNode(Node* last){

    if(last == NULL){
        return 0;
    }

    if(last->next == last){
        return 1;
    }
    int count =1;
    Node* temp = last;
    while(temp->next!=last){
        count++;
        temp = temp->next;
    }

    return count;
}

void convertToNonCircular(Node* &last){
    if(last == NULL){
        return;
    }
    Node* lastNode = last;
    last = last->next;
    lastNode->next = NULL;

}   

void printSingleList (Node* head){
    while(head->next!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}


bool isTwoCircularListEqual(Node* last1,Node* last2){
    if(last1 == NULL || last2 == NULL ){
        if(last1 == NULL && last2 == NULL ){
            return 1;
        }
        else{
            return 0;
        }
    }
    Node* temp1 = last1;
    Node* temp2 = last2;

    if(temp1->data == temp2->data){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1->data == temp2->data){
        if(temp1 == last1 || temp2 == last2){
            if(temp1 == last1 && temp2 == last2){
                return 1;
            }
            return 0;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp1->data == temp2->data){
        return 1;
    }

    return 0;
}


void deleteWholeList(Node* last){
    if(last == NULL){
        return;
    }
    else{
        while(last->next != last){
            deleteFromFirst(last);
        }
        delete(last);
    }
}

int main()
{
    
    // Node* last = NULL;
    // createNodeInEmptyList(last,1);
    // appendNode(last,10);
    // prependNode(last,2);
    // insertAfter(last,2,5);
    // insertAfter(last,5,3);
    // // insertAfter(last,6,2);
    // printList(last);
    // deleteFromLast(last);
    // // cout<<checkCircularList(last)<<endl;
    // deleteFromListAtValue(last,5);
    // // deleteFromFirst(last);
    // // cout<<last<<endl;
    // // cout<<last<<endl;
    // // cout<<last->next<<endl;
    // // cout<<"done"<<endl;
    // // cout<<countNode(last)<<endl;
    // convertToNonCircular(last);
    // // printSingleList(last);

    Node* last = NULL;
    createNodeInEmptyList(last,10);
    appendNode(last,10);
    appendNode(last,10);
    appendNode(last,10);
    appendNode(last,1);

    // Node* last1 = NULL;
    // createNodeInEmptyList(last1,10);
    // appendNode(last1,10);
    // appendNode(last1,10);
    // appendNode(last1,10);
    // appendNode(last1,1);
    printList(last);
    // deleteWholeList(last);
    // printList(last1);

    // cout<<isTwoCircularListEqual(last,last1)<<endl;
    return 0;
}
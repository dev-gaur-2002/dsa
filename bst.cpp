#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:

        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }


};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            // q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

    }
    
}

Node *insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    if(data < root->data){
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

void takeInput(Node* &root){
    cout<<"enter the data to be inserted int BST :"<<endl;

    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

Node* getMin(Node* root){
    
    Node* temp = root;
    if(temp == NULL){
        return temp;
    }

    while(temp->left!=NULL){
        temp = temp->left;

    }

    return temp;
}

Node* deleteFromBst(Node* root,int data){
    if(root == NULL){
        return NULL;
    }

    if(data == root->data){

        // 0 child

        if(root->left == NULL && root->right == NULL){
            delete(root);
            return  NULL;
        }

        //1 child

        //left child 
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete(root);
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            Node* minVal = getMin(root->right);
                root->data = minVal->data;
                root->right = deleteFromBst(root->right , minVal->data);
                return root;
        }

    }
    else if(data < root->data){
        return deleteFromBst(root->left,data);
    }
    else{
        return deleteFromBst(root->right,data);
    }

    return NULL;
}


int main()
{
    Node* root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    Node* min = getMin(root);
    // cout<<min->data<<endl;
    Node* x = deleteFromBst(root,65);
    levelOrderTraversal(root);
    return 0;
}
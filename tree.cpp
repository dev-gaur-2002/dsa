#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};



Node* buildTree(Node* root){
    cout<<"enter the data"<<endl;
    int data ;
    cin>>data;
    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"enter the data to insert at left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter the data to insert at right of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

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
void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrderTraversal(Node* &root){
    cout<<"enter the data for root node"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"enter the data for left of "<<temp->data<<endl;
        int leftdata ;
        cin>>leftdata;

        if(leftdata == -1){
            temp->left = NULL;
        }
        else{
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"enter the data for right of "<<temp->data<<endl;
        int rightData ;
        cin>>rightData;

        if(rightData == -1){
            temp->right = NULL;
        }
        else{
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node* root = NULL;
    buildFromLevelOrderTraversal(root);
    // root = buildTree(root);
    // tree  --> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order traversal 
    levelOrderTraversal(root);
    cout<<"inorder traversal is :" <<endl; 
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal is :"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal is :"<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}

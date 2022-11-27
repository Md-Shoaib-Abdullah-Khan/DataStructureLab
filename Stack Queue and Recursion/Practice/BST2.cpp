#include<iostream>


using namespace std;

struct Node {
    int data;
    struct Node* left_child;
    struct Node* right_child;

    Node(int value){
        data = value;
        left_child = NULL;
        right_child = NULL;
    }
};
void inorder(Node* start);
Node* insert(Node* root, int item);

Node* insert(int item, int index);

int main(){
    int i, num;
    Node* root = NULL;
    root = insert(root, 35);
    root=insert(root, 6);
    root=insert(root, 53);
    root=insert(root, 16);

    inorder(root);
   

}

Node* insert(Node* root, int item){

    if(root == NULL)return new Node(item);
    if(root->data > item) root->left_child = insert(root->left_child, item);
    else root->right_child = insert(root->right_child, item);
    return root;
}

void inorder(Node* current_node){

    if(current_node == NULL)return;
        
        inorder(current_node->left_child);
        cout<<current_node->data<<" ";
        inorder(current_node->right_child);
    
}


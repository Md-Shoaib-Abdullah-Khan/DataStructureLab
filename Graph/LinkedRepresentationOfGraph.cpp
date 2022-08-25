#include<iostream>
#include<bits/stdc++.h>

using namespace std;
bool vis[1000];

typedef struct node Node;
struct node {
    int data;
    Node * next_pointer;
};

Node * create_node();
void insert_in_beginning(int value, Node** start);
void insert_in_ending(int value, Node** start);
void insert_in_specific_position(int value, Node * start);
void linked_list_print(Node * start);
Node * start[10];
void dfs(Node *n){
    if(vis[n->data])return;
    else if(n == NULL)return;
    vis[n->data] = true;
    cout<<n->data<<" ";
    dfs(start[n->data]);
    return;
}


int main()
{
    int arr[] = {5, 3, 9, 42, 0, 10};
    int edges = 0, nodes = 0;
    
    cin>>nodes>>edges;
    

    memset(vis, 0, sizeof(vis));

    for(int i=0;i<nodes;i++) {
        start[i] = NULL;
        
    }

    for(int i = 0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        insert_in_ending(a, &start[b]);
        insert_in_ending(b, &start[a]);
    }
    for(int i=0; i<nodes; i++){
        dfs(start[i]);
        
    }
    // for(int i=0; i<nodes; i++){
    //     linked_list_print(start[i]);
    // }
}

Node *create_node(){
    Node* node = (Node *) malloc(sizeof(Node));

    if(node == NULL) {
        cout<<"Error while creatng new node"<<endl;
    }
    return node;
}

void insert_in_beginning(int value, Node** start){
    Node* new_node = create_node();

    new_node->data = value;
    new_node->next_pointer = *start;
    *start = new_node;
}

void linked_list_print(Node * start){
    if(start == NULL){
        cout<<"Empty Linked List"<<endl;
        //exit(1);
    }
    Node * current_node = start;
    while(current_node!=NULL){
        cout<<current_node->data<<" ";
        current_node = current_node->next_pointer;
    }
    cout<<endl;
}

void insert_in_ending(int value, Node** start){
    Node * current_node = *start;
    Node * new_node = create_node();

    if(current_node==NULL){
        *start = new_node;
        current_node = new_node;
        current_node->next_pointer = NULL;
    } 
    while(current_node->next_pointer!=NULL){
        current_node = current_node->next_pointer;
    }
    new_node->data = value;
    current_node->next_pointer = new_node;
    new_node->next_pointer = NULL;
}




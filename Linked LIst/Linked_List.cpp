#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next_pointer;
};
typedef struct node Node;

Node * create_node();
Node * insert_in_ending(Node *start, int value);
void print_list(Node *start);

int main(){
    Node *start = NULL;
    int arr[] = {6,16,26,35,53};
    //for(int i=0;i<5;i++)start = insert_in_ending(start, arr[i]);
    
    print_list(start);

}

Node * create_node(){
    Node  *new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL){
        cout<<"Creating node failed!";
    }
    return new_node;
}
Node * insert_in_ending(Node *start, int value){
    Node *new_node = create_node();
    Node *current_node = start;

    new_node->data = value;
    new_node->next_pointer = NULL;

    if(current_node == NULL){
        return new_node;
    }
    while(current_node->next_pointer != NULL){
        current_node = current_node->next_pointer;
    }
    current_node->next_pointer = new_node;
    
    return start;
}

void print_list(Node *start){
    
    Node *current_node = start;
    if(current_node == NULL)cout<<"Empty list!"<<endl;
    while(current_node != NULL){
        cout<<current_node->data<<endl;
        current_node = current_node->next_pointer;
    }
    return;
}
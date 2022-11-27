#include<iostream>
using namespace std;



struct Node{
    int data;
    struct Node* next_pointer;
};
typedef struct Node node;

void print_list(node *start);
node* insert_in_the_ending(node* start, int value);
node * create_node();

int main(){
    node* start;
    start = NULL;
    start = insert_in_the_ending(start, 35);
    start = insert_in_the_ending(start, 53);
    print_list(start);

}
node * create_node(){
    node * new_node = (node*)malloc(sizeof(node));

    return new_node;
}
node* insert_in_the_ending(node* start, int value){

    node* new_node = create_node();
    node* current_node = start;

    new_node->data = value;
    new_node->next_pointer = NULL;

    if(current_node == NULL)return new_node;
    while(current_node->next_pointer != NULL)
    {
        current_node = current_node->next_pointer;
    }
    current_node->next_pointer = new_node;
    return start;
}

void print_list(node *start){
    
    node *current_node = start;
    if(current_node == NULL)cout<<"Empty list!"<<endl;
    while(current_node != NULL){
        cout<<current_node->data<<endl;
        current_node = current_node->next_pointer;
    }
    return;
}
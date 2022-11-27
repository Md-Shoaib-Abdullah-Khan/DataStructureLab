#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next_pointer;
};
typedef struct node Node;

Node * create_node();
Node * insert_in_ending(Node *start, int value);
int  search(Node *start, int item);
void print_list(Node *start);
Node* sort(Node* start);

int main(){
    Node *start = NULL;
    int arr[] = {26,35,16,6,53};
    for(int i=0;i<5;i++)start = insert_in_ending(start, arr[i]);

    //cout<<search(start, 7)<<endl;
    sort(start);
    
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
int search(Node *start, int item){
    Node *current_node = start;
    int cnt = 0;
    while(current_node->next_pointer != NULL){
        if(current_node->data == item){
            return cnt;
        }
        else current_node = current_node->next_pointer;
        cnt++;
    }
    return -1;

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
Node* sort(Node* start){
    for(Node* i=start; i!=NULL; i=i->next_pointer){
        for(Node* j=i->next_pointer; j!=NULL; j=j->next_pointer){
            if(j->data < i->data){
                 Node *current_node1 = start;
                 while(current_node1->next_pointer != i){
                current_node1 = current_node1->next_pointer;
                }
                Node *current_node2 = start;
                 while(current_node2->next_pointer != j){
                current_node2 = current_node2->next_pointer;
                }
                current_node1->next_pointer = j;
                current_node2->next_pointer = i; 
            }
        }
    }
}
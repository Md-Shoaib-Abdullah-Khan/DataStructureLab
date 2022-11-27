#include<iostream>


using namespace std;
int tree[100];
void insert(int item, int index);

int main(){
    int i, num;
    
    for(i=0;i<100;i++)tree[i]=-1;

    insert(35, 1);
    insert(6,1);
    insert(53,1);
    insert(26,1);
    insert(26,1);
    
    i=1;
    while(i!=20){
        cout<<" "<<tree[i];
        i++;
    }

}

void insert(int item, int index){
    if(tree[index]==-1){
        tree[index]=item;
        return;
    }

    if(tree[index]<item)insert(item, 2*index+1);
    else if(tree[index]>item)insert(item, 2*index);
    else {
        cout<<index<<endl;
        return;
    }

}

void print(){
    int i,j;
    for(i=1;i<20;i++){
        while(j!=)
    }
}

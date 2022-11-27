#include<iostream>
using namespace std;

int n, tree[100];
void insert(int value);
void del();
int main(){

    insert(35);
    insert(6);
    insert(53);
    insert(16);
    insert(26);
    
    for(int i=1;i<=n;i++)cout<<tree[i]<<" ";
    del();
for(int i=1;i<=n;i++)cout<<tree[i]<<" ";
}
void insert(int value){
    n++;
    tree[n]=value;

    int i=n;
    while(i>1){
        int parent = i/2;
        if(tree[parent]<tree[i]){
            swap(tree[parent], tree[i]);
            i=parent;
        }
        else return;
    }
}
void del(){
    tree[1]=tree[n];
    n--;
    int i=1;
    while(i<n){
        int left = tree[2*i];
        int right = tree[2*i+1];
        int larger;
        if(left>right)larger = 2*i;
        else larger=2*i+1;
        if(tree[i]<tree[larger]){
            swap(tree[i], tree[larger]);
            i=larger;
        }
        else return;

    }
}
#include<iostream>
#include<math.h>
using namespace std;

int arr[100];
char printArr[100][100];
bool found = false;
int find(int loc, int item){
    if(arr[loc] == -1) return loc;
    else if(arr[loc] == item) {
        found = true;
        return loc;
    }
    else if(arr[loc] < item)return find(2*loc +1, item);
    else return find(2*loc, item);
}

void insert(int item){
    found = false;
int loc = find(1, item);
if(found) {
    cout<<"Found element on "<<loc<<endl;
    return;
}
    arr[loc] = item;  

}


int main(){
    for(int i=0;i<100;i++)arr[i]=-1;
    // for(int i=0;i<100;i++){
    //     for(int j=0;j<100;j++) printArr[i][j]=' ';
    // }
   

    while(1){
        int a;
        cin>>a;
        if(a==-1)break;
        insert(a);
    }
    int i,j;
    for( i=1;i<50;i++){
    
        cout<<i<<" "<<arr[i]<<endl;;
        
}
}
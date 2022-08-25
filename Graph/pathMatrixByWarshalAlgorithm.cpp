#include<iostream>
#include<vector>
using namespace std;
int n;
vector<vector<int>>matrix;
vector<vector<int>>path;

void warshal(){

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                    path[i][j] = path[i][j] | (path[i][k] & path[k][j]);
}
int main(){
    cin>>n;
for(int i=0; i<n; i++){
       for(int j=0; j<n; j++)
        {
           matrix[i][j] = 0;
            path[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        matrix[a][b] = 1;
        path[a][b] = 1;
    }
    warshal();
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<path[i][j]<<" ";
            }
            cout<<endl;
        }
}
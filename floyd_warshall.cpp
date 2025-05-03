#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
void floyd_warshall(vector<vector<int>> v){
    int ans[v.size()][v.size()];
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            ans[i][j]=v[i][j];
        }
        ans[i][i]=0;
    }
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            for(int k=0;k<v.size();k++){
                if(ans[j][i]!=INT_MAX && ans[i][k]!=INT_MAX){
                    ans[j][k]=min(ans[j][k],ans[j][i]+ans[i][k]);
                }
            }
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(ans[i][j]!=INT_MAX){
                cout<<ans[i][j]<<" ";
            }
            else{
                cout<<"-- ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int vertices;
    cout<<"Enter the number of vertices : ";
    cin>>vertices;
    vector<vector<int>> v(vertices,vector<int> (vertices,INT_MAX));
    int edges,x,y,w;
    cout<<"Enter the number of edges in graph : ";
    cin>>edges;
    for(int i=0;i<edges;i++){
        cout<<"Enter edge : ";
        cin>>x>>y;
        cout<<"Enter weight of edge :  ";
        cin>>w;
        v[x][y]=w;
    }
    cout<<"Final distance matrix is : "<<endl;
    floyd_warshall(v);
    // 5 9 0 1 10 1 2 2 2 3 9 0 4 3 4 3 2 1 4 4 4 1 1 4 2 8 3 2 7
    return 0;
}
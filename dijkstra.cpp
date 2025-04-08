#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class graph{
  public:
  int vertices;
  int **matrix; 
  graph(int vertices){
    this->vertices=vertices;
    matrix=new int*[vertices];
    for(int i=0;i<vertices;i++){
      matrix[i]=new int[vertices];
      for(int j=0;j<vertices;j++){
        matrix[i][j]=0;
      }
    }
    int edges,x,y,w;
    cout<<"Enter number of edges : ";
    cin>>edges;
    for(int i=0;i<edges;i++){
      cout<<"Enter edge : ";
      cin>>x>>y;
      cout<<"Enter weight : ";
      cin>>w;
      matrix[x][y]=w;
      matrix[y][x]=w;
    }
  }
  int find_min_vertex(vector<bool> &visited,vector<int> &distance){
    int d=INT_MAX,index=-1;
    for(int i=0;i<vertices;i++){
      if(!visited[i] && distance[i]<d){
        d=distance[i];
        index=i;
      }
    }
    return index;
  }
  void print_path(vector<int> &parent,int v){
    if(v==-1){
      return;
    }
    print_path(parent,parent[v]);
    cout<<v<<" ";
  }
  void dijkstra(int src){
    vector<bool> visited(vertices,0);
    vector<int> distances(vertices,INT_MAX);
    vector<int> parent(vertices,-1);
    distances[src]=0;
    for(int i=0;i<vertices-1;i++){
      int curr=find_min_vertex(visited,distances);
      if(curr==-1) break;
      visited[curr]=1;
      for(int j=0;j<vertices;j++){
        if(!visited[j] && distances[curr]!=INT_MAX && matrix[curr][j]!=0 && distances[j]>distances[curr]+matrix[curr][j]){
          distances[j]=distances[curr]+matrix[curr][j];
          parent[j]=curr;
        }
      }
    }
    cout<<"Shortest distance and path from the source : "<<endl;
    for(int i=0;i<vertices;i++){
      cout<<"Vertex : "<<i<<"   Distance : "<<distances[i]<<" "<<endl;
      if(distances[i]==INT_MAX){
        cout<<"No path exists"<<endl;
      }
      else{
        cout<<"Path : ";
        print_path(parent,i);
        cout<<endl;
      }
    }
  }
};
int main(){
  graph g(6);
  g.dijkstra(0);
  return 0;
}
// 0 2 1 0 1 2 0 3 6 2 3 4 3 4 5 3 1 3 1 4 2 1 3 5 4 5 4

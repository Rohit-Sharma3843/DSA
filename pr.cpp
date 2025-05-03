#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class graph{
    public:
    int vertices;
    node **arr;
    graph(int vertices){
        this->vertices=vertices;
        arr=new node*[vertices];
        for(int i=0;i<vertices;i++){
            arr[i]=new node(i);
        }
        int edges,x,y;
        cout<<"Enter the number of edges : ";
        cin>>edges;
        for(int i=0;i<edges;i++){
            cout<<"Enter the edge : ";
            cin>>x>>y;
            node *temp=arr[x];
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=new node(y);
            node *temp2=arr[y];
            while(temp2->next!=nullptr){
                temp2=temp2->next;
            }
            temp2->next=new node(x);
        }
    }
    void view(){
        for(int i=0;i<vertices;i++){
            node *temp=arr[i];
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    void bfs(){
        vector<bool> visited(vertices,0);
        for(int i=0;i<vertices;i++){
            node *temp=arr[i];
            while(temp!=nullptr){
                if(!visited[temp->data]){
                    cout<<temp->data<<" ";
                    visited[temp->data]=1;
                }
                temp=temp->next;
            }
        }
    }
    void dfs_rec(int i){
        static vector<bool> visited(vertices,0);
        cout<<i<<" ";
        visited[i]=1;
        node *first=arr[i];
        while(first!=nullptr){
            if(!visited[first->data]){
                dfs_rec(first->data);
            }
            else{
                first=first->next;
            }
        }
    }
    void dfs_itr(int i){
        node *first;
        stack<int> s;
        vector<bool> visited(vertices,0);
        s.push(i);
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            if(!visited[temp]){
                cout<<temp<<" ";
                visited[temp]=1;
            }
            first=arr[temp];
            while(first!=nullptr){
                if(!visited[first->data]){
                    s.push(first->data);
                }
                first=first->next;
            }
        }
    }
};
int main(){
  graph g(5);
  g.view();
  cout<<endl;
  g.bfs();
  cout<<endl;
  g.dfs_rec(2);
  cout<<endl;
  g.dfs_itr(2);
  return 0;
}
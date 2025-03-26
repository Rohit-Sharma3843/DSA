#include<iostream>
#include<limits.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
class graph{
    public:
    pair <int,int> p=make_pair(0,0);
    pair<int,pair<int,int>> t=make_pair(0,p);
    vector<pair<int,pair<int,int>>> tree_kruskal;
    vector<pair<int,pair<int,int>>> tree_prims;
    int **matrix;
    int *parent;
    int vertices;
    vector<pair<int,pair<int,int>>> g;
    graph(int vertices){
        this->vertices=vertices;
        cout<<"Enter the number of edges : ";
        matrix=new int*[vertices];
        int edge;
        vector<pair<int,pair<int,int>>> ans(vertices*vertices,{0,{0,0}});
        cin>>edge;
        int a,b,w;
        for(int i=0;i<vertices;i++){
            matrix[i]=new int[vertices];
            for(int j=0;j<vertices;j++){
                matrix[i][j]=0;
            }
        }
        for(int j=0;j<edge;j++){
            cout<<"Enter the edge in (u,v) pair : ";
            cin>>a>>b;
            cout<<"Enter the weight of the edge : ";
            cin>>w;
            pair <int,int> e=make_pair(a,b);
            pair<int,pair<int,int>> x=make_pair(w,e);
            ans.push_back(x);
            matrix[a][b]=w;
        }
        g=ans;
        parent=new int[vertices];
        for(int i=0;i<vertices;i++){
            parent[i]=i;
        }
    }
    void unite(int u,int v){
        parent[u]=v;
    }
    int find(int i){
        if(i==parent[i]){
            return i;
        }
        else{
            return find(parent[i]);
        }
    }
    void kruskal(){
        int i,u,v;
        sort(g.begin(),g.end());
        for(int i=0;i<g.size();i++){
            u=find(g[i].second.first);
            v=find(g[i].second.second);
            if(u!=v){
                tree_kruskal.push_back(g[i]);
                unite(u,v);
            }
        }
    }
    int min_vertex(vector<int>& Mst) {
        int min = INT_MAX;
        int u = -1;
        int v = -1;
    
        for (int i = 0; i < vertices; i++) {
            if (Mst[i] == 1) {
                for (int j = 0; j < vertices; j++) {
                    if (matrix[i][j] != 0 && matrix[i][j] < min && Mst[j] == 0) {  // If the edge exists and j is not yet in MST
                        min = matrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            Mst[v] = 1;
            cout << "Edge selected: (" << u << "," << v << ") with cost: " << min << endl;
        }
        return min;
    }
    void prims(int start){
        vector<int> input(vertices,0);
        input[start]=1;
        int total_cost=0;
        cout<<"Edges in the MST : "<<endl;
        for(int i=0;i<vertices;i++){
            int cost=min_vertex(input);
            if(cost!=INT_MAX){
                total_cost+=cost;
            }
        }
        cout<<"Weight of the MST using Prims Algorithm : "<<total_cost<<endl;
    }
};
int main(){
    graph g(5);
    g.kruskal();
    cout<<endl;
    int sum=0;
    for(int i=0;i<g.tree_kruskal.size();i++){
        cout<<"Edge :("<<g.tree_kruskal[i].second.first<<","<<g.tree_kruskal[i].second.second<<") ";
        cout<<"Weight : "<<g.tree_kruskal[i].first<<endl;
        sum+=g.tree_kruskal[i].first;
    }
    cout<<"Weight of the minimum spanning tree using kruskal's algorithm  : "<<sum<<endl;
    g.prims(0);
    // 7 0 1 2 0 3 6 1 2 3 1 3 8 1 4 5 2 4 7 3 4 9
    return 0;
}
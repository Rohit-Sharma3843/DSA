#include<iostream>
#include<vector>
using namespace std;
void warshall(vector<vector<bool>> matrix){
  // vector<vector<vector<bool>>> ans(matrix.size(),vector<vector<int>> (matrix.size(),vector<int> (matrix.size())));
  bool ans[matrix.size()][matrix.size()][matrix.size()];
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix.size();j++){
      ans[0][i][j]=matrix[i][j];
    }
  }
  for(int k=1;k<matrix.size();k++){
    for(int i=0;i<matrix.size();i++){
      for(int j=0;j<matrix.size();j++){
        ans[k][i][j]=ans[k-1][i][j] |ans[k-1][i][k] & ans[k-1][k][j];
      }
    }
  }
  for(int k=0;k<matrix.size();k++){
    cout<<"W["<<k+1<<"]"<<endl;
    for(int i=0;i<matrix.size();i++){
      for(int j=0;j<matrix.size();j++){
        cout<<ans[k][i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl<<endl;
  }
}
int main(){
  int size;
  cout<<"Enter size : ";
  cin>>size;
  int x;
  vector<vector<bool>> v(size,vector<bool> (size,0));
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cin>>x;
      v[i][j]=x;
    }
  }
  warshall(v);
  // 4 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0
  return 0;
}
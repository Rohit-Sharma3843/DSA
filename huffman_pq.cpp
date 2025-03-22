#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
    public:
    char ch;
    int freq;
    node *left,*right;
    node(char ch,int freq){
        this->ch=ch;
        this->freq=freq;
        this->left=nullptr;
        this->right=nullptr;
    }
};
class comp{
    public:
    bool operator()(node *n1,node *n2){
        if(n1->freq<=n2->freq){
            return 0;
        }
        return 1;
    }
};
node *create(priority_queue<node *,vector<node*> ,comp> &pq){
    node *one=nullptr,*two=nullptr;
    while(pq.size()>1){
        one=pq.top();
        pq.pop();
        two=pq.top();
        pq.pop();
        node *three=new node('&',one->freq+two->freq);
        three->left=one;
        three->right=two;
        pq.push(three);
    }
    return pq.top();
}
void print(node *root,string s){
    if(root->left==nullptr && root->right==nullptr){
        cout<<root->ch<<" "<<s<<endl;
        return;
    }
    print(root->left,s+'0');
    print(root->right,s+'1');
}
int main(){
  char c[] = {'a', 'c', 'e', 'h', 'i'};
  int freq[] = {3, 5, 8, 2, 7};
  priority_queue<node *,vector<node*> ,comp> p;
  node *n=nullptr;
  for(int i=0;i<5;i++){
    n=new node(c[i],freq[i]);
    p.push(n);
  }
  node *root=create(p);
  print(root,"");
  return 0;
}
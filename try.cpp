#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class node_bst2tbt{
    public:
    int data;
    node_bst2tbt *left,*right;
    bool leftchild;
    bool rightchild;
    node_bst2tbt(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
        this->rightchild=1;
        this->leftchild=1;
    }
};
void insert(node_bst2tbt *&root,int num){
    node_bst2tbt *n=new node_bst2tbt(num);
    if(root==nullptr){
        root=n;
        return;
    }
    node_bst2tbt *temp=root;
    while(true){
        if(temp->data>num){
            if(temp->left==nullptr){
                temp->left=n;
                break;
            }
            else{
                temp=temp->left;
            }
        }
        else{
            if(temp->right==nullptr){
                temp->right=n;
                break;
            }
            else{
                temp=temp->right;
            }
        }
    }
}
node_bst2tbt *create(){
    int num;
    node_bst2tbt *root=nullptr;
    while(true){
        cout<<"Enter the number you want to insert in BST or enter -1 to exit : ";
        cin>>num;
        if(num==-1){
            break;
        }
        insert(root,num);
    }
    return root;
}
vector<node_bst2tbt*> get_preorder(node_bst2tbt * root){
    stack<node_bst2tbt*> s;
    node_bst2tbt *temp=root;
    vector<node_bst2tbt*> ans;
    while(!s.empty() || temp!=nullptr){
        while(temp!=nullptr){
            s.push(temp);
            temp=temp->left;
        }
        ans.push_back(s.top());
        temp=s.top()->right;
        s.pop();
    }
    return ans;
}
node_bst2tbt* convert(node_bst2tbt *root,vector<node_bst2tbt*> &pre){
    node_bst2tbt*dummy=new node_bst2tbt(1000);
    dummy->left=root;
    dummy->right=dummy;
    dummy->rightchild=0;
    pre[0]->left=dummy;
    pre[0]->leftchild=0;
    pre[pre.size()-1]->rightchild=0;
    pre[pre.size()-1]->right=dummy;
    for(int i=0;i<pre.size();i++){
        if(pre[i]->left==nullptr){
            pre[i]->left=pre[i-1];
            pre[i]->leftchild=0;
            // cout<<pre[i]->data<<" left "<<pre[i]->left->data<<endl;
        }
        if(pre[i]->right==nullptr){
            pre[i]->right=pre[i+1];
            pre[i]->rightchild=0;
            // cout<<pre[i]->data<<" right "<<pre[i]->right->data<<endl;
        }
    }
    return dummy;
}
void inorder_tbt(node_bst2tbt *dummy){
    if(dummy->left==dummy){
        return;
    }
    node_bst2tbt*temp=dummy->left;
    while(temp!=dummy){
        while(temp->leftchild==1){
            temp=temp->left;
        }
        cout<<temp->data<<" ";
        while(temp->rightchild==0){
            if(temp->right==dummy){
                break;
            }
            temp=temp->right;
            cout<<temp->data<<" ";
        }
        temp=temp->right;
    }
}
int main(){
  node_bst2tbt *root=create();
  vector<node_bst2tbt*> ans=get_preorder(root);
//   for(int i=0;i<ans.size();i++){
//     cout<<ans[i]->data<<" ";
//   }
  node_bst2tbt*dummy=convert(root,ans);
  inorder_tbt(dummy);
  return 0;
}
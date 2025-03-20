#include<iostream>
using namespace std;
class node_tbt{
    public:
    int data;
    node_tbt *left,*right;
    bool leftchild,rightchild;
    node_tbt(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
        this->leftchild=0;
        this->rightchild=0;
    }
};
void insert_tbt(node_tbt * dummy,int num){
    node_tbt *n=new node_tbt(num);
    if(dummy->left==dummy){
        n->left=dummy;
        n->right=dummy;
        dummy->left=n;
        dummy->leftchild=1;
        return;
    }
    node_tbt *temp=dummy->left;
    while(true){
        if(temp->data>num){
            if(temp->leftchild==0){
                n->left=temp->left;
                temp->left=n;
                temp->leftchild=1;
                n->right=temp;
                break;
            }
            else{
                temp=temp->left;
            }
        }
        else{
            if(temp->rightchild==0){
                n->right=temp->right;
                temp->right=n;
                temp->rightchild=1;
                n->left=temp;
                break;
            }
            else{
                temp=temp->right;
            }
        }
    }
}
node_tbt *input(){
    node_tbt*dummy=new node_tbt(1000);
    dummy->left=dummy;
    dummy->right=dummy;
    int num;
    while(true){
        cout<<"Enter the number you want to insert in TBT or enter -1 to exit : ";
        cin>>num;
        if(num==-1){
            break;
        }
        insert_tbt(dummy,num);
    }
    return dummy;
}
void inorder_tbt(node_tbt *dummy){
    if(dummy->left==dummy){
        return;
    }
    cout<<"Inorder traversal of TBT : ";
    node_tbt *temp=dummy->left;
    while(temp!=dummy){
        while(temp->leftchild==1){
            temp=temp->left;
        }
        cout<<temp->data<<" ";
        while(temp->rightchild==0){
            if(temp->right==dummy){break;}
            temp=temp->right;
            cout<<temp->data<<" ";
        }
        temp=temp->right;
    }
}
void print(node_tbt *n){
    cout<<"Data : "<<n->data<<endl;
    cout<<"leftchild : "<<n->leftchild<<endl;
    cout<<"rightchild : "<<n->rightchild<<endl;
}
int main(){
  node_tbt *dummy=input();
  node_tbt *n=dummy->left->right->right;
  cout<<endl;
  print(n);
  print(n->left);
  inorder_tbt(dummy);
  return 0;
  // 50 30 70 60 40 80 20 59 -1
}

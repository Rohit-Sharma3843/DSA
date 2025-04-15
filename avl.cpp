#include<iostream>
using namespace std;
class node{
    public:
    string word,meaning;
    int height;
    node *left,*right;
    node(string word,string meaning){
        this->word=word;
        this->meaning=meaning;
        this->left=nullptr;
        this->right=nullptr;
        this->height=0;
    }
};
int compare(string s1,string s2){
    if(s1==s2){
        return 0;
    }
    else if(s1>s2){
        return 1;
    }
    return -1;
}
int get_height(node *root){
    if(root==nullptr){
        return 0;
    }
    return 1+max(get_height(root->left),get_height(root->right));
}
node *rot_left(node *root){
    node *r=root->right;
    root->right=r->left;
    r->left=root;
    root->height=get_height(root);
    r->height=get_height(r);
    return r;
}
node *rot_right(node *root){
    node *l=root->left;
    root->left=l->right;
    l->right=root;
    root->height=get_height(root);
    l->height=get_height(l);
    return l;
}
int balance(node *root){
    return get_height(root->left)-get_height(root->right);
}
node *insert(node *root,string w,string m){
    if(root==nullptr){
        return new node(w,m);
    }
    else if(compare(w,root->word)!=0){
        if(compare(root->word,w)>0){
            root->left=insert(root->left,w,m);
            if(balance(root)==2 && compare(w,root->left->word)>0){
                root->left=rot_left(root->left);
                root=rot_right(root);
            }
            else if(balance(root)==2 && compare(root->left->word,w)>0){
                root=rot_right(root);
            }
        }
        else if(compare(root->word,w)<0){
            root->right=insert(root->right,w,m);
            if(balance(root)==-2 && compare(w,root->right->word)>0){
                root=rot_left(root);
            }
            else if(balance(root)==-2 && compare(root->right->word,w)>0){
                root->right=rot_right(root->right);
                root=rot_left(root);
            }
        }
    }
    else{
        cout<<"Redundant node."<<endl;
    }
    root->height=get_height(root);
    return root;
}
void inorder(node *root){
    if(root==nullptr){
        return ;
    }
    inorder(root->left);
    cout<<root->word<<"    "<<root->meaning<<"   "<<balance(root)<<endl;
    inorder(root->right);
}
void update(node *root,string w,string m){
    if(root->word==w){
        root->meaning=m;
        return;
    }
    if(compare(w,root->word)){
        update(root->right,w,m);
    }
    else{
        update(root->left,w,m);
    }
}
node *find_min(node *root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}
node *del(node *root,string w){
    if(root==nullptr){
        return nullptr;
    }
    else if(compare(w,root->word)>0){
        root->right=del(root->right,w);
    }
    else if(compare(root->word,w)>0){
        root->left=del(root->left,w);
    }
    else{
        if(root->left==nullptr && root->right==nullptr){
            return nullptr;
        }
        else if(root->left==nullptr){
            node *n=root->right;
            delete root;
            return n;
        }
        else if(root->right==nullptr){
            node *n=root->left;
            delete root;
            return n;
        }
        else{
            node *n=find_min(root->right);
            root->word=n->word;
            root->meaning=n->meaning;
            root->right=del(root->right,n->word);
        }
    }
    root->height=get_height(root);
    if(balance(root)<-1){
            if(balance(root->right)>0){
                root->right=rot_right(root->right);
                root=rot_left(root);
            }
            else if(balance(root->right)<=0){
                root=rot_left(root);
            }
    }
    if(balance(root)>1){
            if(balance(root->left)>=0){
                root=rot_right(root);
            }
            else if(balance(root->left)<0){
                root->left=rot_left(root->left);
                root=rot_right(root);
            }
    }
    return root;
}
int main(){
  node *root=nullptr;
  string w,m;
  int choice;
  while(true){
    cout<<"Enter choice :\n1.Insert Word \n2.Display dictionary\n3.Delete word\n";
    cout<<"4.Update Meaning\n5.Exit\n";
    cin>>choice;
    if(choice==1){
        cout<<"Enter the word you want to insert : ";
        cin>>w;
        cout<<"Enter the meaning of the word "<<w<<" : ";
        cin>>m;
        root=insert(root,w,m);
    }
    else if(choice==2){
        cout<<"Word  "<<"    Meaning    "<<"Balance Factor ";
        inorder(root);
        cout<<"\n";
    }
    else if(choice==3){
        cout<<"Enter the word you want to delete : ";
        cin>>w;
        root=del(root,w);
    }
    else if(choice==4){
        cout<<"Enter the word whose meaning you want to change : ";
        cin>>w;
        cout<<"Enter the updated meaning of the word "<<w<<" : ";
        cin>>m;
        update(root,w,m);
    }
    else{
        return 0;
    }
  }
  return 0;
}
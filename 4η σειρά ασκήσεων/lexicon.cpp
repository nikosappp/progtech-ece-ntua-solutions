#include <iostream>  
#include <string>  
  
using namespace std;  
  
class lexicon{  
    private:  
      
    struct node{  
        string word;  
        node *left, *right;  
        int freq;  
        node(const string &data, node *p, node *q):  
         word(data), left(p), right(q) {  
            freq=1;  
        }  
    };  
    node *root;  
  
    public:  
  
    lexicon(){  
        root=nullptr;  
    }  
  
    ~lexicon(){  
        purge(root);  
    }  
  
    void purge(node *riza){  
        if(riza==nullptr) return;  
        else{  
        purge(riza->left);  
        purge(riza->right);  
        delete riza;  
    }  
    }  
  
    void insert_2(node *t, const string s){  
        if(t->word.compare(s)>0){  
            if(t->left==nullptr){  
                node *new_node=new node(s, nullptr, nullptr);  
                t->left=new_node;  
            }  
            else{  
                insert_2(t->left, s);  
            }  
        }  
  
        else if(t->word.compare(s)<0){  
            if(t->right==nullptr){  
                node *new_node=new node(s, nullptr, nullptr);  
                t->right=new_node;  
            }  
            else{  
                insert_2(t->right, s);  
            }  
        }  
  
        else{  
            t->freq++;  
        }  
    }  
      
    void insert(const string &s){  
        if(root==nullptr){  
            node *new_node=new node(s, nullptr, nullptr);  
            root=new_node;  
        }  
        else{  
            insert_2(root, s);  
        }  
    }  
  
    int lookup(const string &s) const{  
        return lookup_2(root, s);  
    }  
  
    int lookup_2(node *t, const string s) const{  
  
        if(t==nullptr){  
            return 0;  
        }  
  
        if(t->word.compare(s) > 0){  
            return lookup_2(t->left, s);  
        }  
        else if(t->word.compare(s) < 0){  
            return lookup_2(t->right, s);  
        }  
        else{  
            return t->freq;  
        }  
    }  
         
    int depth(const string &s) {    
        return depth_2(root, s, 0);    
    }    
    
int depth_2(node *t, const string &s, int dep) const {  
    if (t == nullptr) {  
        return -1;  
    }  
  
    if (t->word == s) {  
        return dep;  
    }  
  
    if (s < t->word) {  
        ++dep;  
        return depth_2(t->left, s, dep);  
    } else {  
        ++dep;  
        return depth_2(t->right, s, dep);  
    }  
}  
  
  
    void replace(const string &s1, const string &s2){  
          
        if(lookup(s1)==0) return;  
  
        node *ptr1=search(root, s1);  
            int freq1=0;  
            freq1=ptr1->freq;  
  
            node_delete1(s1);   
  
            if(lookup(s2)==0){  
                insert(s2);  
                search(root, s2)->freq=freq1;  
            }  
            else{  
                node *ptr2=search(root, s2);  
                ptr2->freq+=freq1;  
            }  
    }  
  
    node* search(node *t, const string &s){  
  
        if(s.compare(t->word)==0 || t==nullptr){    
            return t;    
        }  
  
        if(t->word.compare(s)>0){    
            return search(t->left,s);   
        }  
  
        else{  
            return search(t->right,s);  
        }    
    }  
  
    void node_delete1(const string &s){  
        root=node_delete2(root, s);  
    }  
  
    node* node_delete2(node* t, const string& s) {  
    if (t == nullptr) {  
        return nullptr;  
    }  
  
    if (s < t->word) {  
        t->left = node_delete2(t->left, s);  
    }   
      
    else if (s > t->word) {  
        t->right = node_delete2(t->right, s);  
    }  
      
    else {  
        if (t->left == nullptr) {  
            node* temp = t->right;  
            delete t;  
            return temp;  
        }  
          
         else if (t->right == nullptr) {  
            node* temp = t->left;  
            delete t;  
            return temp;  
        }   
          
        else {  
            node* min = minNode(t->right);  
            t->word = min->word;  
            t->freq = min->freq;  
            t->right = node_delete2(t->right, min->word);  
        }  
    }  
  
    return t;  
}  
  
node* minNode(node* t) {  
    if (t == nullptr || t->left == nullptr) {  
        return t;  
    }  
    return minNode(t->left);  
}  
  
      
  
    friend ostream & operator << (ostream &out, const lexicon &l){  
        l.inorder(l.root, out);  
        return out;  
    }  
  
    //  void inorder(node *t) const{  
    //      if(t==nullptr) return;  
    //      inorder(t->left);  
    //      cout << t->word << " " << t->freq << endl;  
    //      inorder(t->right);  
    //  }  
  
    void inorder(node *t, ostream &out) const {  
       if (t == nullptr) return;  
         inorder(t->left, out);  
         out << t->word << " " << t->freq << endl;  
         inorder(t->right, out);  
    }  
};  
  
   
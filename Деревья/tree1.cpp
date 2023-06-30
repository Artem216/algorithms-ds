#include<iostream>
#include<vector>
 
 
struct node{
    node(int l, int r){
        left = l;
        right = r;
    };
    int value = 0;
    node *l_child = nullptr, *r_child = nullptr;
    int left = 0, right = 0;
};
 
 
struct tree{
    node *root = nullptr;
    std::vector<int> v;
    tree(std::vector<int>& v){
        this->v = v;
        root = new node(0, v.size());
        build(root);
    }
 
    void build(node* cur_v){
        if(cur_v->left + 1 == cur_v->right){
            cur_v->value = v[cur_v->left];
            return;
        }
        int m = (cur_v->left + cur_v->right) / 2;
        cur_v->l_child = new node(cur_v->left, m);
        cur_v->r_child = new node(m, cur_v->right);
        build(cur_v->l_child);
        build(cur_v->r_child);
        cur_v->value = cur_v->l_child->value + cur_v->r_child->value;
    }
 
    int get(node* cur_v, int q_left, int q_right){
        int left = cur_v->left;
        int right = cur_v->right;
        if(q_left <= left && right <= q_right){
            return cur_v->value;
        }
        else if(right <= q_left || q_right <= left){
            return 0;
        }
        else{
            return get(cur_v->l_child, q_left, q_right) +
            get(cur_v->r_child, q_left, q_right);
        }
    }
    int get(int q_left, int q_right){
        return get(root, q_left, q_right);
    }
    void print(){
        print(root);
    }
    void print(node* n){
        if(n == nullptr) return;
        print(n->l_child);
        std::cout << n->value << " ";
        print(n->r_child);
    }
};
 
int main(){
    std::vector<int> v {1, 2, 3, 2, 1, 6};
    tree new_tree(v);
    std::cout << new_tree.get(0, 4);
    return 0;
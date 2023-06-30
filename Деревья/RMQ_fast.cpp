/*
Реализуйте структуру данных, которая на данном массиве из N целых чисел позволяет узнать
максимальное значение на этом массиве и индекс элемента, на котором достигается это максимальное значение. 

input
5 - N 
7 3 1 6 4 - array
3 - кол-во запросов
1 5 - левая и правая граница отрезка
2 4
3 3

output
7 1 - наибольшее значение и индекс 
6 4
1 3

*/

#include <iostream>
#include <vector>

template <typename T>
struct Node {
    T value = INT32_MIN;
    int l = 0, r = 0;
    int ans = -1;
    Node<T> *l_child = nullptr, *r_child = nullptr;
    Node<T>(const int& l_, const int& r_) 
        : l(l_)
        , r(r_) {}
};

template<typename T>
struct Tree {
    Node<T>* root = nullptr;
    std::vector<T> arr;

    Tree(std::vector<T>& arr) {
        this->arr = arr;
        root = new Node<T>(0, arr.size());
        build(root);
    }

    void build(Node<T>* cur_v) {
        if (cur_v->l + 1 == cur_v->r) {
            cur_v->value = arr[cur_v->l];
            cur_v->ans = cur_v->l+1;
            return;
        }
        int m = (cur_v->l + cur_v->r) / 2;
        cur_v->l_child = new Node<T>(cur_v->l, m);
        cur_v->r_child = new Node<T>(m, cur_v->r);
        build(cur_v->l_child);
        build(cur_v->r_child);
        cur_v->value = std::max(cur_v->l_child->value, cur_v->r_child->value);
        if (cur_v->l_child->value >= cur_v->r_child->value)
            cur_v->ans = cur_v->l_child->ans;
        else 
            cur_v->ans = cur_v->r_child->ans;
    }

    std::pair<T, int> get(Node<T>* cur_v, int q_l, int q_r) {
        int l = cur_v->l;
        int r = cur_v->r;
        if (q_l <= l && r <= q_r) {
            return std::make_pair(cur_v->value, cur_v->ans);
        }
        else if (r <= q_l || q_r <= l) {
            return std::make_pair(INT32_MIN, -1);
        }
        else {
            std::pair<T, int> a = get(cur_v->l_child, q_l, q_r);
            std::pair<T, int> b = get(cur_v->r_child, q_l, q_r);

            if (a.first > b.first) 
                return std::make_pair(a.first, a.second);
            else 
                return std::make_pair(b.first, b.second);
        }
    }

    std::pair<T, int> get(int q_l, int q_r) {
        return get(root, q_l, q_r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::vector<int> arr(n, 0);
    for (int &a : arr) 
        std::cin >> a;
    Tree<int> tr(arr);

    int k = 0;
    std::cin >> k;
    for (size_t i = 0; i < k; ++i) {
        int l = 0, r = 0;
        std::cin >> l >> r;
        l--;
        std::pair<int, int> ans = tr.get(l, r);
        std::cout << ans.first << " " << ans.second << "\n";
    }
}

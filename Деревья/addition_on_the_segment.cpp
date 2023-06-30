/*
Реализуйте эффективную структуру данных для хранения массива и выполнения следующих операций:
увеличение всех элементов данного отрезка на одно и то же число; поиск максимума на отрезке. 

input
5 - N
2 4 3 1 5 - array
5 - кол-во запросов
m 1 3 - найти максимум, левая и правая граница отрезка
a 2 4 100 - увеличить все элементы на отрезке,  левый и правый концы отрезка и число add, на которое нужно увеличить все элементы
m 1 3
a 5 5 10
m 1 5

output
4 104 104 - ответы на запросы

*/
#include <iostream>
#include <vector>
#include <cmath>


struct Vertex {
    long long val = 0;
    long long assign = 0;
};

class Tree {
    public:
    std::vector<Vertex> t;


    void build(const std::vector<long long>& v, const long long& idx, const long long& l, const long long& r) {
        if (l + 1 == r) {
            if (l >= v.size()) return;
            t[idx].val = v[l];
            return;
        }
        long long m = (l + r) / 2;
        build(v, idx*2 + 1, l, m);
        build(v, idx*2 + 2, m, r);
        t[idx].val = std::max(t[2*idx + 1].val, t[2*idx + 2].val);
    }

    long long get_max(const long long& ql, const long long& qr, const long long& idx, const long long& l, const long long& r) {
        if (ql <= l && r <= qr) {
            return t[idx].val;
        }
        else if (r <= ql || qr <= l) {
            return INT64_MIN;
        }
        else {
            long long m = (l + r) / 2;
            return std::max(get_max(ql, qr, 2*idx + 1, l, m), get_max(ql, qr, 2*idx + 2, m, r)) + t[idx].assign;
        }
    }

    void add(const long long& ql, const long long& qr, const long long& a, const long long& idx, const long long& l, const long long& r) {
        if (r <= ql || qr <= l) {
            return;
        }
        if (ql <= l && r <= qr) {
            t[idx].assign += a;
            t[idx].val += a;
        }
        else {
            long long m = (l + r) / 2;
            add(ql, qr, a, 2*idx + 1, l, m);
            add(ql, qr, a, 2*idx + 2, m, r);
            t[idx].val = std::max(t[2*idx+1].val, t[2*idx+2].val) + t[idx].assign;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0, m = 0;
    std::cin >> n;
    std::vector<long long> v(n);
    for (long long &a : v) std::cin >> a;
    Tree tr;
    int pow = std::ceil(std::log2(v.size())) + 1;
    tr.t.resize(size_t(std::pow(2, pow)));
    tr.build(v, 0, 0, tr.t.size()/2);
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        char command;
        std::cin >> command;
        int l = 0, r = 0;
        std::cin >> l >> r;
        if (command == 'm') {
            std::cout << tr.get_max(l-1, r, 0, 0, tr.t.size() / 2) << " ";
        }
        if (command == 'a') {
            int64_t a = 0;
            std::cin >> a;
            tr.add(l-1, r, a, 0, 0, tr.t.size() / 2);
        }
    }
}

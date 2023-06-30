/*
В новых элитных электричках каждому пассажиру положено сидячее место. Естественно, количество сидячих мест ограничено и на всех их может не хватить.
Маршрут электрички проходит через N+1 станция, занумерованные от 0 до N. Когда человек хочет купить билет, он называет два числа x и y – номера станций,
откуда и куда он хочет ехать. При наличии хотя бы одного сидячего места на этом участке на момент покупки ему продается билет, иначе выдается сообщение
«билетов нет» и билет не продается. Ваша задача – написать программу, обслуживающую такого рода запросы в порядке их прихода. 

input
5 2 4 - N – количество станций, K – количество мест в электричке, M – количество запросов
0 4 - запрос
1 2
1 4
2 4

output 
1 - билет был продан
1
0 - билет не продается
1

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

    long long n = 0, k = 0, m = 0;
    std::cin >> n >> k >> m;
    std::vector<long long> v(n+1, 0);
    Tree tr;
    long long p = std::ceil(std::log2(v.size())) + 1;
    tr.t.resize(size_t(std::pow(2, p)));
    tr.build(v, 0, 0, tr.t.size()/2);
    for (long long i = 0; i < m; ++i) {
        long long l = 0, r = 0;
        std::cin >> l >> r;
        long long res = tr.get_max(l, r, 0, 0, tr.t.size() / 2);
        if (res < k) {
            std::cout << "1" << "\n";
            tr.add(l, r, 1, 0, 0, tr.t.size()/2);
        }
        else std::cout << "0" << "\n";
    }
}

/*
Реализуйте эффективную структуру данных, позволяющую изменять элементы массива и
вычислять суммы нескольких подряд идущих элементов. 

input
10 - N
613 263 312 670 216 142 976 355 488 370 - array
10 - кол-во запросов
s 2 7 - вычислить сумму, номера левой и правой границы отрезка
s 4 8 
u 7 969 - обновить значение элемента, номер элемента и его новое значение
u 1 558
s 2 7
u 2 731
s 4 9
s 1 3
u 8 76
u 5 377

output
2579 2359 2572 2840 1601 - результат запросов
*/

#include <iostream>


const long long MAXN = 100000;
const long long INF = INT32_MAX;


class Tree{
    public:
        long long t[4*MAXN];
        
        void build (long long a[], long long v, long long tl, long long tr) {
            if (tl == tr)
                t[v] = a[tl];
            else {
                long long tm = (tl + tr) / 2;
                build (a, v*2, tl, tm);
                build (a, v*2+1, tm+1, tr);
                t[v] = t[v*2] + t[v*2+1];
            }
        }
        
        long long sum (long long v, long long tl, long long tr, long long l, long long r) {
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return t[v];
            long long tm = (tl + tr) / 2;
            return sum (v*2, tl, tm, l, std::min(r,tm)) + sum (v*2+1, tm+1, tr, std::max(l,tm+1), r);
        }
        
        void update (long long v, long long tl, long long tr, long long pos, long long new_val) {
            if (tl == tr)
                t[v] = new_val;
            else {
                long long tm = (tl + tr) / 2;
                if (pos <= tm)
                    update (v*2, tl, tm, pos, new_val);
                else
                    update (v*2+1, tm+1, tr, pos, new_val);
                t[v] = t[v*2]  + t[v*2+1];
            }
        }

        
};


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    long long n = 0;
    std::cin >> n;
    long long arr[n];
    for(long long& el : arr){
        std::cin >> el;
    }
    Tree tree;
    tree.build(arr, 1, 0,n - 1);
    long long q = 0;
    std::cin >> q;
    for(long long i = 0; i < q; ++i){
        char quest;
        long long l = 0, r = 0;
        std::cin >> quest >> l >> r;
        if(quest == 's'){
            l--, r--;
            std::cout << tree.sum(1, 0, n - 1, l, r) << " ";
        }
        if(quest == 'u'){
            l--;
            tree.update(1, 0, n - 1, l, r);
        }

    }


    return 0;
}
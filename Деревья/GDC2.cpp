/*
Реализуйте эффективную структуру данных, позволяющую изменять элементы массивы и
вычислять НОД нескольких подряд идущих элементов.

input
5 - N 
2 8 4 16 12 - array
5 - кол-во запросов
s 1 5 -  вычислить НОД, номера левой и правой границы отрезка
s 4 5
u 3 32 - обновить значение элемента, номер элемента и его новое значение
s 2 5
s 3 3

output
2 4 4 32 - результаты запросов
*/


#include <iostream>
#include <vector>

const int MAXN = 100000;
const int INF = INT32_MAX;

int gcd(int a, int b) {
    return (a == 0) ? b: gcd(b % a, a);
}

class Tree{
    public:
        int t[4*MAXN];
        
        void build (int a[], int v, int tl, int tr) {
            if (tl == tr)
                t[v] = a[tl];
            else {
                int tm = (tl + tr) / 2;
                build (a, v*2, tl, tm);
                build (a, v*2+1, tm+1, tr);
                t[v] = gcd(t[v*2], t[v*2+1]);
            }
        }
        
        int sum (int v, int tl, int tr, int l, int r) {
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return t[v];
            int tm = (tl + tr) / 2;
            return gcd(sum (v*2, tl, tm, l, std::min(r,tm)) , sum (v*2+1, tm+1, tr, std::max(l,tm+1), r));
        }
        
        void update (int v, int tl, int tr, int pos, int new_val) {
            if (tl == tr)
                t[v] = new_val;
            else {
                int tm = (tl + tr) / 2;
                if (pos <= tm)
                    update (v*2, tl, tm, pos, new_val);
                else
                    update (v*2+1, tm+1, tr, pos, new_val);
                t[v] = gcd(t[v*2] , t[v*2+1]);
            }
        }

        
};


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    int arr[n];
    for(int& el : arr){
        std::cin >> el;
    }
    Tree tree;
    tree.build(arr, 1, 0,n - 1);
    int q = 0;
    std::cin >> q;
    for(int i = 0; i < q; ++i){
        char quest;
        int l = 0, r = 0;
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
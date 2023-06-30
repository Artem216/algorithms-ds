/*
Реализуйте структуру данных для эффективного вычисления НОД нескольких подряд идущих элементов массива.

input
5 - N
2 2 2 1 5 - array
2 - кол-во запросов
2 3 - [a..b]
2 5

output
2 1 - НОД всех чисел соответствующего участка массив
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
        int l = 0, r = 0;
        std::cin >> l >> r;
        l--, r--;
        std::cout << tree.sum(1, 0, n - 1, l, r) << " ";
    }


    return 0;
}
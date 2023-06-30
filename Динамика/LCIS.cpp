/*
Даны две последовательности чисел — a и b.
Нужно найти наибольшую общую возрастающую подпоследовательность. 
Более формально: такие 1≤i1<i2<⋯<ik≤a.n и 1≤j1<j2⋯<jk≤b.n, что ∀t:ait=bjt,ait<ait+1 и k максимально. 

input
6 5 - n, m
1 2 1 2 1 3 - первая последовательность
2 1 3 2 1 - вторая последовательность

outut
2 - длинна наибольшей общей возвозрастающей подпоследовательности
*/

#include <vector>
#include <iostream>
int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<int> b(m);
    for(int& el : a) std::cin >> el;
    for(int& el : b) std::cin >> el;
    std::vector<std::vector<int>> d(n + 1, std::vector<int>(m + 1));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int max_ = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                if (d[i - 1][j] <= max_ + 1) {
                    d[i][j] = max_ + 1;                   
                }
            }
            else {
                d[i][j] = d[i - 1][j];
            }
            if (a[i - 1] > b[j - 1] && d[i - 1][j] > max_) {
                max_ = d[i - 1][j];
            }
            ans = std::max(d[i][j], ans);
        }
    }
    std::cout << ans;
}
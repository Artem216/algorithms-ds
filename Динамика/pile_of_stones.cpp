/*
У вас есть несколько камней известного веса w1,…,wn.
Напишите программу, которая распределит камни в две кучи так, что разность весов этих двух куч будет минимальной. 

input 
5 - n
5 8 13 27 14 - wi

output
3 - минимальная разность двух куч
*/
#include <iostream>
#include <vector>
#include <bitset>


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    std::vector<int> w(n);
    for(int& el : w) std::cin >> el;
    int ans = 20 * 100000;
    for (int i = 0; i < (1 << n); ++i)
    {
        std::bitset<21> b = i;
        int s0 = 0;
        int s1 = 0;
        for(int j = 0; j < n; ++j){
            if(b[j] == 0) s0 += w[j];
            else s1 += w[j];
        }
        ans = std::min(ans, abs(s0 - s1));
    }
    std::cout << ans;

    return 0;
}
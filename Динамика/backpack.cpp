/*
Найдите максимальный вес золота, который можно унести в рюкзаке
вместительностью S, если есть N золотых слитков с заданными весами. 

input
10 3 - S, N
1 4 8

output
9 - максимальный вес
*/

#include <iostream>
#include <vector>
#include <bitset>


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::bitset<10001> b = 1;
    for(size_t i = 0; i < m; i++){
        int wi = 0;
        std::cin >> wi;
        b = (b << wi) | b;
    }
    for(int i = n; i >= 0; --i){
        if(b[i] == 1){
            std::cout << i;
            break;
        }
    }
    return 0;
}

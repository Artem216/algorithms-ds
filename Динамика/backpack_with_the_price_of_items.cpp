/*
Дано N предметов массой m1, …, mN и стоимостью c1, …, cN соответственно.
Ими наполняют рюкзак, который выдерживает вес не более M. Какую наибольшую стоимость могут иметь предметы в рюкзаке?

input
4 6 - N, M
2 4 1 2 - mi
7 2 5 1 - ci

output
13 - наибольшая возможная стоимость рюкзака

*/

#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> wm(n);
    for (int i = 0; i < n; i++){
        std::cin >> wm[i].first;
    }
    for (int i = 0; i < n; i++){
        std::cin >> wm[i].second;
    }
    std::vector<std::vector<int>> dp (n + 1, std::vector<int> (m + 1, 0));
    for(int i = 0; i <= n; i++ ){
        for (int j = 0; j <= m; j++){
            if (i == 0 || j == 0) continue;
            else{
                if( wm[i - 1].first > j){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    int prev = dp[i - 1][j];
                    int k = wm[i - 1].second + dp[i - 1][j - wm[i - 1].first];
                    dp[i][j] = std::max(prev, k);
                }
            }
        }
    }
    std::cout << dp[n][m];
    return 0;
}
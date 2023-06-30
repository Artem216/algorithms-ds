/*
Полный ориентированный взвешенный граф задан матрицей смежности.
Постройте матрицу кратчайших путей между его вершинами.
Гарантируется, что в графе нет циклов отрицательного веса.

input
4 - n
0 5 9 100
100 0 2 8
100 100 0 7
4 100 100 0

output
0 5 7 13 
12 0 2 8 
11 16 0 7 
4 9 11 0 

*/


#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int>> g(n, std::vector<int>(n, 0));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int x = 0;
            std::cin >> x;
            g[i][j] = x;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                g[j][k] = std::min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }

    for(auto a : g){
        for(auto b : a){
            std::cout << b << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
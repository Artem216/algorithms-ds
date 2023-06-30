/*
Дан ориентированный взвешенный граф. 
Для него вам необходимо найти кратчайшее расстояние от вершины S до вершины F.

input
3 2 1 - N, S, F
0 1 1
4 0 1
2 1 0

output
3 - искомое кратчайшее расстояние или -1, если пути между указанными вершинами не существует
*/



#include <iostream>
#include <vector>

using namespace std;
int count;

void Dijkstra(const int& n, const int& st, const std::vector<std::vector<int>>& g, const int& f)
{
    bool used[n];
    int D[n];
    for(int i = 0;i < n; i++)
    {
        D[i] = g[st][i];
        used[i] = false;
    }
    D[st] = 0;
    int index = 0,u = 0;
    for (int i = 0;i < n;i++)
    {
        int min = INT32_MAX;
        for (int j = 0;j < n; j++)
        {
            if (!used[j] && D[j]<min)
            {
                min = D[j]; 
                index = j;
            }
        }
        u = index;
        used[u] = true;
        for(int j = 0;j < n;j++)
        {
            if (!used[j] && g[u][j]!=INT32_MAX && D[u] != INT32_MAX && (D[u]+g[u][j]<D[j]))
            {
                D[j] = D[u] + g[u][j];
            }
        }
    }
    if (D[f] == INT32_MAX){
        std::cout << "-1";
    }
    else{
        std:: cout << D[f];
    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n = 0, s = 0, f = 0;
    std::cin >> n >> s >> f;
    std::vector<std::vector<int>> g(n, std::vector<int> (n, 0));
    for(size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++)
        {
            int x = 0;
            std::cin >> x;
            if (x == -1)
                x = INT32_MAX;
            g[i][j] = x;   
        }
    }
    Dijkstra(n, s - 1, g, f - 1);
    return 0; 
}


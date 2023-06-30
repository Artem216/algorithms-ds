/*
Дан ориентированный граф, в котором могут быть кратные ребра и петли.
Каждое ребро имеет вес, выражающийся целым числом (возможно, отрицательным).
Гарантируется, что циклы отрицательного веса отсутствуют.
Требуется посчитать длины кратчайших путей от вершины номер 1 до всех остальных вершин.

input
6 4
1 2 10
2 3 10
1 3 100
4 5 -10

output
0 10 20 30000 30000 30000 

Если пути до соответствующей вершины не существует, вместо длины пути выведите число 30000.
*/


#include <iostream>
#include <vector>


const int INF = 30000;
    
struct edge
{
    int a = 0;
    int b = 0;
    int w = 0;
};



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0, m = 0, v = 0;
    std::vector<edge> g;
    std::cin >> n >> m;
    for (size_t i = 0; i < m; i++)
    {
        edge x;
        std::cin >> x.a >> x.b >> x.w;
        x.a--, x.b--;
        g.push_back(x);
    }
    
    std::vector<int> d (n, INF);
	d[v] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m; ++j)
			if (d[g[j].a] < INF)
				d[g[j].b] = std::min(d[g[j].b], d[g[j].a] + g[j].w);
    
    for(int& el : d){
        std::cout << el << " ";
    }
    return 0;
}
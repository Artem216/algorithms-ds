/*
Дан неориентированный граф. Требуется определить, есть ли в нем цикл, и, если есть, вывести его.

input
3
0 1 1
1 0 1
1 1 0

output
YES
3 - кол-во вершин
3 2 1 - i-я вершина

*/

#include <iostream>
#include <vector>

int n = 0;
std::vector<bool> used;
std::vector<int> l;
std::vector<int> a;
std::vector<std::vector<int>> g;

void dfs(int& v, int& p) {
    used[v] = true;
    l.push_back(v);
    for (int to = 0; to < g[v].size(); ++to) {
        if (!g[v][to]) continue;
        if (used[to]) {
            if (to != p) {
                int i = l.size() - 1;
                while (l[i] != to) {
                    a.push_back(l[i] + 1);
                    --i;
                }
                a.push_back(l[i]+1);
                std::cout << "YES\n" << a.size() << "\n";
                for (int el : a)
                    std::cout << el << " ";
                exit(0);
            }
            continue;
        }
        else {
            dfs(to, v);
        }
        l.erase(l.begin() + l.size() - 1, l.end());
    }
}

int main() {
    std::cin >> n;
    used.resize(n, false);
    g.resize(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int a = 0;
            std::cin >> a;
            g[i].push_back(a);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        else dfs(i, i);
    }
    std::cout << "NO";
}
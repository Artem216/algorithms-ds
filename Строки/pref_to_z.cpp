/*
input
8
0 0 1 0 1 2 3 1

output
0 0 1 0 3 0 1 1

*/

#include <iostream>
#include <vector>


int main(){
    int n = 0, i = 0;
    std::cin >> n;
    std::vector<int> z(n);
    std::vector<int> p(n);
    for(int& el : p){
        std::cin >> el;
    }
    for(int i = 1; i < n; i++)
            if(p[i])
                    z[i - p[i] + 1] = p[i];
    
    z[0] = n;
        
    if(z[1]) 
            for(int i = 1; i < z[1]; i++)
                    z[i + 1] = z[1] - i;
    
    int t;
    for(int i = z[1] + 1; i < n - 1; i++)
    {
            t = i;
            if(z[i] && !z[i + 1])
                    for(int j = 1; j < z[i] && z[i + j] <= z[j]; j++)
                    {
                            z[i + j] = std::min(z[j], z[i] - j);
                            t = i + j;
                    }
            i = t;  
    }
    z[0] = 0;
    for(int& el : z){
        std::cout << el << " ";
    }
    return 0;
}
/*
input
8
0 0 1 0 3 0 1 1

output
0 0 1 0 1 2 3 1
*/

#include <iostream>
#include <vector>


int main(){
    int n = 0, i = 0;
    std::cin >> n;
    std::vector<int> z(n);
    std::vector<int> p(n);
    for(int& el : z){
        std::cin >> el;
    }
    for(int i = 1; i < n; i++){
	    if(z[i]){
		    for(int j = z[i] - 1; j >= 0 && !(p[i + j]); j--)
			    p[i + j] = j + 1;
        }
    }
    for(int& el : p){
        std::cout << el << " ";
    }
    return 0;
}
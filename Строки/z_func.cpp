/*
input
abracadabra

output
11 0 0 1 0 1 0 4 0 0 1 
*/


#include <iostream>
#include <vector>

void z_func(std::string& s){
    int left = 0;
    int right = 0;
    int n = (int)s.length();
    std::vector<int> z(n);
	for (int i = 1; i < n; ++i) {
		if (i <= right)
			z[i] = std::min(right - i + 1, z[i - left]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > right)
			left = i,  right = i + z[i] - 1;
	}
    z[0] = s.length();
    for (int& el : z){
        std::cout << el << " ";
    }
}


int main(){
    std::string s;
    std::cin >> s;
    z_func(s);
}
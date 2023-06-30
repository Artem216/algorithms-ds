/*
Строка S была записана много раз подряд, после чего из получившейся строки взяли подстроку и дали вам.
Ваша задача определить минимально возможную длину исходной строки S. 

input 
bcabcab

output 
3
*/


#include <iostream>
#include <vector>
#include <string>

std::vector<int> z_(const std::string& l){
    int left = 0;
    int right = 0;
    int n = l.length();
    std::vector<int> z(n);
    int max_ = 0;
	for (int i = 1; i < n; ++i) {
		if (i <= right)
			z[i] = std::min(right - i + 1, z[i - left]);
		while (i + z[i] < n && l[z[i]] == l[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > right)
			left = i,  right = i + z[i] - 1;
	}
    z[0] = l.length();
    return z;
}
int main(){
    std::string s;
    std::cin >> s;
    std::vector<int> z = z_(s);
    int ans = -1;
    for (int i = 1; i < z.size(); ++i) {
        if (z[0] - z[i] == i) {
            ans = i;
            break;
        }
    }
    if (ans == -1) 
        std::cout << s.length();
    else 
        std::cout << ans;
}

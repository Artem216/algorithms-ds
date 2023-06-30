/*
input
abracadabra

output
0 0 0 1 0 1 0 1 2 3 4
*/


#include <iostream>
#include <vector>

std::vector<int> prefix_function (std::string s) 
{
    int n =  s.length();
    std::vector<int> pi(n); 
    for (int i=1; i<n; ++i) 
    {
        int j = pi[i-1]; 
        while ((j > 0) && (s[i] != s[j])) 
            j = pi[j-1];   

        if (s[i] == s[j]) 
            ++j; 
        pi[i] = j;
     }
     return pi;
} 


int main(){
    std::string s;
    std::cin >> s;
    std::vector<int> ans = prefix_function(s);
    for(int& el : ans){ 
        std::cout << el << " ";
    }
    return 0;
}
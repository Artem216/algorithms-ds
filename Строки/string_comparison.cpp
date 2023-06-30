/* 
input 
trololo - строка
3 - кол-во запросов
1 7 1 7 - [a..b] [c..d] 
3 5 5 7
1 1 1 5

output
Yes
Yes 
No
*/ 

#include <iostream>
#include <vector>

const uint64_t k = 991, mod = 1e9+7; 
const uint64_t maxn = 1e5+5;

void search_(const std::vector<uint64_t>& h,const std::string& s,const std::vector<uint64_t>& p){
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2){
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    uint64_t h_first = (mod + h[y1] - h[x1 - 1]) * p[x2 - x1] % mod;
    uint64_t h_second = (mod + h[y2] - h[x2 - 1]) % mod;
    if (h_first == h_second) 
        std::cout << "Yes" << "\n";
    else
        std::cout << "No" << "\n";
    }


int main(){
    std::string s;
    uint64_t n = 0;
    std::cin >> s >> n;
    std::vector<uint64_t> h(s.length() + 1, 0);
    std::vector<uint64_t> p(maxn, 1);
    for (uint64_t i = 0; i < s.length(); ++i)
        p[i + 1] = (1ll * p[i] * k) % mod;
    for (uint64_t i = 0; i < s.length(); ++i)
        h[i + 1] = (h[i] + p[i] * s[i]) % mod;
    for(uint64_t i = 0; i < n; ++i){
        search_(h, s, p);
    }
    return 0;
}
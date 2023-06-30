#include <iostream>
#include <vector>


int partition(std::vector<int>& arr,const int& left,const int& right){
    int v = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (arr[i] < v)
        {
            i++;
        }
        while (arr[j] > v)
        {
            j--;
        }
        if(i >= j){
            break;
        }
        std::swap(arr[i++], arr[j--]);
    }
    return j;
}


void q_sort(std::vector<int>& arr,const int& left,const int& right){
    if(left < right){
        int q = partition(arr, left, right);
        q_sort(arr, left, q);
        q_sort(arr, q + 1, right);
    }
}


int main(){
    int n = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int& el : arr){
        std::cin >> el;
    }
    q_sort(arr, 0, n - 1);
    for(int& el : arr){
        std::cout << el << " ";
    }
    return 0;
}
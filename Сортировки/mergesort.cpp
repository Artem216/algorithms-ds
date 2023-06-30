#include <iostream>
#include <vector>


void merge(std::vector<int>& arr, int& left, int& mid, int& right){
    int it1 = 0, it2 = 0;
    std::vector<int>result(right - left);
    while ((left + it1) < mid && (mid + it2) < right)
    {
        if (arr[left + it1] < arr[mid + it2]){
            result[it1 + it2] = arr[left + it1];
            it1 += 1;
        }
        else{
            result[it1 + it2] = arr[mid + it2];
            it2 += 1;
        }
    }
    while ((left + it1) < mid){
        result[it1 + it2] = arr[left + it1];
        it1 += 1;
    }
    while ((mid + it2) < right){
        result[it1 + it2] = arr[mid + it2];
        it2 += 1;
    }
    for (int i = 0; i < (it1 + it2); i++)
        arr[left + i] = result[i];
}
void mergeSort(std::vector<int>& arr, int& left, int& right){
    if(left + 1 >= right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}


int main(){
    int n = 0, left = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int& el : arr){
        std::cin >> el;
    }
    mergeSort(arr, left, n);
    for(int& el : arr){
        std::cout << el << " ";
    }
    return 0;
}
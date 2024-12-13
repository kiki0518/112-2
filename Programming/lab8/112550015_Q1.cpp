#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    //TO-DO
    
    vector<int> L;
    vector<int> R;/*
    copy(arr.begin() + l, arr.begin() + m + 1, back_inserter(L));  
    copy(arr.begin() + m + 1, arr.begin() + r + 1, back_inserter(R)); */
    /*vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);*/

    for(int i = l; i <= m; i++)
        L.push_back(arr[i]);
    for(int i = m+1; i <= r; i++) 
        R.push_back(arr[i]);

    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (L[i] < R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < L.size()) {
        arr[k++] = L[i++];
    }

    while (j < R.size()) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    //TO-DO
    if(r > l) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //TO-DO
    mergeSort(arr, 0, n-1);

    for(int num : arr){
        cout << num << " ";
    }
    return 0;
}
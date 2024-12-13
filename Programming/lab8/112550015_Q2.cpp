#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int> >& universe, int i, int j, int& area){
    //Hint : Use DFS here to calculate the area of every planet.
    int m = universe.size();
    int n = universe[0].size();

    if(i < 0 || i >= m || j < 0 || j >= n) return;

    if(universe[i][j]) {
        universe[i][j] = 0;
        area++;
        dfs(universe, i-1, j, area);
        dfs(universe, i+1, j, area);
        dfs(universe, i, j-1, area);
        dfs(universe, i, j+1, area);
    }
    return;
}


int partition(vector<int>& arr, int p, int q) {
    // TODO
    int pivot = arr[q];
    int i = p - 1;
    for (int j = p; j < q; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[q]);
    return i + 1;
}


void quickSort(vector<int>& arr, int p, int q) {
    //TO-DO
    if(p < q) {
        int r = partition(arr, p, q);
        quickSort(arr, p, r-1);
        quickSort(arr, r+1, q);
    }

}

int main(){
    int m, n; //m,n represent the size of the universe.
    int res = 0; //res is the number of planets in the universe.
    vector<int> collectingArea; //collectingArea is used to collect the area of every planet.
    cin >> m >> n;
    vector<vector<int> > universe(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> universe[i][j];
        }
    }
    
  	//TO-DO
    // calculate the area of every planet.
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int area = 0;
            dfs(universe, i, j, area);
            if(area) collectingArea.push_back(area);
        }
    }
    res = collectingArea.size();

    //TO-DO : Use the quickSort function you wrote to sort the vector collectingArea.
    quickSort(collectingArea, 0, res-1);
    

    cout << "The total number of planets is : " << res << endl;
    cout << "The areas of the planets in non-decreasing order are : ";
    for(int area : collectingArea){
        cout << area << " ";
    }
}
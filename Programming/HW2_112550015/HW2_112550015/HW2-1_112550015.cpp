#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > relations(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> relations[i][0] >> relations[i][1];
    }

    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    vector<int> finish_time(n, -1);
    vector<int> inDegree(n, 0);
    vector<vector<int> > adj(n);
    queue<int> q;
    
    for(int i = 0; i < m; i++) {
       inDegree[relations[i][1]-1]++;
       adj[relations[i][0]-1].push_back(relations[i][1]-1);
    }

    for (int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            finish_time[i] = time[i];
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            finish_time[v] = max(finish_time[v], time[v] + finish_time[u]);
            if(--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    int ret = *max_element(finish_time.begin(), finish_time.end());
    cout << ret;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> tree[n];
    int pho[m];
    bool isPho[n] = {0};
    int edgeList[n] = {0};
    int edges = n - 1;

    for(int i = 0; i < m; i++){
        cin >> pho[i];
        isPho[pho[i]] = 1;
    }
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
        edgeList[x]++;
        edgeList[y]++;
    }

    bool minTree = 0;
    while(!minTree){
        minTree = 1;
        for(int i = 0; i < n; i++){
            if(!isPho[i] && edgeList[i] == 1){
                edgeList[i] = 0;
                for(auto j : tree[i]){
                    edgeList[j]--;
                }
                edges--;
                minTree = 0;
            }
        }
    }

    int s = pho[0];
    bool visited[n] = {0};
    stack<int> q;
    int dist[n] = {0};
    q.push(s);
    visited[s] = 1;
    int maxd = 0;
    int maxi = 0;

    while(!q.empty()){
        s = q.top();
        q.pop();
        for(auto i : tree[s]){
            if(!visited[i] && edgeList[i] > 0){
                q.push(i);
                visited[i] = 1;
                dist[i] = dist[s] + 1;
                if(maxd < dist[i]){
                    maxi = i;
                    maxd = dist[i];
                }
            }
        }
    }
    s = maxi;
    for(int i = 0; i < n; i++){
        visited[i] = 0;
        dist[i] = 0;
    }
    q.push(s);
    visited[s] = 1;
    maxd = 0;
    while(!q.empty()){
        s = q.top();
        q.pop();
        for(auto i : tree[s]){
            if(!visited[i] && edgeList[i] > 0){
                q.push(i);
                visited[i] = 1;
                dist[i] = dist[s] + 1;
                maxd = max(maxd, dist[i]);
            }
        }
    }
    cout << edges * 2 - maxd << endl;
}
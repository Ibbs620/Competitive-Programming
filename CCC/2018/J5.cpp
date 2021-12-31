#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    
    int n,m,l;
    int s = 1;
    int p = 0;
    bool minf = false;
    char r = 'Y';
    vector<vector<int>> pageLink = {{0}};
    
    //INPUT
    cin >> n;
    pageLink.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> m;
        if(m == 0) {
            pageLink[i].push_back(0);
        }
        for(int j = 0; j < m; j++){
            cin >> l;
            pageLink[i].push_back(l);
        }
    }
    
    //Set up queue and mark all nodes as unvisited
    queue<int> q;
    vector<bool> visited;
    for(int i = 0; i < n; i++){
        visited.push_back(false);
    }
    q.push(s);
    visited[0] = true;
    visited[s] = true;
    int qs = q.size();
    int it = 0;
    
    //BFS of pageLink
    while(!q.empty()){
        s = q.front();
        it++;
        
        //Check if shortest path was found
        if(it == qs && !minf){
            p++;
            qs = q.size();
            it = 0;
        }
        
        q.pop();
        if(pageLink[s].empty()){
            continue;
        }
        for(int i = 0; i < pageLink[s].size(); i++){
            if(pageLink[s][0] == 0){
                minf = true;
            }
            if(!visited[pageLink[s][i]]){
                q.push(pageLink[s][i]);
                visited[pageLink[s][i]] = true;
            }
        }
    }
    
    //Check for unvisited nodes
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            r = 'N';
            break;
        }
    }
    
    //OUTPUT
    cout << r << "\n" << p;
    
}
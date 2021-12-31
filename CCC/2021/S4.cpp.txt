//NOTE: This solution is incomplete. Only 4/15 points were achieved.

#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, w, d;
   cin >> n >> w >> d;
   vector<int> walk[n+1];
   for(int i = 0; i < w; i++){
        int a, b;
        cin >> a >> b;
        walk[a].push_back(b);
   }
   int subway[n+1];
   int next[n+1];
   int prev = 0;
   for(int i = 1; i <= n; i++) {
        cin >> subway[i];
        next[prev] = subway[i];
        prev = subway[i];
   }
   next[prev] = 0;
   for(int i = 0; i < d; i++){
       int a, b;
       cin >> a >> b;

       int temp = subway[a];
       subway[a] = subway[b];
       subway[b] = temp;

       if(a < n) next[subway[a]] = subway[a+1];
       else next[subway[a]] = 0;
       next[subway[a-1]] = subway[a];
       if(b < n) next[subway[b]] = subway[b+1];
       else next[subway[b]] = 0;
       next[subway[b-1]] = subway[b];

       int station = 0;
       bool vis[n+1];
       bool viss[n+1];
       int dist[n+1];
       for(int i = 0; i <= n; i++){
           vis[i] = false;
           viss[i] = false;
           dist[i] = 0;
       }
       queue<int> q;

       q.push(1);
       vis[1] = true;

       while(!q.empty()){
            int s = q.front(); q.pop();
            if(station <= n){
                station = dist[s] + 1;
                viss[station] = true;
            }
            for(auto u : walk[s]){
                if(vis[u]) continue;
                vis[u] = true;
                dist[u] = dist[s] + 1;
                q.push(u);
                if(u == n) goto print;
            }
            if(station > n) continue;
            if(!viss[station]) continue;
            int u = next[s];
            if(!vis[u] && u != 0 && subway[station] == s){
                q.push(u);
                vis[u] = true;
                dist[u] = dist[s] + 1;
                if(u == n) break;
            } else {
                dist[s]++;
                q.push(s);
            }
       }
       print:;
       cout << dist[n] << endl;
   }
}
//NOTE: This solution is incomplete. Only 2/15 points were achieved.

#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, pair<int,int>> link;
map<pair<int,int>, int> size;

pair<int, int> find(pair<int,int> x){
    while(x != link[x]) x = link[x];
    return x;
}

bool same(pair<int, int> a, pair<int, int> b){
    return find(a) == find(b);
}

void unite(pair<int, int> a, pair<int, int> b){
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

int main(){
    int n, m, p, q;
    int initialWeight = 0, finalWeight = 0;
    cin >> n >> m >> p >> q;
    vector<tuple<int, pair<int,int>, pair<int,int>>> edges;
    vector<tuple<int, pair<int,int>, pair<int,int>>> spanningTree;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            link[make_pair(i, j)] = make_pair(i, j);
            size[make_pair(i, j)] = 1;
        }
    }

    for(int i = 0; i < p; i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = 1; j <= n; j++) {
            edges.push_back(make_tuple(c, make_pair(j, a), make_pair(j, b)));
        }
        initialWeight += c * n;
    }

    for(int i = 0; i < q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        for(int j = 1; j <= m; j++) {
            edges.push_back(make_tuple(z, make_pair(x, j), make_pair(y, j)));
        }
        initialWeight += z * m;
    }

    sort(edges.begin(), edges.end());

    for(auto e: edges){
        auto a = get<1>(e);
        auto b = get<2>(e);
        if(!same(a,b)){
            unite(a,b);
            spanningTree.push_back(e);
            finalWeight += get<0>(e);
        }
    }
    cout << initialWeight - finalWeight;
}
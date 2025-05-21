#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define pb push_back
void solve(int src, vector<vector<pii>> &adj, vector<int> &dist) {
  int n = adj.size();
  dist.assign(n, INT_MAX);
  priority_queue<pii, vector<pii>, greater<>> pq;
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    int u = pq.top().second;
    int w = pq.top().first;
    pq.pop();
    if (w > dist[u]) continue;
    for (auto&i : adj[u]) {
        int v = i.first;
        int vW = i.second;
      if (dist[u] + vW < dist[v]) {
        dist[v] = dist[u] + vW;
        pq.push({dist[v], v});
      }
    }
  }
}
int main() {
  int n = 5;
  vector<vector<pii>> adj(n);
  adj[0].pb({1, 2});adj[0].pb({2, 4});adj[1].pb({2, 1}); adj[1].pb({3, 7});
  adj[2].pb({4, 3});adj[3].pb({4, 1});adj[1].pb({0, 2}); adj[2].pb({0, 4});
  adj[2].pb({1, 1});adj[3].pb({1, 7});adj[4].pb({2, 3}); adj[4].pb({3, 1});
  vector<int> dist;
  int src = 0;
  solve(src, adj, dist);
  cout << "Shortest distances "<<endl;
  for (int i = 0; i < n; i++) {
    cout<< i << "-> " << dist[i] << endl;
  }
  return 0;
}

// author : Anuj Maurya
// created on : [2021-07-18 17:33]	

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+3;
#define int long long int
const int inf = 1e18;
vector<vector<pair<int,int>>> adj(N, vector<pair<int,int>>());
vector<int> dist(N, inf);
void dijkstra() {
	dist[1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, 1});
	while(!pq.empty()) {
		int d = pq.top().first; // distance
		int u = pq.top().second; // vertex
		pq.pop();
		if(dist[u] < d)
			continue;
		for(auto e : adj[u]) {
			int c = e.first; // distance
			int v = e.second; // vertex
			if(dist[v] <= c+d) 
				continue;
			else {
				dist[v] = c+d;
				pq.push({dist[v], v});	
			}
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({w, b}); // directed graph
	}
	dijkstra();
	for(int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> parent(N);
int n, m;

void bfs() {
	visited[1] = true;
	parent[1] = -1;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		for(auto i : adj[curr]) {
			if(!visited[i]) {
				visited[i] = true;
				q.push(i);
				parent[i] = curr;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs();
	int curr = n;
	stack<int> st;
	bool ok = false;
	int count = 0;
	while(curr != -1) {
		st.push(curr);
		curr = parent[curr];
		count++;
		if(count > n)
			break;
		if(curr == -1)
			ok = true;
	}
	if(ok) {
		cout << st.size() << '\n';
		while(!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
	} else {
		puts("IMPOSSIBLE");
	}
}
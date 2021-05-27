#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
using namespace std;
#define ff                 first
#define ss                 second
#define endl               "\n"
#define ll                 long long
#define ld                 long double
#define loop(a, b, c)      for(ll (a) = (b); (a)<=(c); (a)++)
#define looprev(a, b, c)   for(ll (a) = (b); (a)>=(c); (a)--)
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define mii                map<ll, ll>
#define pqb                priority_queue<ll>
#define pqs                priority_queue<int, vi, greater<ll> >
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(t)               int x; cin>>x; while(x--)
/*mt19937                    rng(chrono::steady_clock::now,time_since_epoch(),count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
*/
    
void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

ll Get(vector<ll>&parent, ll a){

	return parent[a]=(parent[a]  == a ? a : Get(parent, parent[a]));

}

void Union(vi &parent, vi &rank, ll a, ll b){

	a=Get(parent, a);
	b=Get(parent, b);
	if(rank[a]==rank[b]){
		rank[a]++;
	}
	if(rank[a] > rank[b]){
		parent[b] = a;
	}else{
		parent[a] = b;
	}
}

int main(int argc, char const *argv[])
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	int n,m;
	cin>>n>>m;
	vi parent(n+1);
	vi rank(n+1, 0);
	for(int i=0; i<n; i++){
		parent[i]=i;
	}
	while(m--){
		string str;
		cin>> str;
		if(str == "union"){
			int x, y;
			cin>>x>>y;
			Union(parent, rank, x, y);
		}
		else{
			int x;
			cin>>x;
			cout<<Get(parent, x)<<endl;
		}
	}

	return 0;
}
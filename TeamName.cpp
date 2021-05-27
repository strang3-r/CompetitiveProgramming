#include <bits/stdc++.h>
using namespace std;

int noOfComonElems(auto &coll1, auto &coll2){
	vector<char>coll3(min(coll1.size(),coll2.size()));
	auto itlast = set_intersection(begin(coll1),end(coll1),begin(coll2),end(coll2),begin(coll3),end(coll3));
	return (itlast - begin(coll3));
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    string arr[n];
	    for(int i=0; i<n; i++){
	    	cin>>arr[i];
	    }
	    map<string, set<char>> mp;
	    for(auto i: arr){
	    	mp[i.substr(1)].insert(i[10]);
	    }
	    int ans = 0;
	    for(auto pairi: mp){
	    	for(auto pairj: mp){
	    		if(pairi != pairj){
	    			int common = noOfComonElems(pairi.second, pairj.second);
	    			ans+=(pairi.second.size() - common)*(pairj.second.size()-common);
	    		}
	    	}
	    }
	    cout<<ans<<endl;
	   } 
	return 0;
}
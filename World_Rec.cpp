// World_Rec.cpp
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		float k1,k2,k3,v;
		cin>>k1>>k2>>k3>>v;
		float w_rec = 9.58,time;
		time = (k1*k2*k3*v);
		time = 100/time;
		time = (int)(time*100+.5);
		time = time/100;
		if(w_rec > time) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
		
	}
	return 0;
}
//by Dhruv Kothari
#include <iostream>
#include <vector>
using namespace std;
int g[1000];
char c[1000];
int n;
vector <int> positions;
int liars(int pos){ //returns liars when bessie is located at pos
	int l=0;
	for(int i=0;i<n;i++){
		if(c[i]=='G'){
			if(g[i]>pos)l++;
		}
		else{
			if(g[i]<pos)l++;
		}
	}
	return l;
}
int main(){
	// this runs at O(n^2)
	cin>>n;
	int ans=n-1;
	for(int i=0;i<n;i++){
		cin>>c[i]>>g[i];
		positions.push_back(g[i]);
		positions.push_back(g[i]-1);
		positions.push_back(g[i]+1);
	}
	for(int i=0;i<positions.size();i++){
		ans=min(ans, liars(positions.at(i))); // update ans!
	}
	cout<<ans;
}

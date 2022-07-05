//by Dhruv Kothari
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	string convert;
	for(int i=0;i<n/2;i++){
		if(s.substr(i*2,2)=="GH"){convert = convert + "B";}
		if(s.substr(i*2,2)=="HG"){convert = convert + "A";}
	}
	s = convert;
	n = s.size();
	int amt = 0;
	//lets use the same strategy for mad scientist now: counting the times A toggles to B ( and vice versa)
	for(int i=0;i<n;i++){
		n = s.size();
		if(i>n)break;
		int start = i;
		int length = 1;
		while(i<n&&s[i]==s[start]){i++;}
		i--;
		amt++;
	}
	//notice how if it ends with A, it won't count as we wouldn't need to reverse it, (so minus 1)...
	if(s[n-1]=='A')amt--;
	cout<<amt<<endl;
} 

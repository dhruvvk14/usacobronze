//by Dhruv Kothari
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	long long c[n];
	for(int i = 0; i < n; i++)cin>>c[i];
	long long ans = 0;
	long long priceAns = 0;
	sort(c, c + n);
	for(int i = 0; i < n; i++){
		long long price = c[i];
		long long cowsToPay = n - i;
		long long cur = (long long) price * cowsToPay;
		if(ans < cur){
			ans = cur;
			priceAns = price;
		}
	}
	cout<<ans<<" "<<priceAns<<endl;
}

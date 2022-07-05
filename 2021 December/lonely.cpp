//by Dhruv Kothari
//Note: This code does NOT solve testcase 11...
#include <iostream>
using namespace std;
int main(){
    int n;
    string order;
    cin>>n>>order;
    int prev = -1;
    int cur = -1;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int g = 0, h = 0;
        for(int j = i; j < n; j++){
            if(order[j]=='G')g++;
            else h++;
            if(j - i >= 2){
                if(g == 1 && h > 1){ans++;} //valid
                else if(h == 1 && g > 1){ans++;} //valid
            }
        }
    }
    cout<<ans<<endl;
}
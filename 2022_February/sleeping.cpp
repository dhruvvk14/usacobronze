#include <iostream>
using namespace std;
void solve(int n, int arr[]){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    for(int p = n; p >= 1; p--){
        if(sum % p != 0){
            continue;
        }
        int cur = 0;
        bool work = true;
        for(int i = 0; i < n; i++){
            cur += arr[i];
            if(cur == sum/p){
                //partition works
                cur = 0;
            }
            else if(cur > sum/p){
                // no work
                work = false;
                break;
            }
        }
        if(work){
            cout<<(n - p)<<"\n"; //amount of operations done!
            return ;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t){
        t--;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        //input
        solve(n, arr);
    }
}

//by Dhruv Kothari
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, k;
int t;
string pref;
void solve(){
    cin>>n>>k>>pref;
    int ans = 0;
    char ansGrid[n];
    bool satisfied[n];
    for(int i = 0; i < n; i++)ansGrid[i] = '.', satisfied[i] = 0;
    for(int i = 0; i < n; i++){
        if(satisfied[i])continue;
        int pos = min(i + k, n - 1);
        if(pos == n - 1 && ansGrid[pos] != '.')pos--;
        ansGrid[pos] = pref[i];
        for(int j = i; j <= pos && j < n; j++){
            if(pref[j] == pref[i])satisfied[j] = 1;
        }
        for(int j = pos; j <= pos + k && j < n; j++){
            if(pref[j] == pref[i])satisfied[j] = 1;
        }
        ans++;
    }cout<<ans<<endl;    
    for(char c : ansGrid)cout<<c;
    cout<<endl;
}
int main(){
    cin>>t;
    while(t--)solve();
}

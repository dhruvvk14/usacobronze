//by Dhruv Kothari
#include <iostream>
#include <algorithm>
using namespace std;
int solve(){
    string s;
    cin>>s;
    if(s.size() < 3)return -1;
    int n = s.size();
    int minOperations = (int) 1e9 + 1;
    for(int i = 0; i <= n - 3; i++){
        if(s.substr(i, 3) == "MOO"){
            return n - 3;
        }
    }
    for(int i = 0; i <= n - 3; i++){
        string cur = s.substr(i, 3);
        int curOperations = n - 3;
        if(cur[1] == 'O'){
            if(cur[0] == 'O')curOperations++;
            if(cur[2] == 'M')curOperations++;
            minOperations = min(minOperations, curOperations);
        }
    }
    if(minOperations == (int) 1e9 + 1)return -1;
    return minOperations;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    while(q--){
        cout<<solve()<<endl;
    }
}

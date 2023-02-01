//by Dhruv Kothari
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int minCost = (int) 1e9 + 1;
int n, m;
vector <pair <int, int> > cowRange;
vector <int> c;
vector <pair <int, int > > range;
vector <int> money;
vector <int> coolBy;
void recurse(string cur){
    if(cur.size() == m){
        int tot = 0;
        int grid[101] = {0};
        for(int i = 0; i < m; i++){
            if(cur[i] == '0')continue;
            tot = tot + money[i];
            int start = range[i].first, end = range[i].second;
            for(int j = start; j <= end; j++){
                grid[j] += coolBy[i];
            }
        }
        for(int i = 0; i < n; i++){
            int start = cowRange[i].first, end = cowRange[i].second;
            for(int j =  start; j <= end; j++){
                if(grid[j] < c[i])return;
            }
        }
        minCost = min(minCost, tot);
        return;
    }
    recurse(cur + "0");//0 denotes not using
    recurse(cur + "1");//1 denotes using it...
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cowRange.resize(n), c.resize(n);
    range.resize(m);
    money.resize(m);
    coolBy.resize(m);
    for(int i = 0; i < n; i++)cin>>cowRange[i].first>>cowRange[i].second>>c[i];
    for(int i = 0; i < m; i++){
        cin>>range[i].first>>range[i].second>>coolBy[i]>>money[i];
    }
    recurse("");
    cout<<minCost<<endl;
}

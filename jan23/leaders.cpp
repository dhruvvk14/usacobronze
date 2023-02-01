//by Dhruv Kothari
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
string breed;
int n;
ll ans = 0;
ll g = 0, h = 0;
int gMax = 0, hMax = 0;
int firstG = -1, firstH = -1;
vector < pair < int, int> > ranges;
vector <bool> leader;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>breed;
    ranges.resize(n);
    leader.resize(n + 1);
    for(int i = 0; i <= n; i++)leader[i] = 0;
    for(int i = 0; i < n; i++)cin>>ranges[i].second, ranges[i].first = i + 1;
    for(int i = 0; i < n; i++){
        if(breed[i] == 'G')gMax = i;
        else hMax = i;
        if(firstG == -1 && breed[i] == 'G')firstG = i;
        if(firstH == -1 && breed[i] == 'H')firstH = i;
    }
    if(firstG != -1 && ranges[firstG].second >= gMax)g++, leader[firstG] = 1;
    if(firstH != -1 && ranges[firstH].second >= hMax)h++, leader[firstH] = 1;
    firstH++, firstG++; //need to account for 1 indexing
    for(int i = 0; i < n; i++){
        if(leader[i])continue;
        if(breed[i] == 'G'){
            if(h == 1 && ranges[i].first <= firstH && firstH <= ranges[i].second){
                ans++;
                //h == 1 means that first H is a leader!
                //check if firstH is in range..
            }
        }
        else if(breed[i] == 'H'){
            if(g == 1 && ranges[i].first <= firstG && firstG <= ranges[i].second){
                ans++;
                //g == 1 means that first G is a leader!
                //check if firstG is in range...
            }
        }
    }cout<<ans + (ll)g * h<<endl;
}

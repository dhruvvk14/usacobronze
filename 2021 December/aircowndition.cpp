//by Dhruv Kothari
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int n, z;
vector<int> desired, current, d;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){cin>>z; desired.push_back(z);}
    for(int i=0;i<n;i++){cin>>z; current.push_back(z);
    d.push_back(desired[i]-current[i]); // difference vector
    }
    ll ans=0;
    while(!d.empty()){ // lets do a greedy approach
    // lets check for a contiguous range of only pos or neg...
    // then get the minimum of the range, and update all the values of -minimum
    //Then answer += abs(minimum)
        n = d.size();
        if(d[0]==0){d.erase(d.begin()); continue;}
        bool pos=d[0]>0;
        int i=0;
        int update_by=d[0];
        if(!pos){
            for(i=0;i<n;i++){
                if((d[0]<0)!=(d[i]<0)||d[i]==0){break;}
                update_by = max(update_by, d[i]);
            }
        }
        else{
            for(i=0;i<n;i++){
                if((d[0]>0)!=(d[i]>0)||d[i]==0){break;}
                update_by=min(update_by, d[i]);
            }
        }
        for(int a=0;a<i;a++){
            d[a]=d[a]-update_by;
        }
        ans = ans + abs(update_by);
    }
    cout<<ans<<endl;
}

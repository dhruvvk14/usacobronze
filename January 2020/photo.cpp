#include <fstream>
#include <set>
using namespace std;
ifstream cin ("photo.in");
ofstream cout("photo.out");
int main(){
    int n;
    cin>>n;
    int sum[n - 1];
    for(int i = 0; i < n - 1; i++)cin>>sum[i];
    for(int start = 1; start <= sum[0] - 1; start++){
        //bool used[n + 1] = {0};
        int ansArr[n];
        ansArr[0] = start;
        for(int i = 1; i < n; i++){
            ansArr[i] = sum[i - 1] - ansArr[i - 1];
        }
        bool valid = 1;
        set <int> all;
        for(int i = 0; i < n; i++){all.insert(ansArr[i]);
            if(ansArr[i] <= 0)valid = 0;
        }
        if(all.size() != n)valid = 0;
        if(!valid)continue;
        for(int i = 0; i < n; i++){
            if(i == n - 1){
                cout<<ansArr[i]; return 0;
            }
            cout<<ansArr[i]<<" ";
        }
    }
}
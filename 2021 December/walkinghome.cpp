//by Dhruv Kothari
#include <iostream>
#include <set>
using namespace std;
set<string> paths;
int n, k;
//lets denote an inverse path as the opposite of a path
// D is down , R is right
// the inverse of DDRR is RRDD
void step_1(){ // k == 1
    string s=""; // we can only do D for n-1 times and R for n-1 times
    for(int i=0;i<n-1;i++){s=s+"D";} // or DDRR and RRDD for n = 3
    for(int i=0;i<n-1;i++){s=s+"R";}
    paths.insert(s);
}
void step_2(){ // k == 2
    for(int d=0;d<n-1;d++){
        string s="";
        int more_down= (n-1) - d;
        for(int i=0;i<d;i++) s = s + "D";
        for(int i=0;i<n-1;i++) s = s + "R";
        for(int i=0;i<more_down;i++) s = s + "D";
        paths.insert(s);
    }
}   
void step_3(){ // k == 3
    for(int d=0;d<n-1;d++){
        for(int r=0;r<n-1;r++){
            string s ="";
            int more_down=(n-1)-d;
            int more_right=(n-1)-r;
            for(int i=0;i<d;i++) s = s + "D";
            for(int i=0;i<r;i++) s = s + "R";
            for(int i=0;i<more_down;i++) s=s+"D";
            for(int i=0;i<more_right;i++)s=s+"R";
            paths.insert(s);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        paths.clear();
        char grid[n][n];
        for(int x=0;x<n;x++){for(int y=0;y<n;y++){cin>>grid[x][y];}}
        if(k==1)step_1();
        if(k==2)step_2();
        if(k==3)step_3();
        int ans=0;
        for(string s : paths){ //validating paths is a pain
            //in my first attempt (non-optimized), the last 2 tescases timed out
            //Essentially, I divided times by 2 by essentailly considering every inverse path with the normal path
            //Let say our path is DDRRRD
            // I would also track RRDDDR
            // way too hard for bronze though...
            bool ok=1, ok2=1;
            int x=0,y=0;
            int x2=0,y2=0;
            for(char c : s){
                if(c=='D')y++, x2++;
                else x++,y2++;
                if(grid[x][y]=='H'){ok=0;}
                if(grid[x2][y2]=='H'){ok2=0;}
                if(!ok&&!ok2)break;
            }
            if(ok)ans++;
            if(ok2)ans++;
        }
        cout<<ans<<endl;
    }
}

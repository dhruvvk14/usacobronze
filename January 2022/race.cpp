#include <fstream>
using namespace std;
//init everything...
int length;
int sigma(int i){return ((i + 1) * (i))/2;}
ifstream cin ("race.in");
ofstream cout("race.out");
int solve(){
    //lets just test the "max" speed required
    //notice how we can bruteforce the answer!
    int maxSpeed; cin>>maxSpeed;
    // int distance = 2 * sigma(maxSpeed) - maxSpeed;
    // int seconds = 2 * maxSpeed - 1;
    int distance = 0, seconds = 0;
    for(int speed = 1; ; speed++){
        if(distance >= length)return seconds;
        if(speed < maxSpeed){
            distance += (speed), seconds++;
            continue;
        }
        distance += speed, seconds++;
        if(distance >= length)return seconds;
        distance += speed, seconds++;
    }return seconds;
}
int main(){
    int queries;
    cin>>length>>queries;
    while(queries--){
        cout<<solve()<<endl;       
    }
}
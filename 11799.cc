#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int cases;
    vector<int> speeds;
    cin>>cases;
    for(int i = 0; i < cases; ++i){
        int numbers;
        int minspeed;
        cin>>numbers;
        for(int j = 0; j < numbers; ++j){
            int speed;
            cin>>speed;
            speeds.push_back(speed);
        }
        minspeed = *max_element(speeds.begin(),speeds.end());
        cout<<"Case "<<i+1<<": "<<minspeed<<endl;
        speeds.clear();
    }
    return 0;
}
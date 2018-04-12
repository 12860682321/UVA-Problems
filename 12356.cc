#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int B,S;
    cin>>S>>B;
    while(B != 0 && S != 0){
    vector<bool> soldiers (S,true);
    for(int b = 0; b < B; b++){
        int l_kill, r_kill;
        bool l_alive,r_alive;
        int left, right;
        l_alive = false;
        r_alive = false;
        cin>>l_kill>>r_kill;
        fill(soldiers.begin()+l_kill-1,soldiers.begin()+r_kill,false);
        for(int l = l_kill-1; l >= 1; l--){
            if(soldiers[l-1] == true){
                l_alive = true;
                left = l;
                break;
            }
        }
        for(int r = r_kill+1; r <= S;r++){
            if(soldiers[r-1] == true){
                r_alive = true;
                right = r;
                break;
            }
        }
        if(!l_alive){
            cout<<'*'<<' ';
        }
        if(!r_alive){
            cout<<'*';
        }
        if(l_alive){
            cout<<left<<' ';
        }
        if(r_alive){
            cout<<right;
        }
        cout<<endl;
    }
    cout<<'-'<<endl;
    cin>>S>>B;
    }
    return 0;
}
#include<iostream>
#include<string>

using namespace std;

int main(){
        char c;
        string total, working;
        total = "";
        working = "";
        bool home,end;
        bool homeafter, endafter;
        homeafter = false;
        endafter = false;
        home = false;
        end = true;
        while(cin.get(c) && cin.eof()){
            if(c == '\n'){
                cout<<total<<endl;
                total = "";
                working = "";
                home = false;
                end = true;
                homeafter = false;
                endafter = false;
            }
            if(c == '['){
                home = true;
                end = false;
            }
            if(c == ']'){
                end = true;
                home = false;
            }
            while(cin.get(c) && cin.eof()){
                if(c == '['){
                    homeafter = true;
                    endafter = false;
                    break;
                }
                if(c == ']'){
                    endafter = true;
                    homeafter = false;
                    break;
                }
                working += c;
            }
            if(home){
                total = working + total;
            }
            if(end){
                total = total + working;
            }
            if(homeafter){
                home = true;
                end = false;
            }
            if(endafter){
                end = true;
                home = false;
            }
            cout<<total<<endl;
    }
    
    
    return 0;
}
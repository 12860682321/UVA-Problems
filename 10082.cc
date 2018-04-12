#include <iostream>
#include <string>

using namespace std;

int main(){
    string keyboard = "1234567890-= QWERTYUIOP[]\ ASDFGHJKL;'ZXCVBNM,./";
    string input;
    while(getline(cin,input)){
        for(unsigned int i = 0; i < input.size(); ++i){
            if(input[i] == ' '){
                continue;
            }
            input[i] = keyboard[(keyboard.find(input[i]))-1];
        }
        cout<<input<<endl;
    }
    return 0;
}
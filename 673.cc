#include <iostream>
#include <string>

using namespace std;

int main(){
    int A;
    int B;
    int cases;
    string str;
    cin>>cases;
    for(int i = 0; i < cases; ++i){
        getline(cin,str,'\n');
        A = 0;
        B = 0;
        for(unsigned int j = 0; j < str.size(); ++j){
            if(str[j] == '(')
                A++;
            else if(str[j] == ')')
                A--;
            else if(str[j] == '[')
                B++;
            else if(str[j] == ']')
                B--;
        }
        if((A == 0 && B == 0) || str.empty()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
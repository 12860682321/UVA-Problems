#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(vector<char> digits){
    long long int ans = 0;
    for(int i = 0; i < digits.size(); ++i){
        ans += digits[i] - '0';
    }
    if(ans < 10){
        return ans;
    }
    string con;
    con = to_string(ans);
    vector<char> c;
    for(int i = 0; i < con.size(); ++i){
        c.push_back(con[i]);
    }
    return func(c);
}

int main(){
    string input;
    while(cin>>input && input != "0"){
        vector<char> digits;
        for(int i = 0; i < input.size(); ++i){
            digits.push_back(input[i]);
        }
        cout<<func(digits)<<endl;
    }
    return 0;
}
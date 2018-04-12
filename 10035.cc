#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string num1, num2;
    int carry[11];
    for(int j = 0; j < 11; ++j)
        carry[j] = 0;
    cin>>num1>>num2;
    while(num1 != "0" && num2 != "0"){
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i = 0; i < min(num1.size(),num2.size());++i){
            if(carry[i]+((int)num1[i]-48)+((int)num2[i]-48)>=10){
                carry[i+1]++;
            }
        }
        for(int i = min(num1.size(),num2.size()); i < max(num1.size(),num2.size());++i){
            if(num1.size() > num2.size()){
                if(carry[i]+((int)num1[i]-48) >= 10){
                    carry[i+1]++;
                }
            }else{
                if(carry[i]+((int)num2[i]-48) >= 10){
                    carry[i+1]++;
                }
            }
        }
        int total = 0;
        for(int i = 0; i < 11; ++i){
            total += carry[i];
        }
        if(total == 0){
            cout<<"No carry operation."<<endl;
        }else if(total == 1){
            cout<<total<<" carry operation."<<endl;
        }else{
            cout<<total<<" carry operations."<<endl;
        }
        for(int i = 0; i < 11; ++i){
            carry[i] = 0; 
        }
        cin>>num1>>num2;
    }
    return 0;
}
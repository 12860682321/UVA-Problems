#include <iostream>
using namespace std;
int main(){
    long long int fib[51] = {};
    fib[0] = 1;
    fib[1] = 2;
    fib[2] = 3;
    for(int i = 3; i < 51; ++i){
        fib[i] = fib[i-1] + fib[i-2];
    }
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; ++i){
        int bits;
        cin>>bits;
        cout<<"Scenario #"<<i+1<<":\n";
        cout<<fib[bits]<<endl;
        cout<<endl;
    }
    return 0;
}
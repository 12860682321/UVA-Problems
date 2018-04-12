#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long int i, j, iterations, max_it;
    long long int value;
    while(cin>>i>>j){
        max_it = 1;
        for(int a = min(i,j); a <= max(i,j); a++){
            value = a;
            iterations = 1;
            while(value != 1){
                if(value%2 == 1){
                    value = value*3+1;
                    iterations++;
                }else{
                    value /= 2;
                    iterations++;
                }
            }
            if(iterations > max_it){
                max_it = iterations;
            }
        }
        cout<<i<<' '<<j<<' '<<max_it<<endl;
    }
    return 0;
}
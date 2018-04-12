#include<iostream>

using namespace std;

int main(){
    long long int A, Atemp;
    int L;
    int iterations;
    int cases = 1;
    cin>>A>>L;
    while(A >= 0 && L >= 0){
        Atemp = A;
        iterations = 0;
        while(Atemp <= L){
            if(Atemp == 1){
                iterations++;
                break;
            }else if(Atemp%2 == 0){
                iterations++;
                Atemp = Atemp/2;
            }else{
                iterations++;
                Atemp = 3*Atemp+1;
            }
        }
        cout<<"Case "<<cases++<<": A = "<<A<<", limit = "<<L<<", number of terms = "<<iterations<<endl;
        cin>>A>>L;
    }
    return 0;
}
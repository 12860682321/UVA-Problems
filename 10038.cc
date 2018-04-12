#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int seqlength;
    while(cin>>seqlength){
        vector<int> seq;
        vector<bool> value;
        bool all_true = true;
        for(int i = 0; i < seqlength;++i){
            int num;
            cin>>num;
            seq.push_back(num);
        }
        for(int i = 0; i < seqlength-1; ++i){
            value.push_back(false);
        }
        if(seq.size() == 1){
            all_true = true;
            cout<<"Jolly"<<endl;
            continue;
        }
        for(int i = 1; i < seqlength; ++i){
            //cout<<abs(seq[i]-seq[i-1])<<" ";
            if(abs(seq[i]-seq[i-1]) > seqlength-1){
                all_true = false;
                break;
            }
            int s = abs(seq[i]-seq[i-1]);
            if(s == 0) continue; 
            value[s-1] = true;
        }
        for(unsigned int i = 0; i < value.size();++i){
            if(!value[i]){
                all_true = false;
                break;
            }
        }
        if(all_true){
            cout<<"Jolly"<<endl;
        }else {
            cout<<"Not jolly"<<endl;
        }
    }
    return 0;
}
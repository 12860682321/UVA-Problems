#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    int op = 0;
    while(getline(cin,line)){
        for(auto i = 0; i < line.size(); ++i){
            if(line[i] == '"' && op == 0){
                line.erase(i,1);
                line.insert(i,"``");
                op = 1;
            }else if(line[i] == '"' && op == 1){
                line.erase(i,1);
                line.insert(i, "''");
                op = 0;
            }
        }
        cout<<line<<endl;
    }
    return 0;
}
#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    map<string,int> trees;
    int cases;
    int total = 0;
    string tree;
    string spacer;
    cin>>cases;
    getline(cin,spacer);
    for(int i = 0; i < cases; ++i){
        total = 0;
        while(getline(cin,tree)){
            if(tree == "\n")
                break;
            if(trees.find(tree) == trees.end()){
                trees.insert(pair<string,int>(tree,1));
            }else{
                ++trees[tree];
            }
        }
        for(auto it = trees.begin(); it != trees.end();++it)
            total += it->second;
        for(auto it = trees.begin(); it != trees.end(); ++it){
            cout<<it->first<<" "<<fixed<<setprecision(4)<<(static_cast<float>(it->second)/total*100)<<endl;
            //cout<<it->first<<" "<<it->second<<endl;
        }
        trees.clear();
    }
    return 0;
}
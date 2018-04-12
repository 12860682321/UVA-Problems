#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string str;
    while (getline(cin,str)){
        vector<string> words;
        stringstream ss;
        ss << str;
        string word;
        while(ss>>word){
            if(isalpha(word[0])){
                words.push_back(word);
            }
        }
        cout<<words.size()<<endl;
    }
    return 0;
}
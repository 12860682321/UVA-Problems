#include <iostream>
#include <string>

using namespace std;

int similar(string test, string what){
    int score = 0;
    for(int i = 0; i < 3; ++i){
        if(test[i] == what[i]){
            score++;
        }
    }
    return score;
}

int main()
{
    int cases;
    cin >> cases;
    string two = "two";
    string one = "one";
    for (int i = 0; i < cases; ++i)
    {
        string str;
        cin>>str;
        if(str.length() == 5){
            cout<<"3\n";
            continue;
        }
        if(similar(str,two) > similar(str,one)){
            cout<<"2\n";
        }else{
            cout<<"1\n";
        }
    }
    return 0;
}
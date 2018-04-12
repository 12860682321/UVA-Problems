#include<iostream>
#include<string>

using namespace std;

int main(){
    int cases = 0;
    string word;
    cin>>word;
    while(word != "#"){
        cases++;
        if(word == "HELLO")
            cout<<"Case "<<cases<<": ENGLISH"<<endl;
        else if(word == "HOLA")
            cout<<"Case "<<cases<<": SPANISH"<<endl;
        else if(word == "HALLO")
            cout<<"Case "<<cases<<": GERMAN"<<endl;
        else if(word == "BONJOUR")
            cout<<"Case "<<cases<<": FRENCH"<<endl;
        else if(word == "CIAO")
            cout<<"Case "<<cases<<": ITALIAN"<<endl;
        else if(word == "ZDRAVSTVUJTE")
            cout<<"Case "<<cases<<": RUSSIAN"<<endl;
        else{
            cout<<"Case "<<cases<<": UNKNOWN"<<endl;
        }
        cin>>word;    
    }
    return 0;
}
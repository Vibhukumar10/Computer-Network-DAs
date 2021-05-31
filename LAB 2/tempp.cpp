#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
bool flag = true;
bool flag2 = true;
int pos = 0;
int c = 0;
string ab;
void sleepsaw();
string b[1000] = {"-"};//initialize the array
string sendergbn(int n,string a){
    if(flag ==true && flag2 == true){
        int len = a.length();
        string b;
        b = a.substr(pos,1);
        pos++;
        flag = false;
        cout<<"Sending "<<b<<endl;
        return b;
    }
}
void recievergbn(int n,string a){
    if(flag == false){
        b[pos-1] = a;
        if(c<n){
            c++;
            flag = true;

        }
        if(c>=n){
                if(b[pos-n] == "-" ){
                cout<<"Error"<<endl;
                flag2 = false;
                for(int i=0;i<n;i++){
                    b[pos-n] = ab.substr(pos-n,1);
                cout<<"Acknowledgement: recieved "<<b[pos-n]<<endl;
                
                flag2 = true;
                }
            }
            else{
            cout<<"Acknowledgement: recieved "<<b[pos-n]<<endl;
            }
            flag = true;
        }
    }
}
void sleepsaw()
{
    Sleep(1000);
    cout<<"sending";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<"."<<endl;
}

int main()
{
    cout<<"\n++++++++++++++++SELECTIVE REPEAT++++++++++++++++"<<endl;
    cout<<"Enter n: ";
    int n;
    cin>>n;
    if(n>0)
    {
        cout<<"Enter String: ";
        cin>>ab;
        string temp;
        int len = ab.length();
        for(int i=0;i<len;i++){
            temp = sendergbn(n,ab);
            sleepsaw();
            recievergbn(n,temp);
        }
        for(int i=1;i<n;i++){
            cout<<"Acknowledgement: recieved "<<b[i+len-n]<<endl;
        }
        pos = 0;
        flag = true;
        b[1000] = {"-"};
        c = 0;
        flag2 = true;
    }
    else
    {
        cout<<"Enter a valid sliding window value"<<endl;
    }
}
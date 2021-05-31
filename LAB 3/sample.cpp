#include<bits/stdc++.h>
using namespace std;

int toDecimal(string s)
{
    return stoi(s,0,2);
}

int main()
{
    string ip;
    cin>>ip;
    string block1="";
    string block2="";
    string block3="";
    string block4="";
    int i=0;
    while(ip[i]!='.' && i<ip.length())
    {
        block1.push_back(ip[i]);
        i++;
    }
    i++;
    while(ip[i]!='.' && i<ip.length())
    {
        block2.push_back(ip[i]);
        i++;
    }
    i++;
    while(ip[i]!='.' && i<ip.length())
    {
        block3.push_back(ip[i]);
        i++;
    }
    i++;
    while(ip[i])
    {
        block4.push_back(ip[i]);
        i++;
    }
    cout<<toDecimal(block1);
}
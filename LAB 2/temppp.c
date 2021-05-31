#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
bool flag = true;
bool flag2 = true;
int pos = 0;
int c = 0;
string ab;
void sleepsaw();
string arr[1000] = {"wr"};//initialize the array
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
        arr[pos-1] = a;
        if(c<n){
            c++;
            flag = true;

        }
        if(c>=n){
                if(arr[pos-n] == "wr" ){
                cout<<"Error"<<endl;
                flag2 = false;
                for(int i=0;i<n;i++){
                    pos = pos-n;
                    sendergbn(n,a);
                    sleepsaw();
                    recievergbn(n,a);
                }
            }
            else{
            cout<<"++++++++++"<<endl;
            cout<<"Acknowledgement: recieved "<<arr[pos-n]<<endl;
            cout<<"++++++++++"<<endl;}
            flag = true;
        }
    }
}
void sleepsaw(){
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
    cout<<"\n++++++++++++++++GO BACK N++++++++++++++++"<<endl;
    cout<<"Enter n: ";
    int n;
    cin>>n;
    if(n>0){
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
        cout<<"++++++++++"<<endl;
        cout<<"Acknowledgement: recieved "<<arr[i+len-n]<<endl;
        cout<<"++++++++++"<<endl;
    }
    //INITIALIZE EVERYTHING BACK TO WAY IT WAS
    pos = 0;
    flag = true;
    arr[1000] = {"wr"};
    c = 0;
    flag2 = true;}
    else{
        cout<<"Enter a valid sliding window value"<<endl;
    }
}
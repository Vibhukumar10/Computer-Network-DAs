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
void sleeping();
string arr[1000] = {"wr"};//initialize the array

string senderSandW(string a)
{
    if(flag)
    {
        int len = a.length();
        string b;
        b = a.substr(pos,1);
        pos++;
        flag = false;
        cout<<"Sending "<<b<<endl;
        return b;
    }

}

string receiverSandW(string a)
{
    if(flag == false)
    {
        arr[pos-1] = a;
        string c;
        if(arr[pos-1] == a){
        c = "Acknowledgement: recieved " + arr[pos-1];
        flag = true;
        return c;}
        else{
            c = "Timeout";
            senderSandW(a);
            flag = true;
            return c;
        }
    }
}

void StopWait()
{
    cout<<"***************Stop and Wait****************\n\n";
    cout<<"Enter the String: ";
    string a;
    cin>>a;
    string temp;
    int len = a.length();
    for(int i=0;i<len;i++){
        temp = senderSandW(a);
        sleeping();
        cout<<receiverSandW(temp)<<endl;
    }
    pos = 0;
    flag = true;
    cout<<"\n\nFinished: Stop and Wait Protocol\n";
    system("pause");
}

string sendergbn(int n,string a)
{
    if(flag ==true && flag2 == true)
    {
        int len = a.length();
        string b;
        b = a.substr(pos,1);
        pos++;
        flag = false;
        cout<<"Sending "<<b<<endl;
        return b;
    }
}
void receiverbgn(int n,string a)
{
    if(flag == false)
    {
        arr[pos-1] = a;
        if(c<n)
        {
            c++;
            flag = true;

        }
        if(c>=n)
        {
            if(arr[pos-n] == "wr" )
            {
                cout<<"Error"<<endl;
                flag2 = false;
                for(int i=0;i<n;i++)
                {
                    pos = pos-n;
                    sendergbn(n,a);
                    sleeping();
                    receiverbgn(n,a);
                }
            }
            else
            {
                cout<<"**********"<<endl;
                cout<<"Acknowledgement: recieved "<<arr[pos-n]<<endl;
                cout<<"**********"<<endl;
            }
            flag = true;
        }
    }
}

void sleeping()
{
    Sleep(500);
    cout<<"sending";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<"."<<endl;
}

string b[1000] = {"-"};

void SelectiveRepeat()
{
    cout<<"\n***************SELECTIVE REPEAT***************"<<endl;
    cout<<"Enter the size of Sliding-Window: ";
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
            sleeping();
            receiverbgn(n,temp);
        }
        for(int i=1;i<n;i++)
        {
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
        cout<<"\nEnter a valid sliding window value."<<endl;
    }
    cout<<"\n\nFinished: Selective Repeat Protocol\n";
    system("pause");
}

void gbn()
{
    cout<<"\n***************GO BACK N***************"<<endl;
    cout<<"Enter the size of the Sliding-Window: ";
    int n;
    cin>>n;
    if(n>0)
    {
        cout<<"Enter String: ";
        cin>>ab;
        string temp;
        int len = ab.length();
        for(int i=0;i<len;i++)
        {
            temp = sendergbn(n,ab);
            sleeping();
            receiverbgn(n,temp);
        }
        for(int i=1;i<n;i++)
        {
            cout<<"**********"<<endl;
            cout<<"Acknowledgement: recieved "<<arr[i+len-n]<<endl;
            cout<<"**********"<<endl;
        }
        pos = 0;
        flag = true;
        arr[1000] = {"wr"};
        c = 0;
        flag2 = true;
    }
    else
    {
        cout<<"\nEnter a valid sliding window value."<<endl;
    }
    cout<<"\n\nFinished: Go-Back-N  Protocol\n";
    system("pause");
}

int main()
{
    while(1)
    {
        start:
        system("cls");
        int choice;
        cout<<"Flow Conrol Protocols (MENU): \n [BY VIBHU KUMAR SINGH]\n\n1. Stop and Wait\n2. Selective Repeat\n3. Go-Back-N\n0. Exit\nEnter your choice: ";
        cin>>choice;
        cout<<"<-------------------------------------------------------------------------------->\n\n";
        switch(choice)
        {
            case 1:
                StopWait();
            break;
            case 2:
                SelectiveRepeat();
            break;  
            case 3:
            start_checksum:
                gbn();
            break;
            case 0:
                exit(0);
            break;
            default:
                cout<<"Invalid input";
                goto start;
        }
    }
}
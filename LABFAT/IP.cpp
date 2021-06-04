#include<bits/stdc++.h>
using namespace std;

void DecimalFirstLast()
{
    start:
    string ip;
    cout<<"\nEnter the Decimal IP Address: ";
    cin>>ip;
    string block1="";
    string block2="";
    string block3="";
    string block4="";
    int i=0;
    while(ip[i]!='.')
    {
        block1.push_back(ip[i]);
        i++;
    }
    i++;
    while(ip[i]!='.')
    {
        block2.push_back(ip[i]);
        i++;
    }
    i++;
    while(ip[i]!='.')
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
    while(true)
    {
        cout<<"1.First Address\n2.Last Address\n3.Number of Addresses\n0.Exit\nEnter your choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                if(stoi(block1)<=127)
                {
                    cout<<"\nFirst Address: "<<block1<<".0.0.0\n\n";
                }
                else if(stoi(block1)>=128 && stoi(block1)<=191)
                {
                    cout<<"\nFirst Address: "<<block1<<"."<<block2<<".0.0\n\n";
                }
                else if(stoi(block1)>=192 && stoi(block1)<=223)
                {
                    cout<<"\nFirst Address: "<<block1<<"."<<block2<<"."<<block3<<".0\n\n";
                }
                else if(stoi(block1)>=224 && stoi(block1)<=239)
                {
                    cout<<"\nFirst Address: Invalid\n\n";
                }
                else if(stoi(block1)>=240 && stoi(block1)<=255)
                {
                    cout<<"\nFirst Address: Invalid\n\n";
                }
                break;
            case 2:
                if(stoi(block1)<=127)
                {
                    cout<<"\nLast Address: "<<block1<<".255.255.255\n\n";
                }
                else if(stoi(block1)>=128 && stoi(block1)<=191)
                {
                    cout<<"\nLast Address: "<<block1<<"."<<block2<<".255.255\n\n";
                }
                else if(stoi(block1)>=192 && stoi(block1)<=223)
                {
                    cout<<"\nLast Address: "<<block1<<"."<<block2<<"."<<block3<<".255\n\n";
                }
                else if(stoi(block1)>=224 && stoi(block1)<=239)
                {
                    cout<<"\nLast Address: Invalid\n\n";
                }
                else if(stoi(block1)>=240 && stoi(block1)<=255)
                {
                    cout<<"\nLast Address: Invalid\n\n";
                }
                break;
            case 3:
                if(stoi(block1)<=127)
                {
                    cout<<"\nNumber of Addresses: "<<(long long int)pow(2,24)<<"\n\n";
                }
                else if(stoi(block1)>=128 && stoi(block1)<=191)
                {
                    cout<<"\n\nNumber of Addresses: "<<(long long int)pow(2,24)<<"\n\n";
                }
                else if(stoi(block1)>=192 && stoi(block1)<=223)
                {
                    cout<<"\nNumber of Addresses: "<<(long long int)pow(2,24)<<"\n\n";
                }
                else if(stoi(block1)>=224 && stoi(block1)<=239)
                {
                    cout<<"\nNumber of Addresses: Invalid\n";
                }
                else if(stoi(block1)>=240 && stoi(block1)<=255)
                {
                    cout<<"\nNumber of Addresses: Invalid\n";
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Choice\n";
                break;
        }
    }
    // if(stoi(block1)<=127)
    // {
    //     cout<<"First Address: "<<block1<<".0.0.0\nLast Address: "<<block1<<".255.255.255\nNumber of Addresses: "<<(long long int)pow(2,24);
    // }
    // else if(stoi(block1)>=128 && stoi(block1)<=191)
    // {
    //     cout<<"First Address: "<<block1<<"."<<block2<<".0.0\nLast Address: "<<block1<<"."<<block2<<".255.255\nNumber of Addresses: "<<(long long int)pow(2,16);
    // }
    // else if(stoi(block1)>=192 && stoi(block1)<=223)
    // {
    //     cout<<"First Address: "<<block1<<"."<<block2<<"."<<block3<<".0\nLast Address: "<<block1<<"."<<block2<<"."<<block3<<".255\nNumber of Addresses: "<<pow(2,8);
    // }
    // else if(stoi(block1)>=224 && stoi(block1)<=239)
    // {
    //     cout<<"First Address: Invalid\nLast Address: Invalid\nNumber of Addresses: Invalid";
    // }
    // else if(stoi(block1)>=240 && stoi(block1)<=255)
    // {
    //     cout<<"First Address: Invalid\nLast Address: Invalid\nNumber of Addresses: Invalid";
    // }
}

int main()
{
    DecimalFirstLast();
    return 0;
}   
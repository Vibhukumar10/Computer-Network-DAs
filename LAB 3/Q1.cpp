#include<bits/stdc++.h>
using namespace std;

int DecimalOrBinary();
void DecimalIPClass();
bool ValidIP(string,int);
void DecimalFirstLast();
void BinaryIPClass();
int toDecimal(string);
void BinaryFirstLast();

void IPClassMenu()
{
    int decimalBinary=DecimalOrBinary();
    switch(decimalBinary)
    {
        case 1:
            DecimalIPClass();
            break;
        case 2:
            BinaryIPClass();
            break;
    }
    cout<<"\n-----------------------------------------\n\n\n";
}

void DecimalIPClass()
{
    start:
    string ip;
    cout<<"Enter the Decimal IP Address: ";
    cin>>ip;
    if(ValidIP(ip,1))
    {
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
        if(stoi(block1)<=127)
        {
            cout<<"\nClass: Class A\nNetwork ID: "<<block1<<"\nHost ID: "<<block2<<"."<<block3<<"."<<block4;
        }
        else if(stoi(block1)>=128 && stoi(block1)<=191)
        {
            cout<<"\nClass: Class B\nNetwork ID: "<<block1<<"."<<block2<<"\nHost ID: "<<block3<<"."<<block4;
        }
        else if(stoi(block1)>=192 && stoi(block1)<=223)
        {
            cout<<"\nClass: Class C\nNetwork ID: "<<block1<<"."<<block2<<"."<<block3<<"\nHost ID: "<<block4;
        }
        else if(stoi(block1)>=224 && stoi(block1)<=239)
        {
            cout<<"\nClass: Class D";
        }
        else
        {
            cout<<"\nClass: Class E";
        }
    }
    else
    {
        cout<<"\nEnter a valid IP Address.\n";
        goto start;
    }
}

void BinaryIPClass()
{
    start:
    string ip;
    cout<<"Enter the Binary IP Address: ";
    cin>>ip;
    if(ValidIP(ip,2))
    {
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
        if(toDecimal(block1)<=127)
        {
            cout<<"\nClass: Class A\nNetwork ID: "<<block1<<"\nHost ID: "<<block2<<"."<<block3<<"."<<block4;
        }
        else if(toDecimal(block1)>=128 && toDecimal(block1)<=191)
        {
            cout<<"\nClass: Class B\nNetwork ID: "<<block1<<"."<<block2<<"\nHost ID: "<<block3<<"."<<block4;
        }
        else if(toDecimal(block1)>=192 && toDecimal(block1)<=223)
        {
            cout<<"\nClass: Class C\nNetwork ID: "<<block1<<"."<<block2<<"."<<block3<<"\nHost ID: "<<block4;
        }
        else if(toDecimal(block1)>=224 && toDecimal(block1)<=239)
        {
            cout<<"\nClass: Class D is for Multicast Addresses";
        }
        else
        {
            cout<<"\nClass: Class E is for  Reserved Addresses";
        }
    }
    else
    {
        cout<<"\nEnter a valid IP Address.\n";
        goto start;
    }
}

int toDecimal(string s)
{
    return stoi(s,0,2);
}

bool ValidIP(string ip, int decimalBinary)
{
    int j=0;
    int dots=0;
    while(ip[j])
    {
        if(!isdigit(ip[j]) && ip[j]!='.')
            return false;
        if(ip[j]=='.')
            dots++;
        j++;
    }
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
    int flag=0;
    if(decimalBinary==1)
    {
        if(dots==3 && !block1.empty() && !block2.empty() && !block3.empty() && !block4.empty())
        {
            if(stoi(block1)>=0 && stoi(block1)<=255)
            {
                if(stoi(block2)>=0 && stoi(block2)<=255)
                {
                    if(stoi(block3)>=0 && stoi(block3)<=255)
                    {
                        if(stoi(block4)>=0 && stoi(block4)<=255)
                        {
                            flag=1;
                            return true;
                        }
                    }
                }
            }
        }
        if(flag==0)
        {
            return false;
        }
    }
    else if(decimalBinary==2)
    {
        int k=0,flag1=0;
        while(ip[k])
        {
            if(ip[k]!='1' && ip[k]!='0' && ip[k]!='.')
            {
                return false;
            }
            k++;
        }
        if(dots==3 && !block1.empty() && !block2.empty() && !block3.empty() && !block4.empty())
        {
            if(toDecimal(block1)>=0 && toDecimal(block1)<=255)
            {
                if(toDecimal(block2)>=0 && toDecimal(block2)<=255)
                {
                    if(toDecimal(block3)>=0 && toDecimal(block3)<=255)
                    {
                        if(toDecimal(block4)>=0 && toDecimal(block4)<=255)
                        {
                            flag1=1;
                            return true;
                        }
                    }
                }
            }
            if(flag1==0)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}

int DecimalOrBinary()
{
    start:
    int choice;
    cout<<"1.Decimal\n2.Binary\nEnter your choice: ";
    cin>>choice;
    cout<<"--------------------------------------------\n\n";
    switch(choice)
    {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            cout<<"\nInvalid Choice\n";
            goto start;
    }
}

void ValidIPMenu()
{
    int decimalBinary=DecimalOrBinary();
    if(decimalBinary==1)
    {
        cout<<"Enter Decimal IP Address: ";
    }
    if(decimalBinary==2)
    {
        cout<<"Enter Binary IP Address: ";
    }
    string ip;
    cin>>ip;
    bool isvalid=ValidIP(ip,decimalBinary);
    if(isvalid)
    {
        cout<<"\nThe input IP Address is VALID.\n";
    }
    else
    {
        cout<<"\nThe input IP Address is INVALID\n";
    }
    cout<<"\n-----------------------------------------\n\n\n";
}

void FirstLastMenu()
{
    int decimalBinary=DecimalOrBinary();
    switch(decimalBinary)
    {
        case 1:
            DecimalFirstLast();
            break;
        case 2:
            BinaryFirstLast();
            break;
    }
    cout<<"\n--------------------------------------\n\n\n";
}

void DecimalFirstLast()
{
    start:
    string ip;
    cout<<"\nEnter the Decimal IP Address: ";
    cin>>ip;
    if(ValidIP(ip,1))
    {
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
        if(stoi(block1)<=127)
        {
            cout<<"First Address: "<<block1<<".0.0.0\nLast Address: "<<block1<<".255.255.255\nNumber of Addresses: "<<(long long int)pow(2,24);
        }
        else if(stoi(block1)>=128 && stoi(block1)<=191)
        {
            cout<<"First Address: "<<block1<<"."<<block2<<".0.0\nLast Address: "<<block1<<"."<<block2<<".255.255\nNumber of Addresses: "<<(long long int)pow(2,16);
        }
        else if(stoi(block1)>=192 && stoi(block1)<=223)
        {
            cout<<"First Address: "<<block1<<"."<<block2<<"."<<block3<<".0\nLast Address: "<<block1<<"."<<block2<<"."<<block3<<".255\nNumber of Addresses: "<<pow(2,8);
        }
        else if(stoi(block1)>=224 && stoi(block1)<=239)
        {
            cout<<"First Address: Invalid\nLast Address: Invalid\nNumber of Addresses: Invalid";
        }
        else if(stoi(block1)>=240 && stoi(block1)<=255)
        {
            cout<<"First Address: Invalid\nLast Address: Invalid\nNumber of Addresses: Invalid";
        }
    }
    else
    {
        cout<<"\nEnter a valid IP Address.\n";
        goto start;
    }
}

void BinaryFirstLast()
{
    start:
    string ip;
    cout<<"\nEnter the Decimal IP Address: ";
    cin>>ip;
    if(ValidIP(ip,2))
    {
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
        if(toDecimal(block1)<=127)
        {
            cout<<"First Address: "<<block1<<".0.0.0\nLast Address: "<<block1<<".11111111.11111111.11111111\nNumber of Addresses: "<<(long long int)pow(2,24);
        }
        else if(toDecimal(block1)>=128 && toDecimal(block1)<=191)
        {
            cout<<"First Address: "<<block1<<"."<<block2<<".0.0\nLast Address: "<<block1<<".11111111.11111111\nNumber of Addresses: "<<(long long int)pow(2,16);
        }
        else if(toDecimal(block1)>=192 && toDecimal(block1)<=223)
        {
            cout<<"First Address: "<<block1<<"."<<block2<<block3<<".0\nLast Address: "<<block1<<".11111111\nNumber of Addresses: "<<pow(2,8);
        }
        else if(toDecimal(block1)>=224 && toDecimal(block1)<=239)
        {
            cout<<"First Address: Invalid\nLast Address: Invalid\nNumber of Addresses: Invalid";
        }
        else
        {
            cout<<"First Address: Invalid\nLast Address: Invalid\nNumber of Addresses: Invalid";
        }
    }
    else
    {
        cout<<"\nEnter a valid IP Address.";
        goto start;
    }
}

void options()
{
    while(true)
    {
        cout<<"---------IPv4 Addressing Main Menu--------\n          by [VIBHU KUMAR SINGH]\n\n";
        cout<<"1.To check the class, network id and host id of an IPv4 address\n2.To check whether given IP address is valid or not\n3.To find first address, last address and number of addresses in the block\n0. Exit\nEnter your choice: ";
        int choice;
        cin>>choice;
        cout<<"----------------------------------------------------------------------------\n\n";
        switch(choice)
        {
            case 1:
                IPClassMenu();
                break;
            case 2:
                ValidIPMenu();
                break;
            case 3:
                FirstLastMenu();
                break;
            case 0:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Choice\n";
                break;
        }
    }
}

int main()
{
    system("cls");
    options();
    return 0;  
}


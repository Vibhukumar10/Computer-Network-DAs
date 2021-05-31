#include <iostream>

using namespace std;
int  hammimg(string a, string b)
{
    string ans = "";
    int count = 0;  
    for (int i = 0; i < 4; i++)
    {
        
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    for(int i = 0;i<4;i++)
    {
        if(ans[i]=='1')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    cout<<"Enter 6 Binary Strings: \n";
    string arr[6];
    int min = 9999;
    for(int i=0;i<6;i++)
    {
        cin>>arr[i];
    }
    for(int i = 0; i<6; i++)
    {
        for(int j = i+1; j<6; j++)
        {
            int d = hammimg(arr[i],arr[j]);
            if(d<min)
            {
                min=d;
            }
        }
    }
    cout<<"\nMinimum Hamming Ditance of these 6 Binary strings are: "<<min;
    return 0;
}
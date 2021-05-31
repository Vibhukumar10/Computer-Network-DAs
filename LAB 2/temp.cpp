#include<bits/stdc++.h>
using namespace std;
string addBinary(string a, string b)
{
    string result = "";
    int s = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);
        result = char(s % 2 + '0') + result;
        s /= 2;
        i--; j--;
    }
    return result;
}

int main(){
int n;
cout<<"Enter number of string: ";
cin>>n;
string arr[n];
for(int i=0;i<n;i++){
    cout<<"Enter msg["<<i<<"]: ";
    cin>>arr[i];
}
string result;

for(int i=0;i<n;i++){
    result = addBinary(result,arr[i]);
}
cout<<"************"<<endl;
cout<<"result = ";
cout<<result<<endl;
string carry;
int len = arr[0].length();
int result_len = result.length();
int c = result_len-len;
cout<<"Carry = ";
if(c==1){
    carry = result.at(0);
}
else{
carry = result.substr(0,c);
}
string carryless = result.substr(c,len);
cout<<carry<<endl;
cout<<"result without carry = ";
cout<<carryless<<endl;
string sum = addBinary(carry,carryless);
cout<<"sum(carry+carryless) = ";
cout<<sum<<endl;
string checksum;
for(int i=0;i<len;i++){
    checksum = checksum+'0';
}
for(int i=0;i<len;i++){
    if(sum[i] == '0'){
        checksum[i] = '1';
    }
}
cout<<"\nChecksum = ";
cout<<checksum<<endl;
}
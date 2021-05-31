#include<bits/stdc++.h>
using namespace std;

string getParity(string str);
void crc_receiver(char input[],char key[],int keylen,int msglen);

void vrc(string str)
{
    string p=getParity(str);
    cout<<"The Even-Parity Bit: "<<p<<"\n";
    string comb=p.append("|");
    comb=comb.append(str);
    cout<<"The combined message with Even-Parity Bit (at the starting): "<<comb<<"\n";
}

string getParity(string str)
{
    int n=str.length(),count=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='1')
        {
            count++;
        }
    }
    string ParityBit;
    if(count%2==0)
    {
        ParityBit="0";
    }
    else
    {
        ParityBit="1";
    }
    return ParityBit;
}

void vrc_main()
{   
    start_vrc:
    cout<<"***SENDER'S SIDE***\n\n";
    cout<<"The input message(string): ";
    string str_vrc,str_vrc_rec;
    cin>>str_vrc;
    for(int i=0;i<str_vrc.length();i++)
    {
        if(!(str_vrc[i]=='0'||str_vrc[i]=='1'))
        {
            cout<<"Wrong input, Please try again.\n";
            system("pause");
            goto start_vrc;
        }
    }
    vrc(str_vrc);
    cout<<"\n\n***RECEIVER'S SIDE***\n\n";
    cout<<"Enter the message recieved(string): ";
    cin>>str_vrc_rec;
    if(getParity(str_vrc_rec)=="0")
    {
        cout<<"\nThere is NO error because the string contains EVEN number of set bits, the message is ACCEPTED.\n\n";
    }
    else
    {
        cout<<"\nThere is an error because the string contains ODD number of set bits, the message is REJECTED.\n\n";
    }
    system("pause");
}

void lrc()
{
    start_lrc:
    int flag=0;
    cout<<"***SENDER'S SIDE***\n\n";
    datablock:
        cout<<"Enter the number of Data Blocks: ";
        int n;
        cin>>n;
        if(n<=0)
        {
            cout<<"\nPlease enter a positive value.\n";
            goto datablock;
        }
    databits:
        cout<<"Enter the number of bits per block: ";
        int m;
        cin>>m;
        if(m<=0)
        {
            cout<<"\nPlease enter a positive value.\n";
            goto databits;
        }
    matrix:
        int flagg=0;
        cout<<"Enter the Data Blocks (matrix form): \n";
        int arr[n+1][m+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]!=0 && arr[i][j]!=1)
                {
                    flagg=1;
                    break;
                }
            }
        }
        if(flagg==1)
        {
            cout<<"\nPlease enter binary input only.\n";
            goto matrix;
        } 

    int XOR=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            XOR=XOR^arr[i][j];
        }
        arr[i][m]=XOR;
        XOR=0;
    }
    int XORR=0;
    for(int j=0;j<m+1;j++)
    {
        for(int i=0;i<n;i++)
        {
            XORR^=arr[i][j];
        }
        arr[n][j]=XORR;
        XORR=0;
    }
    cout<<"\nThe Matrix with Even Parity Bits: \n";
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\nThe combined messsage sent is: ";
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cout<<arr[i][j];
        }
        cout<<" ";
    }
    cout<<"\n\n***RECEIVER'S SIDE***\n\n";
    cout<<"Enter the message received (matrix form): \n";
    int arr_rec[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cin>>arr_rec[i][j];
        }
    }
    int XOR_REC=0;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            XOR_REC^=arr_rec[i][j];
        }
        // cout<<XOR_REC;
        if(XOR_REC!=0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"\nThere is an error because a row or column contains ODD number of set bits, the message is REJECTED.\n";
    }
    else
    {
        cout<<"\nThere is NO error becuase every row and column has EVEN number of set bits, the message is ACCEPTED.\n";
    }
    system("pause");
}

char data[100];
int rightSum(int l)
{
  int sum=0, i=1;
  for(;i<l;i=i+2)
    sum=sum + (int) data[i];
  return sum;
}
int leftSum(int l)
{
  int sum=0, i=0;
  for(;i<l;i=i+2)
    sum=sum + (int) data[i];
  return sum;
}

void checksum_hex()
{
    char buf[100];
    int i, n, op=0, irs=0, ils=0, prs=0, cls=0, wc=0, pls=0, s=0, ocs=0, len=0;
    cout<<"***\n\nSENDER'S SIDE***\n\n";
    printf("Enter the data to be transmitted: ");
    gets(buf);
    gets(data);
    len=strlen(data);
    if(len%2!=0)
        len++;
    irs=rightSum(len);       
    prs=irs%256;          
    cls=irs/256;          
    ils=cls+leftSum(len);    
    pls=ils%256;          
    wc=ils/256;           
    s=pls*256+prs+wc;
    ocs = 65535 - s;
    printf("The checksum generated is %X\n", ocs);
    char cs[100];
    int ch[100];
    cout<<"\n\nRECEIVER'S SIDE***\n\n";
    printf("Enter the data received: ");
    gets(data);
    printf("Enter the received checksum: ");
    gets(cs);
    len=strlen(data);
    if(len%2!=0)
    len++;
    for(i=0;i<strlen(cs);i++)
    {
        if(cs[i]>='0' && cs[i]<='9')
        ch[i]=cs[i]-48;
        else if(cs[i]>='A' && cs[i]<='F')
        ch[i]=cs[i]-55;
        else if(cs[i]>='a' && cs[i]<='f')
        ch[i]=cs[i]-87;
    } 
    irs=rightSum(len) + ch[2]*16 + ch[3];       
    prs=irs%256;          
    cls=irs/256;          
    ils=cls+leftSum(len) + ch[0]*16 + ch[1];    
    pls=ils%256;          
    wc=ils/256;           
    s=pls*256+prs+wc;
    ocs = 65535 - s;
    if(ocs==0)
        printf("\nThe message is accepted!\n");
    else
        printf("\nThe message is rejected as there is an error!\n");
    system("pause");
}

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

void checksum_binary()
{
    int n;
    cout<<"\n\n***SENDER'S SIDE***";
    number:
    cout<<"\n\nEnter number of strings: ";
    cin>>n;
    if(n<=0 || isalpha(n))
    {
        cout<<"\nEnter a valid input (integer).\n";
        goto number;
    }
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter msg["<<i<<"]: ";
        cin>>arr[i];
    }
    string result;
    for(int i=0;i<n;i++)
    {
        result = addBinary(result,arr[i]);
    }
    cout<<"*************"<<endl;
    cout<<"Result= ";
    cout<<result<<endl;
    string carry;
    int len = arr[0].length();
    int result_len = result.length();
    int c = result_len-len;
    cout<<"Carry= ";
    if(c==1)
    {
        carry = result.at(0);
    }
    else
    {
        carry = result.substr(0,c);
    }
    string carryless = result.substr(c,len);
    cout<<carry<<endl;
    cout<<"Result without Carry = ";
    cout<<carryless<<endl;
    string sum = addBinary(carry,carryless);
    cout<<"Sum(Carry+Carryless) = ";
    cout<<sum<<endl;
    string checksum;
    for(int i=0;i<len;i++)
    {
        checksum = checksum+'0';
    }
    for(int i=0;i<len;i++)
    {
        if(sum[i] == '0')
        {
            checksum[i] = '1';
        }
    }
    cout<<"\nChecksum Generated= "<<checksum<<endl;
    cout<<"\n\n***RECEIVER'S SIDE***\n\n";
    cout<<"Enter the strings: \n";
    string arr_rec[n+1];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter msg["<<i<<"]: ";
        cin>>arr_rec[i];
    }
    cout<<"Enter the Checksum received: ";
    string checksum_inp;
    cin>>checksum_inp;
    arr_rec[n]=checksum_inp;
    string result_rec;
    for(int i=0;i<n+1;i++)
    {
        result_rec=addBinary(result_rec,arr_rec[i]);
    }
    string carry_rec;
    int len_rec = arr_rec[0].length();
    int result_len_rec = result_rec.length();
    int c_rec = result_len_rec-len_rec;
    if(c_rec==1)
    {
        carry_rec= result_rec.at(0);
    }
    else
    {
        carry_rec= result_rec.substr(0,c_rec);
    }
    string carryless_rec= result_rec.substr(c,len);
    string sum_rec = addBinary(carry_rec,carryless_rec);
    string checksum_rec;
    for(int i=0;i<len_rec;i++)
    {
        checksum_rec=checksum_rec+'0';
    }
    for(int i=0;i<len_rec;i++)
    {
        if(sum_rec[i] == '0')
        {
            checksum_rec[i] = '1';
        }
    }
    cout<<"\nChecksum Generated= "<<checksum_rec<<endl;
    int flaggg=0;
    for(int i=0;i<checksum_rec.length();i++)
    {
        if(checksum_rec[i]!=0)
        {
            flaggg=1;
            break;
        }
    }
    if(flaggg=1)
    {
        cout<<"\nThe Checksum is not 0, the message is rejected.\n";
    }
    else
    {
        cout<<"\nThe Checksum is 0, the message is accepted.\n";
    }
    system("pause");
}

void checksum()
{
    int choice;
    cout<<"1. Binary Checksum\n2. Hexadecimal Checksum\n0. Exit to Main Menu\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 0:
            return;
        break;
        case 1:
            checksum_binary();
        break;
        case 2:
            checksum_hex();
        break;
    }
}

void crc()
{
    start_crc:
    cout<<"***SENDER'S SIDE***\n\n";
    message:
    int flag=0,flagg=0;
    int i,j,keylen,msglen;
	char input[100],key[30],temp[30],quot[100],rem[30],key1[30],temp1;
	printf("Enter the input message: ");
    scanf("%c",&temp1);
	gets(input);
    for(int i=0;i<strlen(input);i++)
    {
        if(input[i]!='0' && input[i]!='1')
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"\nPlease enter only binary input.\n";
        goto message;
    }
    key:
	printf("Enter the Key: ");
	gets(key);
    for(int i=0;i<strlen(key);i++)
    {
        if(key[i]!='0' && key[i]!='1')
        {
            flagg=1;
            break;
        }
    }
    if(flagg==1)
    {
        cout<<"\nPlease enter only binary input.\n";
        goto key;
    }
	keylen=strlen(key);
	msglen=strlen(input);
	strcpy(key1,key);
	for (i=0;i<keylen-1;i++) 
    {
		input[msglen+i]='0';
	}
	for (i=0;i<keylen;i++)
	 temp[i]=input[i];
	for (i=0;i<msglen;i++) 
    {
		quot[i]=temp[0];
		if(quot[i]=='0')
             for (j=0;j<keylen;j++)
                key[j]='0';
        else
             for (j=0;j<keylen;j++)
                key[j]=key1[j];
		for (j=keylen-1;j>0;j--)
        {
			if(temp[j]==key[j])
                rem[j-1]='0';
            else
                rem[j-1]='1';
		}
		rem[keylen-1]=input[i+keylen];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	printf("Quotient is: ");
	for (i=0;i<msglen;i++)
        printf("%c",quot[i]);
	printf("\nRemainder is: ");
	for (i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
	printf("\nThe combined message sent is: ");
	for (i=0;i<msglen;i++)
        printf("%c",input[i]);
	for (i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
    cout<<"\n\n***RECEIVER'S SIDE***\n\n";
    cout<<"Enter the message received: ";
    char crc_rec[100];
    gets(crc_rec);
    crc_receiver(crc_rec,key,msglen,keylen);
    cout<<"\n";
	system("pause");
}

void crc_receiver(char input[],char key[],int msglen,int keylen)
{
    int flag=0,i=0;
    int j=0;
    char temp[100],rem[100],quot[100],key1[100];
    strcpy(key1,key);
    for(i=0;i<keylen;i++)
	 temp[i]=input[i];
	for (i=0;i<msglen;i++) 
    {
		quot[i]=temp[0];
		if(quot[i]=='0')
             for (j=0;j<keylen;j++)
                key[j]='0';
        else
             for (j=0;j<keylen;j++)
                key[j]=key1[j];
		for (j=keylen-1;j>0;j--)
        {
			if(temp[j]==key[j])
                rem[j-1]='0';
            else
                rem[j-1]='1';
		}
		rem[keylen-1]=input[i+keylen];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
    cout<<"Remainder: ";
    for(i=0;i<strlen(rem);i++)
    {
        cout<<rem[i];
    }
    for(i=0;i<strlen(rem);i++)
    {
        if(rem[i]!='0')
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"\n\nThere is an error as remainder is not 0, the message is REJECTED.\n";
    }
    else
    {
        cout<<"\n\nThere is NO error as remainder is 0, the message is ACCEPTED.\n";
    }
}

void hamming()
{
    start_hamming:
	cout<<"***SENDER'S SIDE***\n\n";
    length:
	int maxp=6;
    int a[50],temp[70],temp2[70];
    int t,i,j,k,nd,n,nh,sum=0,pos=0;
    printf("Enter the length of input message: ");
    scanf("%d",&nd);
    if(nd<=0)
    {
        cout<<"\nPlease enter a positive value.\n";
        goto length;
    }
    message:
    int flag=0;
    printf("Enter the input message: ");
    for(i=0;i<nd;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<nd;i++)
    {
        if(a[i]!=1 && a[i]!=0)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"\nPlease enter binary input only.\n";
        goto message;
    }
    for(i=0,j=0;i<nd;i++)
    {
        for(k=0;k<maxp;k++)
        {
            t=pow(2,k)-1;
            if(j==t)
            {
                temp[j]=0;
                j++;
            }
        }
        temp[j]=a[i];
        j++;
    }
    nh=j;
    printf("The length of Hamming Code: %d bits\n",nh);
    n=nh-nd;
    printf("The number of Parity Bits: %d \n",n);
    cout<<"---Calculating Parity Bits---\n";
    int b[n];
    int m=n-1;
    for(k=0;k<n;k++)
    {
        t=pow(2,k)-1;
        for(i=t;i<nh;)
        {
            for(j=0;j<=t;j++)
            {
                sum=sum+temp[i];
                i++;
                if(i>=nh)
                    break;
            }
            if(i>=nh)
                break;

            for(j=0;j<=t;j++)
            {
                i++;
                if(i>=nh)
                    break;
            }
            if(i>=nh)
                break;
        }
        temp[t]=sum%2;
        sum=0;
        printf("P%d: %d\n",t+1,temp[t]);
    }
    printf("\nHamming Code sent: ");
    for(i=0;i<nh;i++)
    {
        printf("%d ",temp[i]);
    }
    cout<<"\n\n***RECEIVER'S SIDE***\n\n";
   printf("Enter the Hamming Code received: ");
    for(i=0;i<nh;i++)
    {
        scanf("%d",&temp2[i]);
    }
    sum=0;
    for(k=0;k<n;k++)
    {
        t=pow(2,k)-1;
        for(i=t;i<nh;)
        {
            for(j=0;j<=t;j++)
            {
                sum=sum+temp2[i];
                i++;
                if(i>=nh)
                    break;
            }
            if(i>=nh)
                break;
            for(j=0;j<=t;j++)
            {
                i++;
                if(i>=nh)
                    break;
            }
            if(i>=nh)
                break;
        }
        b[m]=sum%2;
        sum=0;
        printf("P%d: %d\n",t+1,b[m]);
        m--;
    }
    for(m=0;m<n;m++)
    {
        pos=pos+b[n-m-1]*pow(2,m);
    }
    printf("Position of Error: %d\n",pos);
    if(temp2[pos-1]==0)
        temp2[pos-1]=1;
    else
        temp2[pos-1]=0;
    printf("\nError Corrected: ");
    for(i=0;i<nh;i++)
    {
        printf("%d ",temp2[i]);
    }
    printf("\n",nd);
    system("pause");
}

int main()
{
    while(1)
    {
        start:
        system("cls");
        int choice;
        cout<<"Error Detection and Correction Algorithms (MENU): \n      [BY VIBHU KUMAR SINGH]\n\n1. Vertical Redundancy Check\n2. Longitudinal Redundancy Check \n3. Checksum\n4. Cyclic Redundancy Check \n5. Hamming Code \n0. Exit\nEnter your choice: ";
        cin>>choice;
        cout<<"<-------------------------------------------------------------------------------->\n\n";
        switch(choice)
        {
            case 1:
                vrc_main();
            break;
            case 2:
                lrc();
            break;  
            case 3:
            start_checksum:
                checksum();
            break;
            case 4:
                crc();
            break;
            case 5:
                hamming();
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

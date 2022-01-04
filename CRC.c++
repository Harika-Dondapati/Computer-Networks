#include <iostream>
#include <string.h>
using namespace std;

/* defining class name CRC and the strings */

class CRC{
    string input,divisor,divident,result;

    /* defining variables here */

    int len_divident, len_gen, len_inp;

 public:

 /* declaring string XOR function */

 string Fun_Xor(string a, string b)
 {
     string result = " ";

     /* checking 0th element is 0 or not */
     if(a[0]=='0')
     {

     /*if it is 0 then return a, .substring   */
         return a.substr(1);
     }
     else
     {
         for(int i=0;i<len_gen;i++)
         {
             result = result + (a[i]==b[i] ? '0':'1');
         }
         return result.substr(1);
     }
 }
    void modulo_div()
    {
        string temp_div = divisor;

        /* subSting function is when we pass 2 arguments then 1st and 2nd arguments
        are start and end points of the substring will consider */

        string temp_divident = divident.substr(0,len_gen);
        int j = len_gen;
        while(j<len_divident)
        {

        /* XOR Function will consider number of dividend is equal to number of divisor */
        /* temp_divident is a 1st argument and temp_divisor is 2nd argument */

        temp_divident = Fun_Xor(temp_divident,temp_div);
        temp_divident = temp_divident + divident[j];
        j++;
        }
        result = input+Fun_Xor(temp_divident, temp_div);
    }
    void Getdata()
    {

    /* Asking user to enter input and coefficients of generator polynomial */

        cout<<"Enter Input: ";
        cin>>input;
        cout<<" Enter coefficients of generator polynomial:";

      /* input variable and divisor */

        cin>>divisor;

     /* we calculate the divisor length and input length using length function */

        len_gen = divisor.length();
         len_inp = input.length();

         /* Now our input variable is dividend variable */

        divident = input;

        /* we declare r to add number of zeros equal to one less than the  number of
           coefficients of divisor */

        int r = len_gen-1;

        /* Iterating */
        for(int i=0;i<r;i++)
        {
            divident=divident +'0';
        }
        len_divident=divident.length();
        modulo_div();
    }

void Sender_Side()
{
    cout<<"input: "<<input<<"\n";
    cout<<"polynomial: "<<divisor<<"\n";
    cout<<"Divident: "<<divident<<"\n";
    cout<<"Data to send: "<<result<<"\n";

}
void Receiver_Side()
{
    string data_rec;
    cout<<"\nEnter Data Received: ";
    cin>>data_rec;

    string temp_div=divisor;
    string temp_divident = data_rec.substr(0,len_gen);
    int j=len_gen;
    while(j<data_rec.length())
    {
        temp_divident =Fun_Xor(temp_divident,temp_div);
        temp_divident=temp_divident+data_rec[j];
        j++;
    }
    string error=Fun_Xor(temp_divident,temp_div);
 cout<<"remainder is:"<<error;

 bool flag=0;
 for(int i=0;i<len_gen-1;i++)
    {
        if(error[i]=='1')
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<" /n correct Data Received Without any Error";
    else
    cout<<" /n Data Receieved Contain Some Error";
}

};
/* Instantaneous our CRC class and object name as crc */
/* Getdata Sender_side Receiver_Side are the main functions I used */
int main(){
    CRC crc;
    crc.Getdata();
    crc.Sender_Side();
    crc.Receiver_Side();
    return 0;
}

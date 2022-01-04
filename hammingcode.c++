#include<iostream>

using namespace std;

int main() {
    int x[10];
    int y[10],c,c1,c2,c3,i;

    cout<<"Enter 4 bits of data one by one\n";
    cin>>x[0];
    cin>>x[1];
    cin>>x[2];
    cin>>x[4];

    //Calculation of even parity
    x[6]=x[0]^x[2]^x[4];
x[5]=x[0]^x[1]^x[4];
x[3]=x[0]^x[1]^x[2];

cout<<"\nEncoded data is\n";
for(i=0;i<7;i++)
        cout<<x[i];

cout<<"\n\nEnter received data bits one by one\n";
    for(i=0;i<7;i++)
        cin>>y[i];

    c1=y[6]^y[4]^y[2]^y[0];
c2=y[5]^y[4]^y[1]^y[0];
c3=y[3]^y[2]^y[1]^y[0];
c=c3*4+c2*2+c1 ;

    if(c==0) {
cout<<"\nNo error while transmission of data\n";
    }
else {
cout<<"\nError on position "<<c;
cout<<"\nData sent : ";
for(i=0;i<7;i++)
         cout<<x[i];

cout<<"\nData received : ";
        for(i=0;i<7;i++)
         cout<<y[i];

cout<<"\nCorrect message is\n";

//if errorneous bit is 0 we complement it else vice versa
if(y[7-c]==0)
y[7-c]=1;
        else
y[7-c]=0;
for (i=0;i<7;i++) {
cout<<y[i];
}
}
return 0;
}

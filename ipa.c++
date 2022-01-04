#include <stdio.h>
int main ()
{
    int ipadd_old[4],ip_new_na[4],ip_new_ba[4];
    int ref []={256,128,64,32,16,8,4,2,1};
    int i,cidr,q,r,delta,temp1,temp2,temp3;
    printf("Please enter ip address octet 1 by 1\n");
    for(i=0;i<4;i++)
    {
        scanf("%d",&ipadd_old[i]);
    }
    printf("\nEntered ip address is\n");
    printf("%d.%d.%d.%d\n\n",ipadd_old[0],ipadd_old[1],ipadd_old[2],ipadd_old[3]);
    if(ipadd_old[0]>=0&&ipadd_old[0]<=127)
    {
        printf("class is A\n");
    }
    else if(ipadd_old[0]>=128&&ipadd_old[0]<=191)
    {
        printf("class is B\n");
    }
    else if(ipadd_old[0]>=192&&ipadd_old[0]<=223)
    {
        printf("class is C\n");
    }
    else if(ipadd_old[0]>=224&&ipadd_old[0]<=239)
    {
        printf("class is D\n");
    }
    else if(ipadd_old[0]>=240&&ipadd_old[0]<=255)
    {
        printf("class is E\n");
    }
    if(ipadd_old[0]<255&&ipadd_old[0]>0&&ipadd_old[1]<255&&ipadd_old[1]>0&&ipadd_old[2]<255&&ipadd_old[2]>0&&ipadd_old[3]<255&&ipadd_old[3]>0)
    {
        printf("valid ip address\n");
        printf("enter the cidr value\n");
        scanf("%d",&cidr);

        if(cidr<32&&cidr>0)
        {
            printf("\nValid cidr\n\n");
            q=cidr/8;
            r=cidr%8;
            delta=ref[r];
            temp1=ipadd_old[3]/delta;
            temp2=delta*temp1;
            temp3=temp2+delta-1;
            if (q == 4)
            {
                ip_new_na [0] = ipadd_old[0];
                ip_new_na [1] = ipadd_old[1];
                ip_new_na [2] = ipadd_old[2];
                ip_new_na [3] = 0;
                ip_new_ba [0] = ipadd_old[0];
                ip_new_ba [1] = ipadd_old[1];
                ip_new_ba [2] = ipadd_old[2];
                ip_new_ba [3] = 255;
            }
            else if(q==3)
            {
                ip_new_na[0]=ipadd_old[0];
                ip_new_na[1]=ipadd_old[1];
                ip_new_na[2]=ipadd_old[2];
                ip_new_na[3]=temp2;
                ip_new_ba[0]=ipadd_old[0];
                ip_new_ba[1]=ipadd_old[1];
                ip_new_ba[2]=ipadd_old[2];
                ip_new_ba[3]=temp3;
            }
            else if(q==2)
            {
                ip_new_na[0]=ipadd_old[0];
                ip_new_na[1]=ipadd_old[1];
                ip_new_na[2]=temp2;
                ip_new_na[3]=0;
                ip_new_ba[0]=ipadd_old[0];
                ip_new_ba[1]=ipadd_old[1];
                ip_new_ba[2]=temp3;
                ip_new_ba[3]=255;
            }
            else if(q==1)
            {
                ip_new_na[0]=ipadd_old[0];
                ip_new_na[1]=temp2;
                ip_new_na[2]=0;
                ip_new_na[3]=0;
                ip_new_ba[0]=ipadd_old[0];
                ip_new_ba[1]=temp3;
                ip_new_ba[2]=255;
                ip_new_ba[3]=255;
            }
            else if(q==0)
            {
                ip_new_na[0]=temp2;
                ip_new_na[1]=0;
                ip_new_na[2]=0;
                ip_new_na[3]=0;
                ip_new_ba[0]=temp3;
                ip_new_ba[1]=255;
                ip_new_ba[2]=255;
                ip_new_ba[3]=255;
            }
            printf("Network ip address is\n");
            printf("%d.%d.%d.%d\n\n",ip_new_na[0],ip_new_na[1],ip_new_na[2],ip_new_na[3]);
            printf("Broadcast ip address is\n");
            printf("%d.%d.%d.%d\n",ip_new_ba[0],ip_new_ba[1],ip_new_ba[2],ip_new_ba[3]);
        }

        else
        {
            printf("Invalid cidr\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid ip address\n");
        return 0;
    }
    return 0;
}

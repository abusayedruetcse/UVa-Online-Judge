#include<iostream>
#include<stdio.h>
using namespace std;
int n,source[101],time[101],duration[101],target[101];
int call_forward(int s,int t_time,int t_extension)
{
    for(int i=0;i<n;i++)
    {
        if(source[i]==t_extension)
        {
            if(t_time<time[i])
            {
                return t_extension;
            }
            if((time[i]+duration[i])%8784>=t_time)
            {
                if(s==target[i])
                    return 9999;

                return call_forward(s,t_time,target[i]);
            }
        }
    }
    return t_extension; // not found t_extension.
}
int main()
{
    int TC,a,b;
    cin>>TC;
    cout<<"CALL FORWARDING OUTPUT\n";
    for(int cas=1;cas<=TC;cas++)
    {
        cout<<"SYSTEM "<<cas<<endl;
        int i=0;
        scanf("%d ",&source[i]);
        while(source[i]!=0)
        {
            scanf("%d %d %d",&time[i],&duration[i],&target[i]);
            i++;
            scanf("%d ",&source[i]);
        }
        n=i;


        scanf("%d",&a);
        while(a!=9000)
        {
            scanf("%d",&b);
            printf("AT %04d CALL TO %04d RINGS %04d\n",a,b,call_forward(b,a,b));
            scanf("%d",&a);
        }
    }
    cout<<"END OF OUTPUT\n";


    return 0;
}

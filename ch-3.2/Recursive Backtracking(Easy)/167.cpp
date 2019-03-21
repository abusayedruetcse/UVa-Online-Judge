#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define n 8
int board[n][n];
int Max;
int row[n];
bool place(int r,int c)
{
    bool flag=true;
    for(int i=0;i<c;i++)
    {
        if(row[i]==r||abs(row[i]-r)==abs(i-c))
        {
            flag=false;
            break;
        }
    }
    return flag;

}
void backtrack(int c)
{
    if(c==n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=board[row[i]][i];
        }
        if(sum>Max)
        {
            Max=sum;
        }
    }
    for(int r=0;r<n;r++)
    {
        if(place(r,c))
        {
            row[c]=r;
            backtrack(c+1);
        }
    }
}
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        Max=0;
        memset(row,0,sizeof(row));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>board[i][j];
            }
        }
        backtrack(0);
        printf("%5.0d\n",Max);
    }
    return 0;
}

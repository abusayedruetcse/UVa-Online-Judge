#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int row[8],T,a,b,line;
bool place(int r,int c)
{
    for(int prev=0;prev<c;prev++)
        if(row[prev]==r||abs(r-row[prev])==abs(c-prev))
            return false;
    return true;
}
void backtrack(int c)
{
    if(c==8&&row[b]==a)
    {
        printf("%2d         ",++line);
        for(int j=0;j<8;j++)
            cout<<row[j]+1<<" ";
        cout<<endl;
        return ;
    }
    for(int r=0;r<8;r++)
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
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        a--;
        b--;
        memset(row,0,sizeof row);
        printf("SOLN            COLUMN\n");
        printf(" #         1 2 3 4 5 6 7 8\n\n");
        line=0;
        backtrack(0);
        if(T)
            cout<<endl;

    }

    return 0;
}

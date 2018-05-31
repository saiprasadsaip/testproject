#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c[]=")))))((((";int cc=0;
    for(int i=0;i<9;i++)
    {

        if(c[i]=='(')
        {
            for(int j=i+1;j<9;j++)
            {

                if(c[j]==')')
                {
                    cc=cc+2;
                    c[j]='$';break;
                }
            }
        }
    }
    cout<<cc;
    return 0;

}

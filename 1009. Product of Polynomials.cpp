//题目链接：https://www.patest.cn/contests/pat-a-practise/1009

#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int k;
    int index;
    float num;
    float a[1001];
    float b[1001];//result
    float c[2001];

    for(int i=0;i<1001;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    //input
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>index>>num;
        a[index]=num;
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>index>>num;
        b[index]=num;
    }

    //calculate
    for(int i=0;i<2001;i++)
        c[i]=0;
    for(int i=0;i<1001;i++)
    {
        if(fabs(a[i])<1e-4) //discard a[i]==0;
            continue;
        else
        {
            for(int j=0;j<1001;j++)
            {
                if(fabs(b[j])>1e-4)
                {
                    c[i+j] += a[i]*b[j];
                }
            }
        }
    }

    int count_sum=0;
    for(int i=0;i<2001;i++)
    {
        if(fabs(c[i])>1e-4)
            count_sum+=1;
    }

    cout<<count_sum;
    for(int i=2000;i>=0;i--)
    {
        if(fabs(c[i])>1e-4)
            printf(" %d %.1f", i, c[i]);
    }

    return 0;
}

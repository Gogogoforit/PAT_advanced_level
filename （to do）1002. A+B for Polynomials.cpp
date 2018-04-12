//题目链接在这儿：https://www.patest.cn/contests/pat-a-practise/1002
//25分拿了15分，有几个测试点有问题


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
    /*test
    for(int i=0;i<10;i++)
    {
        if(a[i]!=0)
            cout<<i<<":"<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        if(b[i]!=0)
            cout<<i<<":"<<b[i]<<" ";
    }
    cout<<endl;
    */

    for(int i=0;i<1001;i++)
    {
        b[i]+=a[i];
    }
    /*
    for(int i=0;i<10;i++)
    {
        if(b[i]!=0)
            cout<<i<<":"<<b[i]<<" ";
    }
    cout<<endl;
    */

    //cerr<<"test"<<fabs(-5)<<endl;
    //calculate

    int count_sum=0;
    for(int i=0;i<1001;i++)
    {
        if(fabs(b[i])>1e-2)
            count_sum+=1;
        else
            b[i]=0;
    }


    cout<<count_sum<<" ";
    int step=0;
    for(int i=1000;i>=0;i--)
    {
        if(b[i]!=0)
        {
            cout<<i<<" ";
            cout.precision(2);
            cout<<b[i];
            step++;
            if(step!=count_sum)
                cout<<" ";
        }
    }

    return 0;
}

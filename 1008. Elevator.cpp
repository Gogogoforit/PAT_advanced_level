//题目链接：https://www.patest.cn/contests/pat-a-practise/1008

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int a[N+1];
    a[0]=0;
    for(int i=1;i<N+1;i++)
    {
        cin>>a[i];
    }
    int move_time=0;
    for(int i=0;i<N;i++)
    {
        if(a[i+1]>a[i])
            move_time += (a[i+1]-a[i])*6;
        else
            move_time += (a[i]-a[i+1])*4;
    }
    int stop_time;
    stop_time=N*5;
    cout<<stop_time+move_time;
    return 0;
}

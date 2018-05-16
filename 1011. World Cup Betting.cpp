//题目链接：https://www.patest.cn/contests/pat-a-practise/1011

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float a[3][3];
    for(int i=0;i<3;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    float sum=1.0;

    for(int i=0;i<3;i++){
        if(a[i][0]>a[i][1] && a[i][0]>a[i][2]){
            cout<<"W ";
            sum *= a[i][0];
            continue;
        }
        else if(a[i][1]>a[i][0] && a[i][1]>a[i][2]){
            cout<<"T ";
            sum *= a[i][1];
            continue;
        }
        else{
            cout<<"L ";
            sum *= a[i][2];
            continue;
        }
    }
    printf("%.2f",(sum*0.65-1)*2);
    return 0;
}

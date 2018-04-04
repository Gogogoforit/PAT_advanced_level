//题目链接在这里：https://www.patest.cn/contests/pat-a-practise/1006
//很简单，没啥可说的。。。
#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    cin>>n;//一共n组数字
    string id[n];
    int in_h[n],in_m[n],in_s[n];
    int out_h[n],out_m[n],out_s[n];
    char temp;
    for(int i=0;i<n;i++)
        cin>>id[i]>>in_h[i]>>temp>>in_m[i]>>temp>>in_s[i]>>out_h[i]>>temp>>out_m[i]>>temp>>out_s[i];
        //cin>>id[i]>>time_in[i]>>time_out[i];
    //for(int i=0;i<n;i++)
     //   cerr<<id[i]<<" "<<in_h[i]<<temp<<in_m[i]<<temp<<in_s[i]<<" "<<out_h[i]<<temp<<out_m[i]<<temp<<out_s[i]<<endl;


    string unlocked,locked;
    int earlest_time=INT_MAX;
    int latest_time=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(in_h[i]*60*60+in_m[i]*60+in_s[i]<earlest_time)
        {
            unlocked=id[i];
            earlest_time=in_h[i]*60*60+in_m[i]*60+in_s[i];
        }
        if(out_h[i]*60*60+out_m[i]*60+out_s[i]>latest_time)
        {
            locked=id[i];
            latest_time=out_h[i]*60*60+out_m[i]*60+out_s[i];
        }
    }
    cout<<unlocked<<" "<<locked;
}

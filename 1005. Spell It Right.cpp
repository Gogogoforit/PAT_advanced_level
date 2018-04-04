//题目链接在这里：https://www.patest.cn/contests/pat-a-practise/1005

#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
    string input;
    cin>>input;
    int sum=0;
    int length=input.length();
    for(int i=0;i<length;i++)//这里不直接用数字的原因是，测试样例可能太大了。。。。
    {
        stringstream ss;
        int temp=0;
        ss<<input[i];
        ss>>temp;
        sum+=temp;
    }
    //接下来依次输出，脑残打表即可
    if(sum==0) //特殊情况
        cout<<"zero";
    stack<int>s;
    while(sum >=1)
    {
        int temp=sum%10;
        s.push(temp);
        sum/=10;
    }
    //cerr<<"sum:"<<sum<<endl;

    int len=s.size();
    for(int i=0;i<len;i++)
    {
        int out=s.top();
        switch (out)
        {
        case 0:
            cout<<"zero";
            break;
        case 1:
            cout<<"one";
            break;
        case 2:
            cout<<"two";
            break;
        case 3:
            cout<<"three";
            break;
        case 4:
            cout<<"four";
            break;
        case 5:
            cout<<"five";
            break;
        case 6:
            cout<<"six";
            break;
        case 7:
            cout<<"seven";
            break;
        case 8:
            cout<<"eight";
            break;
        case 9:
            cout<<"nine";
            break;
        }
        if(i!=(len-1))
            cout<<" ";
        s.pop();
    }
}

//8个测试点，只对了4个，还有一个“段错误”，不明白什么意思，，坑先放在这里，之后填
//题目链接：https://www.patest.cn/contests/pat-a-practise/1007

#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int K;
    cin>>K;
    int in[K];
    int index_i=INT_MIN;
    int index_j=INT_MIN;
    for(int i=0;i<K;i++){
        cin>> in[i];
    }

    cerr<<"in[K] is :";
    for(int i=0;i<K;i++){
        cerr<<in[i]<<" ";
    }


    int matrix[K][K];
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++)
            matrix[i][j]=0; //initialization
    }
    int max_num= INT_MIN;
    bool first_time=true;

    for(int i=K-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(i==K-1)
                matrix[i][j]= in[j];//last row
            else
                matrix[i][j]= matrix[i+1][j]+in[j+K-i-1];

            if(matrix[i][j]>=max_num){
                if(first_time){
                    cerr<<"point #1"<<endl;
                    max_num= matrix[i][j];
                    index_i=i;
                    index_j=j;
                    first_time=false;
                    cerr<<"max_num: "<<max_num<<endl;
                }
                else if(i<=index_i || j <=index_j){
                    cerr<<"point #2"<<endl;
                    max_num= matrix[i][j];
                    index_i=i;
                    index_j=j;
                    cerr<<"max_num: "<<max_num<<endl;
                }
            }
        }
    }

    for(int i=0;i<K;i++){
        cerr<<endl;
        for(int j=0;j<K;j++)
            cerr<<matrix[i][j]<<" "; //initialization
    }


    if (max_num>0)
        cout<<max_num<<" "<<in[index_j]<<" "<< in[index_j+K-index_i-1];
    else
        cout<<0<<" "<<in[0]<<" "<<in[K-1];


    return 0;
}

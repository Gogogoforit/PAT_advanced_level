
//题目链接：https://www.patest.cn/contests/pat-a-practise/1007

#include <iostream>
#include <limits.h>

using namespace std;

int main()

{
    int K;
    cin>>K;
    int in[K];
    int sum = 0;
    int max_sum=INT_MIN;
    int index_i, index_j;
    index_i=index_j=-1;

    for(int i=0;i<K;i++){
        cin>> in[i];
    }
    
    for(int i=0;i<K;i++)
    {
        sum=0;
      for(int j=i;j<K;j++)
        {
          sum +=in[j];
            if(sum>max_sum){
              index_i=i;
                    index_j=j;
                    max_sum=sum;
                }
        }
    }
  
    if(max_sum<0)
      cout<<0<<" "<<in[0]<<" "<<in[K-1];
    else
      cout<<max_sum<<" "<<in[index_i]<<" "<<in[index_j];

    return 0;
}

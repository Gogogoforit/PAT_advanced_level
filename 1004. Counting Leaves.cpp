//题目链接在这儿：https://www.patest.cn/contests/pat-a-practise/1004

#include <iostream>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;

    int layer[N],sequence[N],non_leave[N];
    for(int i=0;i<N;i++){
        layer[i]=-1; //root starts from layer 0, next layer is layer 1. -1 for default
        sequence[i]=-1;//to record each one's father node
        non_leave[i]=0;//1 for non-leave, 0 for leave
    }

    int father,K;

    for(int i=0;i<M;i++)
    {
        cin>>father>>K;
        for(int j=0;j<K;j++)
        {
            int temp;
            cin>>temp;
            sequence[temp-1]=father;
        }
        non_leave[father-1]=1;
    }

    /*test
    for(int i=0;i<N;i++)
    {
        cout<<sequence[i]<<" ";
    }

    12 6
    1 3 2 3 4
    2 2 5 6
    4 1 7
    5 2 8 9
    6 2 10 11
    7 1 12
    */
    int max_depth=0;
    while(layer[N-1]==-1)
    {
        for(int i=0;i<N;i++)
        {
            if(sequence[i]==-1)
            {//initial state
                layer[i]=0;
                continue;
            }
            if(layer[sequence[i]-1]!=-1)
                layer[i]=layer[sequence[i]-1]+1;

            if(layer[i]>max_depth)
                max_depth=layer[i];
        }
    }

    /*test
    cout<<endl<<"Final result:"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<layer[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<non_leave[i]<<" ";
    }
    cout<<endl<<"max_depth:"<<max_depth<<endl;
    */

    for(int i=0;i<=max_depth; i++)
    {
        int num=0;
        for(int j=0;j<N;j++)
        {
            if(layer[j]==i && non_leave[j]==0)
                num++;
        }
        cout<<num;
        if(i!=max_depth)
            cout<<" ";
    }
}


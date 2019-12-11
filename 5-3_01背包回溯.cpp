#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

int number,w[MAX],v[MAX],capacity,dp[MAX][MAX] = {0},item[MAX] = {0};

void FindMax()//动态规划
{
    int i,j;
    //填表
    for(i=1;i<=number;i++)
    {
        for(j=1;j<=capacity;j++)
        {
            if(j<w[i])//包装不进
            {
                dp[i][j]=dp[i-1][j];
            }
            else//能装
            {
                if(dp[i-1][j]>dp[i-1][j-w[i]]+v[i])//不装价值大
                {
                    dp[i][j]=dp[i-1][j];
                }
                else//前i-1个物品的最优解与第i个物品的价值之和更大
                {
                    dp[i][j]=dp[i-1][j-w[i]]+v[i];
                }
            }
        }
    }
}

void FindWhat(int i,int j)//寻找解的组成方式
{
    if(i>=0)
    {
        if(dp[i][j]==dp[i-1][j])//相等说明没装
        {
            item[i]=0;//全局变量，标记未被选中
            FindWhat(i-1,j);
        }
        else if( j-w[i]>=0 && dp[i][j]==dp[i-1][j-w[i]]+v[i] )
        {
            item[i]=1;//标记已被选中
            FindWhat(i-1,j-w[i]);//回到装包之前的位置
        }
    }
}

int main(){
    
    while(cin>>number){
        cin>>capacity;
        for(int i = 1; i < number+1; i++){
            cin>>w[i]>>v[i];
        }
        FindMax();
        cout<<dp[number+1][capacity];//输出最大价值
        FindWhat(number,capacity);
        cout<<endl;
        for(int i = 1; i < number+1; i++){//输出最优解
            cout<<item[i]<<" ";
        }
    
    }
    return 0;
}
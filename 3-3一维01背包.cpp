#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

/**
 * 没有空间优化的01一维01背包
 * 
int dp[MAX][MAX];//关于价值的dp
int c[MAX];//物品价值
int a[MAX];//物品体积
int b;//背包总体积
int n;//物品数量

int simpleBag(){//简单
    memset(dp,0,MAX*MAX*sizeof(int));
    int i,j;
    for(i = 1; i < n; i++){//遍历物品
        for(j = 1; j < b; j++){//遍历体积
            if(j < a[i]){//放不下，只能不放
                dp[i][j] = dp[i-1][j];//与查看上一个物品时相同
            }else{//放得下
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]]+c[i]);//不放或者放，取较大的。
                //j-a[i]：背包容量减去当前物品剩余的重量
            }
        }
    }
    returndp[n-1][b-1];
}

**/

int dp[MAX];//关于价值的dp
int c[MAX];//物品价值
int a[MAX];//物品体积
int b;//背包总体积
int n;//物品数量

int BetterBag(){//空间优化
    memset(dp,0,MAX*sizeof(int));
    int i,j;
    for(i = 1; i < n; i++){//遍历物品
        for(j = 1; j < b; j++){//遍历体积
            if(j < a[i]){//放不下，只能不放
                dp[j] = dp[j];//与查看上一个物品时相同
            }else{//放得下
                dp[j] = max(dp[j],dp[j-a[i]]+c[i]);//不放或者放，取较大的。
                //j-a[i]：背包容量减去当前物品剩余的重量
            }
        }
    }
    return dp[b-1];
}

int main(){
    return 0;
}


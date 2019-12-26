/**
 * 最长上升子序列
 * 
 * 问题定义：
 * 假设我们有一个序列 b i，当b1 < b2 < … < bS的时候，我们称这个序列是上升的。
 * 对于给定的一个序列(a1, a2, …, aN)，我们也可以从中得到一些上升的子序列(ai1, ai2, …, aiK)，
 * 这里1 <= i1 < i2 < … < iK <= N，但必须按照从前到后的顺序。
 * 
 * 解题思路：
 * 序列中的位置k为状态
 * 状态k对应的值为以ak为终点的最长上升子序列的长度
 * 1、遍历序列
 * 2、当前元素a[i]大于i之前的元素a[j]，且dp[j]的序列长度大于max，则更新max。
 * 3、更新以i元素结尾的最长子序列长度
 * 4、判断以i元素为结尾的上升子序列，是否为整个序列的最长上升子序列
 * 5、重复2、3、4直到遍历结束
 * 
 **/
#include <iostream>
using namespace std;
#define MAX 100

int main(){
    int n,a[MAX],dp[MAX];
    while(cin>>n){
        for(int i = 0; i < n; i++ ){
            cin>>a[i];//输入一个序列
            dp[i] = 1;//初始化dp数组为1，每个元素的最长子序列都至少为1
        }
        int i,j,ans = 0;
        for(i = 1; i < n; i++){//遍历序列
            int max = 0;
            for(j = i-1; j > -1; j--){
                if(a[i] > a[j]&& dp[j] > max)//当前元素a[i]是否大于i之前的元素a[j]，且dp[j]的序列长度大于max，则更新max
                    max = dp[j];
            }
            dp[i] += max;//更新以i元素结尾的最长子序列长度
            if(ans<dp[i])//判断以i元素为结尾的上升子序列，是否为整个序列的最长上升子序列
                ans = dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}


/**
 * 最长上上升子序列
 * 序列中的位置k为状态
 * 状态k对应的值为以ak为终点的最长上升子序列的长度
 **/
#include <iostream>
using namespace std;
#define MAX 100

int main(){
    int n,a[MAX],dp[MAX];
    while(cin>>n){
        for(int i = 0; i < n; i++ ){
            cin>>a[i];
            dp[i] = 1;
        }
        int i,j,ans = 0;
        for(i = 1; i < n; i++){
            int max = 0;
            for(j = i-1; j > -1; j--){
                if(a[i] > a[j]&& dp[j] > max)
                    max = dp[j];
            }
            dp[i] += max;
            if(ans<dp[i])
                ans = dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}


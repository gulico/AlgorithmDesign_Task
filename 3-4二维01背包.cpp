#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

int main(){
    int n,w[MAX],b[MAX],v[MAX],c,d,dp[MAX][MAX];
    while(cin>>n){
        cin>>c>>d;
        for(int i = 1; i < n+1; i++){
            cin>>w[i]>>b[i]>>v[i];
        }
        int i,j,k;
        for(i = 0; i < c; i++){
            for(j = 0; j < d; j++){
                dp[i][j] = 0;
            }
        }
        for(k = 0; k < n; k++){//遍历物品
            for(i = 1;i < c; i++){//容量
                for(j = 1; j < d; j++){//容积
                    if(i<w[k]||j<v[k]){//装不下
                        dp[i][j] = dp[i][j];
                    }else{//装得下
                        dp[i][j] = max(c,dp[i-w[k]][j-b[k]]+v[k]);
                    }
                    
                }
            }
        }
        cout<<dp[c][d]<<endl;
    }
    return 0;
}
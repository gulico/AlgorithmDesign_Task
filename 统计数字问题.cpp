#include<stdio.h>
#include<math.h>

int func(int n){//参数n为位数
    if(n==1)
        return 1;
    int ans = 10*func(n-1)+pow(10,n-1);
    //printf("返回：%d\n",ans);
    return ans;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans[11] = {0};
        int max_wei = 10;
        int wei = 1;
        while(n/max_wei>9){//求最高位
            max_wei = max_wei*10;
            wei++;
        }
        for(int i = 0;i < wei; i++){//去除前导0
            ans[0] = ans [0] - pow(10,wei-i);
        }
        //printf("ans[0]:%d\n",ans[0]);
        //printf("max_wei:%d\n",max_wei);
        while(wei){
            int max_wei_num = n/max_wei;//最高位数字
            int num = max_wei_num*func(wei);//除去最高位，剩下m-1位用递推公式求得的数字出现的个数
            //printf("%d\n",num);
            for(int i = 0; i < 10; i++){
                ans[i] = ans[i] + num;
            }
                
        
            for(int i = 0; i < max_wei_num;i++)//最高位出现的数字出现的次数
                ans[i] = ans[i] + max_wei;

            n = n - max_wei * max_wei_num;//抛掉最高位
            max_wei = max_wei/10;
            wei --;

            ans[max_wei_num] = ans[max_wei_num] + n + 1;
        }
        for(int i = 0; i < 10; i++){
            printf("%d ",ans[i]);
        }
        printf("\n"); 
    }
    return 0;
}
/**
 * 问题描述：一本书的页码从1开始顺序编码直接到自然数n.
 * 每个页码都不含多余的前导数字0。
 * 例如， 第6页用数字6表示，而不是06、006等。
 * 数字统计问题要求给定书的总页码，计算出全部页码中分别用到多少次数字0，1，2，---，9
 * 
 * 思路：
 * 1、从1到n遍历位数长度
 * 2、计算位数长度为i下，除了最高位以外，剩下的数字出现的次数 = 最高位数字*10*func(n-1)+10^(n-1);
 * 3、计算最高位出现的数字个数。从0到max_wei_num的数字都出现了max_wei次看，如100-299，最高位1和2各出现了一百次
 * 4、抛掉最高位，重复2、3
 * 5、减去前导0：前导零的个数 = 10^(wei-1)+10^(wei-2)+...+10^(0)
 * 
 * **/

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
        int max_wei = 10;//最高位
        int wei = 1;//位数
        while(n/max_wei>9){//求最高位
            max_wei = max_wei*10;
            wei++;
        }
        for(int i = 0;i < wei; i++){//去除前导0
            ans[0] = ans [0] - pow(10,wei-i);//前导零的个数 = 10^(wei-1)+10^(wei-2)+...+10^(0)
        }
        //printf("ans[0]:%d\n",ans[0]);
        //printf("max_wei:%d\n",max_wei);
        while(wei){
            int max_wei_num = n/max_wei;//最高位数字
            int num = max_wei_num*func(wei);//除去最高位，剩下m-1位用递推公式求得的数字出现的个数
            //printf("%d\n",num);
            for(int i = 0; i < 10; i++){//每一位数字都一样
                ans[i] = ans[i] + num;
            }
            for(int i = 0; i < max_wei_num;i++)//最高位出现的数字，从0到max_wei_num的数字都出现了max_wei次看，如100-299，最高位1和2各出现了一百次
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
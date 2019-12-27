/**
 * 问题描述：
 * 对于任意长度不超过6的所谓升序字符串，迅速计算出它在上述字典中的编码。
 * 
 * 例子：需要注意的是字符串是升序的，比如az下一个是bc而不是ba。
 * 拿dgh来说一下思路，
 * 1、首先判断字符串长度为3，先算长度为1和2的所有情况，
 *    即从26个字母中选1个或两个字母，因为是升序，即sum=C（26，1）+C（26，2）；
 *    再看字符串的第一个字符，为'd',之前有以a,b,c开头的长度为3的字符串，
 *    以a开头，后边2位需要在25个字母中选择（除了a），
 *    以b开头的后2位需要在24个字母中选择（除了a,b），
 *    以c开头的在23个字母（除了a,b,c）中选择，
 *    即sum+=(C(25,2)+C(24,2)+C(23,2));
 * 2、之后再看下一个字母'g'，d与g之间有e,f,
 *    需要算以de开头以及以df开头的所有情况，即sum+=(C(21,1)+C(20,1)),
 * 最后再加上'h'-'g'+1;
 *
**/
#include<stdio.h>
#include<string.h>

int combin(int n,int m){//组合
  int ans = 1;
  for(int i = n - m + 1; i < n + 1; i++){//分子
    ans = ans * i;
  }
  for(int i = 2; i < m + 1; i++){//分母
    ans = ans / i;
  }
  return ans;
}

int main(){
  char str[10];
  while(~scanf("%s",str)){
    int sum = 0;
    int len = strlen(str);
    for(int i = 0; i < len-1;i++){//长度小于最大长度的所有情况都要考虑
      sum = sum + combin(26-i,i+1);
    }
    char temp = 'a'-1;
    if(len>1){
      for(int i = 0; i < len-1; i++){//遍历从最前面的字母开始的所有字母
        for(int j = temp + 1; j < str[i] ; j++){//计算当前字母与前一个字母之间，存在几个字母。比如字母'g'，d与g之间有e,f，两个字母
          sum = sum + combin(26-(j-temp),len-i-1);//计算中间的字母的组合，如de开头以及以df开头的所有情况，即sum+=(C(21,1)+C(20,1))
          printf("i:%d j:%d %d\n",i,j,sum);
        }
        temp = str[i];//置当前字母为，下一个字母的前一个字母
      } 
   }
    if(len > 1)
      sum = sum + str[len-1] - str[len-2] ;
    else
      sum = sum + str[len-1] - 'a' + 1;
    printf("%d\n",sum);
  }
  return 0;
}
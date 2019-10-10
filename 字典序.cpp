#include<stdio.h>
#include<string.h>

int combin(int n,int m){//组合
  int ans = 1;
  for(int i = n - m + 1; i < n + 1; i++){
    ans = ans * i;
  }
  for(int i = 2; i < m + 1; i++){
    ans = ans / i;
  }
  return ans;
}

int main(){
  char str[10];
  while(~scanf("%s",str)){
    int sum = 0;
    int len = strlen(str);
    for(int i = 0; i < len-1;i++){
      sum = sum + combin(26-i,i+1);
    }
    char temp = 'a'-1;
    if(len>1){
      for(int i = 0; i < len-1; i++){
        for(int j = temp + 1; j < str[i] ; j++){
          sum = sum + combin(26-(j-temp),len-i-1);
          printf("i:%d j:%d %d\n",i,j,sum);
        }
        temp = str[i];
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
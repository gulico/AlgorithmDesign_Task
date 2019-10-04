#include<stdio.h>
#include<limits>
using namespace std;

#define MAX 100

double d[MAX];
double tmp[MAX][MAX];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        
        double max = numeric_limits<double>::min();
        double min = numeric_limits<double>::max();
        for(int i = 0; i < MAX;i++){//[0]该行个数；[1]该行最小值；[2]该行最大值
            tmp[i][0] = 0;
            tmp[i][1] = numeric_limits<double>::max();
            tmp[i][2] = numeric_limits<double>::min();
        }
        for(int i = 0; i < n; i++ ){ //输入，顺表找到全部数据的最小值和最大值
            scanf("%lf",&d[i]);
            if(d[i]>max){
                max = d[i];
            }
            if(d[i]<min){
                min = d[i];
            }
        }

        int len = (max-min)/(n-2);//区间长度
        if(len == 0){//特判，最大最小值之间长度不足1
            printf("0\n");
            continue;
        }
        int block_max = 0;//最大区间
        //直接默认所有数据大于0
        for(int i = 0; i < n;  i++ ){//将数据分组，并找到区间最大值和最小值
            int block = (d[i] - min)/len;
            if(block>block_max){
                block_max = block;
            }
            int num = tmp[block][0];
            tmp[block][3+num] = d[i];
            if(d[i]<tmp[block][1]){
                tmp[block][1] = d[i];
            } 
            if(d[i]>tmp[block][2]){
                tmp[block][2] = d[i];
            }
            tmp[block][0]++;
        }
        double ans = 0;
        double cha = 0;
        double left = tmp[0][2];
        double right = left;
        for(int i = 1; i < block_max+1; i++){//寻找最大区间
            if(tmp[i][0]>-1&&tmp[i][0]<1){
                continue;
            }
            right = tmp[i][2];
            cha = right-left;
            if(cha>ans){
                ans = cha;
            }
            left = tmp[i][1];
        }

        printf("%lf\n",ans);

    }
    return 0;
}
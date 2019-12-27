/**
 * 
 * Input.txt
 * 5
 * 2.3 3.1 7.5 1.5 6.3
 * Output.txt
 * 3.2
 * 
 * 核心思想：
 * 1、遍历，找出所有点的最大值和最小值。
 * 2、划分区间　　区间的长度为： len = ( Max - Min ) / ( n - 2 )
 * 3、处理每一个区间
 *      a、求出每一个点对应在哪个区间，( a[i] - Min ) / ( len ) 
 *      b、把每一个点都安放好对应的区间(Block)里面 
 *      c、顺便统计区间里的个数，区间里的左右边界：即 在区间里的最大值和最小值。
 * 4、然后过程中跑就行了，只需要在跑的过程中找出左边区间的最大值，和当前区间最小值进行更新答案，同时更新最后一个右端点。
 * 5、特判两种情况：
 *      a、如果第3步骤出现 长度等于0 时，区间编号求解时：len作为分母，出现这种情况其实答案直接输出0即可。
 *      b、如果出现只有两个数的情况下，如果下标是从0开始更新的，如果处理不好就会在在第一个区间内不更新值。
 * 
 **/

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
            if(block>block_max){//找最大区间
                block_max = block;
            }
            int num = tmp[block][0];
            tmp[block][3+num] = d[i];//将数据投入相应区间
            if(d[i]<tmp[block][1]){//区间最小
                tmp[block][1] = d[i];
            } 
            if(d[i]>tmp[block][2]){//区间最大
                tmp[block][2] = d[i];
            }
            tmp[block][0]++;//该区间数据数量+1
        }
        double ans = 0;
        double cha = 0;
        double left = tmp[0][2];
        double right = left;
        for(int i = 1; i < block_max+1; i++){//寻找最大区间
            if(tmp[i][0]>-1&&tmp[i][0]<1){//该区间没有数据
                continue;
            }
            //该区间有至少一个数据
            right = tmp[i][2];//更新间隙右侧，为该区间的最小值
            cha = right-left;//求间隙
            if(cha>ans){
                ans = cha;
            }
            left = tmp[i][1];//更新间隙左侧为当前区间最大值
        }

        printf("%lf\n",ans);

    }
    return 0;
}
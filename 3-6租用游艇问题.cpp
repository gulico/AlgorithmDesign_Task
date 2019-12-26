/**
 * 租用游艇问题
 * 
 * 问题描述：长江游艇俱乐部在长江上设置了n个游艇出租站1,2,.,n。
 * 游客可在这些游艇出租站租用游艇，并在下游的任何一个游艇出租站归还游艇。
 * 游艇出租站i到游艇出租站j之间的租金为r(i,j),1≤i<j≤n。
 * 试设计一个算法，计算出从游艇出租站1到游艇出租站n所需的最少租金。
 * 
 * input：
 * 第一行出租站个数n，后面n-1行为r(i,j)
 * 3
 * 5 15
 * 7
 * output：
 * 12
 * 
 **/
#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

#define MAX 201

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int n = 0 ,a[MAX][MAX];
        in>>n;
        
        while(!in.eof()){//读到文件末尾
            for(int x = 0; x < n-1; x++){
                for(int y = 0; y < n-1-x;y++){
                    in>>a[x][y];
                }
            }
        }
        int i,j;
        int ans = numeric_limits<int>::max();
        for(i = 1; i < n - 1; i++){//遍历行
            for(j = 0; j < n - 1 - i; j++){//每行n-1-i 个
                int min = numeric_limits<int>::max();
                for(int k  = i - 1,cnt = 0; k > -1; k--,cnt++){
                    //判断到达该出租站的上一站是哪里，取费用最少的5
                    int tmp = a[i][j] + a[k][cnt];//a[i][j]当前出租站，a[k][cnt]上一站
                    min = tmp<min?tmp:min;
                }
                a[i][j] = min;
            }
            //每行最后的数字代表到达n的总费用，判断最后一步应该怎么走是费用最小的
            ans = a[i][j-1]<ans? a[i][j-1]:ans;
        }
        out<<ans<<endl;
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
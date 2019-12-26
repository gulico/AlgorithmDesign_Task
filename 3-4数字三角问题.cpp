/**
 * 数字三角问题：
 * 给定一个由n行数字组成的数字三角形，如图3-2所示。
 * 试设计一个算法，计算出从一角形的顶至底的一条路径，使该路径经过的数字总和最大。
 * 
 * 注意：只能向下走
 *     7
 *    3 8
 *   8 1 0
 *  2 7 4 4
 * 4 5 2 6 5
 * 
 * 解题思路：
 * 1、从下往上，从倒数第二层开始遍历
 * 2、从左到右更新当前节点+左右两个节点，那边比较大，更新到a[i][j]中
 * 3、输出a[0][0]
 * 
 * **/
#include<iostream>
#include<fstream>
using namespace std;

#define MAX 105

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int n = 0 ,a[MAX][MAX],x = 0,y = 0;
        in>>n;
        
        while(!in.eof()){//读到文件末尾
            in>>a[x][y];
            y++;
            if(y>x){
                x++,y = 0;
            }
        }
        for(int i = n - 1; i > -1; i--){//从倒数第二层开始遍历
            for(int j  = 0; j < i + 1; j++){//从左到右更新当前节点+左右两个节点，那边比较大，更新到a[i][j]中
                int t1 = a[i][j] + a[i+1][j];
                int t2 = a[i][j] + a[i+1][j+1];
                a[i][j] = t1>t2?t1:t2;
            }
        }
        out<<a[0][0]<<endl;
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
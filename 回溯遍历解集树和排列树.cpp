#include <iostream>
using namespace std;

#define MAX 100

int n;// n个元素
int x[MAX];

/**
 * 回溯法搜索子集树
 * 
 * output(x)     记录或输出得到的可行解x
 * constraint(t) 当前结点的约束函数
 * bount(t)      当前结点的限界函数
 * t为当前解空间的层数

*/
void backtrack1(int t){
    if(t>n){
        //output(x)
        ;
    }
    else{
        for (int i = 0; i <= 1; i++) {//选择走左边0或者是走右边1
             x[t] = i;
               //if(constraint(t) && bount(t))
               //  backtrack(t+1);
        }
    }
          
}

/**
 * 回溯法搜索排列树
 * 
 * output(x)     记录或输出得到的可行解x
 * constraint(t) 当前结点的约束函数
 * bount(t)      当前结点的限界函数
 * @param t  t为当前解空间的层数
 */
void backtrack2(int t){
    if(t >= n){
        //output(x);
        ;
    }
    else{
        for (int i = t; i <= n; i++) {
            swap(x[t], x[i]);//交换元素顺序，递归
            //if(constraint(t) && bount(t))
            //    backtrack(t+1);
            swap(x[t], x[i]);//换回来
        }
      }
        
}
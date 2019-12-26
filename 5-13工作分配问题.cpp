/**
 * 问题描述：设有n件工作分配给n个人。
 * 将工作i分配给第j个人所需的费用为cij。
 * 试设计一个算法，为每一个人都分配1件不同的工作，并使总费用达到最小。
 * 
 * 输入第一行为n件工作（n个人），后n行为工作费用cij
 * input：
 * 3
 * 10 2 3
 * 2  3 4
 * 3  4 5
 * 
 * output：
 * 9
 * 
 * 解题思路：
 * 
 **/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<limits>
using namespace std;

#define MAX 105

int minCost = numeric_limits<int>::max();//最小花费
int cost[MAX][MAX];//工人分配各种工作的花费
int n;//工人（工作）个数

//检查工作是否可以分配给工人
bool legal(int vis[],int row){
    for(int i = 0; i < row; i++){//检查之前的每一个工人
        if(vis[row]==vis[i])//之前的工人已经分配过该工作
            return false;
    }
    return true;
}

void dfs(int vis[],int row,int cCost){
    if(row == n){//递归出口，所有的工人都分配了工作
        if(cCost < minCost)//若该路径中的费用小于之前记录的
            minCost = cCost;
        return ;
    }else{
        for(int col = 0; col < n ; col ++){//遍历所有工作
            vis[row] = col;//先分配给该工人row看看
            if(legal(vis,row))//若可以分配给他
                dfs(vis,row+1,cCost+cost[row][col]);//分配并下一个工人
        }
    }
}

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int cnt = 0;
        int vis[MAX];
        in>>n;     
        while(!in.eof()){//读到文件末尾
            for(int i= 0; i < n; i++)
                in>>cost[cnt][i];
            cnt++;
        }
        dfs(vis,0,0);
        out<<minCost;
        
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
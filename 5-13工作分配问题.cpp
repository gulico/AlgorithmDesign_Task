#include<iostream>
#include<algorithm>
#include<fstream>
#include<limits>
using namespace std;

#define MAX 105

int minCost = numeric_limits<int>::max();//最小花费
int cost[MAX][MAX];//工人分配各种工作的花费
int n;//工人（工作）个数

bool legal(int vis[],int row){//检查工作是否可以分配给工人
    for(int i = 0; i < row; i++){
        if(vis[row]==vis[i])
            return false;
    }
    return true;
}

void dfs(int vis[],int row,int cCost){
    if(row == n){
        if(cCost < minCost)
            minCost = cCost;
        return ;
    }else{
        for(int col = 0; col < n ; col ++){
            vis[row] = col;
            if(legal(vis,row))
                dfs(vis,row+1,cCost+cost[row][col]);
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
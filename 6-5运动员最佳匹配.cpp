/**
 * 
 * 问题描述：羽毛球队有男女运动员各n人。
 * 给定2个nXn矩阵P和Q。
 * P[i][j]是男运动员i和女运动员j配对组成混合双打的男运动员竞赛优势; 
 * Q[i][j]是女运动员i和男运动员j配合的女运动员竞赛优势。
 * 由于技术配合和心理状态等各种因素影响，P[i][]不一定等于Q[i][i]。
 * 男运动员i和女运动员j配对组成混合双打的男女双方竞赛优势为P[i][j]*Q[j][i]。
 * 设计一个算法，计算男女运动员最佳配对法，使各组男女双方竞赛优势的总和达到最大。
 * 
 * 
 **/

//这道题我觉得还是用回溯比较好，分支限界我不知道界在哪？？？
#include<iostream>
#include<algorithm>
#include<fstream>
#include<limits>
#include<queue>
using namespace std;

#define MAX 105

int maxSum = numeric_limits<int>::min();//最大优势
int P[MAX][MAX],Q[MAX][MAX],PQ[MAX][MAX],maxout[MAX];
int n;//男女运动员各n人

struct node {     
    int i;//第i个男生，即，解集树第i层
    int bestsum;//优势估计最大值，即上界
    int vis[MAX];//该状态下，已经被确定的路径
    friend bool operator < (node a, node b)//操作符重载
    {         
        return a.bestsum < b.bestsum;    //结构体中，bestsum大的优先级高     
    }
};
priority_queue<node>q;   //优先队列

int maxBound(node x){//计算上界，但是我个人觉得这个上界？？真的是合理的嘛
    int sum = 0 ,i;
    for(i = 0; i < x.i ; i++)//已经确定的路径
        sum += PQ[i][x.vis[i]];
    for( ; i < n ; i++){//剩下的未配对的女运动员（不考虑男运动员配对情况下）所能达到的优势最大值之和
        sum += maxout[i];
    }
    return sum;           
}

bool legal(int vis[],int row){//检查此种匹配方式男生女生是否合法
    for(int i = 0; i < row; i++){
        if(vis[row]==vis[i])
            return false;
    }
    return true;
}

void bfs(node x){
    if(x.i == n-1){//到叶子节点，只要是第一次到达叶子节点就可以结束广搜
        if(maxSum < x.bestsum)
            maxSum = x.bestsum;
        return ;
    }else{
        x.i++;//下一个男生
        for(int col = 0; col < n ; col ++){//遍历所有女生
            x.vis[x.i] = col;//匹配这个女生试试
            if(legal(x.vis,x.i)){//若匹配成功
                x.bestsum = maxBound(x);//计算这种情况下的最佳上界
                q.push(x);//加入优先队列
            }
        }
        if(!q.empty()){
            node tmp = q.top();
            q.pop();
            bfs(tmp);
        }
    }
}

void initPQ(){//初始化男女运动员相互作用的优势值PQ，每位男生和最匹配的女生的优势值maxout
    for(int i = 0; i < n; i++){
        int mx = 0;
        for(int j = 0; j < n; j++ ){
            PQ[i][j] = P[i][j] * Q[j][i];
            mx = max(mx,PQ[i][j]);
        }
        maxout[i] = mx;
    }
}

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int cnt = 0;
        int vis[MAX] = {0};
        in>>n;     
        while(!in.eof()){//读到文件末尾
            if(cnt<n){
                for(int i= 0; i < n; i++)
                  in>>P[cnt][i];
                cnt++;
            }else{
                for(int i= 0; i < n; i++)
                    in>>Q[cnt-n][i];
                cnt++;
            }
        }
        initPQ();
        for(int i = 0; i < n ; i++){//将第一层节点放入
            node x;
            x.i = 0;
            vis[x.i] = i;
            memcpy(x.vis, vis, MAX * sizeof(int));
            x.bestsum = maxBound(x);
            q.push(x);
        }
        node tmp = q.top();//取优先队列的队头
        q.pop();
        bfs(tmp);
        out<<maxSum;
        
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
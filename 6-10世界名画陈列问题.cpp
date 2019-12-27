//二维的谁爱写谁写吧，摔
#include<iostream>
#include<algorithm>
#include<fstream>
#include<limits>
#include<queue>
using namespace std;

#define MAX 25

int minNum = numeric_limits<int>::max();//最小警卫数量
int picMap[MAX][MAX] = {-1};//警卫的位置1，可以监控的位置2
int n,m;//m行,n列
int dir[4][4]={{-1,-1},{1,-1},{-1,1},{1,1}};//搜索方向
int dir2[4][4]={{-1,0},{1,0},{0,-1},{0,1}};//警卫可以监视的方向

struct node {     
    int x,y;//目前坐标
    int bestNum;//估计最小值，即上界
    int vis[MAX][MAX];//该状态下，已经被确定的路径
    int remain;//剩下的点
    friend bool operator < (node a, node b)//操作符重载
    {         
        return a.bestNum > b.bestNum;    //结构体中，bestsum小的优先级高     
    }
};
priority_queue<node>q;   //优先队列

int maxBound(node x){//计算上界，我认为仅仅需要算当前确定的路径即可
    int num = 0 ,i,j;
    for(i = 0; i < x.x ; i++){//已经确定的路径
        for(j = 0; j < x.y; j++){
            if(x.vis[i][j]==1){
                num++;
            }
        }
    }
    return num;
}

bool legal(int vis[MAX][MAX],int x,int y){//检查搜索此方向是否合法
    if(x<0||y<0||x>(n-1)||y>(m-1)||vis[x][y]==1)//超出m*n陈列范围或者已经放置过警卫
        return false;
    return true;
}

void push_position(int x,int y,int vis[MAX][MAX],int remain){
    node next ;
    next.x = x;
    next.y = y;
    vis[x][y] = 1;
    for(int i = 0 ; i < 4; i++){
        int tmpx = x + dir2[i][0];
        int tmpy = x + dir2[i][1];
        if(!(tmpx<0||tmpy<0||tmpx>(n-1)||tmpy>(m-1))){//没越界
            if(vis[tmpx][tmpy] != 1){//0或2
                if(vis[tmpx][tmpy] == 0){
                    remain--;
                }
                vis[tmpx][tmpy] = 2;
            }
        }
    }
    memcpy(next.vis, vis, MAX * MAX * sizeof(int));
    next.remain = remain;
    next.bestNum = maxBound(next);
    q.push(next);
}

void bfs(node x){
    if(x.x == n-1 && x.y == m-1){//到叶子节点，即，铺满全图
        if(minNum > x.bestNum)
            minNum = x.bestNum;
        return ;
    }else{
        for(int i = 0; i < 4; i++){//搜索当前位置的四个方向
            node next ;
            next.x = x.x + dir[i][0];
            next.y = x.y + dir[i][1];
            next.remain = x.remain;
            memcpy(next.vis, x.vis, MAX * MAX * sizeof(int));
            if(legal(next.vis,next.x,next.y)){//可以放
                //不放
                next.bestNum = maxBound(next);
                q.push(next);
                //放
                push_position(next.x,next.y,next.vis,x.remain);
            }else{//不可以放，不放
                next.bestNum = maxBound(next);
                q.push(next);
            }
                
            
        }
        if(!q.empty()){
            node tmp = q.top();
            q.pop();
            bfs(tmp);
        }
    }
}

void initPQ(){
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
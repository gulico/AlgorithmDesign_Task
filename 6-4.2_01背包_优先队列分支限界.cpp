/**
 * 题目描述：给定N个物品,每个物品有一个重量W和一个价值V.你有一个能装M重量的背包.问怎么装使得所装价值最大.每个物品只有一个.
 * 输入格式：输入的第一行包含两个整数n, m，分别表示物品的个数和背包能装重量。
 * 以后N行每行两个数Wi和Vi,表示物品的重量和价值
 * 输出格式
 * 输出1行，包含一个整数，表示最大价值。
 * 样例输入
 * 3 5
 * 2 3
 * 3 5
 * 4 7
 * 样例输出
 * 8
 * 
 * 解题思路：
 * 1)   先求出每个物品的单位重量的价值，并按降序排序；
 * 
 * 2)   按此顺序取物品，取或不取的时候都计算出上界：ub=cv+(bagw-cw)(value[i]/weight[i])，即（当前价值+最佳回报*剩余重量）；
 * 
 * 3)   比较两种情况下的上界ub，选择界限大的方式。前提是选取该物品后总重不会超过背包容量：bagw；
 * 
 * 4）一个物品要么选，要么不选，选了就往选了的方式下继续分支，重复2，3，没选就往没选的方式下分支。
 * **/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<limits>
#include<queue>
using namespace std;

#define MAX 105

int maxValue = numeric_limits<int>::min();//最大价值
int n,m;//n件物品，m容量的背包

struct node {     
    int i;//第i件物品，即，解集树第i层
    int bestvalue;//估计最大价值，即上界
    int capacity;//该状态下的容量
    bool vis[MAX];//该状态下，已经被确定的路径（直接放vetcor排序好的顺序）
    friend bool operator < (node a, node b)//操作符重载
    {         
        return a.bestvalue < b.bestvalue;    //结构体中，bestvalue大的优先级高     
    }
};

struct Goods{
    float w;//重量
    float v;//价值
    int i;//序号
}goods[MAX];

bool cmp(Goods &a,Goods &b){
    return a.v/a.w > b.v/b.w;//单位容量内价值降序
}
priority_queue<node>q;   //状态优先队列


int maxBound(node x){//计算上界，假设物品可分割，将背包完全填满
    int sum = 0 ,i,capacity = x.capacity;
    for(i = 0; i < x.i ; i++){//已经确定的路径
        if(x.vis[i]){
            sum += goods[i].v;
        }
    }
    for( ; i < n ; i++){//部分物品按照单位容量内价值高低的顺序装入
        if(capacity - goods[i].w > 0){//可以装下
            capacity = capacity - goods[i].w;
            sum += goods[i].v;
        }else{//装不下，则把最前面的物品的一部分填满背包
            sum = sum + (goods[i].v / goods[i].w) * capacity;
            break;
        }
    }
    return sum;           
}

void push_goods(int i,int bestvalue,int capacity,bool vis[MAX]){
    node x;
    x.i = i;
    x.bestvalue = bestvalue;
    x.capacity = capacity;
    memcpy(x.vis, vis, MAX * sizeof(bool));
    q.push(x);
}

void bfs(node x){
    if(x.i == n-1){//到叶子节点，只要是第一次到达叶子节点就可以结束广搜
        if(maxValue < x.bestvalue)
            maxValue = x.bestvalue;
        return ;
    }else{
        x.i++;//下一个物品
        if(x.capacity - goods[x.i].w > 0){//可以放
            //不放
            x.vis[x.i] = false;
            push_goods(x.i,maxBound(x),x.capacity,x.vis);
            //放
            x.vis[x.i] = true;
            push_goods(x.i,maxBound(x),x.capacity - goods[x.i].w,x.vis);
        }else{//放不下
            //不放
            x.vis[x.i] = false;
            push_goods(x.i,maxBound(x),x.capacity,x.vis);
        }
        
        if(!q.empty()){
            node tmp = q.top();
            q.pop();
            bfs(tmp);
        }
    }
}

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int cnt = 0;
        in>>n>>m;     
        while(!in.eof()){//读到文件末尾
            goods[cnt].i = cnt;
            in>>goods[cnt].w>>goods[cnt].v;
            cnt++;
        }
        sort(goods,goods+n,cmp);//按照单位容量内价值高低的顺序排序
        bool vis[MAX]  = {false};
        node x;
        x.capacity = m;
        memcpy(x.vis, vis, MAX * sizeof(bool));
        push_goods(0,maxBound(x),m,vis);//不装第一件物品
        x.vis[0] = true;
        push_goods(0,maxBound(x),m - goods[0].w,vis);//装第一件物品

        node tmp = q.top();//取优先队列的队头
        q.pop();
        bfs(tmp);
        out<<maxValue;
        
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
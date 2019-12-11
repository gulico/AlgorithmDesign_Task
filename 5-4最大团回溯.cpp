#include <iostream>
using namespace std;
int m[101][101];//有向图的邻接矩阵
int x[101];//当前团的解
int bestx[101];//最优解
int n;//表示图的顶点数
int cn=0;//当前团的大小
int bestn;//当前最优值
void getbestn(int i)
{
    if(i>n){//递归出口，到根节点时，更新最优值和最优解，返回
        bestn=cn;//更新最优值
        for(int j=1;j<=n;j++)
            bestx[j]=x[j];
        return ;//返回
    }
  
    x[i]=1;//先假定x[i]=1;
    for(int j=1;j<i;j++){
        if(x[j]==1&&m[i][j]==0){
            x[i]=0;//如果该点与已知解中的点无边相邻
            break;//则不遍历左子树
        }
    }
    if(x[i]==1){//当且仅当x[i]==1时，遍历左子树
        cn++;//该点加入当前解
        getbestn(i+1);//递归调用
        cn--;//还原当前解
    }
  
  	//剪枝
    x[i]=0;//假定x[i]==0
    if(cn+n-i>bestn){//如果当前值+右子树可能选择的节点<当前最优解，不遍历左子树
        x[i]=0;
        getbestn(i+1);
    }
    return ;
}
int main()
{
    cin>>n;//输入图的顶点数
    //输入图的邻接矩阵
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++)
        cin>>m[i][j];
    //求最优解
    getbestn(1);
    cout<<bestn<<endl;//输出最优值
    //输出
    for(int i=1;i<=n;i++)
        if(bestx[i])
        cout<<i<<" ";//输出最优解
    return 0;
}
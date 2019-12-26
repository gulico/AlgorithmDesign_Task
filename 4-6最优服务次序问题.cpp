/**
 * 4-6最优服务次序问题
 * 
 * 问题描述：设有n个顾客同时等待一项服务。
 * 顾客i需要的服务时间为ti 1≤i≤n。
 * 应如何安排n个顾客的服务次序才能使平均等待时间达到最小？
 * 平均等待时间是n个顾客等待服务时间的总和除以n。
 * 
 * 思路：因为服务时间长，意味着其他所有人都要多等待该人的服务时间
 * 所以，升序排序服务时间。服务时间最少的让最多的人等待即可。
 **/ 
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

#define MAX 105

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int k = 0,x = 0;
        in>>k;
        int lasting[MAX];
        while(!in.eof()){//读到文件末尾
            in>>lasting[x++];
        }

        sort(lasting,lasting+k);//默认升序

        int sum = 0;
        for(int i = 0; i < k; i++ ){
            sum = sum + lasting[i]*(k-i);
            cout<<lasting[i]<<endl;
        }
        sum = sum / k;
        out<<sum<<endl;
        
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
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
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
        for(int i = n - 1; i > -1; i--){
            for(int j  = 0; j < i + 1; j++){
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
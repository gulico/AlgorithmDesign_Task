#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

#define MAX 201

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int n = 0 ,a[MAX][MAX];
        in>>n;
        
        while(!in.eof()){//读到文件末尾
            for(int x = 0; x < n-1; x++){
                for(int y = 0; y < n-1-x;y++){
                    in>>a[x][y];
                }
            }
        }
        int i,j;
        int ans = numeric_limits<int>::max();
        for(i = 1; i < n - 1; i++){
            for(j = 0; j < n - 1 - i; j++){
                int min = numeric_limits<int>::max();
                for(int k  = i - 1,cnt = 0; k > -1; k--,cnt++){
                    //判断到达该出租站的上一站是哪里
                    int tmp = a[i][j] + a[k][cnt];
                    min = tmp<min?tmp:min;
                }
                a[i][j] = min;
            }
            //每行最后的数字代表到达n的总费用，判断最后一步应该怎么走是费用最小的
            ans = a[i][j-1]<ans? a[i][j-1]:ans;
        }
        out<<ans<<endl;
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
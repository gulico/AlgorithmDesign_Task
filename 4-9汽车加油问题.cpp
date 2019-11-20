#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

#define MAX 105

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int k = 0,n = 0,x = 0;
        in>>n>>k;
        int dist[MAX];      
        while(!in.eof()){//读到文件末尾
            in>>dist[x++];
        }
        int ans = 0,sum = 0;

        for(int i = 0; i < k+1; i++ ){
            if(sum+dist[i]>n){
                cout<<sum<<endl;
                ans++;
                sum = dist[i];
            }else{
                sum += dist[i];
            }
            if(sum > 7){
                out<<"No Solution"<<endl;
                break;
            }  
        }
        out<<ans<<endl;
        
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
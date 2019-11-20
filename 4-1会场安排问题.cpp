#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

#define MAX 105
                                                                             
struct Activity{
    int start;
    int end;
}act[MAX];
bool visit[MAX] = {false};

bool cmp(Activity &a,Activity &b){
    if(a.end == b.end )
        return a.start > b.start;//降序
    return a.end < b.end;//升序
}

int main(){

    fstream in("input.txt",ios::in);
    fstream out("output.txt",ios::out);
    if(in.is_open()){
        int k = 0,x = 0;
        in>>k;
        
        while(!in.eof()){//读到文件末尾
            in>>act[x].start;
            in>>act[x].end;
            x++;
        }

        sort(act,act+k,cmp);
        int cnt = 0,ans = 0;
        while(cnt<k){
            int endtime;
            for(int i = 0; i < k; i++){//选择每个会场第一个活动
                if(visit[i] == false){
                    endtime = act[i].end;
                    visit[i] = true;
                    cnt++;
                    break;
                } 
            }
            for(int i = 0; i < k; i++){
                if(visit[i] == false && act[i].start > endtime){
                    visit[i] = true;
                    endtime = act[i].end;
                    cnt++;
                }
            }
            ans++;
        }
        out<<ans<<endl;
        
    }else{
        cout<<"文件打开失败！"<<endl;
    }
    in.close();
    out.close();
    return 0;
}
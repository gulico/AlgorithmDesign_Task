/**
 * 4-1会场安排问题
 * 思路：HDU2037 今年暑不ac 变体
 * 1、结构体快排。活动结束时间升序排序；活动结束时间相同，按开始时间降序排列
 * 2、按顺序遍历，比较开始时间是否比当前已经被安排的结束时间晚，是则安排活动到当前会场，更新被安排的结束时间，该活动被标记
 * 3、遍历结束若存在没有被安排的活动，则会场数+1
 * 4、重复步骤2，直到所有活动都被安排
 **/
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
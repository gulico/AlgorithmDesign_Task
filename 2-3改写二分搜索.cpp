#include<iostream>

template<class T>
int func(T a[],const T x,int left,int right,int& i,int& j){
    T middle;
    while(left<=right){
        middle = (left+right)/2;
        if(x>a[middle]){
            left = middle + 1;
            continue;
        }
        if(x<a[middle]){
            right = middle -1;
            continue;
        }
        i = j = middle;
        return 1;  
    }
    i = right;
    j = left;
    return 0;
}

int main(){
    int a[5] = {1,2,5,7};
    int n;
    while(scanf("%d",&n)!=EOF){
        int i = 0,j = 0;
        int find = func(a,n,0,3,i,j);
        printf("find:%d i:%d j:%d\n",find,i,j);
    }
    return 0;
}

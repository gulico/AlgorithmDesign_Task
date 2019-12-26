/**
 * 题目：设a[0:n- 1]是已排好序的数组。
 * 请改写二分搜索算法，
 * 使得当搜索元素x不在数组中时，返回小于x的最大元素位置i和大于x的最小元素位置j。
 * 当搜索元素在数组中时，i和j相同，均为x在数组中的位置。
 **/
#include<iostream>

template<class T>
int func(T a[],const T x,int left,int right,int& i,int& j){
    T middle;
    while(left<=right){
        middle = (left+right)/2;
        if(x>a[middle]){//在中间的右侧，下一次循环
            left = middle + 1;
            continue;
        }
        if(x<a[middle]){//在中间的左侧。直接下一次循环
            right = middle -1;
            continue;
        }
        i = j = middle;//找到了
        return 1;  
    }
    //没找到
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

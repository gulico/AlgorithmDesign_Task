/**
 *  快速排序的基本实现
 * 快速排序算法是一种基于交换的高效的排序算法，它采用了分治法的思想：
 * 1、从数列中取出一个数作为基准数（枢轴，pivot）。 
 * 2、将数组进行划分(partition)，将比基准数大的元素都移至枢轴右边，将小于等于基准数的元素都移至枢轴左边。
 * 3、再对左右的子区间重复第二步的划分操作，直至每个子区间只有一个元素。
 * 
 * 快速排序时间复杂度
 * 快速排序的时间复杂度在最坏情况下是O(N2)，平均的时间复杂度是O(N*lgN)。
 * 这句话很好理解：假设被排序的数列中有N个数。遍历一次的时间复杂度是O(N)，需要遍历多少次呢？至少lg(N+1)次，最多N次
 * (01) 为什么最少是lg(N+1)次？快速排序是采用的分治法进行遍历的，我们将它看作一棵二叉树，它需要遍历的次数就是二叉树的深度，而根据完全二叉树的定义，它的深度至少是lg(N+1)。
 * 因此，快速排序的遍历次数最少是lg(N+1)次。
 * (02) 为什么最多是N次？这个应该非常简单，还是将快速排序看作一棵二叉树，它的深度最大是N。因此，快读排序的遍历次数最多是N次。
 * 
 * 快速排序稳定性
 * 快速排序是不稳定的算法，它不满足稳定算法的定义。
 * 算法稳定性 -- 假设在数列中存在a[i]=a[j]，若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！
 * 
 * 参考：https://www.cnblogs.com/miracleswgm/p/9199124.html
 * 
 **/

#include<iostream>
using namespace std;

void swap(int& a,int& b);

int partition(int a[],int left,int right){
    int i = left + 1;
    int j = right;
    int key = a[left];//设置最左边的数为基准

    while(i <= j){
        while(a[i] < key){//从左寻找大于基准key的数
            i++;
        }
        while(a[j] > key){//从右寻找小于基准key的数
            j--;
        }

        if(i < j){//交换以上寻找到的大于基准的数和小于基准的数
            swap(a[i++],a[j--]);
        }
        else{//否则（i==j或者i>j）
            i++;
        }
    }
    swap(a[left],a[j]);//最后交换基准数和最后一个需要交换的数字
    return j;//返回基准
}

void quick_sort(int a[],int left,int right){
    if(left>right)
        return ;
    int j = partition(a,left,right);//找到基准
    quick_sort(a , left  , j - 1);//继续划分基准左侧
    quick_sort(a , j + 1 , right);//继续划分基准右侧
}

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a[10] = {2,4,5,7,82,2,4,9,3,1};
    quick_sort(a,0,9);
    for(int i = 0; i < 10 ; i++ ){
        cout<<a[i]<<" ";
    }
    return 0;
}
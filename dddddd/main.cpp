//
//  main.cpp
//  dddddd
//
//  Created by student on 15/8/21.
//  Copyright (c) 2015年 student. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
//在这里添加一行注释
const int INF=0x7fffffff;
int max_sub_array(int arr[],int n,int &left,int &right)
{
    int maxium=-INF;
    int sum;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>maxium){
                maxium=sum;
                left=i;
                right=j;
            }
        }
    }
    return maxium;
}
int max_sub_array(int arr[],int l,int r,int &left,int &right)
{
    if(l<r){
        int mid=(l+r)/2;
        int ll,lr;
        int suml=max_sub_array(arr,l,mid,ll,lr);
        int rl,rr;
        int sumr=max_sub_array(arr,mid+1,r,rl,rr);
        int sum_both=0;
        int max_left=-INF;
        int ml = 0,mr = 0;
        for(int i=mid;i>=l;i--)
        {
            sum_both+=arr[i];
            if(sum_both>max_left){
                max_left=sum_both;
                ml=i;
            }
        }
        int max_right=-INF;
        sum_both=0;
        for(int i=mid+1;i<=r;i++)
        {
            sum_both+=arr[i];
            if(sum_both>max_right){
                max_right=sum_both;
                mr=i;
            }
        }
        sum_both=max_left+max_right;
        if(suml<sumr) {
            if(sumr<sum_both) {
                left=ml;
                right=mr;
                return sum_both;
            }
            else {
                left=rl;
                right=rr;
                return sumr;
            }
        }
        else{
            if(suml<sum_both) {
                left=ml;
                right=mr;
                return sum_both;
            }
            else {
                left=ll;
                right=lr;
                return suml;
            }
        }
    }
    else {
        left=l;
        right=r;
        return arr[l];
    }
}
int max_sub_array_(int arr[],int n,int& left,int&right)
{
    int cursum=arr[0];
    int maxsum=arr[0];
    int pos=0;
    pos=0;
    for(int i=1;i<n;i++) {
        cursum+=arr[i];
        if(cursum<arr[i])
        {
            pos=i;
            cursum=arr[i];
        }
        if(cursum>maxsum)
        {
            maxsum=cursum;
            left=pos;
            right=i;
        }
    }
    return maxsum;
    
}
void test1()
{
    int arr[]={1,-2,3,5,-3,4,-2,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    int left,right;
    int sum;
    cout<<"arr:";
    copy(arr,arr+len,ostream_iterator<int>(cout, " "));
    cout<<endl;
    sum=max_sub_array(arr,len,left,right);
    cout<<"method1:("<<left<<","<<right<<")  ";
    cout<<"sum="<<sum<<endl;
//    sum=max_sub_array(arr,0,len-1,left,right);
//    cout<<"method2:("<<left<<","<<right<<")  ";
//    cout<<"sum="<<sum<<endl;
//    sum=max_sub_array(arr,len,left,right);
//    cout<<"method3:("<<left<<","<<right<<")  ";
//    cout<<"sum="<<sum<<endl;
    
}
int main()
{
    test1();
    
}
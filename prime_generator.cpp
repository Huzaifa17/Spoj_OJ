#include<bits/stdc++.h>
using namespace std;
vector<int> sieve(int b)
{
    int i,j,k,n,m,p;
    n=sqrt(b)+1;
    vector<int> arr;
    arr.push_back(2);
    int arr2[n+1]={0};
    for(i=3;i<=n;i+=2)
    {
        if(!arr2[i])
        {
            arr.push_back(i);
            for(j=i*i;j<=n;j+=i*2)
            {
                arr2[j]=1;
            }
        }
    }
    return arr;
}

void segsieve(int a,int b)
{
    int i,j,k,n,m,r;
    int base,curr;
    vector<int> array=sieve(b);
    int array2[b-a+1]={0};
    if(a==1)
    {
        array2[0]=1;
    }
    for(i=0;i<array.size();++i)
    {
        curr=array[i];
        base=(a/curr)*curr;
        if(base<a)
        {
            base+=curr;
        }
        for(j=base;j<=b;j+=curr)
        {
            array2[j-a]=1;
        }
        if(base==curr)
        {
            array2[base-a]=0;
        }
    }
    for(i=0;i<b-a+1;++i)
    {
        if(array2[i]==0)
        {
            cout<<i+a<<endl;
        }
    }
    return ;
}


int main()
{
    int i,j,k,n,m,t;
    cin>>t;
    for(i=0;i<t;++i)
    {
        cin>>m>>n;
        if(i!=0)
        {
            cout<<endl;
        }
        segsieve(m,n);
    }
    return 0;
}

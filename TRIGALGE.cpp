#include<bits/stdc++.h>
using namespace std;


double bs(double a,double b,double c)
{
	double l=0,r=c,mid,sum;
	while(l<=r)
	{
	    mid=l+(r-l)/2;
	    sum=(a*mid)+(b*(sin(mid)));
	    if(fabs(c-sum)<=0.000001)
	    {
			return mid;
		}
		else if(sum>c)
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	return 0.00;
}

int main()
{
	int i,j,k,t;
	cin>>t;
	for(i=0;i<t;++i)
	{
		double a,b,c;
		cin>>a>>b>>c;
		cout<<fixed<<setprecision(13)<<bs(a,b,c)<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int level[9][9];
//int graph[65][65];
 int x[10]={0,-1,-1,-2,-2,2,2,1,1};
 int y[10]={0,-2,2,-1,1,-1,1,-2,2};



int bfs(string s1,string s2)
{
	int i,j,k,x1,x2,y1,y2,m,n;
	x1=s1[0]-'a'+1;
	x2=s2[0]-'a'+1;
	y1=s1[1]-'0';
	y2=s2[1]-'0';
	int visited[9][9];
	for(i=1;i<=8;++i)
	{
		for(j=1;j<=8;++j)
		{
			visited[i][j]=0;
		}
	}
	for(i=1;i<=8;++i)
	{
		for(j=1;j<=8;++j)
		{
			level[i][j]=0;
		}
	}
	list<pair<int,int>> queue2;
	queue2.push_back({x1,y1});
	level[x1][y1]=0;
	visited[x1][y1]=1;
	while(!queue2.empty())
	{
		     pair<int,int> p1=queue2.front();
             queue2.pop_front();
             if(p1.first==x2 && p1.second==y2)
             return level[x2][y2];
             for( i=1;i<=8;i++)
             {
                 m=p1.first+x[i],n=p1.second+y[i];
                 if(m>8 || m<1 || n>8 || n<1 || visited[m][n])
                 continue;
                 else
                 {
                     visited[m][n]=1;
                     level[m][n]=level[p1.first][p1.second]+1;
                     queue2.push_back(make_pair(m,n));
                 }
             }
	}
	return level[x2][y2];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,i,j,k,m,t;
	string s1,s2;
	cin>>t;
	for(i=0;i<t;++i)
	{
		cin>>s1>>s2;
		cout<<bfs(s1,s2)<<endl;
	}
	return 0;
}

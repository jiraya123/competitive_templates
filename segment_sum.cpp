#include<bits/stdc++.h>
using namespace std;

#define pu push_back
#define fi first
#define se second
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define mm (s+e)/2
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(int i=st; i<en; i++)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define sz 200000

struct segtree {

int size;
vector<int> sums;
void init(int n)
{
	size=1;
	while(size<n) size*=2;

	sums.assign(2*size+1,0);

}

void build(int nd,int s,int e,vector<int> &a)
{
   if(s==e)
   {
   	if(s<a.size())
   	{
      sums[nd]=a[s];
   	}
   	return;
   }

   int m=(s+e)/2;
   build(2*nd,s,m,a);
   build(2*nd+1,m+1,e,a);
   sums[nd]=sums[2*nd]+sums[2*nd+1];

}
void build(vector<int> &a)
{
	build(1,0,size-1,a);
}

void upd(int nd, int s,int e,int idx,int val)
{
	if(s==e){
		sums[nd]=val;
		return;
	}
	int m=(s+e)/2;
	if(idx<=m) upd(2*nd,s,m,idx,val);
	else upd(2*nd+1,m+1,e,idx,val);
	sums[nd]=sums[2*nd]+sums[2*nd+1];
}
void upd(int idx,int val)
{
	upd(1,0,size-1,idx,val);
}

int qry(int nd,int l,int r,int s,int e)
{ 
	if(s>r ||l>e) return 0;
	if(l<=s && e<=r) return sums[nd];
	int m=(s+e)/2;
	int x= qry(2*nd,l,r,s,m);
	int y=qry(2*nd+1,l,r,m+1,e);
	return x+y;
}
int qry(int l,int r)
{
	return qry(1,l,r,0,size-1);
}


};
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
  segtree st;
  st.init(n);
	vector<int> A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	st.build(A);
	while(m--)
	{
		int x,l,r;
		cin>>x>>l>>r;
		if(x==1)
		{
			st.upd(l,r);
		}else
		{
			cout<<st.qry(l,r-1)<<"\n";
		}

	}


}
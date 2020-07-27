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
struct item
{
int m,c;
};
struct segtree {

int size;
vector<item> sums;
item merge(item a,item b)
{
	if(a.m<b.m) return a;
	if(a.m>b.m) return b;
	return {a.m,a.c+b.c};
}
void init(int n)
{
	size=1;
	while(size<n) size*=2;

	sums.assign(2*size+1,{2000000000LL,0});

}

void build(int nd,int s,int e,vector<int> &a)
{
   if(s==e)
   {
   	if(s<a.size())
   	{
      sums[nd]={a[s],1};
   	}
   	return;
   }

   int m=(s+e)/2;
   build(2*nd,s,m,a);
   build(2*nd+1,m+1,e,a);
   sums[nd]=merge(sums[2*nd],sums[2*nd+1]);

}
void build(vector<int> &a)
{
	build(1,0,size-1,a);
}

void upd(int nd, int s,int e,int idx,int val)
{
	if(s==e){
		sums[nd]={val,1};
		return;
	}
	int m=(s+e)/2;
	if(idx<=m) upd(2*nd,s,m,idx,val);
	else upd(2*nd+1,m+1,e,idx,val);
	sums[nd]=merge(sums[2*nd],sums[2*nd+1]);
}
void upd(int idx,int val)
{
	upd(1,0,size-1,idx,val);
}

item qry(int nd,int l,int r,int s,int e)
{ 
	if(s>r ||l>e) return {2000000000,0};
	if(l<=s && e<=r) return sums[nd];
	int m=(s+e)/2;
	auto x= qry(2*nd,l,r,s,m);
	auto y=qry(2*nd+1,l,r,m+1,e);
	return merge(x,y);
}
item qry(int l,int r)
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
			auto x=st.qry(l,r-1);
			cout<<x.m<<" "<<x.c<<"\n";
		}

	}


}
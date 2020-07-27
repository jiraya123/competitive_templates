#include<bits/stdc++.h>
using namespace std;

#define pu push_back
#define fi first
#define se second
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii> 
#define sz 1000010
#define mm (s+e)/2
int A[sz],tree[4*sz],lazy[4*sz];
void push(int v,int s,int e)
{
     tree[v*2]+=lazy[v]*(mm-s+1LL);
     tree[v*2+1]+=lazy[v]*(e-mm);
     lazy[v*2]+=lazy[v];
     lazy[v*2+1]+=lazy[v];
     lazy[v]=0;

}
void build(int nd,int s,int e)
{
	if(s==e)tree[nd]=A[s];
	else{

		build(2*nd,s,mm);
		build(2*nd+1,mm+1,e);
		tree[nd]=tree[2*nd]+tree[2*nd+1];
	}

}
void upd(int nd,int s,int e,int l,int r, int idx)
{
	if(l>r) return ;
	if(l==s && r==e) {
		tree[nd]+=idx*(e-s+1LL);
		lazy[nd]+=idx;
		return;
	}
	push(nd,s,e);
	upd(2*nd,s,mm,l,min(mm,r),idx);
	upd(2*nd+1,mm+1,e,max(mm+1,l),r,idx);
	tree[nd]=tree[2*nd]+tree[2*nd+1];
}

int qry(int nd,int s,int e,int l, int r)
{
	if(l>r) return 0;
	if(l==s&& r==e) return tree[nd];
	push(nd,s,e);
	return qry(2*nd,s,mm,l,min(r,mm))+qry(2*nd+1,mm+1,e,max(l,mm+1),r);
}
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		int n,m,p;
		cin>>n>>m>>p;
		
	
}

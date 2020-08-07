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
int mod=1000000007;
struct segtree{
	vector<int>sums;
	vector<int>lazy;
	int size=1;
	int nop=1000000000000000LL;
	int nval=0;
	void modify(int &a,int b,int s,int e)
	{   if(b!=nop)
		   a=b*(e-s+1);
	}
	int calc(int a,int b)
	{
		return a+b;
	}

	void build(int nd,int s,int e)
	{
		if(s==e) {sums[nd]=1; return;}
		int m=(s+e)/2;
		build(2*nd,s,m);
		build(2*nd+1,m+1,e);
		sums[nd]=calc(sums[2*nd],sums[2*nd+1]);

	}
	void init(int n)
	{
		while(size<n) size*=2;
		sums.assign(size*2+1,0);
		lazy.assign(size*2+1,nop);
		// build(1,0,size-1);

	}

	void propo(int nd,int s,int e)
	{
		if(s==e)return;
		int m=(s+e)/2;
		modify(sums[2*nd],lazy[nd],s,m);
		modify(sums[2*nd+1],lazy[nd],m+1,e);
		modify(lazy[2*nd],lazy[nd],1,1);
		modify(lazy[2*nd+1],lazy[nd],1,1);
		lazy[nd]=nop;
	}
    
	void upd(int nd,int s,int e , int l, int r,int val)
	{     // cout<<s<<" "<<e<<" "<<val<<"\n";
	propo(nd,s,e);
         if(s>r || l>e) return;
         if(l<=s && e<=r) {
            modify(sums[nd],val,s,e);
            modify(lazy[nd],val,1,1);
         	return;
         }

         int m=(s+e)/2;
         upd(2*nd,s,m,l,r,val);
         upd(2*nd+1,m+1,e,l,r,val);
         int rr=calc(sums[2*nd],sums[2*nd+1]);
        
         sums[nd]=rr;
	}

	void upd(int l,int r,int val)
	{
		upd(1,0,size-1,l,r,val);
	}

	int qry(int nd,int s,int e,int l,int r)
	{  propo(nd,s,e);
		if(s>r || l>e) return nval;
         if(l<=s && e<=r) {
            
         	return sums[nd];
         }
		int m=(s+e)/2;
		int yy,xx;
		 yy=qry(2*nd,s,m,l,r);
		xx= qry(2*nd+1,m+1,e,l,r) ;
		
		int rr= calc(xx,yy);
		
		return rr;
	}
	int qry(int l,int r)
	{
		return qry(1,0,size-1,l,r);
	}


};
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		fast
	int n,m;
	segtree st;
	cin>>n>>m;
	st.init(n);
	while(m--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int l,r,val;
			cin>>l>>r>>val;
			r--;
			st.upd(l,r,val);
		}else{
			int l,r;
			cin>>l>>r;
			r--;
			cout<<st.qry(l,r)<<"\n";
		}
	}
}

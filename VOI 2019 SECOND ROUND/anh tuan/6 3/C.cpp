#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

struct SCC
{
	const int INF = int(1e9);
	vector<vector<int> > vec;
	int index;
	vector<int> idx;
	vector<int> lowlink;
	vector<bool> onstack;
	stack<int> s;
	vector<int> sccidx;
	int scccnt;
	vi topo;

	//lower sccidx means appear later
	void init(int n)
	{
		idx.assign(n,-1);
		index = 0;
		onstack.assign(n,0);
		lowlink.assign(n,INF);
		while(!s.empty()) s.pop();
		sccidx.assign(n,-1);
		scccnt = 0;
		vec.clear();
		vec.resize(n);
	}

	void addedge(int u, int v) //u -> v
    {
		vec[u].pb(v);
	}

	void connect(int u){
		idx[u] = index;
		lowlink[u] = index;
		index++;
		s.push(u);
		onstack[u] = true;
		for(int i = 0; i < vec[u].size(); i++){
			int v = vec[u][i];
			if(idx[v] == -1){
				connect(v);
				lowlink[u] = min(lowlink[u], lowlink[v]);
			}
			else if(onstack[v]){
				lowlink[u] = min(lowlink[u], idx[v]);
			}
		}
		if(lowlink[u] == idx[u]){
			while(1){
				int v = s.top();
				s.pop();
				onstack[v] = false;
				sccidx[v] = scccnt;
				if(v == u) break;
			}
			scccnt++;
		}
	}

	void tarjan(){
		for(int i = 0; i < vec.size(); i++){
			if(idx[i] == -1){
				connect(i);
			}
		}
	}
};

int n;
SCC scc;

void build(){  // build the tree
	for (int i = 2*n - 1; i > 0; --i){
		scc.addedge(2*(2*n+(i<<1)), 2*(2*n+i));
		scc.addedge(2*(2*n+i)+1, 2*(2*n+(i<<1))+1);
		scc.addedge(2*(2*n+(i<<1)+1), 2*(2*n+i));
		scc.addedge(2*(2*n+i)+1, 2*(2*n+(i<<1)+1)+1);
	  //t[i] = t[i<<1] + t[i<<1|1];
	}
}

void add(int v, int l, int r){  // add on interval [l, r)
	//cerr<<"DO : "<<v<<' '<<l<<' '<<r<<'\n';
	v+=2*n;
  for (l += 2*n, r += 2*n; l < r; l >>= 1, r >>= 1) {
	  //cerr<<"NODE : "<<l<<' '<<r<<' '<<v<<'\n';
    if (l&1){
		//cerr<<"ADD : "<<2*n+v<<' '<<2*n+l<<'\n';
		scc.addedge(2*(2*n+v), 2*(2*n+l)+1);
		//res += t[l++];
		l++;
	}
    if (r&1){
		r--;
		//cerr<<"ADD : "<<2*n+v<<' '<<2*n+r<<'\n';
		scc.addedge(2*(2*n+v), 2*(2*n+r)+1);
	}
  }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		vec.pb(mp(x,i*2));
		cin>>x;
		vec.pb(mp(x,i*2+1));
	}
	sort(vec.begin(),vec.end());
	int lo=0; int hi=int(1e9)+1;
	int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)>>1;
		//no two chosen should have distance < mid
		bool pos=1;
		if(mid>0){
			scc.init(12*n+10);
			for(int i=0;i<n;i++){
				scc.addedge((i*2)*2, (i*2+1)*2+1);
				scc.addedge((i*2)*2+1, (i*2+1)*2);
				scc.addedge((i*2+1)*2, (i*2)*2+1);
				scc.addedge((i*2+1)*2+1, (i*2)*2);
			}
			for(int i=0;i<vec.size();i++){
				//cerr<<"MATCH : "<<vec[i].se<<' '<<4*n+i<<'\n';
				for(int j=0;j<2;j++){
					scc.addedge((2*n+2*n+i)*2+j,(vec[i].se)*2+j);
					scc.addedge((vec[i].se)*2+j,(2*n+2*n+i)*2+j);
				}
			}
			build();
			for(int i=0;i<vec.size();i++){
				int pos=vec[i].fi;
				int r=lower_bound(vec.begin(),vec.end(),mp(pos+mid,-1))-vec.begin();
				add(i,i+1,r);
				int l = lower_bound(vec.begin(),vec.end(),mp(pos-mid+1,-1))-vec.begin();
				add(i,l,i);
				//cerr<<l<<' '<<i<<' '<<r-1<<'\n';
			}
			scc.tarjan();
			for(int i=0;i<2*n;i++){
				if(scc.sccidx[2*i]==scc.sccidx[2*i+1]){
					//cerr<<"FAIL : "<<i<<'\n';
					pos=0;
					break;
				}
			}
		}
		if(pos){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<ans<<'\n';
}

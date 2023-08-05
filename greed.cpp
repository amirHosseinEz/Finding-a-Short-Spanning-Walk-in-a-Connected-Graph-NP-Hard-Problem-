#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 15000 + 7;
vector<int> ans;
int last;
vector<int> g[maxn];
bool bvis[maxn], visited[maxn];
int bpar[maxn];
vector<int> bans;
int v1 = 0;
int deg[maxn];

void bfs2(int v){
	bans.clear();
	queue<int> q;
	q.push(v);
	int u;
	bool seen = 0;
	for(int i = 0; i <= last; i++)
		visited[i] = 0;
	visited[v] = 1;
	while(seen == 0){
		
		int tmp = q.front();
		q.pop();
		vector<pair<int, int>> shf;
		for(auto x: g[tmp])
			shf.push_back({deg[x], x});
		sort(shf.begin(), shf.end());
		vector<int> srt;
		for(auto x: shf)
			srt.push_back(x.second);
			
		for(auto x: srt){
			if(!bvis[x] && !visited[x]){
				bvis[x] = 1;
				q.push(x);
				bpar[x] = tmp;
				seen = 1;
				u = x;
				visited[x] = 1;
				break;
			}
			else if(!visited[x]){
				q.push(x);	
				visited[x] = 1;
				bpar[x] = tmp;
			}
		}
	}

	int cur = bpar[u];
	while(cur != v){

    	bans.push_back(cur);
    	cur = bpar[cur];

	}

	v1 = u;
	
}


int main () {
	ifstream file("edges.txt", ios::in);
	ofstream file2("greedyali.txt", ios::out);
	int v = 0, u = 0;
	while(1){
	    int v, u;
	    long long d;
	    file >> v >> u;
	    if(v == -1)
			break;
		g[v].push_back(u);
		g[u].push_back(v);
		deg[v] ++;
		deg[u] ++;
		last = max(last, max(u, v));
	
	}
	int md = 0, mindeg;
	for(int i = 0; i <= last; i++){
		md = max(md, deg[i]);
		if(deg[i] == md)
			mindeg = i;
	}
	
    file.close();
	int mini = 9999999;
	int ind;
		int cur = 8355;
		int sum = 1;
		for(int i = 0; i<= last; i++)
			bvis[i] = 0;
		bvis[cur] = 1;
		ans.clear();
		while(1){
			file2 << cur << " ";
			ans.push_back(cur);
			if(sum == last + 1)
				break;
			bfs2(cur);
			cur = v1;
			sum ++;
			reverse(bans.begin(), bans.end());
			for(auto x: bans){
				file2 << x << " ";
				ans.push_back(x);
			}
				 
			
			
		}
		

	cout << ans.size() << "  " << ind  << " $$$$$$$$$$$$$4\n";

}
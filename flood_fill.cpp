#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define nline "\n"
#define ll long long int

/******************************/
int check(int n,int m,int i,int j,vector<vector<int>>&vis,vector<vector<int>>&mat){
	int xi[]={-1,0,1,0};
	int yi[]={0,1,0,-1};
	queue<pair<int,int>>q;
	q.push({i,j});
	vis[i][j]=1;
	int ans=mat[i][j];
	while(!q.empty()){
	 	int size=q.size();
	 	for(int i1=0;i1<size;i1++){
	 		auto k=q.front();q.pop();
	 		for (int i2=0;i2<4;i2++){
	 			int newx=k.first+xi[i2];
	 			int newy=k.second+yi[i2];
	 			if (newx>=0 && newy>=0 && newx<n && newy<m && mat[newx][newx]!=0 && vis[newx][newy]==0){
	 				ans+=mat[newx][newy];
	 				vis[newx][newy]=1;
	 				q.push({newx,newy});
	 			}
	 		}
	 	}
	}
	return ans;
}

void solve(){
	int n,m;
	 cin>>n>>m;
	 vector<vector<int>>mat(n,vector<int>(m,0));
	 for(int i=0;i<n;i++){
	 	for (int j=0;j<m;j++){
	 		cin>>mat[i][j];
	 	}
	 }

	int res=0;
	vector<vector<int>>vis(n,vector<int>(m,0));
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if(vis[i][j]==0 && mat[i][j]!=0){
				res=max(check(n,m,i,j,vis,mat),res);

			}
		}
	}
   
   cout<<res<<endl;




}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

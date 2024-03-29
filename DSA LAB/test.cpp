#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void edge(vector<int>adj [],int u,int v){
	adj[u].push_back(v);
}
void bfs(int s,vector<int>adj [],bool visit[]){
	queue<int> q;
	q.push(s);
	visit[s]=true;
	while(!q.empty()){
		int u=q.front();
		cout<<u<" ";
		q.pop();
		
		for(int i=0;i<adj[u].size();i++){
			if(!visit[adj[u][i]]){
				q.push(adj[u][i]);
				visit[adj[u][i]]=true;
			}
		}
	}
}

void dfs(int s,vector<int> adj[],bool visit[]){
	stack<int> stk;
	stk.push(s);
	visit[s]=true;
	
	while(!stk.empty()){
		int u=stk.top();
		cout<<u<<" ";
		stk.pop();
		
		for(int i=0;i<adj[u].size();i++){
			if(!visit[adj[u][i]]){
				stk.push(adj[u][i]);
				visit[adj[u][i]]=true;
			}
		}
	}
}
int main(){
	vector<int>adj [5];
	bool visit[5];
	for(int i=0;i<5;i++){
		visit[i]=false;
	}
	
	edge(adj,0,2);
	edge(adj,0,1);
	  edge(adj,1,3);
	  edge(adj,2,0);
	  edge(adj,2,3);
	  edge(adj,2,4);
	  cout<<"BFS traversal is"<<"  ";
	  //call bfs funtion
	  bfs(0,adj,visit);//1 is a starting point
	  cout<<endl;
	  
	  //again initialise all node unvisited for dfs
  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  cout<<"DFS traversal is"<<"  ";
  //call dfs function
  dfs(0,adj,visit);//1 is a starting point
	
	return 0;
}

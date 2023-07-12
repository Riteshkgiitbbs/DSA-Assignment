#include <bits/stdc++.h> 



void bfs( unordered_map<int,list<int> > &adjList,  unordered_map<int,bool> &visited,vector<int> &ans,
int node ){
   queue<int> q;
   q.push(node);
   visited[node] =1;
   while(!q.empty()){
       int frontNode=q.front();
       q.pop();
       // store the front node  into ans;
       ans.push_back(frontNode);
       // traverse all neighbour of the frontnnode
       for(auto i: adjList[frontNode]){
           if(!visited[i]){
               q.push(i);
               visited[i]=1;
           }
       }
   }
}


void preparedAdjList(  unordered_map<int,list<int> >&adjList,vector<pair<int, int>> &edges){
    for(int  i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,list<int> >adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    preparedAdjList(adjList,edges);
    //traverse all component of the graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
}
// this code gives time limit exceed.! please ask to any onne

//                                              CODESTORY WITH MIK

// L-1

// LC-00    BASICS OF GRAPH
// cycles in fraph,degrees in grah,min spanning tree,algos of graph

//  L-2

// LC-00    REPRESENTATION OF GRAPH
// adjacency list and adjacency matrix
// given adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
//     vector<int> make(vector<vector<int>>& adj) {
//         
//         unordered_map<int ,vector<int>> mp ;
//         for(int u=0; u < adj.size();u++)
//         {
//             for(int &v : adj[u])
//             {
//                 mp[u].push_back(*v) ;
//             }
//         }
//     }

// L-3

// LC-00    DFS AND BFS
// class Solution {
//   public:
// void DFS( unordered_map<int ,vector<int>>& mp,int u,vector<bool>& visited,vector<int>& result)
//   {
//         if(visited[u]== true) return ;
//         visited[u] = true ;
//         result.push_back(u) ;
//         for(int &v : mp[u])
//         {
//             if(!visited[v]) DFS(mp,v,visited,result );
//         }
//   }
// vector<int> dfs(vector<vector<int>>& adj)
//     {
//         unordered_map<int ,vector<int>> mp ;
//         int n=adj.size() ;
//     // adjacency list making 
//         for(int u=0; u < n;u++)
//         {
//             for(int &v : adj[u])
//             {
//                 mp[u].push_back(v) ;
//             }
//         }  
//         vector<int> result ;
//         vector<bool> visited(n,false) ;     
//         DFS(mp,0,visited,result ) ;    
//         return result ;
//     }
// }; 
//    bfs
// class Solution {
//   public:
//     // Function to return Breadth First Traversal of given graph.
//     void BFS( unordered_map<int ,vector<int>>& mp,int u,vector<bool> visited ,vector<int>& result)
//     {
//        queue<int> q ;
//        q.push(u) ;
//        visited[u] = true;
//        result.push_back(u) ;
//        while(!q.empty())
//        {
//            int u = q.front() ;q.pop();
//            for(int& v : mp[u])
//            {
//                if(!visited[v])
//                 {
//                    q.push(v) ;
//                    visited[v] = true;
//                    result.push_back(v);
//                 }   
//            }
//        }
//     }
//     vector<int> bfs(vector<vector<int>> &adj) { 
//         unordered_map<int ,vector<int>> mp ;
//         int n=adj.size() ;
//     // adjacency list making 
//         for(int u=0; u < n;u++)
//         {
//             for(int &v : adj[u])
//             {
//                 mp[u].push_back(v) ;
//             }
//         }
//         vector<int> result ;
//         vector<bool> visited(n,false) ;
//         BFS(mp,0,visited, result ) ;
//         return result ;
//     }
// };

// L-4

// LC-00    DETECT CYCLE IN UNDIRECTED GRAPH DFS
//                      DFS
// class Solution {
//   public:
//    bool DFS(unordered_map<int,vector<int>> adj,int u,vector<bool>& visited,int parent)
//    {
//        visited[u] = true ;
//        for(int &v : adj[u])
//        {
//            if(parent==v) continue ;
//            if(visited[v]==true) return true ;
//            if(DFS(adj,v,visited,u)==true) return true ;
//        }
//        return false ;
//    }
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         // Code here
//         unordered_map<int,vector<int>> adj ;
//         for(auto &vec : edges)
//         {
//             int u=vec[0] ;
//             int v=vec[1] ;
//             adj[u].push_back(v) ;
//             adj[v].push_back(u) ;
//         }
//         vector<bool> visited(V,false) ;
//         for(int i=0;i<V;i++)
//         {
//             if(!visited[i] && DFS(adj,i,visited,-1)) return true ;
//         }
//         return false ;
//     }
// };
//        

// L-5

// LC-00    DETECT CYCLE IN UNDIRECTED GRAPH BFS
//   BFS
// class Solution {
//   public:
//    bool BFS(unordered_map<int,vector<int>> adj,int u,vector<bool>& visited)
//    {
//        queue<pair<int,int>> q ;
//        q.push({u,-1}) ;
//        visited[u] = true ;
//        while(!q.empty())
//        {
//            pair<int,int> p = q.front() ;
//            q.pop() ;
//            int source = p.first ; int parent = p.second ;
//            for(int &v : adj[source])
//            {
//                if(visited[v]==false)
//                {
//                    visited[v]=true ;
//                    q.push({v,source}) ;
//                }
//                else if(parent != v)
//                {
//                    return true;
//                }
//            }
//        }
//        return false ;
//    }
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         // Code here
//         unordered_map<int,vector<int>> adj ;
//         for(auto &vec : edges)
//         {
//             int u=vec[0] ;
//             int v=vec[1] ;
//             adj[u].push_back(v) ;
//             adj[v].push_back(u) ;
//         }
//         vector<bool> visited(V,false) ;
//         for(int i=0;i<V;i++)
//         {
//             if(!visited[i] && BFS(adj,i,visited)) return true ;
//         }
//         return false ;
//     }
// };

// L-6

// LC-00    DETECT CYCLE IN DIRECTED GRAPH DFS
// class Solution {
//   public:
//     bool DFS(unordered_map<int,vector<int>> adj , int u ,vector<bool>& visited,vector<bool> &inreccursion)
//     {
//         visited[u] = true;
//         inreccursion[u] = true ;
//         for(int &v : adj[u])
//         {
//             if(!visited[v] && DFS(adj,v,visited,inreccursion)) return true ;
//             else if(inreccursion[v] == true) return true ;
//         }
//         inreccursion[u] = false ;
//         return false ;
//     }
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         // code here
//         unordered_map<int,vector<int>> adj ;
//         for(auto &vec : edges)
//         {
//             int u=vec[0] ;
//             int v=vec[1] ;
//             adj[u].push_back(v) ;
//         }
//         vector<bool> visited(V,false) ;
//         vector<bool> inreccursion(V,false) ;
//         for(int i=0;i<V;i++)
//         {
//             if(!visited[i] && DFS(adj,i,visited,inreccursion)) return true ;
//         }
//         return false ;      
//     }
// };

// L-7

// LC-00    TOPOLOGICAL SORT USING DFS
// class Solution {
//   public:
//      void checktopo(vector<vector<int>>& adj,int u,vector<bool>&visited , stack<int>&st){
//         visited[u]=true;
//         for(int &v : adj[u]){
//             if(!visited[v]){
//                 checktopo(adj,v,visited,st);
//             }
//         }
//         st.push(u);
//     }
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         vector<vector<int>>adj(V);
//         vector<bool>visited(V,false);
//         for(auto vec : edges){
//             int u = vec[0];
//             int v = vec[1];
//             adj[u].push_back(v);
//         }
//         stack<int>st;
//         for(int i=0;i<V;i++){
//             if(!visited[i]){
//                 checktopo(adj,i,visited,st);
//             }
//         }
//         vector<int>ans;
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
// }
// };

// L-8

// LC-00    TOPOLOGICAL SORT USING BFS
// KAHNS ALGORITHM
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>> adj ;
//         int n = numCourses ;
//         vector<bool> visited(n,false) ;
//         vector<int> indegree(n,0) ;
//         for(int i =0;i<n;i++)
//         {
//             int a = prerequisites[i][0] ;
//             int b = prerequisites[i][1] ;
//             // b--->a
//             adj[b].push_back(a) ;
//             indegree[a]++;
//         }
//         // fill queue with indgree 0 elements
//         queue<int> q ;
//         for(int i=0;i<n;i++)
//         {
//             if(indegree[i] == 0) q.push_back(i) ;
//         }
//         vector<int> result ;
//         while(!q.empty())
//         {
//             int u=q.front() ;q.pop() ;
//             result.push_back(u) ;
//             for(int &v : adj[u])
//             {
//                 if(indegree[v]==0) q.push(v) ;
//             }
//         }
//     }
// };

// L-9

// LC-00    DETECT CYCLE IN DIRECTED GRAPH BFS
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>> adj ;
//         int n = numCourses ;
//         vector<bool> visited(n,false) ;
//         vector<int> indegree(n,0) ;
//         for(int i =0;i<n;i++)
//         {
//             int a = prerequisites[i][0] ;
//             int b = prerequisites[i][1] ;
//             // b--->a
//             adj[b].push_back(a) ;
//             indegree[a]++;
//         }
//         // fill queue with indgree 0 elements
//         queue<int> q ;
//         for(int i=0;i<n;i++)
//         {
//             if(indegree[i] == 0) q.push_back(i) ;
//         }
//         vector<int> result ;
//         while(!q.empty())
//         {
//             int u=q.front() ;q.pop() ;
//             result.push_back(u) ;
//             for(int &v : adj[u])
//             {
//                 if(indegree[v]==0) q.push(v) ;
//             }
//         }
//         if(result.size()==n) return true ;// completely traversed
//         return false ;
//     }
// };

// L-10

// LC-547   NUMBER OF PROVINCES DFS
// class Solution {
// public:
//     void DFS(vector<vector<int>> isConnected , int u,vector<bool> &visited,int n)
//     {   
//         visited[u] = true ;
//         for(int v=0;v<n;v++)
//         {
//             if(!visited[v] && isConnected[u][v]==1 )
//             {
//                 DFS(isConnected , v,visited,n );
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size() ;
//         int cnt = 0;
//         vector<bool> visited(n,false) ;
//         for(int i=0;i<n;i++)
//         {
//             if(!visited[i])
//             {
//                 DFS(isConnected,i,visited,n) ;
//                 cnt++ ;
//             }
//         }
//         return cnt ;
//     }
// };

// L-11

// LC-547   NUMBER OF PROVINCES BFS
// class Solution {
// public:
//     void DFS(vector<vector<int>> isConnected , int u,vector<bool> &visited,int n)
//     {   
        // queue<int> q ;q.push(u) ; visited[u] = true ;
        // while(!q.empty())
        // {
        //         int curr = q.front() ;q.pop() ;
        //         for(int &v : adj[curr])
        //         {
        //                 if(!visited[v]) q.push(v) ;
        //         }
        // }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size() ;
//         int cnt = 0;
//         vector<bool> visited(n,false) ;
//         for(int i=0;i<n;i++)
//         {
//             if(!visited[i])
//             {
//                 DFS(isConnected,i,visited,n) ;
//                 cnt++ ;
//             }
//         }
//         return cnt ;
//     }
// };

// L-12

// LC-207   COURSE SCEDHULE I DFS
// class Solution {
// public:
// bool topologicalsort(unordered_map<int,vector<int>> adj,int n,vector<int> &indegree)
// {
//     vector<int> result ;
//     queue<int> q ;
//     // fill queue with indgree 0 elements
//         for(int i=0;i<n;i++)
//         {
//             if(indegree[i] == 0) q.push(i) ;
//         }
//     while(!q.empty())
//         {
//             int u=q.front() ;q.pop() ;
//             result.push_back(u) ;
//             for(int &v : adj[u])
//             {   indegree[v]-- ;
//                 if(indegree[v]==0) q.push(v) ;
//             }
//         }
//         if(result.size() == n) return true; 
//         return false ;
// }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>> adj ;
//         int n = numCourses ;
//         vector<int> indegree(n,0) ;
//         for(int i =0;i<prerequisites.size();i++)
//         {
//             int a = prerequisites[i][0] ;
//             int b = prerequisites[i][1] ;
//             // b--->a
//             adj[b].push_back(a) ;
//             indegree[a]++;
//         }
//         return topologicalsort(adj,n,indegree) ;
//     }
// };

// L-13

// LC-210   COURSE SCHEDULE II DFS
//

// L-14         

// LC-207   COURSE SCHEDULE I BFS
//

// L-15

// LC-210   COURSE SCHEDULE II BFS
//

// L-16

// LC-785   BIPARTITE GRAPH DFS
// class Solution {
// public:
//     bool checkbipartite(vector<vector<int>> graph , int curr , vector<int>& color ,int currcolor)
//     {
//         color[curr] = currcolor ;
//         // color adjacent node
//         for(int &v : graph[curr])
//         {
//             if(color[v] == color[curr]) return false ;
//             if(color[v] == -1) // not coloured and visited
//             {
//                 int colorOfV=1- currcolor ;
//                 if(!checkbipartite(graph ,v,color,colorOfV)) return false ;
//             }
//             // already coloured
//         }
//         return true ;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size() ;
//         vector<int> color(n,-1); // no one coloured and visited in begining
//         // red =1 ;
//         // green=0 ;
//         for(int i=0;i<n;i++)
//         {
//             if(color[i] == -1) // not visited
//             {
//               if(checkbipartite(graph , i,color,1)==false) return false  ;//starting with red
//             }
//         }
//         return true;
//     }
// };

// LC-17

// LC-785   BIPARTITE GRAPH BFS
//

// L-18

// LC-00    DISJOINT SET UNION
//

// L-19

// LC-00    RANK AND PATH COMPRESSION
// class Solution {
// public:
//     vector<int> rank;
//     vector<int> parent;
//     int find(int i)
//     {
//         if(parent[i] == i) return i ;
//         return parent[i] = find(parent[i]);
//     }
//     void unions(int x ,int y)
//     {
//         int x_parent = find(x) ;
//         int y_parent = find(y) ;
//         if(x_parent == y_parent) return ;
//         if(rank[x_parent] > rank[y_parent])
//         {
//             parent[y_parent] = x_parent ;
//         }
//         else if(rank[y_parent] < rank[x_parent])
//         {
//             parent[x_parent] = y_parent ;
//         }
//         else
//         {
//             parent[x_parent] = y_parent;
//             rank[y_parent]++ ;
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         rank.resize(n,0) ;
//         parent.resize(n) ;
//         for(int i=0;i<n;i++) parent[i] = i ;
//     }
// };

// L-20

// LC-00    DETECT CYCLE USING DSU
//

// L-21

// LC-990   SATISFIABILITY OF EQUALITY - EQUATIONS
// class Solution {
// public:
//     vector<int> rankv;
//     vector<int> parent;
//     int find(int i) {
//         if (parent[i] == i) return i;
//         return parent[i] = find(parent[i]); // path compression
//     }
//     void unions(int x, int y) {
//         int x_parent = find(x);
//         int y_parent = find(y);
//         if (x_parent == y_parent) return;
//         if (rankv[x_parent] > rankv[y_parent]) {
//             parent[y_parent] = x_parent;
//         } 
//         else if (rankv[y_parent] > rankv[x_parent]) {
//             parent[x_parent] = y_parent;
//         } 
//         else {
//             parent[y_parent] = x_parent;
//             rankv[x_parent]++; 
//         }
//     }
//     bool equationsPossible(vector<string>& equations) {
//         parent.resize(26);
//         rankv.resize(26, 0);
//         for (int i = 0; i < 26; i++) parent[i] = i;
//         // union equal chars
//         for (string &s : equations) {
//             if (s[1] == '=') {
//                 unions(s[0] - 'a', s[3] - 'a');
//             }
//         }
//         // check not equal constraints
//         for (string &s : equations) {
//             if (s[1] == '!') {
//                 int parentfirst = find(s[0] - 'a');
//                 int parentsecond = find(s[3] - 'a');
//                 if (parentfirst == parentsecond) return false;
//             }
//         }
//         return true;
//     }
// };

// L-22

// LC-1319  NO. OF OPERATION TO MAKE NETWORK CONNECTED
// class Solution {
// public:
//     vector<int> rank;
//     vector<int> parent;
//     int find(int i)
//     {
//         if(parent[i] == i) return i ;
//         return parent[i] = find(parent[i]);
//     }
//     void unions(int x ,int y)
//     {
//         int x_parent = find(x) ;
//         int y_parent = find(y) ;
//         if(x_parent == y_parent) return ;
//         if(rank[x_parent] > rank[y_parent])
//         {
//             parent[y_parent] = x_parent ;
//         }
//         else if(rank[y_parent] < rank[x_parent])
//         {
//             parent[x_parent] = y_parent ;
//         }
//         else
//         {
//             parent[x_parent] = y_parent;
//             rank[y_parent]++ ;
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         rank.resize(n,0) ;
//         parent.resize(n) ;
//         for(int i=0;i<n;i++) parent[i] = i ;
//         if(connections.size() < n-1) return -1 ;
//         int components = n ;
//         for(auto &vec : connections)
//         {   // parent not equals
//             if(find(vec[0]) != find(vec[1]))
//             {
//                 unions(vec[0] , vec[1]);
//                 components-- ;
//             }
//         }
//         return components-1 ;
//     }
// };

// L-23

// LC-2316  COUNT UNREACHEABLE PAIRS OF NODES
// class Solution {
// public:
// vector<int> rank ;
// vector<int> parent ;
// int find(int i)
// {
//     if(parent[i] == i) return i;
//     return parent[i] = find(parent[i]) ;
// }
// void unions(int x ,int y)
// {
//     int x_parent = find(x) ;
//     int y_parent = find(y) ;
//     if(x_parent == y_parent) return ;
//     if(rank[x_parent] > rank[y_parent]) parent[y_parent] =x_parent ;
//     else if(rank[y_parent] > rank[x_parent]) parent[x_parent] =y_parent ;
//     else
//     {
//         parent[y_parent] = x_parent ;
//         rank[x_parent]++ ;
//     }
// }
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         rank.resize(n,0);
//         parent.resize(n) ;
//         for(int i=0;i<n;i++) parent[i] = i;
//         // making components
//         for(auto &vec : edges)
//         {
//             int u= vec[0] ; int v = vec[1] ;
//             unions(u,v) ;
//         }
//         // map for storing size of components
//         unordered_map<int , int> mp ;
//         for(int i=0;i<n;i++)
//         {
//             int papaji = find(i) ;
//             mp[papaji]++ ;
//         }
//         // ans from map to result
//         long long result =0 ;long long remainingnodes =n ;
//         for(auto &it : mp)
//         {
//             long long size = it.second ;
//             result += (size) *(remainingnodes - size) ;
//             remainingnodes-=size ;
//         }
//         return result ;
//     }
// };

// L-24

// LC-00    DIJKSTRA ALGORITHM I
// User Function Template
// class Solution {
//   public:
//     vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
//         // Code here
//         priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq ;
//         unordered_map<int,vector<pair<int,int>>> adj;
//         for(auto &it : edges)
//         {
//             int u = it[0] ;
//             int v = it[1] ;
//             int w = it[2] ;
//             adj[u].push_back({w,v}) ;
//             adj[v].push_back({w,u}) ;
//         }
//         vector<int> result(V ,INT_MAX) ;
//         result[src] = 0 ;
//         pq.push({0,src}) ;
//         while(!pq.empty())
//         {
//             int d = pq.top().first ;
//             int node=pq.top().second ;
//             pq.pop() ;
//             for(auto &it : adj[node])
//             {
//                 int dist = it.first ;
//                 int adjnode = it.second ;
//                 if(d + dist < result[adjnode])
//                 {
//                     result[adjnode] = d+dist ;
//                     pq.push({d+dist , adjnode}) ;
//                 }
//             }
//         }
//         return result ;
//     }
// };

// L-25

// LC-00    DIJKSTRA ALGORITHM II
// implement by SET

// L-26     

// LC-00    DIJKSTRA ALGORITHM III
// TC - E.V.log V

// L-27     

// LC-00    SHORTEST PATH IN WEIGHTED UNDIRECTED GRAPH
// class Solution {
//   public:
//     vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
//         // Code here
//         unordered_map<int , vector<pair<int,int>>> adj ;
//     priority_queue<pair<int,int>> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq ;
//         for(auto &vec : edges)
//         {
//             int u=vec[0] ; int v = vec[1] ; int w = vec[2] ;
//             adj[u].push_back({w,v}) ;
//             adj[v].push_back({w,u}) ;
//         }
//         vector<int> result(n+1,INT_MAX) ;
//         vector<int> parent(n+1) ;
//         // self parent
//         for(int i=1;i<= n;i++) parent[i] = i ;
//         result[1] = 0;// source
//         pq.push({0,1});// d, node
//         while(!pq.empty())
//         {
//             int d = pq.top().first ;
//             int node=pq.top().second; pq.pop() ;
//             for(auto &it : adj[node])
//             {
//                 int dist = it.first ;
//                 int adjnode=it.second ;
//                 if(d +dist < result[adjnode])
//                 {
//                     result[adjnode] = d+dist ;
//                     pq.push({d+dist , adjnode}) ;
//                     parent[adjnode] = node ;
//                 }
//             }
//         }
//         if(result[n] == INT_MAX) return{-1} ;
//         vector<int> path ; int node = n ;
//         while(parent[node]!=node )
//         {
//             path.push_back(node) ; node=parent[node] ;
//         }
//         path.push_back(1) ; // 1 is source  
//         reverse(path.begin() , path.end());
//         return path ;
//     }
// };

// L-28     

// LC-743   NETWORK DELAY TIME 
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         unordered_map<int, vector<pair<int, int>>> adj;
//         for(auto &vec : times) {    
//             int u = vec[0];
//             int v = vec[1];
//             int w = vec[2];         
//             adj[u].push_back({v, w});       
//         }    
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// 	vector<int> result(n+1, INT_MAX);
// 	result[k] = 0;
// 	pq.push({0, k});
// 	while(!pq.empty()) {
// 	    int d  = pq.top().first;
// 	    int node = pq.top().second;
// 	    pq.pop();
// 	    for(auto &vec : adj[node]) {
// 		int adjNode = vec.first;
// 		int dist    = vec.second;
// 		if(d + dist < result[adjNode]) {
// 		    result[adjNode] = d + dist;
// 		    pq.push({d+dist, adjNode});
// 		}
// 	    }
// 	}  
//         int ans = INT_MIN; 
//         for(int i = 1; i <= n; i++)
//             ans = max(ans, result[i]); 
// 	return ans == INT_MAX ? -1 : ans;
//     }
// };

// L-29

// LC-109   SHORTEST PATH IN BINARY MATRIX
// class Solution {
// public:
// vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
// typedef pair<int,pair<int,int>> p ; // wt ->x,y
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int m= grid.size() ;
//         int n=grid[0].size() ;
//         if(m==0 || n==0 || grid[0][0]!=0) return -1 ;
//         auto issafe = [&](int x ,int y)
//         {
//             return x >=0 && x<m && y>=0 && y<n ;
//         };
//         vector<vector<int>> result(m , vector<int>(n,INT_MAX)) ;
//         priority_queue<p,vector<p>,greater<p>> pq ;
//         pq.push({0 ,{0,0}}) ;
//         result[0][0] = 0 ;
//         while(!pq.empty())
//         {
//             int d = pq.top().first ;
//             auto node = pq.top().second ;pq.pop() ;
//             int x = node.first ;
//             int y = node.second ;
//             for(auto &dir : directions)
//             {   
//                 int x_ = x + dir[0] ;
//                 int y_ = y + dir[1] ;
//                 int dist = 1 ;
//                 if(issafe(x_,y_) && grid[x_][y_]==0 && d + dist < result[x_][y_])
//                 {
//                     result[x_][y_] = d+dist ;
//                     grid[x_][y_] = 1; 
//                     pq.push({d+dist ,{x_,y_}}) ;
//                 }
//             }
//         }
//         if(result[m-1][n-1] == INT_MAX) return -1 ;
//         return result[m-1][n-1]+1;
//     }
// };

// L-30

// LC-1631  PATH WITH MINIMUM EFFORT   
// class Solution {
// public:
//     typedef pair<int, pair<int, int>> P;
//     vector<vector<int>> directions = {
//                 {-1,0},
//         {0,-1},         {0,1},
//                 {1, 0}
//     };
//    // Interesting right :-) 
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int m = heights.size();
//         int n = heights[0].size();
//         auto isSafe = [&](int x, int y) {
//             return x>=0 && x<m && y>=0 && y<n;
//         };
//         vector<vector<int>> result(m, vector<int>(n, INT_MAX));
//         priority_queue<P, vector<P>, greater<P>> pq;
//         pq.push({0, {0, 0}});
//         result[0][0] = 0;
//         while(!pq.empty()) {
//             int diff  = pq.top().first;
//             auto node = pq.top().second;
//             pq.pop();
//             int x = node.first;
//             int y = node.second;        
//             //Why returning now ?
//             //Because there is no way that the rest of elements can update the weight of destination cell even smaller due to the min heap.
//             if(x == m-1 && y == n-1)
//                 return diff;          
// 	    for(auto dir:directions) {
// 		int x_   = x + dir[0];
// 		int y_   = y + dir[1];
// 		if(isSafe(x_, y_)) {
// 		    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
// 		    if(result[x_][y_] > newDiff) {
// 			result[x_][y_] = newDiff;
// 			pq.push({result[x_][y_], {x_, y_}});
// 		    }
// 		}
// 	     }
//         }
//         return result[m-1][n-1];
//     }
// };

// L-31

// LC-00    BELLMAN FORD ALGORITHM
// User function Template for C++
// class Solution {
//   public:
//     vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
//         // Code here
//         vector<int> result(V ,1e8) ;
//         result[src] = 0 ;
//         for(int count = 1 ;count <= V-1 ; count++)
//         {
//             for(auto &vec : edges)
//             {
//                 int u = vec[0] ;
//                 int v = vec[1] ;
//                 int w = vec[2] ;
//                 if(result[u] != 1e8 && result[u] + w < result[v])
//                 {
//                     result[v] = result[u] + w ;
//                 }
//             }
//         }
//         // one more time to detect -ve cycle
//         for(auto &vec : edges)
//             {
//                 int u = vec[0] ;
//                 int v = vec[1] ;
//                 int w = vec[2] ;
//                 if(result[u] != 1e8 && result[u] + w < result[v])
//                 {
//                     return {-1} ;
//                 }
//             }
//         return result ;
//     }
// };

// L-32

// LC-00    FLOYD MARSHALL ALGORITHM    
// class Solution {
//   public:
//     void floydWarshall(vector<vector<int>>& dist) {
//         int n = dist.size();
//         for (int via = 0; via < n; via++) {
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < n; j++) {
//                     // Only update if both paths are not infinity
//                     if (dist[i][via] != 1e8 && dist[via][j] != 1e8) {
//                         dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
//                     }
//                 }
//             }
//         }
//     }
// };

// L-33

// LC-00    SPANNING TREE BASICS
// basics

// L-34

// LC-00    PRIMS ALGORITHM
// class Solution {
//   public:
//     typedef pair<int,int> p;
//     int spanningTree(int V, vector<vector<int>>& edges) {
//         // Build adjacency list
//         vector<vector<pair<int,int>>> adj(V);
//         for (auto &e : edges) {
//             int u = e[0];
//             int v = e[1];
//             int w = e[2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }
//         // Min-heap for {weight, node}
//         priority_queue<p, vector<p>, greater<p>> pq;
//         vector<bool> inMST(V, false);     
//         pq.push({0, 0});  // start with node 0, weight 0
//         int sum = 0;      
//         while (!pq.empty()) {
//             auto [wt, node] = pq.top();
//             pq.pop();          
//             if (inMST[node]) continue;  // already taken
//             inMST[node] = true;
//             sum += wt;       
//             for (auto &[v, w] : adj[node]) {
//                 if (!inMST[v]) {
//                     pq.push({w, v});
//                 }
//             }
//         }    
//         return sum;
//     }
// };

// L-35

// LC-1584  MIN COST TO CONNECT ALL POINTS
// class Solution {
// public:
// typedef pair<int,int> p;
//     int spanningTree(int V, vector<vector<pair<int,int>>>& edges) {
//         // Build adjacency list
//         // vector<vector<pair<int,int>>> adj(V);
//         // for (auto &e : edges) {
//         //     int u = e[0];
//         //     int v = e[1];
//         //     int w = e[2];
//         //     adj[u].push_back({v, w});
//         //     adj[v].push_back({u, w});
//         // }
//         // Min-heap for {weight, node}
//         priority_queue<p, vector<p>, greater<p>> pq;
//         vector<bool> inMST(V, false);
//         pq.push({0, 0});  // start with node 0, weight 0
//         int sum = 0;
//         while (!pq.empty()) {
//             auto [wt, node] = pq.top();
//             pq.pop();
//             if (inMST[node]) continue;  // already taken
//             inMST[node] = true;
//             sum += wt;       
//             for (pair<int,int> vec : edges[node]) {
//                 int v = vec.first;
//                 int w = vec.second ;
//                 if (!inMST[v]) {
//                     pq.push({w, v});
//                 }
//             }
//         }     
//         return sum;
//     }
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int V = points.size();
//         vector<vector<pair<int,int>>> adj(V) ;
//         for(int i = 0; i< V ;i++)
//         {
//             for(int j =i+1; j <V;j++)
//             {
//                 int x1 = points[i][0] ;
//                 int y1 = points[i][1] ;
//                 int x2 = points[j][0] ;
//                 int y2 = points[j][1] ;
//                 int d =abs(x1-x2) + abs(y1-y2) ;
//                 adj[i].push_back({j , d}) ;
//                 adj[j].push_back({i , d}) ;
//             }
//         }
//         return spanningTree(V , adj) ;
//     }
// };

// L-36

// LC-00    KRUSKAL ALGORITHM
// class Solution {
//   public:
//     typedef pair<int,int> p;
//     vector<int> parent;
//     vector<int> rank;
// int find (int x) {
//     if (x == parent[x]) 
//         return x;
//     return parent[x] = find(parent[x]);
// }
// void Union (int x, int y) {
//     int x_parent = find(x);
//     int y_parent = find(y);
//     if (x_parent == y_parent) 
//         return;
//     if(rank[x_parent] > rank[y_parent]) {
//         parent[y_parent] = x_parent;
//     } else if(rank[x_parent] < rank[y_parent]) {
//         parent[x_parent] = y_parent;
//     } else {
//         parent[x_parent] = y_parent;
//         rank[y_parent]++;
//     }
// }
// int kruskal(vector<vector<int>> &vec)
// {
//     int sum = 0 ;
//     for(auto &temp : vec)
//     {
//         int w = temp[0] ;
//         int u = temp[1] ;
//         int v = temp[2] ;
//         int parent_u = find(u) ;
//         int parent_v = find(v) ;
//         if(parent_u != parent_v)
//         {
//             Union(u,v) ;sum+=w ;
//         }
//     }
//     return sum ;
// }
//     int spanningTree(int V, vector<vector<int>>& edges) {
//        parent.resize(V) ;
//        rank.resize(V,0) ;
//        for(int i=0;i<V;i++) parent[i] = i ;    
//        vector<vector<int>> vec ;
//        for(int i =0;i<edges.size();i++)
//        {
//            int u = edges[i][0] ;
//            int v = edges[i][1] ;
//            int w = edges[i][2] ;
//            vec.push_back({w,u,v}) ;
//        }
//        sort(vec.begin() , vec.end()) ;
//        return kruskal(vec) ;
//     }
// };

// L-37

// LC-00    MIN COST TO CONNECT ALL POINTS
// using kruskal algo

// L-38

// LC-00    STRONGLY CONNECTED COMPONENTS

// L-39

// LC-00    DISJOINT SET UNION BY SIZE AND PATH COMPRESSION
// class DSU {
//     vector<int> parent;
// 	vector<int> size;
// public:
//     DSU(int n) {
//     	parent.resize(n);
//         size.resize(n);
//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }
//     int find(int x) {
//         if (x == parent[x])
//             return x;
//         return parent[x] = find(parent[x]);
//     }
//     void Union (int x, int y) {
// 	    int x_parent = find(x);
// 	    int y_parent = find(y);
// 	    if (x_parent == y_parent) 
// 	        return;	
// 	    if(size[x_parent] > size[y_parent]) {
// 	        parent[y_parent] = x_parent;
// 	        size[x_parent]  += size[y_parent];
// 	    } else if(size[x_parent] < size[y_parent]) {
// 	        parent[x_parent] = y_parent;
// 	        size[y_parent]  += size[x_parent];
// 	    } else {
// 	        parent[x_parent] = y_parent;
// 	        size[y_parent]  += size[x_parent];
// 	    }
// 	}
// };

// L-40

// LC-00    EULER PATH AND CIRCUIT IN UNDIRECTED
// BASICS

// L-41

// LC-00    DETECT EULER PATH AND CIRCUIT 
// class Solution {
//   public:
//   void DFS(vector<int>adj[], int u, vector<bool>& visited) {
//         visited[u] = true;
//         for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
//             if(visited[*it] == false) {
//                 DFS(adj, *it, visited);
//             }
//         }
//     }
//   bool isconnected(int V, vector<int> adj[]){
//       int nonzerodegreevertex = -1 ;
//       for(int i=0;i<V ;i++)
//       {
//           if(adj[i].size() != 0) { nonzerodegreevertex = i ;break ; }
//       }
//       vector<bool> visited(V , false) ;
//       DFS(adj , nonzerodegreevertex,visited) ;
//       // check if all non zero vertex visited or not
//       for(int i=0;i<V;i++)
//       {
//           if(visited[i]==false && adj[i].size()>0) return false ;
//       }
//       return true; 
//   }
//     int isEulerCircuit(int V, vector<int> adj[]) {
//         // check is connected or not 
//         if(isconnected(V ,adj)== false ) return false ;  
//         // count number of odd degree vertex
//         int cntodd = 0;
//         for(int i=0;i<V;i++)
//         {
//             if(adj[i].size() %2!= 0) cntodd++ ;
//         }
//         if(cntodd >2) return 0 ; // none 
//         if(cntodd == 2) return 1 ;// graph
//         return 2;                 // circuit
//     }
// };

// L-42

// LC-00    EUELER PATH AND CIRCUIT IN DIRECTED
// INDEGREE AND OUTDEGREE

// L-43

// LC-2097  VALID ARRANGEMENTS OF PAIRS - HIERHOLZER ALGORITHM
// class Solution {
// public:
//     vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
//         unordered_map<int,int> indegree , outdegree ;
//         unordered_map<int , vector<int>> adj ;
//         for(auto &edge : pairs)
//         {
//             int u = edge[0] ;
//             int v = edge[1] ;
//             adj[u].push_back(v) ;
//             indegree[v]++ ;
//             outdegree[u]++;
//         }
//         // find start node
//         int  startnode = pairs[0][0] ;
//         for(auto &it : adj)
//         {
//             int node = it.first ;
//             if(outdegree[node] - indegree[node] ==1)
//             {
//                 startnode= node ;
//                 break; 
//             }
//         }
//         // do DFS
//         stack<int> st ;
//         vector<int> eulerpath ;
//         st.push(startnode) ;
//         while(!st.empty())
//         {
//             int curr = st.top() ;
//             if(!adj[curr].empty())
//             {
//                 int ngbr = adj[curr].back() ;
//                 adj[curr].pop_back() ;
//                 st.push(ngbr) ;
//             }
//             else
//             {
//                 eulerpath.push_back(curr) ;
//                 st.pop() ;
//             }
//         }
//         // build result
//         reverse(eulerpath.begin() , eulerpath.end()) ;
//         vector<vector<int>> result ;
//         for(int i=0;i<eulerpath.size()- 1;i++)
//         {
//             result.push_back({eulerpath[i] , eulerpath[i+1]}) ;
//         }
//         return result ;
//     }
// };

// L-44

// LC-1245  DIAMETER OF UNDIRECTED GRAPH

// L-45

// LC-3203  FIND MINIMUM DIAMETER
// class Solution {
// public:
//     pair<int,int> bfs(unordered_map<int , vector<int>> adj , int source)
//     {
//             queue<int> q ;
//             q.push(source) ;
//             unordered_map<int , bool> visited ;
//             visited[source] = true ;
//             int distance = 0 ;
//             int farthestnode = source ; 
//             while(!q.empty())
//             {   int size = q.size() ;// current level me itne nodes hai
//                 while(size--)
//                 {
//                     int curr = q.front() ; q.pop() ;
//                     farthestnode = curr ;
//                     for(auto &ngbr : adj[curr])
//                     {
//                         if(visited[ngbr] == false)
//                         {
//                             visited[ngbr] = true ;
//                             q.push(ngbr) ;
//                         }
//                     }
//                 }
//                 if(!q.empty()) distance++ ;
//             }
//             return  {farthestnode , distance} ;
//     }
//     int diameter(unordered_map<int , vector<int>> adj)
//     {
//         // find the farthest node from random node lets start from 0
//         auto [farthestnode , distance] = bfs(adj , 0) ;
//         // the farthest  node we got is one node of diameter
//         // find the fathest node from node we got above , that will be ohter end of diameter
//         auto [othernode , diameter] = bfs(adj , farthestnode) ;
//         return diameter ;
//     }
//     unordered_map<int,vector<int>> makeAdj(vector<vector<int>>& edges)
//     {
//         unordered_map<int, vector<int>> adj ;
//         for(auto &edge : edges)
//         {
//             int u = edge[0] ;
//             int v = edge[1] ;
//             adj[u].push_back(v) ;
//             adj[v].push_back(u) ;
//         }
//         return adj ;
//     }
//     int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
//         unordered_map<int , vector<int>> adj1 = makeAdj(edges1); 
//         unordered_map<int , vector<int>> adj2 = makeAdj(edges2);
//         int d1 = diameter(adj1) ; 
//         int d2 = diameter(adj2) ;
//         int combined = (d1+1)/2 + (d2+1)/2 + 1;
//         return max({d1 , d2,combined}) ; 
//     }
// };

// L-46

// LC-00    MULTI SOURCE BFS
// why multi source

// L-47

// LC-994   ROTTING ORANGES
// class Solution {
// public:
//     typedef pair<int,int> p;
//     vector<p> directions{{-1,0},{0,1},{1,0},{0,-1}};
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int minutes = 0;
//         int fresh = 0;
//         queue<p> q;
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == 2) {
//                     q.push({i,j});
//                 }
//                 if(grid[i][j] == 1) {
//                     fresh++;
//                 }
//             }
//         }    
//         if(fresh == 0) return 0; // No fresh oranges at all      
//         while(!q.empty()) {
//             int size = q.size();
//             bool rotted_this_minute = false;
//             for(int k = 0; k < size; k++) {
//                 auto top = q.front(); q.pop();
//                 int i = top.first, j = top.second;
//                 for(auto &dir : directions) {
//                     int new_i = i + dir.first;
//                     int new_j = j + dir.second;
//                     if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1) {
//                         grid[new_i][new_j] = 2;
//                         q.push({new_i, new_j});
//                         fresh--;
//                         rotted_this_minute = true;
//                     }
//                 }
//             }
//             if(rotted_this_minute) minutes++;
//         }     
//         return fresh == 0 ? minutes : -1;
//     }
// };

// L-48

// LC-1765  MAP OF HIGHEST PEAK










































































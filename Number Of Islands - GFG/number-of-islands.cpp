//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector<int>parent;
  vector<int>rank;
  
  void makeSet(int n)
  {
      parent=vector<int>(n);
      rank=vector<int>(n);
      for(int i=0;i<n;i++)
      {
          parent[i]=i;
          rank[i]=0;
      }
  }
  
  int findPar(int node)
  {
      
      if(parent[node]==node)
      {
          return node;
      }
      
      return parent[node]= findPar(parent[node]);
  }
  
  void unionByRank(int u,int v)
  {
      int x=findPar(u);
      int y=findPar(v);
      if(x==y)
      {
          return;
      }
      if(rank[x]<rank[y])
      {
          parent[x]=y;
      }
      else if(rank[y]<rank[x])
      {
          parent[y]=x;
      }
      else if(rank[x]==rank[y])
      {
          parent[y]=x;
          rank[x]++;
      }
      
  }
  
  bool isValid(int x,int y,int n,int m)
  {
      return (x>=0 and x<n and y>=0 and y<m);
  }
  
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &queries) {
        makeSet(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        int cnt=0;
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        for(auto it:queries)
        {
            int r=it[0];
            int c=it[1];
            if(vis[r][c]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            
            cnt++;
            vis[r][c]=1;
            
            for(int ind=0;ind<4;ind++)
            {
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,n,m) )
                {
                    
                    //going to its four adjacent neighbour and if they are land(vis will be 1) and their parents are not equal then we do cnt-- and take union
                    if(vis[newr][newc]==1)
                    {
                      
                        int nodeNo=r*m+c;
                        int adjNodeNo=newr*m+newc;
                        if(findPar(nodeNo)!=findPar(adjNodeNo))
                        {
                            cnt--;
                    
                        unionByRank(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
            
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
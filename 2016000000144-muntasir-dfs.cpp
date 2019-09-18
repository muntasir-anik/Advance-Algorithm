#include<bits/stdc++.h>
#define max 50004
using namespace std;
int  n,m,q,x,y;
bool visited[max];
bool dfsDone[max];
vector < int > hasPathTo[max];
vector < pair < int, int > > qs;
vector < int  > edges[max];
void dfs(int source) {
    hasPathTo[source].push_back(source);
    std::fill_n(visited,max,false);
    vector < int > stack;
    stack.push_back(source);
    visited[source]=true;
    while(!stack.empty()) {
        int u=stack.back();
        stack.pop_back();
        for(int v=0;v<edges[u].size();v++) {
            if(dfsDone[edges[u][v]]){
                visited[edges[u][v]]=true;
                for(int i=0;i<hasPathTo[edges[u][v]].size();i++) {
                    hasPathTo[source].push_back(hasPathTo[edges[u][v]][i]);
                    visited[hasPathTo[edges[u][v]][i]]=true;
                }
            }
            if(!visited[edges[u][v]]) {
                hasPathTo[source].push_back(edges[u][v]);
                stack.push_back(edges[u][v]);
                visited[edges[u][v]]=true;
            }
        }
    }
    dfsDone[source]=true;
    return;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>x>>y;
        edges[x].push_back(y);
    }
    cin>>q;
    while(q--) {
        cin>>m>>x>>y;
        if(m==1) (y==0)?edges[x].push_back(++n):edges[++n].push_back(x);
        else qs.push_back(make_pair(x,y));
    }
    for(int i=1;i<=n;i++) {
        dfs(i);
    }
    for(int i=0;i<qs.size();i++) {
        bool found=false;
        for(int j=0;j<hasPathTo[qs[i].first].size();j++){
            if(hasPathTo[qs[i].first][j]==qs[i].second) {
                found=true;
                break;
            }
        }
        cout<<((found)?"Yes\n":"No\n");
    }
    return 0;
}

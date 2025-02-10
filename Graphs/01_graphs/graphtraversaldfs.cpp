#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template <typename T>
//now we make adjacency list with weights
class Graph{
    public:
    unordered_map<T,list<pair<T,int> > > adjlist;

    void addedge(T u,T v,int wt, bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        if(direction == 1){
            // Directed graph means u -> v 
            adjlist[u].push_back(make_pair(v,wt));
        }
        else{
            // direction ==  0 means
            // undirected graph 
            // u-------v
            // u <-> v
            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u,wt});
        }
        printadjlist();
        cout<<endl;
    }

    void printadjlist(){
        for(auto i : adjlist){
            cout<<i.first<<": { ";
            for(pair<T,int> p : i.second)
                cout<<"{"<<p.first<<","<<p.second<<"}, ";
            cout<<"}"<<endl;
        }
    }

    void dfs(T src, unordered_map<T,bool>& vis){
        //Two observation i don't need base case
        // first reason is that we do next recursive call when there is not visited
        // secondaly homework question 
        // find out number of disconnected components in the graph
        vis[src] = true;
        cout<<src<<" ";
        
        for(auto nbr : adjlist[src]){
            T nbrdata = nbr.first;
            if(!vis[nbrdata]) dfs(nbrdata,vis); 
        }
    }

};
int main(){
    Graph<char> g;
    // continues graph
    g.addedge('a','b',5,0);
    g.addedge('b','c',10,0);
    g.addedge('c','d',20,0);
    g.addedge('d','e',50,0);
    g.addedge('e','f',20,0);


    unordered_map<char,bool> visited;
    //for avoid disconnect case failure 
    // call them with for loop 
    for(char node = 'a'; node <= 'f'; node++){
        if(!visited[node]) g.dfs(node,visited);
    }
    // g.dfs('a',visited);
    return 0;
}
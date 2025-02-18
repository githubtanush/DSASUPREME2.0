//breadth first search - travel in like level order traversal
//it can occur with the help of queue
  

// adjacency list 
// a -> { b,c }
// b -> { a,c,d }
// c -> { a,b,e,f }
// d -> { b }
// e -> { c,f }
// f -> { e,c }

// visited data structure       edge list
// a -> F                       a -> b  b -> d
// b -> F                       b -> a  d -> b
// c -> F                       a -> c  c -> e
// d -> F                       c -> a  e -> f
// e -> F                       b -> c  f -> e
// f -> F                       c -> b    

// src node -> a so push a in this queue and then vis[a] = true;
// a | b | c | d | e | f 
// bfs is breadth first search 

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

    void bfstraversal(T src,unordered_map<char,bool>& vis){
        //adjlist already data member me hai 
        // //visited
        // unordered_map<T,bool> vis;
        //queue
        queue<T> q;
        //initial state
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            T frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();

            // go to neighbour
            for(auto neighbour : adjlist[frontNode]){
                T neighbourdata = neighbour.first;
                if(!vis[neighbourdata]){
                    q.push(neighbourdata);
                    vis[neighbourdata] = true;
                }
            }
        }
    }
};
int main(){
    // Graph<char> g;
    // continues graph
    // g.addedge('a','b',5,0);
    // g.addedge('b','c',10,0);
    // g.addedge('c','d',20,0);
    // g.addedge('d','e',50,0);

    // disconnect graph 
    Graph<char> g;
    g.addedge('a','b',5,0);
    g.addedge('b','c',10,0);
    g.addedge('d','e',20,0);
    g.addedge('f','f',50,0);
    
     //visited
    unordered_map<char,bool> vis;

    //ab mein har ek node ke liye bfs traversal 
    for(char node='a' ; node <= 'f' ; node++){
        if(!vis[node]) g.bfstraversal(node,vis);
    }
    return 0;
}
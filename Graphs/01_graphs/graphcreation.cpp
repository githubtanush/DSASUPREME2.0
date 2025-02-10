// graph creation - by two ways 
// 1.) adjacency matrix
// 2.) adjacency list

// graph  0 - 1 
//           / \"
//          2   3

//edge-list 0->1 / 1->2 / 2->3 / 1->3

//adjacency matrix - n * n : n -> number of nodes
// 4 node case mein 4 node ka matrix bna diya 

//________________________
//| 0 | 0 | 1  | 0  | 0  |
//| 1 | 0 | 0  | 1  | 1  |
//| 2 | 0 | 0  | 0  | 1  |
//| 3 | 0 | 0  | 0  | 0  |
//-------------------------



//######################################################################################################################################################################################################################
// adjacency - list
// edge list - 0 : {1}
//             1 : {2,3}
//             2 : {3}
//             3 : {4}
//             4 : {5}
//             5 : {3}
//sbke immediate neighbour dekhne hai 
//map<int,list<int>>// list is an stl in the c++    

//list is an stl which is used in cpp

#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
// class Graph{
//     public: 
//         unordered_map<int,list<int> > adjlist;
//         // int -> source list<int> -> neighbour
//         // int -> source list<pair<int,int>> -> 1st value neighbour 
//         //2nd value -> distance
    
//     void addedge(int u,int v,bool direction){
//         //direction - > 0 -> undirected
//         // direction -> 1 -> directed
//         //agr direction 1 hai matlab directed graph hai matlab direction 1 hi side hai double side nhi hai
//         if(direction == 1){
//             //means sirf u se v ja rah hu 
//             // vaapis nhi aa rah hu 
//             // u --> v
//             // u -*- v
//             adjlist[u].push_back(v);
//         }
//         // agr direction 0 ho gya to matlab undirected graph hai matlab direction 0 hai matlab dono side se hai 
//         else{
//             //direction = 0;
//             // u -- v
//             // u -> v
//             adjlist[u].push_back(v);
//             // v -> u;
//             adjlist[v].push_back(u);
//         }
//         cout<<endl<<"printing adjList"<<endl;
//         printadjlist();
//         cout<<endl;
//     }
//     void printadjlist(){
//         for(auto i : adjlist){
//             cout<<i.first<<"-> {";
//             for(auto neighbour : i.second){
//                 cout<<neighbour<<", ";
//             }
//             cout<<"}"<<endl;
//         }
//     }
// };

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

};

//Adjacency list time complexity and space complexity ? 
//Time Complexity = 
//Space Complexity = 

//created graph with the help of adjacency matrix
// void solve(vector<pair<int,int> > edgelist){
//     int n = edgelist.size();
//     vector<vector<int> > adj(n, vector<int>(n,0));
//     for(auto i : edgelist){
//         int u = i.first;
//         int v = i.second;
//         adj[u][v] = 1;
//     }
// }
//Time Complexity = O(N^2);
//Space Complexity = O(N^2);
 
int main(){
    // Graph g;
    // g.addedge(0,1,1);//first 2 parameter is nodes and last parameter represents that it is directed or undirected
    // g.addedge(1,2,1);//first 2 parameter is nodes and last parameter represents that it is directed or undirected
    // g.addedge(1,3,1);//first 2 parameter is nodes and last parameter represents that it is directed or undirected
    // g.addedge(2,3,1);//first 2 parameter is nodes and last parameter represents that it is directed or undirected

    Graph<char> g;
    g.addedge('a','b',5,0);
    g.addedge('b','c',10,0);
    g.addedge('c','d',20,0);
    g.addedge('d','e',50,0);
    return 0;
}
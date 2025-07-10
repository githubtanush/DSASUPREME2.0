//cycle detection 
// undirected - BFS/ DFS
// Directed - BFS/ DFS

// Undirected graph -  src at 0
// 0 - 1 - 2
//     |   |
//     3 - 4 - 5

//Cycle detect krne ka simple method agr hm kisi bhi node par uske parent
//node ke elava bhi phunch paay to yaani hm agr kisi bhi node par nonparent
//node se phunch paay matlab us jagah cycle present hai 

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public: 
        unordered_map<int,list<int> > adjlist;
        // int -> source list<int> -> neighbour
        // int -> source list<pair<int,int>> -> 1st value neighbour 
        //2nd value -> distance
    
    void addedge(int u,int v,bool direction){
        //direction - > 0 -> undirected
        // direction -> 1 -> directed
        //agr direction 1 hai matlab directed graph hai matlab direction 1 hi side hai double side nhi hai
        if(direction == 1){
            //means sirf u se v ja rah hu 
            // vaapis nhi aa rah hu 
            // u --> v
            // u -*- v
            adjlist[u].push_back(v);
        }
        // agr direction 0 ho gya to matlab undirected graph hai matlab direction 0 hai matlab dono side se hai 
        else{ 
            //direction = 0;
            // u -- v
            // u -> v
            adjlist[u].push_back(v);
            // v -> u;
            adjlist[v].push_back(u);
        }
        cout<<endl<<"printing adjList"<<endl;
        printadjlist();
        cout<<endl;
    }
    void printadjlist(){
        for(auto i : adjlist){
            cout<<i.first<<"-> {";
            for(auto neighbour : i.second){
                cout<<neighbour<<", ";
            }
            cout<<"}"<<endl;
        }
    }

    bool checkcycleundirectedbfs(int src){
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        //initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontnode = q.front();
            q.pop();

            for(auto nbr : adjlist[frontnode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontnode;
                }
                //cycle present 
                else if(visited[nbr] == true && nbr != parent[frontnode]) return true;
            }
        }
        //cycle not present 
        return false;
    }
};
int main(){
    // Graph<char> g;
    // g.addedge('a','b',5,0);
    // g.addedge('b','c',10,0);
    // g.addedge('c','d',20,0);
    // g.addedge('d','e',50,0);

    Graph g;
    g.addedge(0,1,0);
    g.addedge(1,2,0);
    g.addedge(1,3,0);
    g.addedge(2,4,0);
    g.addedge(3,4,0);
    g.addedge(2,5,0);

    int src = 0;

    bool iscyclic = g.checkcycleundirectedbfs(src);
    if(iscyclic) cout<<"Cycle present"<<endl;
    else cout<<"Cycle Absent"<<endl;
    return 0;
}

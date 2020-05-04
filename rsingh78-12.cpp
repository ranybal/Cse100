/**************************

The Bellman-Ford Algorithm
written by Ranvir Singh

***************************/


#include <iostream>
#include <limits.h>
using namespace std;


void Init_Single_Source(int *d, int NV){
        for(int i = 0; i < NV; i++) {
        d[i] = INT_MAX; 
    }
    d[0] = 0;

}

void RELAX(int **G, int *g, int NV, int NE)
{
    int i;
    int j;
   
    for(i = 1; i < NV; i++) { 
        for(j = 0; j < NE; j++) { 
           int u = G[0][j];
           int v = G[1][j];
           int w = G[2][j];
            if(g[u] != INT_MAX) {
                if(g[v] > g[u] + w){
                g[v] = g[u] + w;
                }
            }
        }
    }

}

void PRINT_FUNC(int *d, int NV)
{
    cout << "TRUE" <<endl;
    for(int i = 0; i < NV; i++) {
        if(d[i] < INT_MAX)
            cout << d[i] <<endl; 
        if(d[i] == INT_MAX) 
            cout << "INFINITY" <<endl;
    }
}

void Bellman_Ford(int ** G, int NV, int NE) {
    int condition = 1;
    int i, j;
    int d[NV];
    bool reachable = true;
    
    
  
    Init_Single_Source(d, NV);
    
    
    RELAX(G, d, NV, NE);    
    for(j = 0; j < NE; j++) { 
      int u = G[0][j];
      int v = G[1][j];
      int w = G[2][j];
        if(d[u] != INT_MAX) {
            if(d[G[1][j]] > d[G[0][j]] + G[2][j])
            condition = 2;
          
      }
    }
    switch(condition){
        case 1:
            PRINT_FUNC(d, NV);
        break;
        case 2:
            cout << "FALSE" << endl;
        break;
        default:
            NULL;
        
    }
}

int main() {
    
    int i, j;
    int NV = 0;
    int NE = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    cin >> NV;
    cin >> NE;
    int **G;
    G = new int *[3]; 
    for(i = 0; i < NV; i++) {
        
        G[i] = new int[NE]; 
    }
    for(i = 0; i < NE; i++) {
        cin >> u >> v >> w; 
        G[0][i] = u; 
        G[1][i] = v;
        G[2][i] = w;
    }
    
    Bellman_Ford(G, NV, NE);
    return 0;
    
}
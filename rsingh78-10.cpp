
/*************************************

Lab10 - Strongly connected components
written by Ranvir Singh

**************************************/

#include <iostream>

#include <list>

#include <stack>


using namespace std;

// create a class with the name of Strongly connected components


class Stronglyconnectedcomponent

{

// Declare the vertex

int Vertex;

// Declare a list od adjacent node

list<int> *adjacent;

// create a function to fill the node

void SCCfillID(int vertex, bool traveresd[], stack<int> &Stack);

// Create a function to use DFS approach to traverse

// the vertex node

void SSCDFS(int vertex, bool traveresd[],int node,int ar[]);

// create the bydefault constructor

public:

Stronglyconnectedcomponent(int Vertex);

void connectededge(int vertex, int w);

// create the function to print the the stongly connected

// components

void printSCCs(int node,int arr[]);

// get transpose method to conncet the graph

Stronglyconnectedcomponent getTranspose();

};

// define the function of strongly connected class

Stronglyconnectedcomponent::Stronglyconnectedcomponent(int Vertex)

{

// this method to traverse the vertex

this->Vertex = Vertex;

// traverse the adjacent vertex

adjacent = new list<int>[Vertex];

}

// Definene the Strongly connected to display the DFS tree vertex node

void Stronglyconnectedcomponent::SSCDFS(int vertex, bool traveresd[],int node,int arr[])

{

// which node is traversed, assign that is true

traveresd[vertex] = true;

arr[vertex]=node;

// recall all the visited vertex in the list

list<int>::iterator i;

for (i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)

if (!traveresd[*i])

SSCDFS(*i, traveresd,node,arr);

}

Stronglyconnectedcomponent Stronglyconnectedcomponent::getTranspose()

{

Stronglyconnectedcomponent g(Vertex);

for (int vertex = 0; vertex < Vertex; vertex++)

{


list<int>::iterator i;

for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)

{

g.adjacent[*i].push_back(vertex);

}

}

return g;

}


void Stronglyconnectedcomponent::connectededge(int vertex, int w)

{

adjacent[vertex].push_back(w); 

}


void Stronglyconnectedcomponent::SCCfillID(int vertex, bool traveresd[], stack<int> &Stack)

{


traveresd[vertex] = true;


list<int>::iterator i;

for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)

if(!traveresd[*i])

SCCfillID(*i, traveresd, Stack);



Stack.push(vertex);

}



void Stronglyconnectedcomponent::printSCCs(int node,int arr[])

{


stack<int> Stack;


bool *traveresd = new bool[Vertex];

for(int i = 0; i < Vertex; i++)

traveresd[i] = false;


for(int i = 0; i < Vertex; i++)

if(traveresd[i] == false)

SCCfillID(i, traveresd, Stack);


Stronglyconnectedcomponent gr = getTranspose();


for(int i = 0; i < Vertex; i++)

traveresd[i] = false;


while (Stack.empty() == false)

{


int vertex = Stack.top();

Stack.pop();


if (traveresd[vertex] == false)

{

gr.SSCDFS(vertex, traveresd,vertex,arr);

int min=vertex;

for(int i=0;i<node;i++)

{


if(arr[i]==vertex)

{


if(min>i)

min=i;

}

}



for(int i=0;i<node;i++)

if(arr[i]==vertex)

arr[i]=min;



}

}

}



int main()

{



int node,edge;

cin>>node;

cin>>edge;



Stronglyconnectedcomponent g(node);



for(int i=0;i<edge;i++)

{



int u,w;

cin>>u>>w;

g.connectededge(u,w);

}

int arr[node];

for(int i=0;i<node;i++)

{

arr[i]=node+2;

}

g.printSCCs(node,arr);



for(int i=0;i<node;i++)

{

cout<<arr[i]<<endl;

}

return 0;

}
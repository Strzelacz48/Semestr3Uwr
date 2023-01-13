/*#include <iostream>
using namespace std;
struct V
{
    int n;
    int neighbors[100];
};
void search_graph(struct V *v)
{
    int i;
    for (i = 0; i < v->n; i++)
    {
        cout << v->neighbors[i] << endl;
    }
}
int main()
{
    struct V G[5] = {
        {1, {1}},
        {2, {0,2}},
        {3, {1,3,4}},
        {1, {2}},
        {1, {2}}};
    return 0;
}*/
V := array of vertex
struct vertex{
    neighbors := list of neighbors vertexes
    radius := longest path from vertex
}

//recursive function that traverses through every vertex and edge of a tree
//complexity(2m + 2n)
int find_radius(vertex from, vertex current){
    int radius = 0;// distance of going between 
    for (int i = 0; i < current.neighbors.length; i++)
    {
        vertex neighbor_i = current.neighbors[i] ;
        if(neighbor_i == from)
            continue;

        tmp = find_radius(current, neighbor_i) + 1;
        if(tmp > t)
            radius = tmp;
    }

    //store radius
    current.radius = radius

    //fix if path that you came from is longer than the branches of neighbor_i
   for (int i = 0; i < current.neighbors.length; i++)
    {
        vertex neighbor_i = current.neighbors[i] ;
        if(neighbor_i == from)
            continue;

        neighbor_i.radius = max(neighbor_i.radius + 1, radius)
    }


    return radius;
}

//fill in every v.radius using find_radius
//pass an arbitrary starting vertex
find_radius(null, V[69])

int min = +inf;
list = [];
for (int i = 0; i < V.length; i++)
{
    if(V[i].radius < min){
        min = V[i].radius 
        list = [ V[i] ] //overwrite previous list
    }else if (V[i].radius == min){
        list.add(V[i])
    }
}

list := central vertex

Just some templates codes which help me in contests

General Points: 
- In C/C++, truncate division is used to determine the remainder <br/>
SO USE THIS : (a%b + b)%b ;  <br/>
(In programming languages which uses truncate divison to find the remainder, we always find remainder as : add quotient to remainder and again take remainder to avoid negative remainder and get the correct result.)

<br/>
GRAPHS and TREES
<br/>

<ul>
<li> 
To get parent array in tree, perform a dfs with root of tree as specifed (generally 1) and fill the parent array;
</li>
  
<li>
To get Least common ansestor of two nodes in a tree: <br/>
(say we want lca of a,b) then we would first fill our parent array using dfs with source as root node , now we can calulate the path of node a and node b using par array , as going from a->par[a]->par[par[a]] till we reach the root. and LCA of a,b would be last node which is equal in path(a), path(b);
</li>

<li>
To get Diameter of the tree : <br/>
Consider any node as source node (root) and calculate depth of each node using DFS. 
Now the node with max depth would be for sure one endpoint of the diameter, call this node as mx_node.
Now take mx_node as source and recalculate the depth of each node using DFS. Now the max depth you get in this array would be diameter of tree.
</li>

<li>
Floyd Warshall Algo: <br/>
updating all pairwise distance , such that if addition of kth node would affect our dis[i][j], 
then we would update our dis[i][j] = dis[i][k]+ dis[k][j];
if addition of kth node wont give us any shorter path , dis[i][j] wont be affected;
</li>
  
</ul>

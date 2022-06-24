//unlike binary tree we don't have to go to each and every node
//we need to just make a check at each level either to go to left or to right
//complexity is O(h) not O(n)->n=no of nodes.
//inserto also O(h)
//same with deletion
//in case of deletion we firt find minmum of nodes 
//we cal recursivley to find minimum in sub trees 
//d to find the root
//d' to find the minumum of sub trees
//d' to delete the minum
//d+2d'<2h work done
//deletion->O(h)
//skew ->disadavntage ->everything is O(n) there
//hence we don'y prefer skew


/*
balanced tree->for every node=>h(left subt)-h(right subtree)<=1
for bst to do well we want balanced tree
height of tree (idea)<O(log n)-->isse zyada nhi hona chahiye

ALL TYPES OF BALANCED TREES---->
1.AVL TREE->READ AND IMPLEMET-->
     root
  h=4    h=6
then we rortae the tree such that root comes to lesser height side and more height root becomes overall root
learn to implement it and coversion method


2.red black tree--->learn to implemet it
3.2-4 tree-->impleemt this too




*/
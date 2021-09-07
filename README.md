# Program-to-Delete-node-in-AVL-Tree
## STEPS 
Let w be the node to be deleted 
1) Perform standard BST delete for w. 
2) Starting from w, travel up and find the first unbalanced node. Let z be the first unbalanced node, y be the larger height child of z, and x be the larger height child of y. Note that the definitions of x and y are different from insertion here. 
3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z. There can be 4 possible cases that needs to be handled as x, y and z can be arranged in 4 ways. Following are the possible 4 arrangements: 
a) y is left child of z and x is left child of y (Left Left Case) 
b) y is left child of z and x is right child of y (Left Right Case) 
c) y is right child of z and x is right child of y (Right Right Case) 
d) y is right child of z and x is left child of y (Right Left Case)
Like insertion, following are the operations to be performed in above mentioned 4 cases. Note that, unlike insertion, fixing the node z won’t fix the complete AVL tree. After fixing z, we may have to fix ancestors of z as well

![image](https://user-images.githubusercontent.com/69696459/132339734-cdb1814b-fe5f-42fe-be07-641a3a7de25c.png)

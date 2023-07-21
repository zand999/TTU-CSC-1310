#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// Stack template
template <typename vartype>
class BinaryTree
{
private:
   struct TreeNode
   {
      vartype value;           // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   
   // Private member functions
   void insert(TreeNode *newNode){
      if(root == nullptr){
         root = new
      }
   }

   
   
public:
   // Constructor
   BinaryTree()
      { root = NULL; }
      
   // Destructor
   ~BinaryTree(){ destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(vartype){
      TreeNode *temp = new TreeNode;
      temp -> value = item;
      temp -> left = nullptr;
      temp -> right = nullptr;


   }
};


}
#endif
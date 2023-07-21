


#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

template <typename vartype>
class BinaryTree
{
private:
   struct TreeNode
   {
      vartype value;
      TreeNode *left;
      TreeNode *right;  
   };

   TreeNode *root;    

   void insert(TreeNode *&nodePtr, TreeNode *&newNode){
      if (nodePtr == nullptr)
         nodePtr = newNode;                 
      else if (newNode->value < nodePtr->value)
         insert(nodePtr->left, newNode); 
      else 
         insert(nodePtr->right, newNode); 
   }
   
   void displayInOrder(TreeNode *nodePtr) const{
      if (nodePtr){
         displayInOrder(nodePtr->left);
         cout << nodePtr->value << endl;
         displayInOrder(nodePtr->right);
      }
   }
   void displayPreOrder(TreeNode *nodePtr) const{
      if (nodePtr){
         cout << nodePtr->value << endl;
         displayPreOrder(nodePtr->left);     
         displayPreOrder(nodePtr->right);
      }
   }
   void displayPostOrder(TreeNode *nodePtr) const{
      if (nodePtr){
         displayPostOrder(nodePtr->left);    
         displayPostOrder(nodePtr->right);
         cout << nodePtr->value << endl;
      }
   }

   void destroySubTree(TreeNode *nodePtr){
      if (nodePtr){
         if (nodePtr->left)
            destroySubTree(nodePtr->left);
         if (nodePtr->right)
            destroySubTree(nodePtr->right);
         delete nodePtr;
      }
   }
   
public:

   BinaryTree(){
      root = NULL; 
   }
      

   ~BinaryTree(){
      destroySubTree(root); 
   }

      

   void insertNode(vartype item){
      TreeNode *newNode = nullptr;  

      newNode = new TreeNode;
      newNode->value = item;
      newNode->left = newNode->right = nullptr;
      

      insert(root, newNode);
   }
   bool searchNode(vartype item){
      TreeNode *nodePtr = root;

      while (nodePtr){
         if (nodePtr->value == item)
            return true;
         else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
         else
            nodePtr = nodePtr->right;
      }
      return false;
   }
   
   void displayInOrder() const{  
      displayInOrder(root); 
   }
      
   void displayPreOrder() const{
      displayPreOrder(root);
   }
      
   void displayPostOrder() const{
      displayPostOrder(root);
   }
};



#endif
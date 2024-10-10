#include <iostream>

using namespace std ; 


class Node 
{
	public : 
		int data ; 
		Node* left; 
		Node* right; 

		Node(int value) 
		{
			data=value; 
			left=right=NULL; 
		}
} ;

class BST 
{
	public : 
		Node* root ; 
		BST() {root=NULL;}
		// helpers are used to implement the recursive solution.
		Node* insertHelper(Node* node , int value )
		{
			if(node==NULL)
				return new Node(value);
			if(node->data >value)
			{
				node->left=insertHelper(node->left,value);
			}
			else if (node->data <value)
			{
				node->right=insertHelper(node->right,value);

			}
			return node;
		}
		void insert(int value)
		{
			root=insertHelper(root,value);
		}

		bool searchHelper(Node* node, int value)
		{
			if(node==NULL)	
				return false; 
			if(node->data==value)
				return true; 
			else if (node->data<value)
			{
				return searchHelper(node->right,value);
			}
			else 
				return searchHelper(node->left,value);
		}
		bool search(int value)
		{
			return searchHelper(root,value);
		}

		void displayHelper(Node* node) // inorder traversal will display the numbers sorted
		{
			if(node!=NULL)
			{
				displayHelper(node->left);
				cout<<node->data<<'\n';
				displayHelper(node->right);
			}
		}

		void display()
		{
			displayHelper(root);
		}
		int successor(Node* node)
		{
			node=node->right; 
			while(node->left!=NULL)
				node=node->left;
			return node->data; 
		}
		Node* deleteHelper(Node* node , int value)
		{
			if(node==NULL)
				return node ;
			else 
			{
				if(node->data <value)
				{
					node->right=deleteHelper(node->right,value);
				}
				else if (node->data > value)
				{
					node->left=deleteHelper(node->left,value);
				}
				else // node is found
				{
					if(node->left==NULL && node->right==NULL) // leaf Node
					{
						delete node; // free memory
						return NULL ;
					}
					else if(node->right!=NULL) //right Node exist -> replace its value with upper bound 
					{
						// get that value 
						node->data=successor(node); 
						node->right=deleteHelper(node->right , node->data); // remove that node 

					}
					else 
					{
						Node* tmp = node; 
						node=node->left; 
						delete tmp;
					}
				}
				return node; 
			} 


		}
		void remove(int value)
		{
			root=deleteHelper(root,value);
		}
} ;



		int main()
		{
			BST tree=BST();
			tree.insert(5);
			tree.insert(1);
			tree.insert(6);
			tree.insert(3);
			tree.insert(4);
			tree.insert(2);
			tree.insert(7);
			tree.insert(8);

			tree.remove(5);
			tree.remove(6);

			tree.display();



		}


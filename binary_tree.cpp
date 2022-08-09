#include<iostream>
using namespace std;

struct node{
	int key;
	node* left;
	node* right;
};
node* insert(node * tree, int val);
node* search (node*tree, int val);
void destroy_tree(node* tree);
node* remove(node* tree, int val);
node* remove_max_node (node* p_tree, node* p_max_node);
node* find_max(node*tree);
int getElementCount(node* tree);
void traverse(node* tree);


int main(){

node* root =NULL;
root=insert(root,8);
root=insert(root,10);
root=insert(root,11);
root=insert(root,6);
root=insert(root,5);
traverse(root);

return 0;
}

node* insert(node * tree, int val){
	if(tree==NULL)
	{
		node * new_tree=new node;
		new_tree->left=NULL;
		new_tree->right=NULL;
		new_tree->key=val;
		// cout<<" HIi ";
		return new_tree;
	}
	if(val<tree->key)
	{
		tree->left=insert(tree->left,val);
	}
	else {
		tree->right=insert(tree->right,val);
	}
}
node* search (node*tree, int val){
	if(tree=NULL)
		return NULL;
	else if(tree->key==val)
		return tree;
	else if(val<tree->key)
		return search(tree->left,val);
	else
		return search(tree->right,val);
	
}
void destroy_tree(node* tree){
	if(tree!=NULL){
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		delete tree;
	}
}
node* remove(node* tree, int val)
{
	if(tree==NULL)
		return NULL;
	else if(tree->key==val)
	{
		// there are three base cases
		// if tree has no child return NULL.
		// if only one child then return that child.
		// problem is with 2 child we can'nt simple return any child it will unabalance the tree.
		// so we can either find largest element on the left side and replace it wiht it or find the lowest element on the right and replace with it.

		if(tree->left==NULL){
			node* right_tree=tree->right;
			delete tree;
			return right_tree;
		}
		if(tree->right==NULL){
			node* left_tree=tree->left;
			delete tree;
			return left_tree;
		}
		node* max_tree=find_max(tree->left);
		max_tree->left=remove_max_node(tree->left,max_tree);
		max_tree->right=tree->right;
		delete tree;
		return max_tree;

	}

	else if(val<tree->key)
	{
		tree->left=remove(tree->left,val);
	}
	else 
		tree->right=remove(tree->right,val);
	return tree;
}
node* remove_max_node (node* p_tree, node* p_max_node)
{
// defensive coding--shouldn't actually hit this
if ( p_tree == NULL )
{
return NULL;
}
// we found or node, now we can replace it
if ( p_tree == p_max_node )
{
// the only reason we can do this is because we know
// p_max_node->p_right is NULL so we aren’t losing
// any information. If p_max_node has no left sub-tree,
// then we will just return NULL from this branch, which
// will result in p_max_node being replaced with an empty tree,
// which is what we want.
return p_max_node->left;
}
// each recursive call replaces the right sub-tree tree with a
// new sub-tree that does not contain p_max_node.
p_tree->right = remove_max_node( p_tree->right, p_max_node );
return p_tree;
}
node* find_max(node*tree)
{
	if(tree==NULL)
		return NULL;
	if(tree->right==NULL)
		return tree;
	return find_max(tree->right);
}int getElementCount(node* tree)
{
    if (tree == NULL)
        return 0;
    else if (tree->left == NULL && tree->right == NULL)
        return 1;
    else
        return 1 + getElementCount(tree->left) + getElementCount(tree->right);
}
void traverse(node* tree)
{
	// if(tree==NULL)
		// cout<<"HI";
    if (tree != NULL)
    {
        traverse(tree->left);
        cout <<tree->key << endl;
        traverse(tree->right);
    }
}
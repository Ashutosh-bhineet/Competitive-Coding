#include<iostream>
#include<queue>
using namespace std;
	
	
class Node{
public:
	int data;
	Node *left;
	Node *right;
	
	Node(int d){
		data = d;
		left = right = NULL;
	}
};
	
//Helper
//Insert one single node in already created bst
Node* insert(Node*root,int key){
	if(root==NULL){
		return new Node(key);
	}
	if(key<root->data){
		root->left = insert(root->left,key);
	}
	else{
		root->right = insert(root->right,key);
	}
	return root;
}
	
	
Node* createBST(){
	//read entire input and create a BST
	int d;
	cin>>d;
	Node*root = NULL;
	
	while(d!=-1){
		root = insert(root,d);
		cin>>d;
	}
	return root;
}
	
void levelOrderPrint(Node *root){
	//BFS 
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		Node *temp = q.front();
	
		if(temp==NULL){
			q.pop();
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			q.pop();
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	
	}
	cout<<endl; 
	return;
}
	
// Search O(H)
bool search(Node *root, int key){
	// Complete the Search Function for BST
	// 8.10 
	if(root==NULL){
		return false;
	}
	
	if(root->data==key){
		return true;
	}
	if(root->data < key){
		return search(root->right,key);
	}
	else{
		return search(root->left,key);
	}
}
	
// C R U D
	
Node* remove(Node *root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		//Actual Deletions happens in this case
		//case 0 -> no children 
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
	
		// case 1 -> single child 
		else if(root->left!=NULL && root->right==NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL){
			Node *temp = root->right;
			delete root;
			return temp;
	
		}
	
		//case 2 -> 2 children
		else{
	
			//right subtree min dhundo!
			Node* temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			//overwrite the root with next value 
			root->data = temp->data;
			//delete the next value from the rightsubtree
			root->right = remove(root->right, temp->data);
			return root;
	
		}
	}
	else if(root->data > key){
		root->left = remove(root->left,key);
	}
	else{
		root->right = remove(root->right,key);
	}
	return root;
	
}	
int main(){
	
	Node *root = createBST();
	levelOrderPrint(root);
	
	return 0;
}
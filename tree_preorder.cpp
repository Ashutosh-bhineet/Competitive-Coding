    #include<iostream>
    #include<queue>
    using namespace std;
     
    class Node{
    public:
    	int data;
    	Node *left;
    	Node*right;
     
    	Node(int d){
    		data = d;
    		left = right = NULL;
    	}
    };
     
    // Should Read Input and Recursively build the tree
    Node* buildTree(){
     
    	int d;
    	cin>>d;
     
    	if(d==-1){
    		return NULL;
    	}
     
    	Node * root = new Node(d);
    	root->left = buildTree();
    	root->right = buildTree();
    	return root;
    }
     
    void printTree(Node *root){
    	if(root==NULL){
    		return;
    	}
     
    	printTree(root->left);
    	cout<<root->data<<" ";
    	printTree(root->right);
    }
     
    //Preorder traversal for searching
    bool search(Node *root,int key){
    	if(root==NULL){
    		return false;
    	}
     
    	if(root->data==key || search(root->left,key)|| search(root->right,key)){
    		return true;
    	}
    	return false;
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
			return;
		}
     
     
    int main(){
    	//1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    	Node *root = buildTree();
    	// printTree(root);
    	levelOrderPrint(root);
     
    	// cout<< search(root,7);
     
    	return 0;
    }
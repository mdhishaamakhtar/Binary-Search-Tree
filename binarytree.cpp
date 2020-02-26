#include<iostream>
using namespace std;
struct Node{
  	int data;
  	Node* left;
  	Node* right;
};

Node* getNewNode(int data){
	Node* newNode = new Node();
  	newNode->data=data;
  	newNode->left = newNode->right = NULL;
  	return newNode;
}
Node* Insert(Node* root,int data){
  	if(root == NULL) { // empty tree
		root = getNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(Node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
Node* FindMin(Node* root){
	if(root == NULL){
		cout<<"Error: Tree is Empty";
	}
	else if(root->left == NULL){
		return root;
	}
	return FindMin(root->left);
}
Node* FindMax(Node* root){
	if(root == NULL){
		cout<<"Error: Tree is Empty";
	}
	else if(root->right == NULL){
		return root;
	}
	return FindMax(root->right);
}
int FindHeight(Node* root){
	if(root == NULL){
		return -1;
	}
	int leftheight = FindHeight(root->left);
	int rightheight = FindHeight(root->right);
	if(rightheight >= leftheight){
		return rightheight+1;
	}
	else{
		return leftheight+1;
	}
}
void preorder(Node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node* root){
	if(root == NULL){
		return;
	}	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
Node* Delete(Node* root,int data){
	if(root == NULL){
		return root;
	}
	else if(data < root->data){
		root->left = Delete(root->left,data);
	}
	else if(data > root->data){
		root->right = Delete(root->right,data);
	}
	else{
		//Case 1: No Child
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		//Case 2: One Child
		else if(root->left == NULL){
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		//Case 3: Two Children
		else{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
int main(){
 	Node* root = NULL;
 	root = Insert(root,15);
 	root = Insert(root,10);
 	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	
	Node* min = FindMin(root);
	Node* max = FindMax(root);
	cout<<"Minimum Element:"<<min->data<<"\n";
	cout<<"Maximum Element:"<<max->data<<"\n";

	int height = FindHeight(root);
	cout<<"Height of tree:"<<height<<"\n";

	cout<<"Inorder Traversal:\n";
	inorder(root);
	cout<<"\nPostorder Traversal:\n";
	postorder(root);
	cout<<"\nPreorder Traversal:\n";
	preorder(root);
	cout<<"\n";
	Delete(root,8);
	cout<<"Inorder after deletion:\n";
	inorder(root);
	cout<<"\n";

	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) {
		cout<<"Found\n";
	}
	else{
		cout<<"Not Found\n";
	}
}

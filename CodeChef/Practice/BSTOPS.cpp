#include <iostream>
#include <vector>
#include <map>
#include <list>
#define ll long long

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};
Node *head = NULL;
map<int, int> mp;
void inorder(Node* root)
{
    if(root == NULL)return;
    if(root->left != NULL)mp[(root->left)->data] = 2*(mp[root->data]);
    if(root->right != NULL)mp[(root->right)->data] = 2*(mp[root->data]) + 1;
    inorder(root->left);
    inorder(root->right);
}
Node* findmin(Node *root)   
{
    Node* temp = root;
    while(temp->left !=NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node* findmax(Node *root)   
{
    Node* temp = root;
    while(temp->right !=NULL)
    {
        temp = temp->right;
    }
    return temp;
}
int insert(int data)
{
    if(head == NULL)
    {
        Node *ptr = new Node;
        head = ptr;
        ptr->data = data;
        ptr->left = ptr->right = NULL;
        mp[data] = 1;
        
    }
    else
    {
        Node *temp = head;
        Node *prev = head;
        while (temp != NULL)
        {
            prev = temp;
            if(data >temp->data )temp = temp->right;
            else temp = temp->left;
        }
        Node* ptr = new Node;
        ptr->data = data;
        ptr->left = ptr->right = NULL;
        if(data > prev->data)
        {
            mp[data] = (2*mp[prev->data]) + 1;
            prev->right = ptr;
        }
        else 
        {
            mp[data] = (2*mp[prev->data]);
            prev->left = ptr;
        } 
    }

    return mp[data];
    
};
int Delete(int data)
{
    Node *temp = head;
    Node *prev = head;
    while (temp->data != data)
    {
        prev = temp;
        if(data >temp->data )temp = temp->right;
        else temp = temp->left;
    }
    if(temp->left = temp->right = NULL)
    {
        
    }
    else if(temp->right == NULL || temp->left == NULL)
    {
        cout << "temp->data: "<< temp->data << ", data: "<< data << endl;
        //cout << (temp->right)->data << endl;
        if(data> prev->data && temp->right == NULL )
        {
            mp[(temp->left)->data] = mp[temp->data];
            prev->right = temp->left;
            inorder(prev->right);
        }
        else if(data> prev->data && temp->left == NULL )
        {
            
            mp[(temp->right)->data] = mp[temp->data];
            prev->right = temp->right;
            inorder(prev->right);
        }
        else if(data< prev->data && temp->left == NULL )
        {
            cout << "Here" << endl;
            mp[(temp->right)->data] = mp[temp->data];
            prev->left = temp->right;
            inorder(prev->left);
        }
        else if(data< prev->data && temp->right == NULL )
        {
           
            mp[(temp->left)->data] = mp[temp->data];
            prev->left = temp->left;
            inorder(prev->left);
        }
        
        
    }
    else if (temp->right != NULL && temp->left != NULL)
    {
        int maxdata = findmax(temp->left)->data;
        mp[maxdata] = mp[temp ->data];
        Delete(maxdata);
        if(data>prev->data)
        {
            (prev->right)->data = maxdata;
            inorder(prev->right);
        }
        else
        {
            (prev->left)->data = maxdata;
            inorder(prev->left);
        }
        
        
    }
    int returndata = mp[temp->data];
    delete(temp);
    return returndata;
    

};
void inordert(Node* root)
{
    if(root == NULL)return;
    inordert(root->left);
    cout << root->data << endl;
    inordert(root->right);
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
       char operation;
       int data;
       cin >> operation >> data;
       if(operation == 'i')
       {
           insert(data);
       } 
       else if(operation = 'd')cout << Delete(data) << endl;
       
    }
    inordert(head);
}
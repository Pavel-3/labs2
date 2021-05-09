#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
    struct node *left;
    string data;
    int number;
    struct node *right;
} *root;

node *NewNode(int num, string data){
    node *p = new node;
    p->number = num;
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

void AddNode(node *root, int num, string data)
{

    node *prev, *t;
    bool isFind = true;
    t = root;
    prev = t;
    while(t && isFind){
        prev = t;
        if(num == t->number){
            isFind = false;
            cout << "\nInvalid number! Try another key!";
        }else if(num < t->number) t = t->left;
        else t = t->right;
    }
    if(isFind){
        t = NewNode(num, data);
        if(num < prev->number) prev->left = t;
        else prev->right = t;
    }
}

// get Height
int getHeight(node *p)
{
   if (!p)
       return 0;

   int left = getHeight(p->left);
   int right = getHeight(p->right);
   return max(left, right) + 1;
}
// Swap min and max

//function to find the minimum value in a node
node *find_minimum(node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL)
        return find_minimum(root->left);
    return root;
}

//function to find the minimum value in a node
node *find_max(node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->right != NULL)
        return find_max(root->right);
    return root;
}

void SwapData(node *root)
{
    node *min = find_minimum(root),
         *max = find_max(root);
    string t;
    if(max != NULL || min != NULL){
        cout << "min = " << min->number << "; max = " << max->number << ";" << endl;
        t = min->data;
        min->data = max->data;
        max->data = t;
        cout << "Elements changed!" << endl;
    }else {
        cout << "Tree is empty!!!";
    }
}


// View Node

void Print(node *tree, long r)
{
    if(tree!=NULL)
            {
                Print(tree->right, r+5);
                for (int i=0; i < r ; i++)
                    printf(" ");
                printf("(%d ", tree->number); cout << tree->data << ")" <<endl;
                Print(tree->left, r+5);
            }
}

void ViewNode(struct node *root, char v)
   {
        if(root != NULL){
            if(v == '1'){
                cout<< "    " <<root->number << "     "<< root->data << endl;
                ViewNode(root->left, v);
                ViewNode(root->right, v);
            }else if(v == '2'){
                ViewNode(root->left, v);
                ViewNode(root->right, v);
                cout<< "    " <<root->number << "     "<< root->data << endl;
            }else if(v == '3'){
                ViewNode(root->left, v);
                cout<< "    " <<root->number << "     "<< root->data << endl;
                ViewNode(root->right, v);
            }else{
                Print(root, 0);
            }
        }
   }

// function search
void search(struct node *root, int num)
{
    if(root == NULL){
        cout << "Tree is empty";
        return;
    }
    if(root->number == num) cout << "Data = " << root->data;
    else if(num > root->number) search(root->right, num);
    else search(root->left, num);
}

// funnction to delete a node
node *DeleteNode(node *root, int num)
{
    //searching for the item to be deleted
    if(root == NULL)
        return NULL;
    if (num > root->number)
        root->right = DeleteNode(root->right, num);
    else if(num < root->number)
        root->left = DeleteNode(root->left, num);
    else
    {
        //No Children
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right == NULL)
        {
            struct node *temp;
            if(root->left == NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->number);
        }
    }
    return root;
}


void clear(node *node)
{
    if(node != NULL)
    {
        if(node->left != NULL)
            clear(node->left);
        if(node->right != NULL)
            clear(node->right);
        delete node;
    }else
    {
        cout << "Tree is empty!!!" << endl;
        return;
    }
}


int main(){

    node *root = NULL;
    string data;
    char v;
    int number;

    while(true){
        system("cls");
        cout<<"\nAdd - 1";
        cout<<"\nView - 2";
        cout<<"\nIndividual - 3";
        cout<<"\nFined node - 4";
        cout<<"\nDelete node - 5";
        cout<<"\nExit - 0\n";

        switch (_getch())
        {
        case '1':
            system("cls");
            cout << "\nEXIT - '.'";
            if(!root){
                cout << "\nData = "; cin >> data;
                cout << "\nInput number = "; cin >> number;
                root = NewNode(number, data);
            }
            while (true) {
                cout << "\nData = "; cin >> data;
                if(data == ".") break;
                cout << "\nInput number: "; cin >> number;
                AddNode(root, number, data);
            }
            break;
        case '2':
            system("cls");
            if(root == NULL) cout << "Tree is empty!";
            else{
                cout << "What obxod: \n straight - 1 \n back - 2 \n > key - 3\n view with depth - 4\n";
                v = _getch();
                cout << "---Tree---\n";
                ViewNode(root, v);
            }
            _getch();
            break;

        case '3':
            system("cls");
            SwapData(root);
            _getch();
            break;
        case '4':
            system("cls");
            if(root == NULL) cout << "Tree is empty!";
            else {
                cout<<"\nWhat element do you want view? Input namber = "; cin >> number;
                search(root, number);
            }
            _getch();
            break;
        case '5':
            system("cls");
            if(root == NULL) cout << "Tree is empty!";
            else{
            cout<<"\nWhat element do you want DELETE? Input namber = "; cin >> number;
            root = DeleteNode(root, number);
            }

            _getch();
            break;
        case '0':
            clear(root);
            return 0;
        }
    }
}

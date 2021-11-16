/* Binary Search Tree(BST) */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct nodeType
{
 int info;
 struct nodeType *left;
 struct nodeType *right;
 };
typedef struct nodeType *nodeptr;
nodeptr root;

int insertNode(int Item)
{
 nodeptr p , newNode,back;

 p = root;
 back=NULL;

 newNode = (nodeType *) malloc(sizeof(nodeType));
 newNode -> left = NULL;
 newNode -> right = NULL;
 newNode -> info = Item;

 while (p!=NULL)
 {
  back=p;
  if (p->info > Item)
   p = p->left;
  else
   p = p->right;
 }

 if(back == NULL)
  root = newNode;
 else if (back->info > Item)
  back->left  = newNode;
 else back->right  = newNode;

 return 0;
}
void Search(int Item)
{
 nodeptr p , newNode,back;

 p = root;
 back=NULL;


 while (p!=NULL)
 {
  if(p->info==Item)
  {
   cout<<"Found\n";
   break;
  }
  else if (p->info > Item)
   p = p->left;
  else
   p = p->right;
 }

}

void inOrder(nodeptr p)
{
  if(p!=NULL)
  {
    inOrder(p->left);
    printf("%d  ",p->info);
    inOrder(p->right);
  }
}

void preOrder(nodeptr p)
{
  if(p!=NULL)
  {
    printf("%d  ",p->info);
    preOrder(p->left);
    preOrder(p->right);
  }
}

void postOrder(nodeptr p)
{
  if(p!=NULL)
  {
    postOrder(p->left);
    postOrder(p->right);
    printf("%d  ",p->info);
  }
}

int menu()
{
 int n;

 printf("\n\nMain Menu\n");
 printf("1. Insert\n");
 printf("2. Display\n");
 printf("3. Search\n");
 printf("4. Exit\n\n");
 printf("Enter Choice(1-4): ");
 scanf("%d",&n);
 printf("\n");
 return n;
}

void Display()
{
 if(root)
 {
  printf("\nTraverse Tree INorder\n");
  inOrder(root);
  printf("\nTraverse Tree PREorder\n");
  preOrder(root);
  printf("\nTraverse Tree POSTorder\n");
  postOrder(root);
 }
 else printf("\nBST IS NULL\n");
}

int main()
{
 nodeptr p;
 int VAL;

 root = NULL;

 char ch[11];
 int n = 2;

 n = menu();

 do
 {
  if(n==1)
  {
   printf("\nInsert a val :");
   scanf("%d",&VAL);
   insertNode(VAL);
   //Display();
   }
  if(n==2)
  {

   Display();
  }
  if(n==3)
  {
   cout<<" Enrer the item : ";
   int item;
   cin>>item;
   Search(item);
  }
  if(n==4)
  {
   printf("\n");
   break;
  }
  if(n>3)
   printf("\nWrong Choice\n");
  n = menu();

 } while(1);
 return 0;
}

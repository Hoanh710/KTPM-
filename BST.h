#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxlength 100

//THU VIEN DANH CHO CAY NHI PHAN TIM KIEM (BST)

//typedef ... elementtype;
//Whatever type of element

typedef struct{
  char Username[maxlength];
  char Password[maxlength]; 
  char request[2000];
} infor;
typedef infor elementType;

typedef struct node_type{
  elementType element;
  struct node_type *left, *right;
}nodeType;

typedef nodeType *treeType;//treetype la 1 con tro tro den kieu Node. treeType = Node*



//1. Khoi tao cay rong
void makeNullTree(treeType *T){
  (*T) = NULL;
}

//2. Xem lieu co phai cay rong ko
int isEmptyTree(treeType T){
  return T == NULL;
}

//3. Lay con trai
treeType leftChild(treeType n){
  if(n != NULL) return n->left;
  else return NULL;
}

//4. Lay con phai
treeType rightChild(treeType n){
  if(n != NULL) return n->right;
  else return NULL;
}

//5. Tao ra 1 node moi
nodeType *createNode(elementType newData){
  nodeType *N;
  N = (nodeType*)malloc(sizeof(nodeType));
  if(N != NULL){
    N->left = NULL;
    N->right = NULL;
    N->element = newData;
  }
  return N;
}

//6. Kiem tra co phai La hay k
int isLeaf(treeType n){
  //Neu khong co con trai + con phai -> la Leaf
  if(n != NULL){
    return (leftChild(n) == NULL) && (rightChild(n) == NULL);
  }
  else return -1;
}

//7. Dem so node trong cay
int countNode(treeType T){
  if(isEmptyTree(T)) return 0;
  else return 1 + countNode(leftChild(T)) + countNode(rightChild(T));
}

//8. Tim kiem nhi phan
treeType search(char* x, treeType root){
  if(root == NULL){//Neu tree rong || de quy den node leaf ma van ko thay -> return NULL
    return NULL;//Not found
  }
  else if(strcasecmp(root->element.Username,x) == 0){//Neu tim thay
    return root;
  }
  else if(strcasecmp(root->element.Username,x) < 0){
   // printf("%s  \n", root->element.tu);//Neu < khoa can tim -> tiep tuc tim ben phai
    return search(x, root->right);
  }
  else{
   // printf("%s  \n", root->element.tu);//Neu > khoa can tim -> tiep tuc tim ben trai
    return search(x, root->left);
  }
}

int max(int a, int b){
  if(a > b)
    return a;
  return b;
}

//9. Tao cay tim kiem nhi phan
void insertNode(elementType x, treeType *root){    //Neu truyen vao con tro -> thay doi ca tree. Neu chi truyen vao root bthg -> phai return de lay gia tri
  if(*root == NULL){//Truong hop co so: nut rong
    /*Create a new node for key x*/
    *root = (nodeType*)malloc(sizeof(nodeType));
    
    (*root)->element = x;
    (*root)->left = NULL; 
    (*root)->right = NULL;
  }
  else if(strcasecmp(x.Username, (*root)->element.Username) <= 0)//Neu khoa them vao < khoa nut goc 
    insertNode(x, &(*root)->left);
  
  else if(strcasecmp(x.Username, (*root)->element.Username) > 0)
    insertNode(x, &(*root)->right);
}

//11. Tinh chieu cao cay
int treeHeight(treeType root){
  if(root == NULL)
    return -1;
  else return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}
//12. Tinh so nut la (leaf node)
int leafNode(treeType root){
  if(root == NULL){
    return 0;
  }
  else if(isLeaf(root)){
    return 1;
  }
  else{
    return leafNode(root->left) + leafNode(root->right);
  }
}
//13. Tinh so nut trong
int innerNode(treeType root){
  if(root == NULL){
    return 0;
  }
  if(!isLeaf(root)){
    return 1 + innerNode(root->left) + innerNode(root->right);
  }
  else//Neu la leaf
    return 0;
}

//14. So con phai
int numRight(treeType root){
  if(root == NULL){
    return 0;
  }
  else if(root->right != NULL){
    return 1 + numRight(root->left) + numRight(root->right);
  }
  else /*neu root->right == NULL*/
    return numRight(root->left);
}

//15. Ham duyet cay theo thu tu giua
void inOrderPrint(treeType root){
  if(root != NULL){
    inOrderPrint(root->left);
    printf("%-10s   %-10s  \n", root->element.Username,root->element.Password);
    inOrderPrint(root->right);
  }
}

//16. Ham duyet cay theo thu tu truoc
/*void preOrderPrint(treeType root){
  if(root != NULL){
    printf("%s  \n", root->element.tu);
    preOrderPrint(root->left);
    preOrderPrint(root->right);
  }
}*/

//17. Ham duyet cay theo thu tu sau
/*void postOrderPrint(treeType root){
  if(root != NULL){
    preOrderPrint(root->left);
    preOrderPrint(root->right);
    printf("%s  \n", root->element.tu);
  }
}*/

//18. Ham xoa nut cuc trai cua cay con phai
elementType deleteMin(treeType *root){
  elementType k;
  if((*root)->left == NULL){
    k = (*root)->element;
    (*root) = (*root)->right;
    return k;
  }
  else return deleteMin(&(*root)->left);
}

//19. Xoa 1 nut trong cay nhi phan tim kiem
void deleteNode(elementType x, treeType *root){
  if(*root != NULL){
    if(strcmp(x.Username, (*root)->element.Username) < 0){
      deleteNode(x, &(*root)->left);
    }
    else if(strcmp(x.Username, (*root)->element.Username) > 0){
      deleteNode(x, &(*root)->right);
    }
    else if((*root)->left == NULL && (*root)->right == NULL){
      *root = NULL;//Truong hop la node leaf -> xoa luon
    }
    else if((*root)->left == NULL){//Neu chi co 1 con phai->cha tro den thang con phai cua con
      *root = (*root)->right;
    }
    else if((*root)->right == NULL){//Neu chi co 1 con trai
      *root = (*root)->left;
    }
    else //Copy gia tri cua node cuc trai cua cay con phai cho gia tri cua root
      (*root)->element = deleteMin(&(*root)->right);
  }
}
void inOrderPrinttofile(FILE *fptr,treeType root){
  if(root != NULL){
    inOrderPrinttofile(fptr,root->left);
    fprintf(fptr,"%s %s \n",root->element.Username,root->element.Password);
    inOrderPrinttofile(fptr,root->right);
  }
}

//20. Ham giai phong toan bo cay
void freeTree(treeType root){
  if(root != NULL){
    freeTree(root->left);
    freeTree(root->right);
    free((void*)root);
  }
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define RH -1
#define EQ  0
#define LH +1



struct BSTree
{
    BSTree* left;
    BSTree* right;
    int val;
    int bf;
    BSTree(int x,int y) : left(nullptr), right(nullptr), val(x), bf(y){}     
};



void Print(BSTree* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::queue<BSTree*> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while(!nodes.empty())
    {
        BSTree* pNode = nodes.front();
        printf("%d ", pNode->val);

        if(pNode->left != nullptr)
        {
            nodes.push(pNode->left);
            ++nextLevel;
        }
        if(pNode->right != nullptr)
        {
            nodes.push(pNode->right);
            ++nextLevel;
        }

        nodes.pop();
        --toBePrinted;
        if(toBePrinted == 0)
        {
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}

void R_Rotate(BSTree **T)
{
    
    BSTree *lc = (*T)->left;
    (*T)->left = lc->right;
    lc->right = *T;
    *T = lc;
}
void L_Rotate(BSTree **p)
{
    BSTree *lc = (*p)->right;
    (*p)->right = lc->left;
    lc->left = *p;
    *p = lc;
}

void LeftBalance(BSTree **T)
{
    BSTree *Tl = (*T)->left;
      switch(Tl->bf)
        {
            case LH:
              (*T)->bf = Tl->bf = EQ;
              R_Rotate(T);
                break;
            case RH:
               BSTree *Tlr = Tl->right;
               switch(Tlr->bf)
               {
                case LH:
                   (*T)->bf = RH;
                   Tl->bf = EQ;
                   break;
                 case RH:
                   (*T)->bf = EQ;
                   Tl->bf = LH;
                   break;
                 case EQ:
                   (*T)->bf = Tl->bf = EQ;
                   break;
               }
               Tlr->bf = EQ;
               L_Rotate(&Tl);
               R_Rotate(T);
               break; 
        }
        
}

void RightBalance(BSTree **T)
{
    BSTree *Tr = (*T)->right;
      switch(Tr->bf)
        {
            case RH:
             (*T)->bf =Tr->bf = EQ;
              L_Rotate(T);
                break;
            case LH:
               BSTree *Trl = Tr->left;
               switch(Trl->bf)
               {
                case LH:
                   (*T)->bf = EQ;
                   Tr->bf = RH;
                   break;
                 case RH:
                   (*T)->bf = LH;//
                   Tr->bf = EQ;
                   break;
                 case EQ:
                   (*T)->bf = Tr->bf = EQ;
                   break;
               }
               Trl->bf = EQ;
               R_Rotate(&Tr);
               L_Rotate(T);
               break; 
        }
        
}

bool InsertAVL(BSTree **T,int e,bool *taller)
{
    if(*T == nullptr)
    {
        *T = new BSTree(e,EQ);
        *taller = 1;
        return true;
    }
    else
    {
        if(e == (*T)->val)
        {
            *taller = 0;
            return false;
        }
        else if(e > (*T)->val)
        {
            if(InsertAVL(&(*T)->right,e,taller) == false)
                return false;
            if(*taller == true)
            {
                switch((*T)->bf)
                {
                  case EQ:
                    (*T)->bf = RH;
                    *taller = 1;
                    break;
                  case LH:
                    *taller = 0;
                    (*T)->bf = EQ;
                    break;
                  case RH:
                    RightBalance(T);
                     *taller = 0;
                    break;
                }
                  
            }
            return true;

        }
        else
        {
            if(InsertAVL(&(*T)->left,e,taller) == false)
                 return false;
                
            if(*taller == true)
            {
                switch((*T)->bf)
                {
                  case EQ:
                    (*T)->bf = LH;
                    *taller = 1;
                    break;
                  case RH:
                    *taller = 0;
                    (*T)->bf = EQ;
                    break;
                  case LH:
                    LeftBalance(T);
                     *taller = 0;
                    break;
                }  
            }

            return true;
        }
    }
}
void change(int *c)
{
    int a = 99;
    *c = a;
}
std::vector<int> vec;
     bool InOrder(BSTree *node)
     {
         if(node == nullptr)
           return true;    

         if(true == InOrder(node->left))
         {
            if(vec.size() == 0 || node->val > vec.back())
                vec.push_back(node->val);
            else
                return false;

            if(false == InOrder(node->right))
                return false;
         }
         else
            return false;
         
         return true;
     }
int main()
{
    BSTree *t = nullptr;
    bool taller;
    for(int i = 0;i<10;i++)
    InsertAVL(&t,i,&taller);
    Print(t);
    cout<<endl;
    cout<<endl;
    cout<<(true == InOrder(t))<<endl;
    cout<<endl;



}
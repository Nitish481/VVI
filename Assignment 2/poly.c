#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int coeff;
  int pow;
  struct Node *next;
};
typedef struct Node *node;

void createNode(int c, int p, node *temp)
{
  node r, t;
  r = (node)malloc(sizeof(struct Node));
  r->next = NULL;
  r->coeff = c;
  r->pow = p;

  if (*temp == NULL)
  {
    *temp = r;
  }
  else
  {
    t = *temp;
    while (t->next != NULL)
      t = t->next;
    t->next = r;
  }
}

void createPoly(node *head)
{
  int x,c,p;

  do {
    printf("\nEnter power: ");
    scanf("%d",&p);
    printf("\nEnter coefficient: ");
    scanf("%d",&c);
    createNode(c, p, head);
    printf("\nEnter 0 to Stop.");
    scanf("%d",&x);
  }while (x!=0);
}
void sort(node *head)
{
  node l, h;
  int p, c;
  if (*head == NULL)
  {
    return;
  }
  l = *head;
  if (l->next == NULL)
  {
    return;
  }
  while (l != NULL)
  {
    h = l->next;
    while (h != NULL)
    {
      if (h->pow < l->pow)
      {
        p = l->pow;
        c = l->coeff;
        l->pow = h->pow;
        h->pow = p;
        l->coeff = h->coeff;
        h->coeff = c;
      }
      h = h->next;
    }
    l = l->next;
  }
}
void show(node p)
{
  node t;
  t = p;
  if (t == NULL)
    return;
  while (t != NULL)
  {
    printf(" %dx^%d", t->coeff, t->pow);
    if (t->next != NULL)
    {
      if (t->next->coeff >= 0)
        printf(" +");
    }
    t = t->next;
  }
  printf("\n");
}

node add(node p1, node p2)
{
  node sum, x, y, t;
  sum = NULL;
  if (p1 == NULL && p2 == NULL)
  {
    printf("No polynomials passed!");
    return sum;
  }
  x = p1;
  y = p2;
  sort(&x);
  sort(&y);
  show(x);
  show(y);
  while (x != NULL && y != NULL)
  {
    if (x->pow < y->pow)
    {
      createNode(x->coeff, x->pow, &sum);
      x = x->next;
    }
    else if (x->pow > y->pow)
    {
      createNode(y->coeff, y->pow, &sum);
      y = y->next;
    }
    else
    {
      createNode(y->coeff + x->coeff, y->pow, &sum);
      x = x->next;
      y = y->next;
    }
  }
  
  while (x != NULL)
  {
    createNode(x->coeff, x->pow, &sum);
    x = x->next;
  }
  while (y != NULL)
  {
    createNode(y->coeff, y->pow, &sum);
    y = y->next;
  }
  return sum;
}

node sub(node p1, node p2)
{
   node diff, x, y, t;
  diff = NULL;
  if (p1 == NULL && p2 == NULL)
  {
    printf("No polynomials passed!");
    return diff;
  }
  x = p1;
  y = p2;
  sort(&x);
  sort(&y);
  while (x != NULL && y != NULL)
  {
    if (x->pow < y->pow)
    {
      createNode(x->coeff, x->pow, &diff);
      x = x->next;
    }
    else if (x->pow > y->pow)
    {
      createNode(-y->coeff, y->pow, &diff);
      y = y->next;
    }
    else
    {
      createNode(x->coeff - y->coeff, y->pow, &diff);
      x = x->next;
      y = y->next;
    }
  }
  
  while (x != NULL)
  {
    createNode(x->coeff, x->pow, &diff);
    x = x->next;
  }
  while (y != NULL)
  {
    createNode(-y->coeff, y->pow, &diff);
    y = y->next;
  }
  return diff;
}

void removeDuplicates(node p)
{
  node l,r,t;
  l=p;
  while(l != NULL && l->next != NULL)
  {
      r=l;
      while(r->next!=NULL)
      {
        if(l->pow==r->next->pow)
        {
          l->coeff=l->coeff+r->next->coeff;
          t=r->next;
          r->next=r->next->next;
          free(t);
        }
        else
          r=r->next;        
      }
      l=l->next;
  }
}

node mult(node p1, node p2)
{
  node mul,x,y;
  int c,p;
  mul=NULL;
  x=p1;
  y=p2;
  while(x!=NULL){
    while(y!=NULL){
      c = x->coeff * y->coeff;
      p = x->pow + y->pow;
      createNode(c,p,&mul);
      y=y->next;
    }
    y=p2;
    x=x->next;
  }
  removeDuplicates(mul);
  sort(&mul);
  return mul;
}

int main()
{
  node p1, p2, sum, diff, mul;
  int ch;
  p1 = NULL;
  p2 = NULL;
  do
  {
    printf("\n1.Create 2 polynomials\n2.Add polynomials\n3.Subtract\n4.Multiply\n0.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 0:
        break;
      case 1:
        printf("\nEnter 1st polynomial:");
        createPoly(&p1);
        printf("\nEnter 2nd polynomial:");
        createPoly(&p2);
        break;
      case 2:
        sum = add(p1, p2);
        show(sum);
        break;
      case 3:
        diff = sub(p1,p2);
        printf("\nP1 - P2:\n");
        show(diff);
        break;
      case 4:
        mul = mult(p1,p2);
        printf("\nP1 * P2:\n");
        show(mul);
        break;
      default:
        printf("\nInvalid choice!");
    }
  
  } while (ch);
  
  
  
  return 0;
}

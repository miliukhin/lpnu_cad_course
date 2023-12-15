#include <stdlib.h>
#include <stdio.h>

struct tree {
  char info;
  struct tree *left;
  struct tree *right;
};

struct tree *root; /* начальная вершина дерева */
struct tree *stree(struct tree *root,
                   struct tree *r, char info);
void print_tree(struct tree *root, int l);

int main(void)
{
  char s[80];
 root = NULL;  /* инициализация корня дерева */

  do {
    printf("Введите букву: ");
    fgets(s, 20, stdin);
    root = stree(root, root, *s);
  } while(*s);

  print_tree(root, 0);

  return 0;
}

struct tree *stree(
  struct tree *root,
  struct tree *r,
  char info)
{

  if(!r) {
    r = (struct tree *) malloc(sizeof(struct tree));
    if(!r) {
      printf("Не хватает памяти\n");
      exit(0);
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    if(!root) return r; /* первый вход */
    if(info < root->info) root->left = r;
    else root->right = r;
    return r;
  }

  if(info < r->info)
    stree(r, r->left, info);
  else
    stree(r, r->right, info);

  return root;
}

void print_tree(struct tree *r, int l)
{
  int i;

  if(!r) return;

  print_tree(r->right, l+1);
  for(i=0; info);
  print_tree(r->left, l+1);
}


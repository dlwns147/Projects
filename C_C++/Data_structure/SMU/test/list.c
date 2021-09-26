#define _CRT_SECURE_NW_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define element char*
typedef struct node{
    element data;
    struct node *link;
} node;

void error(char* message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

node* insert_1stnode(node* head, element value)
{
    node *n=(node*)malloc(sizeof(node));
    n->data=value;
    n->link=head;
    head=n;
    return head;
}

node* insert_node(node* head, node* pre, element value)
{
    node *n=(node*)malloc(sizeof(node));
    n->data=value;
    n->link=pre->link;
    pre->link=n;
    return head;
}
node* delete_1stnode(node* head)
{
    if(head==NULL) return NULL;
    node* remove=head;
    head=head->link;
    free(remove);
    return head;
}
node* delete_node(node* head, node* pre)
{
    node *remove=pre->link;
    pre->link=remove->link;
    free(remove);
    return head;    
}

void print_node(node* head)
{
    node* print=head;
    while(print!=NULL)
    {
        printf("%s->",print->data);
        print=print->link;
    }
    printf("NULL \n");
}


int main(void)
{
        element *str;
    strcpy(str,"123");
    node *list=NULL;
    delete_1stnode(list);
    for(int i=0;i<5;i++)
        list=insert_1stnode(list,str);
    element *str;
    str="123";
    list=insert_node(list,list->link->link->link,str);
    list=delete_1stnode(list);
    list=delete_node(list,list->link);
    print_node(list);
}



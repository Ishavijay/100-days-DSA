/*Problem: Create and Traverse Singly Linked List*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*createnode(int value){
    struct node *n=malloc(sizeof(struct node));
    n->data=value;
    n->next=NULL;
    return n;
}
int main(){
    struct node*head =NULL;
    struct node*tail =NULL;
    struct node*temp=NULL;
    int n;
    scanf("%d",&n);
    int value;
    for(int i=0;i<n;n++){
    scanf("%d",&value);
    struct node*newnode=createnode(value);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }}
    temp=head;
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp=temp->next;}
    return 0;
}
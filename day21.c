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
    struct node*tenth =NULL;
    struct node*temp=NULL;
    int value;
    for(int i=0;i<10;i++){
    scanf("%d",&value);
    struct node*newnode=createnode(value);
    if(head==NULL){
        head=newnode;
        tenth=newnode;
    }
    else{
        tenth->next=newnode;
        tenth=newnode;
    }}
    temp=head;
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp=temp->next;}
    return 0;
}
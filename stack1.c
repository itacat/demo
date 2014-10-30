#include<stdio.h>
#include<stdlib.h>
typedef struct track1{
	int score;
	struct track1 *next;
}track;
track *init();
track *pop(track *p,int newScore);
//入栈
track *push(track *head,int *pushScore);
//出栈
void clear(track *head);
int length(track *head);
int main(int argc, char const *argv[])
{
	/* code */
	track *head,*p;
	int i=0,newScore,length1,pushScore;
	head=p=init();
	for (i = 0; i < 5; i++)
	{
		/* code */
		scanf("%d",&newScore);
		p=pop(p,newScore);
	}
	length1=length(head);
	printf("length is %d\n",length1);
	push(head,&pushScore);
	printf("push is %d\n",pushScore);
	getchar();getchar();
	return 0;
}
track *init(){
	track *head=NULL;
	head=(track*)malloc(sizeof(track));
	if(head==NULL){
		printf("memory isnt enough");
		exit(1);
	}
	head->next=NULL;
	return head;
}
int length(track *head){
	track *p=head;int i=0;
	while((p->next)!=NULL){
		p=p->next;
		i++;
	}
	return i;
}
track *pop(track *p,int newScore){
	track *newp=NULL;
	newp=(track *)malloc(sizeof(track));
	if (newp==NULL)
	{
		/* code */
		printf("memory isnt enough");
		exit(1);
	}
	p->next=newp;
	newp->score=newScore;
	newp->next=NULL;
	return newp;
}
track *push(track *head,int *pushScore){
	int length1=length(head),i;track *p=head;
	for (i = 0; i < (length1-1); i++)
	{
		/* code */
			p=p->next;
	}
	*pushScore=(p->next)->score;
	free(p->next);
	p->next=NULL;
	return p;
}
void clear(track *head){
	track *p,*q;
	p=q=head;
	while((q->next)!=NULL){
		p=p->next;
		free(q);
		q=p;
	}
	free(q->next);
}
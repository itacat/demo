#include<stdio.h>
#include<stdlib.h>
typedef int Score;
typedef struct linkedlist
{
	/* data */
	Score score;
	struct linkedlist *next;
}llist;
llist *init();
//创建链表,返回头指针
void visit(llist *head);
//遍历节点
void ndelete(llist *p);
//删除p后的节点
void insert(llist *p,Score insertScore);
//在p后插入一个节点,
int length(llist *head);
void add(llist *head,Score newScore);
//
void clear(llist *head);
//清空一个链表
llist *find(llist *head,llist *p);
void edit(llist head,llist *p,Score *editScore);
//edit
int main(int argc, char const *argv[])
{
	/* code */
	llist *head,*p;int i,insertScore,leng;
	head=init();
	for(i=0;i<5;i++){
		scanf("%d",&insertScore);
		insert(head,insertScore);
	}
	leng=length(head);
	printf("length is %d\n",leng);
	visit(head);
	ndelete(head);
	printf("after delete\n");
	visit(head);
	printf("after add\n");
	p=find(head,head->next);
	add(head,100);
	visit(head);
	printf("after clear\n");
	clear(head);
	getchar();getchar();
	return 0;
}
llist *init(){
	llist *head=NULL;
	head=(llist *)malloc(sizeof(llist));
	if(head==NULL){
		printf("memory is not enough");
		exit(1);
	}
	head->next=NULL;
	return head;
}
void visit(llist *head){
	llist *p=head;
	while((p->next)!=NULL){
		p=p->next;
		printf("%d\n",(p->score));
	}
}
void insert(llist *p,Score insertScore){
	llist *newNode=NULL;
	newNode=(llist*)malloc(sizeof(llist));
	if(newNode==NULL){
		printf("memory is not enough");
		exit (1);
	}
	newNode->score=insertScore;
	newNode->next=p->next;
	p->next=newNode;
}
void ndelete(llist *p){
	llist *dNode=p->next;
	if(p->next==NULL){
		printf("is Empty now");
	}
	else{
		dNode=p->next;
		p->next=(p->next)->next;
		free(dNode);
	}
}
int length(llist *head){
	llist *p=head;int i=0;
	while((p->next)!=NULL){
		p=p->next;
		i++;
	}
	return i;
}
void add(llist *head,Score newScore){
	llist *newNode=NULL,*p=head;
	newNode=(llist*)malloc(sizeof(llist));
	if (newNode==NULL)
	{
		/* code */
		printf("memory is not enough");
		exit(1);
	}
	while((p->next)!=NULL){
		p=p->next;
	}
	p->next=newNode;
	newNode->next=NULL;
	newNode->score=newScore;
}
void clear(llist *head){
	llist *p=head,*nextNode=NULL;
	do{
		nextNode=p->next;
		free(p);
		p=nextNode;
	}while(nextNode!=NULL);
	free(p);
}

llist *find(llist *head,llist *fNode){
	llist *p=head;
	while(p!=NULL){
		if (p==fNode)break;
		p=p->next;
	}
	return p;
}
void edit(llist *head,llist *p,Score *editScore){
	llist *fNode=find(head,p);
	if(fNode==NULL){
		printf("no such Node");
	}
	else{
		fNode->score=*editScore;
	}
}
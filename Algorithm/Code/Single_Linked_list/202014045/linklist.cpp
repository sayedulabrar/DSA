#include<iostream>
#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;

void initializeList()
{
    list = 0;
}

int insertItem(int item)
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = list ;
	list = newNode ;
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	struct listNode *temp, *prev ;
	temp = list ;
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ;
	}
	if (temp == 0) return NULL_VALUE ;
	if (temp == list)
	{
		list = list->next ;
		free(temp) ;
	}
	else
	{
		prev->next = temp->next ;
		free(temp);
	}
	return SUCCESS_VALUE ;
}


struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ;
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ;
	}
	return 0 ;
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

int insertLast(int item)
{
    struct listNode * newNode,* temp ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	temp=list;
	while(temp->next!=0)
    {
        temp = temp->next;
    }
    newNode->next=NULL;
    temp->next=newNode;
    return SUCCESS_VALUE ;


}

int insertAfter(int oldItem, int newItem)
{
    struct listNode *temp, *prev ,* newNode;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = newItem ;
	temp = list ;
	while (temp != 0)
	{
		if (temp->item == oldItem) break ;
		temp = temp->next ;
	}
	if (temp == 0)
    {
        return NULL_VALUE ;
    }else
    {
       prev=temp->next;
       temp->next=newNode;
       newNode->next=prev;
       return SUCCESS_VALUE ;
    }

}

int deleteLast()
{
   struct listNode *temp, *prev ;
   if (list == NULL)
   {
     return NULL_VALUE;
   }else
   {
      temp = list ;
	while (temp->next!= 0)
	{
		prev = temp;
		temp = temp->next ;
	}
	if(prev!= NULL)
    {
        prev->next=NULL;
        free(temp);

    }
    return SUCCESS_VALUE ;
   }



}

int deleteFirst()
{
  struct listNode *cur;
  if (list == NULL)
   {
     return NULL_VALUE;
   }else
   {
   cur=list;
   list=list->next;
   free(cur);
   return SUCCESS_VALUE;
   }

}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4.insertLast.5.insertAfter.6.deleteLast.7.deleteFirst.8. Print. 9. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            printf("Enter the item: ");
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            printf("Enter the item need to be deleted: ");
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            printf("Enter item to be searched: ");
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item,l;
            printf("Enter the item: ");
            scanf("%d", &item);
            l=insertLast(item);
            if(l==SUCCESS_VALUE)
            {
                printf("%d has been inserted after the last item.\n",item);
            }

        }
        else if(ch==5)
        {
            int item,nt,l;
            printf("Enter the item after which the new item will be inserted.\n");
            scanf("%d",&item);
            printf("Enter  the new item:\n");
            scanf("%d",&nt);
            l=insertAfter(item,nt);
            if(l==SUCCESS_VALUE)
            {
                printf("%d has been inserted after %d\n",nt,item);
            }else{
                printf("%d was not found in the list\n",item);
            }



        }
        else if(ch==6)
        {
            int l;
            l=deleteLast();
            if(l==SUCCESS_VALUE)
            {
             printf("The last item of the list has been deleted.\n");
            }else{
                printf("The list is empty.\n");
            }


        }
        else if(ch==7)
        {
            int m;
            m=deleteFirst();
            if(m==SUCCESS_VALUE)
            {
             printf("The first item has been deleted.\n");
            }else{
                printf("The list is empty.\n");
            }

        }
        else if(ch==8)
        {
            printList();
        }
        else if(ch==9)
        {
            break;
        }
        printf("\n");
    }

}

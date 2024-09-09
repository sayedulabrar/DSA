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
struct listNode * tail;

void initializeList()
{
    list = 0;
	tail = 0;
}


//add required codes to set up tail pointer
int insertItem(int item) //insert at the beginning
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = list ;
	list = newNode ;
	return SUCCESS_VALUE ;
}

//add required codes to set up tail pointer
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

//add required codes to set up tail pointer
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
    //write your codes here
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. (Add from homework). 5. Print. 6. exit.\n");

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
            printf("Enter item to be deleted: ");
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
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}

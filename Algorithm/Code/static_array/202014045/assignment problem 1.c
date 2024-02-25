#include<stdio.h>
#include<math.h>
int arr[10];
int length=0;
int insertlast()
{
    if(length<10)
    {
    int l,b;
    printf("Insert the number you want to enter at the end of the list\n");
    scanf("%d",&b);
    arr[length]=b;
    l=length;
    length++;
    if(length<10)
    {
        printf("list is not full\n");
    }else if(length==10)
    {
        printf("list is full\n");
    }
    return l;
    }else
    {
    return -1;
    }
}
int inserat(int element, int pos)
{
    int i;
    if(length==10)
        return -1;
    else if (pos>length || pos<0)
        return -2;
    for(i=length-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=element;
    length++;
    return pos;
}
int indexof()
{
    int x,i,y=0;
    scanf("%d",&x);
    for(i=0;i<length;i++)
    {
        if(arr[i]==x)
        {
        y=1;;
        break;
        }
    }
    if(y==1)
    {
        return i;
    }else
    {
        return -1;
    }

}
int lastindexof()
{
int x,i,y=0;
    scanf("%d",&x);
    for(i=length-1;i>=0;i--)
    {
        if(arr[i]==x)
        {
        y=1;;
        break;
        }
    }
    if(y==1)
    {
        return i;
    }else
    {
        return -1;
    }
}
int deletelast()
{
 if(length>0)
 {
     int m;
     m=length--;
     arr[m]=0;
     return 1;
 }else
 {
     return -1;
 }
}
int deleteat(int pos){
    int i;
    if(length==0)
        return -1;
    if(pos>=length || pos<0)
        return -2;
    for(i=pos;i<=length-2;i++)
    {
        arr[i]=arr[i+1];
    }
    length--;
    return length;

}
int deleteelement(int ele)
{
    int i,j;
    for(i=0;i<length;i++)
    {
        if(arr[i]==ele)
        {
            arr[i]=0;
            j=i;
            break;
        }
    }
    return j;
}
void deleteallelement(int ele)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(arr[i]==ele)
        {
            arr[i]=0;
        }
    }
}
void Display()
{
    int i,j;
    for(i=0;i<length;i++)
    {
        if(arr[i]==0)
        {
            continue;
        }else
        {
            printf("%d ",arr[i]);
        }
    }
}
int main()
{
    int a,c,n,num,j,k,l,element,position;
    printf("Enter your choice:\n");
    printf("1.insert last\n2.InsertAt\n3.IndexOf\n4.LastIndexOf\n5.DeleteLast\n6.DeleteAt\n7.DeleteElement\n8.DeleteAllElement\n9.print\n");
 while(scanf("%d",&num))
 {
    switch(num){
    case 1:
        a=insertlast();
        if(a!=-1)
        {
            printf("The number has been inserted at index %d\n",a);
        }else if(a==-1)
        {
            printf("insertion failed\n");
        }
        break;
    case 2:
        printf("insert the number and it's position:\n");
        scanf("%d%d",&element,&position);
        a=inserat(element,position);
        printf("The element has been inserted at %d th position\n",a);
        break;
    case 3:
        a=indexof();
        if(a==-1)
        {
            printf("The element is not present in the list\n");
        }else
        {
            printf("The index of the first occurrence of the element is %d\n",a);
        }
        break;
    case 4:
        a=lastindexof();
        if(a==-1)
        {
            printf("The element is not present in the list\n");
        }else
        {
            printf("The index of the last occurrence of the element is %d \n",a);
        }
        break;
    case 5:
        a=deletelast();
        if(a==-1)
        {
            printf("The list is empty\n");
        }else
        {
            printf("The last element has been deleted\n");
        }
        break;
    case 6:
        printf("Enter position:\n");
        scanf("%d",&position);
        a=deleteat(position);
        if(a==-1)
            printf("List Empty\n");
        else if(a==-2)
            printf("Incorrect pos value\n");
        else
            printf("Deleted from position %d\n",a);
        break;
    case 7:
        printf("Enter the element of the list you want to delete:\n");
        scanf("%d",&element);
        a=deleteelement(element);
        printf("The first occurance of %d which was at position %d has been deleted\n",element,a);
        break;
    case 8:
        printf("Enter the element which you want to delete:\n");
        scanf("%d",&element);
        deleteallelement(element);
        printf("All occurence of %d has been deleted \n",element);
        break;
    case 9:
        printf("All the elements of the list are:\n");
        Display();
        break;


    }
 }




}

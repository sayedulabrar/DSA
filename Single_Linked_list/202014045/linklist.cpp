#include<iostream>
#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    listNode * next;
};

listNode * list;

void initializeList()
{
    list = NULL;
}

int insertItem(int item)
{
	 listNode * newNode ;
	newNode = ( listNode*) malloc (sizeof( listNode)) ;
	newNode->item = item ;
	newNode->next = list ;
	list = newNode ;
	return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
	 listNode *temp, *prev ;
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


 listNode * searchItem(int item)
{
	 listNode * temp ;
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
     listNode * temp;
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
     listNode * newNode,* temp ;
	newNode = ( listNode*) malloc (sizeof( listNode)) ;
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
     listNode *temp, *prev ,* newNode;
    newNode = ( listNode*) malloc (sizeof( listNode)) ;
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
    listNode *temp, *prev ;
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
   listNode *cur;
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






148. Sort List

class Solution {
public:
// to merge n sorted lists
// for (int i =  lists.size() - 1; i > 0; i--) {
//     lists[i - 1] = merge(lists[i], lists[i - 1]);
// }

ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == NULL)
        return head;
    ListNode *fast = head->next, *slow = head;
    while(fast && fast->next) {  karon one time next nlll acceptable but null er next nai as it is already null.
        fast = fast->next->next;
        slow = slow->next;
    }

    //slow is the mid.
    ListNode *r = sortList(slow->next);
    slow->next = NULL;
    ListNode *l = sortList(head);
    return merge(l, r);
}

ListNode *merge(ListNode *l, ListNode *r) {
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;
    while (l && r) {
        if (l->val < r->val) {
            node->next = l;
            l = l->next;
        } else {
            node->next = r;
            r = r->next;
        }
        node = node->next;//as we have to take our nodes forward
    }
    if (l)
        node->next = l;
    else 
        node->next = r;
    return dummy->next;
}
};






Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLess = new ListNode(0);
        ListNode* dummyGreater = new ListNode(0);
        ListNode* less = dummyLess;
        ListNode* greater = dummyGreater;
        
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                less->next = curr;
                less = less->next;
            } else {
                greater->next = curr;
                greater = greater->next;
            }
            curr = curr->next;
        }
        
        greater->next = nullptr;
        less->next = dummyGreater->next;
        
        return dummyLess->next;
    }
};











Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 || l2  || carry != 0) {
            int digit1 = l1 ? l1->val : 0;
            int digit2 = l2 ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};


21. Merge Two Sorted Lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify handling the result
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Append the remaining nodes
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy->next;
    }
};



reverse linklist
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;   

        current->next = prev;
        prev = current;
        current = next;   

    }

    return prev;
}

reverse linklist from left to right 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p=head;
        ListNode* q=NULL;
        int cnt=1;

        while(cnt!=left){ //move to left
            q=p;
            p=p->next;
            cnt++;
        }

        ListNode* curr=p->next; 
        ListNode* prev=p;
        cnt++; //move pointers by one...

        while(cnt<=right){ //reverse till right..
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            cnt++;
        }

        if(q!=NULL) q->next=prev; //adjust pointers after reverse..
        else head=prev; 

        if(p!=NULL) p->next=curr;

        return head;
    }
};



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases where the head needs to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n nodes ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Move both pointers together until fast pointer reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};




class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Find the size of the linked list
        int size = 1;
        ListNode* tail = head;
        while (tail->next) {
            size++;
            tail = tail->next;
        }

        // Calculate the effective rotation value
        int rotateCount = k % size;
        if (rotateCount == 0) return head; // No need to rotate

        // Move the tail to the node before the new head after rotation
        int moveCount = size - rotateCount - 1;
        ListNode* newTail = head;
        int count=1;
        while(count<=moveCount) {
            count++;
            newTail = newTail->next;
        }

        // Rotate the list
        tail->next = head; // Make it circular
        head = newTail->next; // New head after rotation
        newTail->next = nullptr; // Make newTail the new tail

        return head;
    }
};



Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

class LRUCache {
private:
    int capacity;
    unordered_map<int, int> cache;
    list<int> recentlyUsed;

    void updateRecentlyUsed(int key) {
        recentlyUsed.remove(key); // O(n) operation to find and remove the key
        recentlyUsed.push_front(key); // O(1) operation to insert the key at the front
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }

        // Key is found, update its position in the recently used list
        updateRecentlyUsed(key);
        return cache[key];
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update its value and position in the recently used list
            updateRecentlyUsed(key);
            cache[key] = value;
            return;
        }

        if (cache.size() == capacity) {
            // Cache is at full capacity, remove the least recently used item
            int LRUKey = recentlyUsed.back();
            recentlyUsed.pop_back(); // O(1) operation to remove from the back of the list
            cache.erase(LRUKey); // O(1) operation to remove from the map
        }

        // Insert the new key-value pair
        recentlyUsed.push_front(key); // O(1) operation to insert at the front of the list
        cache[key] = value;
    }
};









class LRUCache {
public:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> recentlyUsed;

    void updateRecentlyUsed(int key) {
        recentlyUsed.erase(cache[key].second);
        recentlyUsed.push_front(key);
        cache[key].second = recentlyUsed.begin();
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        updateRecentlyUsed(key);
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            updateRecentlyUsed(key);
            cache[key].first = value;
            return;
        }

        if (cache.size() == capacity) {
            int LRUKey = recentlyUsed.back();
            recentlyUsed.pop_back();
            cache.erase(LRUKey);
        }

        recentlyUsed.push_front(key);
        cache[key] = {value, recentlyUsed.begin()};
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
struct ListNode
{
	int val;
	struct ListNode* next;
	struct ListNode* random;
};
void ListPrint(struct ListNode* head)
{
	struct ListNode* cur = head;
	while (cur)
	{
		printf("%d", cur->val);
		cur = cur->next;
	}
}
void ListDestroy(struct ListNode** tmp)
{
	struct ListNode* cur = *tmp;
	while (cur)
	{
		*tmp = (*tmp)->next;
		free(cur);
		cur = NULL;
		cur = (*tmp);
	}
}

struct ListNode* copyRandomList(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* tmp = NULL;
	struct ListNode* newhead=NULL;
	struct ListNode* tail = head;
	struct ListNode* newN = NULL;
	if (head == NULL)
		return NULL;
	else
	{

		while (cur)//复制val 并链接到原链表后面
		{
			struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
			if (newnode == NULL)
			{
				exit(1);
			}
			newnode->val = cur->val;
			tmp = cur->next;
			cur->next = newnode;
			newnode->next = tmp;
			cur = tmp;
		}
		//复制random
		cur = head;
		while (cur)
		{
			newN = cur->next;
			if (cur->random == NULL)
			{
				newN->random = NULL;
				cur = cur->next->next;
			}
			else
			{
				newN->random = cur->random->next;
				cur = cur->next->next;
			}
		}
		//拆解出复制好的新链表 恢复原链表
		cur = head;
		while (cur)
		{
			if (cur == head)
			{
				tail = newhead = cur->next;
				cur->next = tail->next;
				cur = cur->next;
			}
			else
			{
				tail->next = cur->next;
				tail = cur->next;
				cur->next =tail->next;
				cur = cur->next;

			}
		}
		tail->next = NULL;
		return newhead;
	}
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp;
	if (n1 != NULL)
	{
		n1->val = 1;
	}
	else exit(-1);
	if (n2 != NULL)
	{
		n2->val = 2;
	}
	else exit(-1);
	if (n3 != NULL)
	{
		n3->val = 3;
	}
	else exit(-1);
	if (n4 != NULL)
	{
		n4->val = 4;
	}
	else exit(-1);
	if (n5 != NULL)
	{
		n5->val = 5;
	}
	else exit(-1);
	if (n6 != NULL)
	{
		n6->val = 6;
	}
	else exit(-1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;
	n1->random = n2;
	n2->random = n3;
	n3->random = n4;
	n4->random = n5;
	n5->random = n6;
	n6->random = NULL;
	tmp = copyRandomList(n1);
	ListPrint(tmp);
	//ListDestroy(&n1);
	return 0;
}

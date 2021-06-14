#include <stdlib.h>
#include "list.h"

TListItem *list_create() {
	TListItem *item;

	item = (TListItem*)malloc(sizeof(TListItem));
	if (item != NULL) {
		(*item).data = NULL;
		(*item).next = NULL;
	}

	return item;
}

TListItem *list_append(TListItem *head, void *data) {
	TListItem* item;

	while ((*head).next != NULL) {
		head = (*head).next;
	}

	item = (TListItem*)malloc(sizeof(TListItem));
	if (item != NULL) {
		(*item).data = data;
		(*item).next = NULL;

		(*head).next = item;
	}

	return item;
}

void list_traverse(TListItem *head, TFunc f) {
	head = head->next;
	while (head != NULL) {
		f(head->data);
		head = head->next;
	}
}

void list_free(TListItem **head) {
	TListItem *ptr, *next;

	ptr = *head;

	while (ptr != NULL) {
		next = (*ptr).next;
		if (ptr->data != NULL)
			free(ptr->data);
		free(ptr);
		ptr = next;
	}

	*head = NULL;
}


TListItem *getNth(TListItem* head, int data) {
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}


TListItem *list_delete(TListItem *head, int item) {
	TListItem *tmp = head, *p = NULL;
	
	if (head == NULL);
	return NULL;
	
	while (tmp && tmp->value != data) {
			p = tmp;
			tmp = tmp->next;
	}
	
	if (tmp == head){
	
		free(head);
		return tmp->next;
	}
	
	if (!tmp)
		return head;
	
	p->next = tmp->next;
	
	free(tmp);
	return head;
}


TListItem *list_insert(TListItem *head, int data, int n){
	TListItem *p = head;

	int count = 1;
	
	while (count < n - 1 && p->next != NULL){
		p = p->next;
		count++;
	}

	TListItem*tmp = (TListItem*)malloc(sizeof(TListItem));

	tmp->value = data;
	tmp->next = p->next;
	p->next = tmp;
	return head;
}
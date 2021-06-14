#ifndef __LIST__
#define __LIST__

typedef struct {
	void *data;
	void *next;
} TListItem;

typedef void *TFunc(void*);


TListItem *list_create();


TListItem *list_append(TListItem *head, void *data);


TListItem *list_insert(TListItem *head, int data, int n);


void list_traverse(TListItem *head, TFunc f);


void list_free(TListItem **head);


TListItem *list_search(TListItem *head, int needle);


TListItem *list_delete(TListItem *head, int item);

#endif // !__LIST__
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print(void *value) {
	printf("%f\n", *((double*)value));
}

int main(int argc, char **argv) {
	TListItem* list;
	TListItem* item;

	double* data;

	list = list_create();

	data = (double*)malloc(sizeof(double));
	*data = 1;
	list_append(list, data);

	data = (double*)malloc(sizeof(double));
	*data = 2;
	list_append(list, data);

	data = (double*)malloc(sizeof(double));
	*data = 3;
	list_append(list, data);

	data = (double*)malloc(sizeof(double));
	*data = 5;
	list_append(list, data);

	data = (double*)malloc(sizeof(double));
	*data = 8;
	list_append(list, data);


	list_traverse(list, print);
	printf("\n");

	item = list_search(list, 5);

	list_delete(list, item);

	list_traverse(list, print);

	list_free(list);
}

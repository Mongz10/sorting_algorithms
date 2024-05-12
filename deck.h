root@c334ae211d22:/sorting_algorithms# cat > 3-quick_sort.c
#include "sort.h"
void qs_partition(int *arr, size_t size, size_t left, size_t right);
void swap_elem(int *arr, size_t size, int *a, int *b);
/**
 * quick_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
        if (array && size > 1)
                qs_partition(array, size, 0, size - 1);
}
/**
 * qs_partition - sorts partition according to pivot
 * @arr: original array
 * @size: size of original array
 * @left: leftmost element of partition
 * @right: rightmost element of partition
 */
void qs_partition(int *arr, size_t size, size_t left, size_t right)
{
        int pivot = arr[right]; /* pivot is last elem */
        size_t i, j;

        if (left < right)
        {
                for (i = j = left; j < right; j++)
                {
                        if (arr[j] <= pivot)
                        {
                                swap_elem(arr, size, &arr[j], &arr[i]);
                                i++;
                        }
                }
                swap_elem(arr, size, &arr[j], &arr[i]);

                /* lesser partition */
                if (i > 0)
                        qs_partition(arr, size, left, i - 1);
                /* greater partition */
                qs_partition(arr, size, i + 1, right);
        }
}
/**
 * swap_elem - swap value of array elements
 * @arr: array (for print)
 * @size: size of array (for print)
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap_elem(int *arr, size_t size, int *a, int *b)
{
        int tmp;

        if (*a != *b)
        {
                tmp = *a;
                *a = *b;
                *b = tmp;
                print_array(arr, size); /* print updated array */
        }
}
^C
root@c334ae211d22:/sorting_algorithms# cat > deck.h

root@c334ae211d22:/sorting_algorithms# cat > 3-quick_sort.c
#include "sort.h"
void qs_partition(int *arr, size_t size, size_t left, size_t right);
void swap_elem(int *arr, size_t size, int *a, int *b);
/**
 * quick_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
        if (array && size > 1)
                qs_partition(array, size, 0, size - 1);
}
/**
 * qs_partition - sorts partition according to pivot
 * @arr: original array
 * @size: size of original array
 * @left: leftmost element of partition
 * @right: rightmost element of partition
 */
void qs_partition(int *arr, size_t size, size_t left, size_t right)
{
        int pivot = arr[right]; /* pivot is last elem */
        size_t i, j;

        if (left < right)
        {
                for (i = j = left; j < right; j++)
                {
                        if (arr[j] <= pivot)
                        {
                                swap_elem(arr, size, &arr[j], &arr[i]);
                                i++;
                        }
                }
                swap_elem(arr, size, &arr[j], &arr[i]);

                /* lesser partition */
                if (i > 0)
                        qs_partition(arr, size, left, i - 1);
                /* greater partition */
                qs_partition(arr, size, i + 1, right);
        }
}
/**
 * swap_elem - swap value of array elements
 * @arr: array (for print)
 * @size: size of array (for print)
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap_elem(int *arr, size_t size, int *a, int *b)
{
        int tmp;

        if (*a != *b)
        {
                tmp = *a;
                *a = *b;
                *b = tmp;
                print_array(arr, size); /* print updated array */
        }
}
^C
root@c334ae211d22:/sorting_algorithms# cat > deck.h
#ifndef DECK_H
#define DECK_H

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum kind_e - enumeration of card suits
 * @SPADE: spade suit = 0
 * @HEART: heart suit = 1
 * @CLUB: club suit = 2
 * @DIAMOND: diamond suit = 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif

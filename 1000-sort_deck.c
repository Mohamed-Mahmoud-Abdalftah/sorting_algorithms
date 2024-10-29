#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "deck.h"

/**
 * swap_next - swaps node with next node
 *
 * @deck: address of the pointer to head
 * @node: node to swap
 */

void swap_next(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * deck_len - returns the length of a card deck
 * @h: head node to the deck
 *
 * Return: the size of the deck
 */

size_t deck_len(const deck_node_t *h)
{
	size_t cont = 0;

	while (h != NULL)
	{
		cont++;
		h = h->next;
	}

	return (cont);
}

/**
 * card_to_int - assigns a unique numeric value to each card
 * @node: the card node to extract the value from
 *
 * Return: a unique card id
 */

int card_to_int(deck_node_t *node)
{
	int y;
	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (y = 0; y < 13; y++)
	{
		if (!strcmp(node->card->value, values[y]))
			return (y + (13 * node->card->kind));
	}

	printf("Card is out of range.");
	exit(EXIT_FAILURE);
}

/**
 * sort_deck - sorts the deck with cocktail shaker
 *
 * @deck: the card deck to sort
 */

void sort_deck(deck_node_t **deck)
{
	int swapped = 1, value1, value2;
	size_t lo = 0, hi = (deck_len(*deck) - 1), y = 0;
	deck_node_t *tmp = *deck;

	if (!deck || !(*deck) || !((*deck)->next))
		return;
	while (swapped)
	{
		swapped = 0;
		for (; y < hi; y++)
		{
			value1 = card_to_int(tmp);
			value2 = card_to_int(tmp->next);
			if (value2 < value1)
			{
				swap_next(deck, tmp);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; y > lo; y--)
		{
			value1 = card_to_int(tmp);
			value2 = card_to_int(tmp->prev);
			if (value2 > value1)
			{
				swap_next(deck, tmp->prev);
				swapped = 1;
			}
			else
				tmp = tmp->prev;
		}
		hi -= 1;
		lo += 1;
	}
}

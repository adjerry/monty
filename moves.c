#include "monty.h"
 /** 
 * del_node_index - Delete a specific node in stack_t type list 
 * @head: Head of the stack 
 * @idx: index of the node to delete, starting at 0 
 * Return: 1 success or -1 if it fails 
 */ 
  
 int del_node_index(stack_t **head, unsigned int idx) 
 { 
         stack_t *node, *del_node; 
         unsigned int i = 0; 
  
         if (*head == NULL) 
                 return (-1); 
         node = *head; 
         while (node && i < idx) 
         { 
                 node = node->next; 
                 i++; 
         } 
         if (i < idx) 
                 return (-1); 
         if (i == 0 && node->next) 
         { 
                 del_node = node; 
                 node = node->next; 
                 node->prev = NULL; 
                 *head = node; 
                 free(del_node); 
                 return (1); 
         } 
         else if (i > 0) 
         { 
                 del_node = node; 
                 node = node->prev; 
                 node->next = del_node->next; 
                 free(del_node); 
         } 
         else 
         { 
                 *head = node->next; 
                 free(node); 
         } 
         return (1); 
 } 
  
 /** 
 * len_stack - Calculates the length of the stack 
 * @head: Head of the stack dlist 
 * Return: number of nodes in the stack 
 */ 
  
 size_t len_stack(const stack_t *head) 
 { 
         unsigned int len = 0; 
  
         while (head != NULL) 
         { 
                 head = head->next; 
                 len++; 
         } 
         return (len); 
 } 
  
 /** 
 * swap - Swap the top two element of the stack 
 * @stack: Pointer to the head of the stack 
 * @line_number: line number 
 * Return: Nothing (void) 
 */ 
  
 void swap(stack_t **stack, unsigned int line_number) 
 { 
         char message[100]; 
         stack_t *first, *second; 
         int temp; 
  
         if (len_stack(*stack) < 2 || *stack == NULL) 
         { 
                 sprintf(message, "L%u: can't swap, stack too short", line_number); 
                 error_mes(message, "", stack); 
         } 
  
         first = *stack; 
         second = first->next; 
         temp = second->n; 
         second->n = first->n; 
         first->n = temp; 
 } 
  
 /** 
 * rotl - Rotate the stack up one, the top element shift to the bottom 
 * @stack: Pointer to the head of the stack 
 * @line_number: line number 
 * Return: Nothing (void) 
 */ 
  
 void rotl(stack_t **stack, unsigned int line_number) 
 { 
         int temp; 
         stack_t *help, *new, *root; 
  
         (void) line_number; 
         help = *stack; 
         if (*stack == NULL) 
                 return; 
         if (len_stack(*stack) > 1) 
         { 
                 temp = help->n; 
                 del_node_index(stack, 0); 
                 new = malloc(sizeof(*new)); 
                 if (!new) 
                         error_mes("Error: malloc failed", "", stack); 
                 root = *stack; 
                 new->n = temp; 
                 new->next = NULL; 
                 if (help == NULL) 
                 { 
                         new->prev = NULL; 
                         help = new; 
                 } 
                 while (root->next) 
                         root = root->next; 
                 new->prev = root; 
                 root->next = new; 
         } 
 } 
  
 /** 
 * rotr - Rotate the stack down one, the bottom element shift to the top 
 * @stack: Pointer to the head of the stack 
 * @line_number: line number 
 * Return: Nothing (void) 
 */ 
  
 void rotr(stack_t **stack, unsigned int line_number) 
 { 
         stack_t *elem_1, *elem_2; 
  
         (void) line_number; 
         elem_1 = *stack; 
         if (elem_1 == NULL) 
                 return; 
         elem_2 = elem_1; 
         if (elem_1->next == NULL) 
                 ; 
         else 
         { 
                 while (elem_2->next != NULL) 
                         elem_2 = elem_2->next; 
                 elem_2->prev->next = NULL; 
                 elem_2->prev = NULL; 
                 elem_2->next = elem_1; 
                 elem_1->prev = elem_2; 
                 *stack = elem_2; 
         } 
 }

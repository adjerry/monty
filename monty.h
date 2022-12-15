#ifndef _MONTY_H
#define _MONTY_H
#include <stdio.h>
#include <stdlib.h>  
#include <string.h> 
 /** 
  * struct stack_s - doubly linked list representation of a stack (or queue) 
  * @n: integer 
  * @prev: points to the previous element of the stack (or queue) 
  * @next: points to the next element of the stack (or queue) 
  * 
  * Description: doubly linked list node structure 
  * for stack, queues, LIFO, FIFO Holberton project 
  */ 
 typedef struct stack_s 
 { 
         int n; 
         struct stack_s *prev; 
         struct stack_s *next; 
 } stack_t; 
 /** 
 * struct glob - Structure for global variable (Is this cheating? xD). 
 * @Line_buffer: Result of getline on file. 
 * @file: File to read. 
 */ 
 typedef struct glob 
 { 
         char *Line_buffer; 
         FILE *file; 
 } glob_t; 
  
 extern glob_t my_global; 
 /** 
  * struct instruction_s - opcode and its function 
  * @opcode: the opcode 
  * @f: function to handle the opcode 
  * 
  * Description: opcode and its function 
  * for stack, queues, LIFO, FIFO Holberton project 
  */ 
 typedef struct instruction_s 
 { 
         char *opcode; 
         void (*f)(stack_t **stack, unsigned int line_number); 
 } instruction_t; 
 void push_s(stack_t **stack, unsigned int line_number); 
 void push_q(stack_t **stack, unsigned int line_number); 
 void pall(stack_t **stack, unsigned int line_number); 
 void pint(stack_t **stack, unsigned int line_number); 
 void pop(stack_t **stack, unsigned int line_number); 
 void swap(stack_t **stack, unsigned int line_number); 
 void add(stack_t **stack, unsigned int line_number); 
 void sub(stack_t **stack, unsigned int line_number); 
 void divi(stack_t **stack, unsigned int line_number); 
 void mul(stack_t **stack, unsigned int line_number); 
 void mod(stack_t **stack, unsigned int line_number); 
 void pchar(stack_t **stack, unsigned int line_number); 
 void pstr(stack_t **stack, unsigned int line_number); 
 void rotl(stack_t **stack, unsigned int line_number); 
 void rotr(stack_t **stack, unsigned int line_number); 
 void check_opc(char *, instruction_t (*o)[], int, stack_t **); 
 void error_mes(char *mess, char *arg, stack_t **stack); 
 void free_all(stack_t **stack); 
 short isnumber(char *str); 
 #endif /* _MONTY_H */

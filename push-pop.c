#include "monty.h" 
 /** 
 * push_s - Push on a stack. 
 * @stack: Stack. 
 * @line_number: Line number. 
 */ 
 void push_s(stack_t **stack, unsigned int line_number) 
 { 
         stack_t *new; 
         char *arg, message[100]; 
  
         if (!stack) 
                 error_mes("No stack present.", "", stack); 
         arg = strtok(NULL, " \t"); 
         sprintf(message, "L%d: usage: push integer", line_number); 
         if (!arg || !isnumber(arg)) 
                 error_mes(message, "", stack); 
         new = malloc(sizeof(stack_t)); 
         if (!new) 
                 error_mes("Error: malloc failed", "", stack); 
         new->n = atoi(arg); 
         new->next = *stack; 
         new->prev = NULL; 
         if (*stack) 
                 (*stack)->prev = new; 
         *stack = new; 
 } 
 /** 
 * push_q - Push on a queue. 
 * @stack: Stack. 
 * @line_number: Line number. 
 */ 
 void push_q(stack_t **stack, unsigned int line_number) 
 { 
         stack_t *new, *h = *stack; 
         char *arg, message[100]; 
  
         if (!stack) 
                 error_mes("No stack present.", "", stack); 
         arg = strtok(NULL, " \t"); 
         sprintf(message, "L%d: usage: push integer", line_number); 
         if (!arg || !isnumber(arg)) 
                 error_mes(message, "", stack); 
         new = malloc(sizeof(stack_t)); 
         if (!new) 
                 error_mes("Error: malloc failed", "", stack); 
         new->n = atoi(arg); 
         new->next = NULL; 
         if (!*stack) 
         { 
                 new->prev = *stack; 
                 *stack = new; 
                 return; 
         } 
         while (h->next) 
                 h = h->next; 
         h->next = new; 
         new->prev = h; 
 } 
 /** 
 * pop - Deletes top item on a stack or queue. 
 * @stack: Stack. 
 * @line_number: Line number. 
 */ 
 void pop(stack_t **stack, unsigned int line_number) 
 { 
         stack_t *iterator = *stack; 
         char message[100]; 
  
         if (!stack) 
                 error_mes("No stack present.", "", stack); 
         sprintf(message, "L%d: can't pop an empty stack", line_number); 
         if (!*stack) 
                 error_mes(message, "", stack); 
  
         *stack = iterator->next; 
         if (iterator->next) 
                 iterator->next->prev = NULL; 
         free(iterator); 
 } 
 /** 
 * error_mes - Prints error message and exits with failure. 
 * @mess: Message to print. 
 * @arg: Additional argument. 
 * @stack: stack to free. 
 */ 
 void error_mes(char *mess, char *arg, stack_t **stack) 
 { 
         free_all(stack); 
         fprintf(stderr, "%s%s\n", mess, arg); 
         exit(EXIT_FAILURE); 
 } 
  
 /** 
 * free_all - Frees the stack 
 * @stack: stack to free 
 * Return: Nothing (void) 
 */ 
  
 void free_all(stack_t **stack) 
 { 
         stack_t *temp; 
  
         while (*stack) 
         { 
                 temp = *stack; 
                 *stack = (*stack)->next; 
                 free(temp); 
         } 
         if (my_global.Line_buffer) 
                 free(my_global.Line_buffer); 
         if (my_global.file) 
                 fclose(my_global.file); 
 }

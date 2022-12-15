#include "monty.h"
#include <ctype.h>
glob_t my_global; 
/** 
 * main - Entry point. 
 * @argc: Argument count. 
 * @argv: Argument vector. 
 * Return: EXIT_SUCCESS or EXIT_FAILURE 
 */ 
int main(int argc, char *argv[]) 
{ 
         instruction_t opcodes[14] = {{"push", push_s}, {"pall", pall}, {"pint", pint}, 
         {"pop", pop}, {"swap", swap}, {"add", add}, {"sub", sub}, {"div", divi}, 
         {"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, 
         {"rotr", rotr}}; 
         int line_number = 1, getl_res = 0; 
         size_t buf_size = 0; 
         stack_t *stack = NULL; 
  
         if (argc != 2) 
                 error_mes("USAGE: monty file", "", &stack); 
         my_global.file = fopen(argv[1], "r"); 
         if (!my_global.file) 
                 error_mes("Error: Can't open file ", argv[1], &stack); 
         while (1) 
         { 
                 getl_res = getline(&my_global.Line_buffer, &buf_size, my_global.file); 
                 if (getl_res == EOF) 
                         break; 
                 check_opc(strtok(my_global.Line_buffer, " \t"), &opcodes, line_number, 
                         &stack); 
                 line_number++; 
         } 
         free_all(&stack); 
         return (EXIT_SUCCESS); 
 } 
 /** 
 * check_opc - Checks if the opcode is valid and executes it. 
 * @Line_buffer: Opcode given by the user (after strtok). 
 * @opcodes: Valid opcodes. 
 * @line_number: Line number of script. 
 * @stack: Stack (or queue) to work with. 
 */ 
 void check_opc(char *Line_buffer, instruction_t (*opcodes)[], int line_number, 
 stack_t **stack) 
 { 
         int i, len = strlen(Line_buffer); 
         char message[100]; 
  
         if (Line_buffer[len - 1] == '\n') 
                 Line_buffer[len - 1] = 0; 
         if (!strcmp(Line_buffer, "nop") || Line_buffer[0] == '#') 
                 return; 
         if (!strcmp(Line_buffer, "")) 
                 return; 
         if (!strcmp(Line_buffer, "queue")) 
         { 
                 (*opcodes)[0].f = push_q; 
                 return; 
         } 
         if (!strcmp(Line_buffer, "stack")) 
         { 
                 (*opcodes)[0].f = push_s; 
                 return; 
         } 
         for (i = 0; i < 14; i++) 
         { 
                 if (!strcmp(Line_buffer, (*opcodes)[i].opcode)) 
                 { 
                         (*opcodes)[i].f(stack, line_number); 
                         return; 
                 } 
         } 
         if (i == 14) 
         { 
                 sprintf(message, "L%d: unknown instruction %s", line_number, Line_buffer); 
                 error_mes(message, "", stack); 
         } 
         return; 
  
 } 
 /** 
 * isnumber - checks if a string is a number. 
 * @str: String to check. 
 * Return: 1 if is a number, 0 if not. 
 */ 
 short isnumber(char *str) 
 { 
         short i; 
  
         if (*str == '\n') 
                 return (0); 
         for (i = 0; *(str + i) && *(str + i) != '\n'; i++) 
                 if (!isdigit(*(str + i)) && *(str + i) != '-') 
                         return (0); 
         return (1); 
 }

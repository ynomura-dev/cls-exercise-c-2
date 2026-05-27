#define STACK_SIZE 1000
typedef char* STACK_TYPE; 


void push(STACK_TYPE x);
STACK_TYPE pop(void);
void print_stack(void);
int is_stack_empty(void);
int is_stack_full(void);
void init_stack(void);
STACK_TYPE peek(void);

#define QUEUE_SIZE 1000
typedef char* QUEUE_TYPE;


void init_queue(void);
int is_queue_empty(void);
int is_queue_full(void);
void enqueue(QUEUE_TYPE x);
QUEUE_TYPE dequeue(void);

void print_queue(void);
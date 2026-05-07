#define LIST_SIZE 100000

typedef int LIST_TYPE;
typedef int POSITION;

/* error handling */
void errorExit(const char *message);

/* list operations */
int listLength (void);
int isListEmpty(void);
int isListFull(void);
void insert(POSITION pos, LIST_TYPE x);
void append(LIST_TYPE x);
LIST_TYPE deleteAt(POSITION pos);
LIST_TYPE retrive(POSITION pos);
LIST_TYPE replace(POSITION pos, LIST_TYPE new_value);
void initList(void);
void printList(void);

int countPositiveMultipleOf3or5(void);
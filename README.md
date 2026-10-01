Multiple header files cannot be used in the same file since all have the same node_t. I did that purposefully since students must not be lazy like me ;). Well the readme file is vibe coded if not for the actual code.

# Data Structures in C

Basic data structure implementations in C for learning and coursework.

## Header Files

### `Linkedlist.h`

Singly linked list.

```c
void init_list(node_t **head);
node_t *createNode(double data);
node_t *insert(node_t *head, double data, int pos);
double del(node_t **head, char *ch);
node_t *order(node_t *head, char *ch);
void display(node_t *head);
void deinit_list(node_t *head);
```

* `init_list()` — initializes the list.
* `createNode()` — creates a new node.
* `insert()` — inserts a node at a given position.
* `del()` — deletes a node.
* `order()` — sorts the list.
* `display()` — displays the list.
* `deinit_list()` — frees the list.

### `DoublyLinkedlist.h`

Doubly linked list.

```c
void init_list(node_t **head);
node_t *createNode(double data);
node_t *insert(node_t *head, double data, int pos);
double del(node_t **head, char *ch);
node_t *order(node_t *head, char *ch);
void display(node_t *head);
void deinit_list(node_t *head);
```

Same operations as the singly linked list, with nodes containing both `next` and `prev` pointers.

### `Circularlist.h`

Circular linked list.

```c
void init_list(node_t **head);
node_t *createNode(double data);
node_t *insert(node_t *head, double data, int pos);
double del(node_t **head, char *ch);
node_t *order(node_t *head, char *ch);
void display(node_t *head);
void deinit_list(node_t **head);
```

The last node points back to the first node.

### `Stack.h`

Stack implemented using a linked list.

```c
void init_stack(stack_t *s);
void push(stack_t *s, int l);
int pop(stack_t *s);
int peek(stack_t *s);
void display(stack_t *s);
void deinit_stack(stack_t *s);
```

* `push()` — adds an element to the top.
* `pop()` — removes and returns the top element.
* `peek()` — returns the top element without removing it.
* `display()` — displays the stack.

### `Queue.h`

Queue implemented using a linked list.

```c
void init(queue_t *p);
void enqueue(queue_t *p, int l);
int dequeue(queue_t *p);
int peek(queue_t *p);
int is_empty(queue_t *p);
int is_full(queue_t *p);
void display(queue_t *p);
void deinit(queue_t *p);
```

* `enqueue()` — adds an element to the rear.
* `dequeue()` — removes and returns the front element.
* `peek()` — returns the front element.
* `is_empty()` — checks whether the queue is empty.
* `is_full()` — checks whether another node can currently be allocated.
* `display()` — displays the queue.

### `Priority_Queue.h`

Priority queue implemented using a linked list.

```c
void init(pq_t *q);
void enqueue(pq_t *q, int a, int p);
int dequeue(pq_t *q);
int peek(pq_t *q);
int is_empty(pq_t *q);
int is_full(pq_t *q);
void display(pq_t *q);
void deinit(pq_t *q);
```

* `enqueue()` — inserts an element according to its priority.
* `dequeue()` — removes and returns the highest-priority element.
* `peek()` — returns the highest-priority element without removing it.
* `is_empty()` — checks whether the queue is empty.
* `is_full()` — checks whether another node can currently be allocated.
* `display()` — displays the priority queue.

**Priority convention:** a smaller priority value means higher priority.

For example:

```text
1 → highest priority
2
3
4 → lowest priority
```

## Things You Should Not Do

* Do not use an invalid position such as `pos <= 0` when inserting into a linked list.
* Do not use a node after it has been deleted or freed.
* Do not access `head`, `front`, `rear`, or `top` without ensuring the structure is initialized.
* Do not manually modify `next`/`prev` pointers unless you understand how the links are affected.
* Do not call `dequeue()` or `pop()` on an empty structure.
* Do not call `peek()` on an empty structure without handling its return value appropriately.
* Do not free the same node more than once.
* Do not include multiple headers that define conflicting types/functions in the same source file.
* Do not change the priority convention in `Priority_Queue` without also changing its insertion logic.

## Requirements

A C compiler such as GCC is required.

Example:

```bash
gcc program.c -o program
./program
```

## Note

These implementations are primarily for learning and coursework purposes. They may be modified and improved as I continue learning C and data structures.

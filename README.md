Multiple header files cannot be used in the same file since all have the same node_t. I did that purposefully since students must not be lazy like me ;). 

# Data Structures in C

Basic data structure implementations in C.

## Header Files

### `Linkedlist.h`

For implementing a **singly linked list**.

Functions:

```c
node_t *init_list();
node_t *insert(node_t *head, double data, int pos);
node_t *del(node_t *head, int pos);
void display(node_t *head);
void deinit_list(node_t **head);
```

* `init_list()` — creates/initializes an empty list.
* `insert()` — inserts a value at the given position.
* `del()` — deletes the node at the given position.
* `display()` — displays the list.
* `deinit_list()` — frees the entire list.

---

### `DoublyLinkedlist.h`

For implementing a **doubly linked list**.

Functions:

```c
node_t *init_list();
node_t *insert(node_t *head, double data, int pos);
node_t *del(node_t *head, int pos);
void display(node_t *head);
void deinit_list(node_t **head);
```

* `init_list()` — initializes an empty list.
* `insert()` — inserts a value at the given position.
* `del()` — deletes the node at the given position.
* `display()` — displays the list.
* `deinit_list()` — frees the entire list.

---

### `Circularlist.h`

For implementing a **circular linked list**.

Functions:

```c
node_t *init_list();
node_t *insert(node_t *head, double data, int pos);
node_t *del(node_t *head, int pos);
void display(node_t *head);
void deinit_list(node_t **head);
```

* `init_list()` — initializes an empty list.
* `insert()` — inserts a value at the given position.
* `del()` — deletes the node at the given position.
* `display()` — traverses and displays the circular list.
* `deinit_list()` — frees the entire list.

---

### `Stack.h`

For implementing a **stack using a linked list**.

Functions:

```c
stack_t *init_stack();
void push(stack_t *s, double data);
double pop(stack_t *s);
double peek(stack_t *s);
void deinit_stack(stack_t **s);
```

* `init_stack()` — creates an empty stack.
* `push()` — adds an element to the top.
* `pop()` — removes and returns the top element.
* `peek()` — returns the top element without removing it.
* `deinit_stack()` — frees the stack.

---

### `Queue.h`

For implementing a **queue using a linked list**.

Functions:

```c
queue_t *init_queue();
void enqueue(queue_t *q, double data);
double dequeue(queue_t *q);
double peek(queue_t *q);
void deinit_queue(queue_t **q);
```

* `init_queue()` — creates an empty queue.
* `enqueue()` — adds an element to the rear.
* `dequeue()` — removes and returns the front element.
* `peek()` — returns the front element without removing it.
* `deinit_queue()` — frees the queue.

## Requirements

A C compiler such as **GCC** is required.

Example:

```bash
gcc program.c -o program
./program
```

## Note

These implementations are primarily for **learning and coursework purposes**. They may be modified or improved as I continue learning C and data structures.

Each data structure has its own header file and implementation file. Avoid including multiple headers that define the same type name (such as `node_t`) in the same source file.

# XOR Linked List

A doubly-linked-list where instead of each node holding two pointers to its neighbours, 
it holds a XOR value of the two pointers.

## Examples
```c++
XORLinkedList<std::string> names;    // Create an empty list
names.add("John");                   // Add an item to the end of the list
names.add("Bob");
```

### Indexing
```c++
names[0];   // Get the first element of the list
names[-1];  // Negative indexing! Get the last item
```

### Array Initialization
```c++
XORLinkedList<int> numbers({ 1, 2, 3 });  // Initialize from an array
```

### Iteration
```c++
for (int number : numbers.iter()) {/* ... */}

for (int number : numbers.reverse_iter()) {/* ... */}  // Reverse Iteration!
```

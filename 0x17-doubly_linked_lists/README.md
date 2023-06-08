Doubly Linked List Project

This project focuses on implementing a doubly linked list data structure in the C programming language. The goal is to gain a solid understanding of doubly linked lists and how to work with them.

Table of Contents
Introduction
File Structure
Requirements
Usage
Testing
Contributing
License


Introduction
A doubly linked list is a data structure where each node contains references to both the previous and next nodes in the list. This allows for efficient traversal in both directions and enables insertion and deletion operations at both ends of the list.

In this project, we will be working with a provided data structure called dlistint_t, which represents a node in the doubly linked list. The structure consists of an integer value n and two pointers, prev and next, which point to the previous and next nodes, respectively.

The project requirements specify that only a limited set of C standard library functions can be used, such as malloc, free, printf, and exit. All other functions must be implemented by us.

File Structure
The project files are structured as follows:

lists.h: Header file containing the function prototypes.
0-function_name.c: Source file containing the implementation of a specific function.
1-function_name.c: Source file containing the implementation of another function.
...
main.c: Example main file for testing purposes (not required to submit).


Requirements
Allowed editors: vi, vim, emacs
All files will be interpreted/compiled on Ubuntu 20.04 LTS using gcc with C standard library functions mentioned in the requirements.
Code should follow the Betty style guide for formatting.
Each source file should contain no more than 5 functions.
Code should be modular, with functions implemented for specific operations.
Use the provided dlistint_t structure for the doubly linked list node.
A README.md file is mandatory.


Usage
To use the doubly linked list implementation in your own code, follow these steps:

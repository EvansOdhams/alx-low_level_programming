# Hash Tables in C

This project implements a basic hash table data structure in the C programming language. The hash table allows efficient insertion, retrieval, and deletion of key-value pairs.

## Table of Contents
- [Introduction](#introduction)
- [Usage](#usage)
- [Functions](#functions)
- [Tests](#tests)
- [Contributing](#contributing)
- [License](#license)

## Introduction

A hash table, also known as a hash map, is a data structure that uses a hash function to map keys to array indices. This allows for constant-time average-case performance for basic operations such as insertion, retrieval, and deletion.

This project provides a simple implementation of a hash table using chaining collision handling. Chaining involves maintaining a linked list of elements for each array index, where collisions occur when multiple keys hash to the same index.

## Usage

To use the hash table implementation in your C project, follow these steps:

1. Include the `hash_tables.h` header file in your source code.
2. Compile your program with `hash_tables.c` to ensure the functions are linked correctly.
3. Create a hash table using `hash_table_create(size)`, where `size` is the desired size of the hash table array.
4. Use the provided functions to insert, retrieve, and delete key-value pairs from the hash table.
5. Remember to call `hash_table_delete(ht)` to free the memory allocated by the hash table when you're done.

## Functions

The following functions are provided by the hash table implementation:

- `hash_table_create(size)`: Creates a new hash table with the specified size.
- `hash_table_set(ht, key, value)`: Inserts a key-value pair into the hash table.
- `hash_table_get(ht, key)`: Retrieves the value associated with a key from the hash table.
- `hash_table_print(ht)`: Prints the contents of the hash table.
- `hash_table_delete(ht)`: Deletes the hash table and frees the allocated memory.

Refer to the `hash_tables.h` header file for more details on the function prototypes.

## Tests

A set of tests is included in the project to ensure the correct functioning of the hash table implementation. You can run these tests to verify that the hash table operations are working as expected.

To run the tests, compile the test file (`main.c`) along with the hash table implementation. Then, execute the resulting binary.

## Contributing

Contributions to this hash table project are welcome! If you find any issues or have suggestions for improvements, please feel free to submit a pull request or open an issue on the GitHub repository.

## License

This project is licensed under the [MIT License](LICENSE). You are free to modify and distribute the code for personal or commercial purposes.


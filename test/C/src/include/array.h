/**
 * Simple implementation of an int array that carries a length field.
 * This provides a constructor, a copy constructor, and a destructor.
 * @author Hou Seng (Steven) Wong (housengw@berkeley.edu)
 * @author Edward A. Lee (eal@berkeley.edu)
 */

#ifndef ARRAY_H
#define ARRAY_H

#include "stdlib.h"

typedef struct int_array_t {
    int* data;
    size_t length;
} int_array_t;

/**
 * @brief Construct an array with the given length initialized with zeros.
 * The caller is responsible for calling the destructor to free the allocated memory.
 * @param length The length.
 * @return A pointer to the array struct. 
 */
int_array_t* int_array_constructor(size_t length) {
    int_array_t* val = (int_array_t*) malloc(sizeof(int_array_t));
    val->data = (int*) calloc(length, sizeof(int));
    val->length = length;
    return val;
}

/**
 * @brief Given a pointer to an int_array_t struct, construct a copy.
 * The caller is responsible for calling the destructor to free the allocated memory.
 * The argument and return value are void* so that this function can be set as the
 * copy constructor used by the C runtime for mutable inputs.
 * @param array The array to copy.
 * @return void* 
 */
void* int_array_copy_constructor(void* array) {
    int_array_t* other_arr = (int_array_t*) array;
    int_array_t* val = (int_array_t*) malloc(sizeof(int_array_t));
    val->data = (int*) calloc(other_arr->length, sizeof(int));
    val->length = other_arr->length;
    for (size_t i = 0; i < other_arr->length; i++) {
        val->data[i] = other_arr->data[i];
    }
    return (void*) val;
}

/**
 * @brief Free the memory associated with the specified array.
 * The argument has type void* so that this function can be set as the
 * destructor used by the C runtime for token types, which are freed
 * when their reference count decrements to zero.
 * @param array The array to free.
 */
void int_array_destructor(void* array) {
    free(((int_array_t*) array)->data);
    free(array);
}

#endif
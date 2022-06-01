#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024
#define HEAP_FREED_CAP 1024

#define TODO() \
    do { \
    fprintf(stderr, "%s:%d: TODO: %s\n" is not implemented yet, \
            __FILE__, __LINE__, __func__); \
    abort(); \
    } while(0)
}

typedef struct {
    void *start;
    size_t size;
} Heap_Chunk;

typedef struct {
    size_t count;
    Heap_Chunk CHUNKS[HEAP_ALLOCED_CAP];
} Heap_Chunk_List;

void    chunk_list_dumb(const Chunk_List *list)
{
    printf("Allocated Chunks (%zu):\n", list->count);
    for (size_t i = 0; i < list->count; ++i) {
        printf(" start: %p, size: %zu\n",
                list->chunks[i].start,
                list->chunks[i].size);
    }
}

int     chunk_list_find(void *ptr)
{
    TODO();
    return -1;
}

void    chump_list_insert(Chunk_List *list, void *ptr, size_t size)
{
    TODO();
}

void    chunk_list_remove(Chunk_List *list, size_t index)
{
    TODO();
}

char heap[HEAP_CAP] = {0};
size_t heap_size = 0;

Chunk_List alloced_chunks = {0};
Chunk_List freed_chunks = {0};

void    *malloc(size_t size)
{
    if (size > 0)
    {
        assert(heap_size + size <= HEAP_CAP);
        void *ptr = heap + heap_size;
        heap_size += size;

        chunk_list_insert(&alloced_chunks, ptr, size);
        return(ptr);
    }
    else
    {
        return(NULL);
    }
}

void    free(void *ptr)
{
    TODO();
}

void    collect()
{
    TODO();
}

int     main()
{
    for (int i = 0; i < 100; ++i) {
        void *p = malloc(i);
        if (i % 2 == 0)
        {
            free(p);
        }
    }
    
    heap_dump_alloced_chunks();

    // free(root);

    return(0);
}

#ifndef __FOREACH_
#define __FOREACH_

typedef int (user_fn_1arg)(void * param1);
typedef void (foreach_1arg)(void * arg1, user_fn_1arg *callback);
typedef struct Array Array;

struct Array {
        foreach_1arg *foreach;
        void *elements;
        int nelems;
        int size;
        int curr;
};

Array * create_array(void *elems, int nelems, int size);

#endif /* FOREACH */

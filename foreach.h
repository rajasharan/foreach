#ifndef __FOREACH_
#define __FOREACH_

typedef int (user_fn_1arg)(void * param1);
typedef void (foreach_1arg)(void * arg1, user_fn_1arg *callback);
typedef struct Array Array;
typedef struct Element Element;

struct Array {
        foreach_1arg *foreach;
        Element *elements;
        int nelems;
        int curr;
};

struct Element {
        void *elem;
        int size;
        Element *next;
};

Array * create_array(Element *elems, int nelems);

#endif /* FOREACH */

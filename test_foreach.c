#include <stdlib.h>
#include <stdio.h>
#include "foreach.h"

typedef struct Element Element;
struct Element {
        int key;
        double rand;
};

int callback(void *elem)
{
        Element *e = (Element *)elem;
        printf("%d\n", e->key);
        return 0;
}

int main(void)
{
        Element elems[20];
        int i;
        for (i=0; i<20; i++)
                elems[i].key = 20-i;

        Array *arr = create_array(elems, 20, sizeof(Element));
        arr->foreach(arr, callback);
        return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "foreach.h"

int callback(void *elem)
{
        Element *e = (Element *)elem;
        printf("%d\n", e->size);
        return 0;
}

int main(void)
{
        Element elems[20];
        int i;
        for (i=0; i<20; i++)
                elems[i].size = 20-i;

        Array *arr = create_array(elems, 20);
        arr->foreach(arr, callback);
        return 0;
}

#include "foreach.h"
#include <stdlib.h>

static void each_1arg(void *arg1, user_fn_1arg *callback)
{
        Array *arr = (Array *)arg1;
        void *elem = arr->elements;

        while (arr->curr < arr->nelems) {
                /* TODO: later check return value */
                callback( (elem + (arr->curr * arr->size)) );
                arr->curr++;
        }
}

Array * create_array(void *elems, int nelems, int size)
{
        Array *array = (Array *) malloc(sizeof(Array));
        array->elements = elems;
        array->nelems = nelems;
        array->size = size;
        //TODO: later copy one by one and set nelems
        //array->elements = (Element *) malloc(sizeof(Element));

        array->curr = 0;
        array->foreach = each_1arg;

        return array;
}

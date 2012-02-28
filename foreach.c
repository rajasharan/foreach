#include "foreach.h"

static void each_1arg(void *arg1, user_fn *callback)
{
        Array *arr = (Array *)arg1;
        Element *elem = (Element *)(arr->elements);

        while (arr->curr < arr->nelems) {
                callback(&elem[arr->curr]); /* later check return value */
                arr->curr++;
        }
}

Array * create_array(Element *elems, int nelems)
{
        Array *array = (Array *) malloc(sizeof(Array));
        array->elements = elems;
        array->nelems = nelems;
        //later copy one by one and set nelems
        //array->elements = (Element *) malloc(sizeof(Element));

        array->curr = 0;
        array->foreach = each_1arg;

        return array;
}

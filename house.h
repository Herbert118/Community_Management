#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED
#include "service.h"
typedef struct house
{
    int number;
    int used_or_not;
    float price;
    struct house *next;
} HOUSE;


#endif // HOUSE_H_INCLUDED

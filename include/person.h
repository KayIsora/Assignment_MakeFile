#ifndef PERSON_H
#define PERSON_H
#define NAME_MAX_LEN 63

typedef struct {
    int  id;
    char name[NAME_MAX_LEN + 1];
    int  age;
} Person;

#endif

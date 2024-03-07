// will implement external chaining for the buckets in the hashtable
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person * next;
} person;

person * hash_table[TABLE_SIZE]; // an array of person pointers

unsigned int hash(char *name) {
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i=0; i<length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i<TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table() {
    printf("Start\n");
    for (int i = 0; i<TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p) {
    if (p == NULL ) return false;
    int index = hash(p->name);
    p-> next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person *hash_table_lookup (char *name) {
    int index = hash(name);
    person *tmp = hash_table[index];
    while (tmp != NULL && strcmp(tmp->name, name) != 0) {
        tmp = tmp->next;
    }

    return tmp;
}

person *hash_table_delete(char *name) {
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while (tmp != NULL && strcmp(tmp->name, name) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL) {
        hash_table[index] = tmp ->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}

int main() {

    init_hash_table();

    person jacob = {.name="Jacob", .age = 2};
    person kate = {.name = "kate", .age = 45};
    person michael = {.name = "Michael", .age = 30};
    person emily = {.name = "Emily", .age = 25};
    person alex = {.name = "Alex", .age = 40};
    person sarah = {.name = "Sarah", .age = 22};
    person john = {.name = "John", .age = 33};
    person lisa = {.name = "Lisa", .age = 22};
    person daniel = {.name = "Daniel", .age = 35};
    person laura = {.name = "Laura", .age = 19};
    person chris = {.name = "Chris", .age = 50};
    person olivia = {.name = "Olivia", .age = 27};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&michael);
    hash_table_insert(&emily);
    hash_table_insert(&alex);
    hash_table_insert(&sarah);
    hash_table_insert(&john);
    hash_table_insert(&lisa);
    hash_table_insert(&daniel);
    hash_table_insert(&laura);
    hash_table_insert(&chris);
    hash_table_insert(&olivia);

    print_table();

}

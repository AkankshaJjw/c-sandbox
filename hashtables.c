#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*) (g)

typedef struct {
    char name[MAX_NAME];
    int age;
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
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        }
        else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p) {
    if (p == NULL ) return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if ((hash_table[try] == NULL) || (hash_table[try] == DELETED_NODE)) {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup (char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return false;
        if(hash_table[try]== DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            return hash_table[try];
        }
    }

    return NULL;
}

person *hash_table_delete(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return false;
        if(hash_table[try]== DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
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

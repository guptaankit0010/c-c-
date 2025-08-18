#include <stdio.h>
#include <string.h>
union Address
{
    char name[5];
    char street[10];
};

struct Address2
{
    char name[5];
    char street[10];
};

int main()
{
    union Address add1 = {"qwsdd"};
    int *street;
    int *name;
    street = &add1.street;
    name = &add1.name;

    printf("%s\n", add1.name);
    strcpy(add1.street, "FEEEfEEEE");
    printf("%s\n%ld\n", add1.name, sizeof(add1.name));
    printf("%s\n%ld\n", add1.street, sizeof(add1.street));
    printf("%s\n", add1.street);
    printf("%x\n", street);
    printf("%x\n", name);
    printf("%x\n", &add1);
    printf("%d\n", sizeof(add1));

    char c4, c3, c1, c2;

    c1 = 300;
    c2 = 4;
    c3 = 1;
    c4 = c1 * c2 / c3;

    struct Address2 add2 = {"sdsds", "REREREE"};
    struct Address2 add3 = {"sdsds", "REREREE"};
    int *addP2 = &add2;
    int *addP3 = &add3;

    return 0;
}
#include <stdio.h>

#include "hash_table.h"

int main(void)
{
    ht_hash_table *ht = ht_new();

    printf("ht_insert(\"test\", \"deez nuts\")\n");
    ht_insert(ht, "test", "deez nuts");

    printf("ht_search(\"test\"): %s\n", ht_search(ht, "test"));

    printf("ht_delete(\"test\")\n");
    ht_delete(ht, "test");

    printf("ht_search(\"test\"): %s\n", ht_search(ht, "test"));

    ht_del_hash_table(ht);

    return 0;
}
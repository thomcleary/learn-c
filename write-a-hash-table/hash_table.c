#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"
#include "prime.h"

#define HT_INITIAL_BASE_SIZE 53

// Must be bigger than the size of the alphabet (in this case ASCII, so > 128)
#define HT_PRIME_1 137
#define HT_PRIME_2 263

// Deleting from an open addressed hash table is more complicated than inserting or searching.
// The item we wish to delete may be part of a collision chain.
// Removing it from the table will break that chain, and will make finding items in the tail of the chain impossible.
// To solve this, instead of deleting the item, we simply mark it as deleted.
// We mark an item as deleted by replacing it with a pointer to a global sentinel item which represents that a bucket contains a deleted item.
static ht_item HT_DELETED_ITEM = {NULL, NULL};

// NOTE: Tutorial skips NULL checks for allocations

static ht_item *ht_new_item(const char *k, const char *v)
{
    ht_item *i = malloc(sizeof(ht_item));

    i->key = strdup(k);
    i->value = strdup(v);

    return i;
}

static void ht_del_item(ht_item *i)
{
    // This if guard was not in the guide, raise issue?
    if (i != &HT_DELETED_ITEM)
    {
        free(i->key);
        free(i->value);
        free(i);
    }
}

static int ht_hash(const char *s, const int a, const int m)
{
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        hash += (long)pow(a, len_s - (i + 1)) * s[i];
    }
    hash = hash % m;
    return (int)(hash);
}

static int ht_get_hash(const char *s, const int num_buckets, const int attempt)
{
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);

    // If hash_b == (num_buckets - 1),
    // then (hash_b + 1) will result in the return statement being equivalent to
    // hash_a % num_buckets
    // and can cause infinite cycles when probing the hash table
    if (hash_b % num_buckets == 0)
    {
        hash_b = 1;
    }

    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

static ht_hash_table *ht_new_sized(const int base_size)
{
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));

    ht->base_size = base_size;
    ht->size = next_prime(ht->base_size);
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item *));

    return ht;
}

static void ht_resize(ht_hash_table *ht, const int base_size)
{
    if (base_size < HT_INITIAL_BASE_SIZE)
    {
        return;
    }
    ht_hash_table *new_ht = ht_new_sized(base_size);
    for (int i = 0; i < ht->size; i++)
    {
        ht_item *item = ht->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM)
        {
            ht_insert(new_ht, item->key, item->value);
        }
    }

    ht->base_size = new_ht->base_size;
    ht->count = new_ht->count;

    // To delete new_ht, we give it ht's size and items
    const int tmp_size = ht->size;
    ht->size = new_ht->size;
    new_ht->size = tmp_size;

    ht_item **tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;

    ht_del_hash_table(new_ht);
}

static void ht_resize_up(ht_hash_table *ht)
{
    const int new_size = ht->base_size * 2;
    ht_resize(ht, new_size);
}

static void ht_resize_down(ht_hash_table *ht)
{
    const int new_size = ht->base_size / 2;
    ht_resize(ht, new_size);
}

ht_hash_table *ht_new()
{
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

void ht_del_hash_table(ht_hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        ht_item *item = ht->items[i];
        if (item != NULL)
        {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

void ht_insert(ht_hash_table *ht, const char *key, const char *value)
{
    const int load = ht->count * 100 / ht->size;
    if (load > 70)
    {
        ht_resize_up(ht);
    }

    ht_item *item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item *cur_item = ht->items[index];

    int i = 1;
    while (cur_item != NULL)
    {
        // This looks like it will leave deleted items in the array forever?
        if (cur_item != &HT_DELETED_ITEM)
        {
            if (strcmp(cur_item->key, key) == 0)
            {
                ht_del_item(cur_item);
                ht->items[index] = item;
                return;
            }
        }
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

char *ht_search(ht_hash_table *ht, const char *key)
{
    int index = ht_get_hash(key, ht->size, 0);
    ht_item *item = ht->items[index];

    int i = 1;
    while (item != NULL)
    {
        if (item != &HT_DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                return item->value;
            }
        }

        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }

    return NULL;
}

void ht_delete(ht_hash_table *ht, const char *key)
{
    const int load = ht->count * 100 / ht->size;
    if (load < 10)
    {
        ht_resize_down(ht);
    }

    int index = ht_get_hash(key, ht->size, 0);
    ht_item *item = ht->items[index];

    int i = 1;
    while (item != NULL)
    {
        if (item != &HT_DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
                ht->count--;
                return;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
}

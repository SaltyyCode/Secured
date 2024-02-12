#include "include/hashtable.h"

int main(void)
{
    hashtable_t * ht = new_hashtable (&hash, 6);
    ht_insert(ht, "Saltyy", "Home");
    ht_insert(ht, "2212429193", "Freeze");
    ht_insert(ht, "Vision", "./ Documents / Tournament / Modules / Vision");
    ht_insert(ht, "Kratos", "./ Trash / Hollidays_Pics /. secret_folder / kratos .ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_delete(ht, "Vision");
    ht_delete(ht, "Kratos");
    ht_dump(ht);
    printf("Looking for \"%s\":\"%s\"\n", "Saltyy", ht_search(ht, "Saltyy"));
    printf("Looking for \"%s\":\"%s\"\n", "Vision", ht_search(ht, "NULL"));

    return 0;
}
#ifndef MY_HASH_H
#define MY_HASH_H

#include<uthash.h>

// hash struct
struct hash{
    int id;
    char name[10];
    UT_hash_handle hh;
};

/****************************************************
 * Function name: add
 * Description: insert a hash struct in dict
 * Parameter:
 * @new_id: key for a new hash struct
 * @new_name: name for a new hash struct
 * Return: no
****************************************************/
void add(struct hash **dict, int new_id, char *new_name){
    // using struct hash**, is suggested by the author,
    // because using struct hash* may cause some problems
    struct hash *s;
    HASH_FIND_INT(*dict, &new_id, s);
    // uthash will not do this for you
    if(NULL == s){
        s = malloc(sizeof(struct hash));
        s->id = new_id;
        HASH_ADD_INT(*dict, id, s);
    }
    // if this id exists, just renew its name
    strcpy(s->name, new_name);
}

/****************************************************
 * Function name: find_id
 * Description: find a hash struct via id
 * Parameter:
 * @dict: the dict you want to find from
 * @given_id: the id you want to find
 * Return: the found hash struct
****************************************************/
struct hash* find_id(struct hash **dict, int given_id){
    struct hash *res;
    HASH_FIND_INT(*dict, &given_id, res);
    return res ? res : NULL;
}

/****************************************************
 * Function name: delete_id
 * Description: delete a hash struct from a dict
 * Parameter:
 * @dict: the dict you want to delete from
 * @hh: the hash struct you want to delete
 * Return: the found hash struct
****************************************************/
void delete_id(struct hash **dict, struct hash *hh){
    struct hash *temp;
    HASH_FIND_INT(*dict, &hh->id, temp);
    if(temp){
        printf("%d deleted.\n", hh->id);
        HASH_DEL(*dict, hh);
        free(hh);
    }
}

/****************************************************
 * Function name: delete_all
 * Description: delete all hash struct in a dict
 * Parameter:
 * @dict: the dict you want to clear
 * Return: no
****************************************************/
void delete_all(struct hash **dict){
    struct hash *cur, *temp;
    unsigned int cnt = HASH_COUNT(*dict);

    // method 1:
    // via HASH_ITER macro
    HASH_ITER(hh, *dict, cur, temp){
        printf("%d:\"%s\" deleted.\n", cur->id, cur->name);
        HASH_DEL(*dict, cur);
        free(cur);
    }
    // method 2:
    // this will not free the space, use it carefully
    // via HASH_CLEAR macro
    // HASH_CLEAR(hh, *dict);

    printf("%d hash struct(s) deleted.\n", cnt);
}

/****************************************************
 * Function name: print_hash
 * Description: iter all hash struct in a dict and print key:"value"
 * Parameter:
 * @dict: the dict you want to iter
 * Return: no
****************************************************/
void print_hash(struct hash **dict){
    struct hash *iter;
    // Do not use this iter way to delete hash struct,
    // for it breaks next pointer when you free each of it.
    for(iter = *dict; iter != NULL; iter = iter->hh.next){
        printf("%d:\"%s\"\n", iter->id, iter->name);
    }
}

/****************************************************
 * Function name: by_id
 * Description: a compare function for sorting a dict by id, switch only when a < b
 * Parameter:
 * @a: left hash
 * @b: right hash
 * Return: 1(a>b); 0(a==b); -1(a<b)
****************************************************/
int by_id(struct hash *a, struct hash *b){
    /* compare a to b (cast a and b appropriately)
     * return (int) -1 if (a < b)
     * return (int)  0 if (a == b)
     * return (int)  1 if (a > b)
     */
    return (a->id - b->id);
}
/****************************************************
 * Function name: sort_by_id
 * Description: using by_id() function to sort a dict
 * Parameter:
 * @dict: the dict you want to sort
 * Return: no
****************************************************/
void sort_by_id(struct hash **dict){
    HASH_SORT(*dict, by_id);
}


#endif
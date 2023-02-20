#ifndef UTAU_H
#define UTAU_H

#include <stdio.h>

typedef struct hiragana
{
    char group; // what group the hiragana is in
    char vowel; // the vowel of the hiragana
    int defined;// whether or not the hiragana is defined (used for strLen replacement)
} hira;

struct hiragana sal_new_hiragana(char group, char vowel);
int sal_is_roomaji(char *str);
int sal_hiraLen(struct hiragana *str);
void sal_str_to_hira(char *roomaji, struct hiragana *dest);
FILE *sal_to_mp3(struct hiragana *str);

#endif
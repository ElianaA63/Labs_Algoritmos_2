#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    int longitud=1; //asumo que ya tiene un caracter por '\0'
    for(int i=0;s[i]!='\0';i++)
    {
        longitud ++;
    }
    return longitud;

}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool equivalent=true;
    if(fstring_length(s1) == fstring_length(s2))
    {
        for(unsigned int i = 0u; i < fstring_length(s2) && equivalent; i++)
        {
            if(s1[i] != s2[i])
            {
                equivalent = false;
            }
        }
    }
    else
    {
        equivalent = false;
    }
    return equivalent;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool palabra_igual = true;
    bool palabra_menor = true;
    for(unsigned int i=0u; i< FIXSTRING_MAX; i++)
    {
        if(s1[i] > s2[i] && s1[i] != '\0' && s2[i]!='\0'&&palabra_igual)
        {
            palabra_menor = false;
            palabra_igual = false;
        }
        else if(s1[i] < s2[i] && s1[i] != '\0' && s2[i]!='\0'&&palabra_igual)
        {
            palabra_menor =true;
            palabra_igual =false;
        }
        else if(s1[i] == '\0' && s2[i]!='\0'&&palabra_igual)
        {
            palabra_menor= true;
            palabra_igual= false;
        }
        else if(s2[i]=='\0'&& s1[i] != '\0' &&palabra_igual)
        {
            palabra_menor = false;
            palabra_igual = false;
        }
    }
    return palabra_menor;
}


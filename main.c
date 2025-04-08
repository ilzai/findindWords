#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct mapSymbols{
    char symb;
    char *arr;
}mapSymbols;

mapSymbols map[] = {
    {'q', "qwa"},
    {'w', "wqase"},
    {'e', "ewsdr"},
    {'r', "redft"},
    {'t', "trfgy"},
    {'y', "ytghu"},
    {'u', "uyhji"},
    {'i', "ioujk"},
    {'o', "oipkl"},
    {'p', "pol"},
    {'a', "aqzsw"},
    {'s', "sweadxz"},
    {'d', "derfcxs"},
    {'f', "frtgvcd"},
    {'g', "gtbfhyv"},
    {'h', "hygbnju"},
    {'j', "juhnmki"},
    {'k', "kijmlo"},
    {'l', "lkop"},
    {'z', "zasx"},
    {'x', "xzsdc"},
    {'c', "cxdfv"},
    {'v', "vfcgb"},
    {'b', "bvghn"},
    {'n', "nbhjm"},
    {'m', "mkjn"}
};

int isContains(char *target, char find){
    int i = 0;
    while(target[i] != '\0'){
        if(target[i] == find){
            return 1;
        }
        i++;
    }
    return 0;
}

int isClose(char first, char second){
    int sizeMap = sizeof(map) / sizeof(*map);
    int i = 0;
    while(tolower(first) != map[i].symb){
        i++;
        if(i > sizeMap)
            return 0;
    }
    if(isContains(map[i].arr, tolower(second)))
        return 1;
    else
        return 0;
}

int compare(char *cmpString){
    int i = 0;
    int j = 1;
    if(cmpString[j] == '\0')
        return 1;
    while(cmpString[j] != '\0'){
        if(!isClose(tolower(cmpString[i]), tolower(cmpString[j]))){
            return 0;
        }
        i++; j++;
    }
    return 1;
}

int main(char *argv, int argc){
    char *dictionaryPath = "englishDictionary.txt";
    FILE *dict = fopen(dictionaryPath, "r");
    if(!dict){
        printf("error - can not open dictionary file\n");
    }else{
        int countWords = 0;
        char stringBuf[50];
        memset(&stringBuf, 0, sizeof(stringBuf));
        while(fscanf(dict, "%s", stringBuf) != EOF){
            if(compare(stringBuf)){
                printf("correct string %s\n", stringBuf);
                countWords++;
            }
            memset(&stringBuf, 0, sizeof(stringBuf));
        }
        fclose(dict);
        printf("total words counted: %d\n", countWords);
    }
    return 0;
}
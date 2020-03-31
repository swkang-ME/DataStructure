#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char *name, char *phone)
{
    NameCard * card = malloc(sizeof(NameCard));

    strcpy(card->name, name);
    strcpy(card->phone, phone);

    return card;
}

void ShowNameCardInfo(NameCard * pcard)
{
    printf("이름 : %s\n", pcard->name);
    printf("전화번호 : %s\n",pcard->phone);
}

int NameCompare(NameCard *pcard, char *name)
{
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone)
{

    strcpy(pcard->phone, phone);
}
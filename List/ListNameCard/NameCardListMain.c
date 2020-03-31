#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList.h"



int main()
{
    List list;
    NameCard *pcard;
    NameCard *pcard2;

    ListInit(&list);

    // save the point data
    pcard = MakeNameCard("이진수", "010-1111-2222");
    LInsert(&list, pcard);

    pcard = MakeNameCard("한지영", "010-3242-2345");
    LInsert(&list, pcard);

    pcard = MakeNameCard("조수진", "010-7854-5345");
    LInsert(&list, pcard);
    
    // 한지영 정보를 조회
     printf("현재 데이터의 수: %d \n", LCount(&list));
     if (LFirst(&list, &pcard))
     {
         if (NameCompare(pcard, "한지영") == 0)
            ShowNameCardInfo(pcard);

        while(LNext(&list, &pcard))
        {
            if (NameCompare(pcard, "한지영") == 0)
            {
                ShowNameCardInfo(pcard);
                break;
            }
        }
     }

    // 이진수 정보를 조회하여 전화번호 변경
     if (LFirst(&list, &pcard))
     {  
        if (NameCompare(pcard, "이진수") == 0)
         {  
            pcard2 = pcard;
            printf("\n%p    %p\n\n\n", &pcard, &pcard2);
            ChangePhoneNum(pcard, "010-9999-9999");
         }
         else
         {
            while(LNext(&list, &pcard))
            {
                if (NameCompare(pcard, "이진수") == 0)
                {
                    ChangePhoneNum(pcard, "010-9999-9999");
                    break;
                }
            }
         }
       
     }
     

    // 조수진 정보를 조회하여 삭제
     if (LFirst(&list, &pcard))
     {
         if (NameCompare(pcard, "조수진") == 0)
         {
            pcard = LRemove(&list);
            free(pcard);
         }

        while(LNext(&list, &pcard))
        {
            if (NameCompare(pcard, "조수진") == 0)
            {
                pcard = LRemove(&list);
                free(pcard);
                break;
            }
        }
     }

    // 모든 사람 정보를 출력
     printf("현재 데이터의 수: %d \n", LCount(&list));
     if (LFirst(&list, &pcard))
     {
        ShowNameCardInfo(pcard);

        while(LNext(&list, &pcard))
        {

            ShowNameCardInfo(pcard);

        }
     }

}
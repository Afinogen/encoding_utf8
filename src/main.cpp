/*
 * main.cpp
 *
 *  Created on: 25.03.2013
 *      Author: Afinogen
 */

#include <windows.h>
#include <fstream>

int main()
{
    char InputStr[] =
            "%D0%90%D0%91%D0%92%D0%93%D0%94%D0%95%D0%81%D0%96%D0%97%D0%98%D0%99%D0%9A%D0%9B%D0%9C%D0%9D%D0%9E%D0%9F%D0%A0%D0%A1%D0%A2%D0%A3%D0%A4%D0%A5%D0%A6%D0%A7%D0%A8%D0%A9%D0%AA%D0%AB%D0%AC%D0%AD%D0%AE%D0%AF%D0%B0%D0%B1%D0%B2%D0%B3%D0%B4%D0%B5%D1%91%D0%B6%D0%B7%D0%B8%D0%B9%D0%BA%D0%BB%D0%BC%D0%BD%D0%BE%D0%BF%D1%80%D1%81%D1%82%D1%83%D1%84%D1%85%D1%86%D1%87%D1%88%D1%89%D1%8A%D1%8B%D1%8C%D1%8D%D1%8E%D1%8F";

    int LenRead = 1;

    char sm1[3] = { '\0' };
    char sm2[3] = { '\0' };
    int sm1_num = 0;
    int sm2_num = 0;
    char OutStr[5] = { '\0' };

    std::ofstream f1;
    f1.open("text_utf8.txt");

    while (strlen(InputStr) > LenRead)
    {
        sm1[0] = InputStr[LenRead];
        sm1[1] = InputStr[LenRead + 1];
        sm2[0] = InputStr[LenRead + 3];
        sm2[1] = InputStr[LenRead + 4];

        sscanf(sm1, "%x", &sm1_num);
        sscanf(sm2, "%x", &sm2_num);

        OutStr[0] = sm1_num;
        OutStr[1] = sm2_num;

        f1.write(OutStr, 2);
        LenRead += 6;
    }

    f1.close();
    return 0;
}


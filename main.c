#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 400
#define L 20

#define FILE_IN "input.txt"
#define FILE_OUT "Dettagli.txt"
#define OK 3

#define INIZIO "Abano Terme - Comune controllato: \n"

int confrontaData(int g1, char* m1, int a1, int g2, char* m2, int a2);

int main(int argc, char** argv)
{
    FILE* f = fopen(FILE_IN, "r");
    FILE* gg = fopen(FILE_OUT, "w");

    int giorno; char mese[L]; int anno;
    giorno = atoi(argv[1]);
    strcpy(mese, argv[2]);
    anno = atoi(argv[3]);

    int trovato = 0;
    char line[N];
    while( (fgets(line, N, f)!=NULL) && !trovato )
    {
        int g; char m[L]; int a;
        if (sscanf(line, "%d %s %d", &g, m, &a)==OK)
        {
            if(confrontaData(giorno, mese, anno, g, m, a))
            {
                trovato = 1;
            }
        }
    }

    trovato = 0;
    while( (fgets(line, N, f)!=NULL) && !trovato )
    {
        if(strcmp(line, INIZIO)==0)
        {
            fprintf(gg, "%s", line);
            trovato = 1;
            int fine = 0;
            while( (fgets(line, N, f)!=NULL) && !fine )
            {
                int g; char m[L]; int a;
                if (sscanf(line, "%d %s %d", &g, m, &a)==OK)
                {
                    printf("%d %s %d", g, m, a);
                    fine = 1;
                }
                else
                {
                    fprintf(gg, "%s", line);
                }
            }
        }
    }


    fclose(f);
    fclose(gg);

    return 0;
}


int confrontaData(int g1, char* m1, int a1, int g2, char* m2, int a2)
{
    if(g1==g2)
    {
        if(strcmp(m1, m2)==0)
        {
            if(a1==a2)
            {
                return 1;
            }
        }
    }

    return 0;
}
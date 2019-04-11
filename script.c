#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 400
#define L 20

#define FILE_OUT "out"
#define ESTENSIONE ".txt"

#define PROGRAMMA ".\\post.exe"

void incrementaData(int* g, char* m, int* a);
int annoBisestile(int* anno);

int main(int argc, char** argv)
{
    int giorno; char mese[L]; int anno;
    giorno = atoi(argv[1]);
    strcpy(mese, argv[2]);
    anno = atoi(argv[3]);

    int versione = 1;
    char comando[N];
    int max = atoi(argv[4]);

    while(versione<=max)
    {
        sprintf(comando, "%s %d %s %d %s%d%s", PROGRAMMA, giorno, mese, anno, FILE_OUT, versione, ESTENSIONE);
        system(comando);
        versione++;
        int i;
        for(i=0; i<10; i++)  incrementaData(&giorno, mese, &anno);
        printf("\n");
    }

    return 0;
}

void incrementaData(int* g, char* m, int* a)
{


    if(strcmp(m, "Gennaio")==0)
    {
        if((*g)==31)
        {
            (*g) = 1;
            strcpy(m, "Febbraio");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Febbraio")==0)
    {
        if(annoBisestile(a))
        {
            if((*g)==29)
            {
                (*g) = 1;
                strcpy(m, "Marzo");
                return;
            }
            else
            {
                (*g)++;
                return;
            }
        }
        else
        {
            if((*g)==28)
            {
                (*g) = 1;
                strcpy(m, "Marzo");
                return;
            }
            else
            {
                (*g)++;
                return;
            }
        }
    }

    if(strcmp(m, "Marzo")==0)
    {
        if((*g)==31)
        {
            (*g) = 1;
            strcpy(m, "Aprile");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Aprile")==0)
    {
        if((*g)==30)
        {
            (*g) = 1;
            strcpy(m, "Maggio");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Maggio")==0)
    {
        if((*g)==31)
        {
            (*g) = 1;
            strcpy(m, "Giugno");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Giugno")==0)
    {
        if((*g)==30)
        {
            (*g) = 1;
            strcpy(m, "Luglio");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Luglio")==0)
    {
        if((*g)==31)
        {
            (*g) = 1;
            strcpy(m, "Agosto");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Agosto")==0)
    {
        if((*g)==31)
        {
            (*g) = 1;
            strcpy(m, "Settembre");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Settembre")==0)
    {
        if((*g)==30)
        {
            (*g) = 1;
            strcpy(m, "Ottobre");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Ottobre")==0)
    {
        if((*g)==31)
        {
            (*g) = 1;
            strcpy(m, "Novembre");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Novembre")==0)
    {
        if((*g)==30)
        {
            (*g) = 1;
            strcpy(m, "Dicembre");
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }

    if(strcmp(m, "Dicembre")==0)
    {
        if((*g)==31)
        {
            (*g) = 1;
            strcpy(m, "Gennaio");
            (*a)++;
            return;
        }
        else
        {
            (*g)++;
            return;
        }
    }


}

int annoBisestile(int* anno)
{

    if ((*anno)%100==0)
    {
        if ((*anno)%400==0)
        {
            return 1;
        }
    }
    else
    {
        if ((*anno)%4==0)
        {
            return 1;
        }
    }

    return 0;

}

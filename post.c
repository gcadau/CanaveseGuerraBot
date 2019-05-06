#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 400
#define L 20

#define FILE_IN "input.txt"

#define GIORNI 10
#define LINES 202

#define OK 3

#define DISTANZA 10

#define COMUNE "Comune"

#define A_CAPO '\n'

void elaboraComune(char* line, char* dest);
int confrontaData(int g1, char* m1, int a1, int g2, char* m2, int a2);
void incrementaData(int* g, char* m, int* a);
int annoBisestile(int* anno);

int main(int argc, char** argv)
{
    char FILE_OUT[L];
    strcpy(FILE_OUT, argv[4]);

    char FILE_OUT_BIS[L];
    strcpy(FILE_OUT_BIS, FILE_OUT);
    strcat(FILE_OUT_BIS, ".bis.txt");

    FILE* f = fopen(FILE_IN, "r");
    FILE* gg = fopen(FILE_OUT, "w");
    FILE* h = fopen(FILE_OUT_BIS, "w");

    int giorno; char mese[L]; int anno;
    giorno = atoi(argv[1]);
    strcpy(mese, argv[2]);
    anno = atoi(argv[3]);

    int prec = 0;
    char Prec[N];
    int count = 0;
    char line[N];
    while(fgets(line, N, f)!=NULL)
    {
        if(count<GIORNI)
        {
           int g; char m[L]; int a;
            if (sscanf(line, "%d %s %d", &g, m, &a)==OK)
            {
                if(confrontaData(giorno, mese, anno, g, m, a))
                {
                    fprintf(gg, "%s", line);

                    fgets(line, N, f);
                    char parola[L];
                    sscanf(line, "%s", parola);
                    if(strcmp(parola, COMUNE)!=0)
                    {
                        fprintf(gg, "%s", line);
                        prec = 0;
                    }
                    else
                    {
                        prec = 1;
                        strcpy(Prec, line);
                    }

                    incrementaData(&giorno, mese, &anno);
                    count++;
                }
            }
        }
        else
        {
            int i;
            fprintf(h, "Primi 100 comuni per conquiste.\n");
            int lines = LINES-3;
            if(prec)
            {
                char pars[N];
                elaboraComune(Prec, pars);
                fprintf(h, "\t%s: ", pars);
                lines-=2;
                int m;
                sscanf(line, "%d", &m);
                fprintf(h, "%d\n", m);
            }

            lines/=2;
            for(i=0; i<=lines; i++)
            {
                fprintf(h, "\t");
                if(i!=0 || prec)   fgets(line, N, f);
                char pars[N];
                elaboraComune(line, pars);
                fprintf(h, "%s: ", pars);

                fgets(line, N, f);
                int n;
                sscanf(line, "%d", &n);
                fprintf(h, "%d\n", n);
            }

            fgets(line, N, f);
            fprintf(h, "%s", line);
            break;
        }
    }

    fclose(f);
    fclose(gg);
    fclose(h);

    printf("%d %s %d", giorno, mese, anno);

    return 0;
}

void elaboraComune(char* line, char* dest)
{
    char pars[N];
    int i;

    char* pt = line;
    pt+=DISTANZA;

    i=0;
    while((*pt)!=A_CAPO)
    {
        pars[i] = (*pt);
        pt++;
        i++;
    }

    pars[i] = '\0';

    strcpy(dest, pars);
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

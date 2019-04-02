#ifndef COMUNI_H
#define COMUNI_H

typedef struct comuni_s* Comuni;

int allocaComuni(Comuni *comuni);
void stampaComuni(Comuni comuni);
void calcolaDistanze(Comuni comuni);
void conquista(Comuni comuni);
void insorgi(Comuni comuni);
void liberaComuni(Comuni comuni);

#endif //COMUNI_H

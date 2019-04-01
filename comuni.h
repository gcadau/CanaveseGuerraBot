#ifndef COMUNI_H
#define COMUNI_H

typedef struct comuni_s* Comuni;

int leggiComuni(Comuni* comuni);
void stampaComuni(Comuni comuni);
void calcolaDistanze(Comuni comuni);

#endif //COMUNI_H

#ifndef ANNO_H
#define ANNO_H

typedef struct anno_s* Anno;

void setAnno(Anno* anno, int a);
void stampaAnno(Anno anno);
void incrementaAnno(Anno anno);
int annoBisestile(Anno anno);
void liberaAnno(Anno anno);

#endif //ANNO_H

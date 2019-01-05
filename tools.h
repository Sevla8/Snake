#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include "list.h"

char* inttostr(int);
int strlength(char*);
int strtoint(char*);
S_list* ajout_tete(S_list*, S_coord);
S_list* supprimer_dernier(S_list*);
S_list* supprimer_premier(S_list* head);

#endif
#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include "list.h"

char* inttostr(int);
S_list* ajout_tete(S_list*, S_coord);
S_list* supprimer_dernier(S_list*);

#endif
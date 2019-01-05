#include "tools.h"

char* inttostr(int nb){
	if (nb == 0){
		char* tab = (char*) malloc(sizeof(char) * 2);
		tab[0] = '0'; tab[1] = '\0';
		return tab;
	}
	int cp = nb;
	int l = 0;
	while (cp != 0){
		cp = cp / 10;
		l = l+1;
	}
	cp = nb;
	char* tab = (char*) malloc(sizeof(char) * (l + 1));
	for (int i = 0; i < l; i = i+1){
		tab[l-1-i] = cp % 10 + 48;
		cp = cp / 10;
	}
	tab[l] = '\0';
	return tab;
}

int strlength(char* str){
	int taille = 0;
	for(int i = 0; str[i] != '\0'; i = i+1){
		taille = taille+1;
	}
	return taille;
}

int strtoint(char* str){
	if (strlength(str) != 0 && str[0] >= '0' && str[0] <= '9') {
		int x = 0;
		for (int i = 0; str[i] >= '0' && str[i] <= '9' && i < strlength(str); i = i+1){
			x = x * 10 + (str[i]-48);
		}
		return x;
	}
	return 0;
}

S_list* ajout_tete(S_list* head, S_coord coord) {
	S_list* new = (S_list*) malloc(sizeof(S_list));
	new->coord.x = coord.x;
	new->coord.y = coord.y;
	new->next = head;
	new->prev = NULL;
	if (head != NULL) {
		head->prev = new;
	}
	return new;
}

S_list* supprimer_dernier(S_list* head) {
	if (head != NULL) {
		S_list* cur;
		for (cur = head; cur->next != NULL; cur = cur->next) {}
		S_list* tmp = cur->prev;
		if (tmp != NULL) {
			tmp->next = NULL;
			free(cur);
			return head;
		}
	}
	return NULL;
}

S_list* supprimer_premier(S_list* head) {
	if (head != NULL) {
		S_list* tmp = head->next;
		if (tmp != NULL) {
			tmp->prev = NULL;
			free(head);
			return tmp;
		}
	}
	return NULL;
}
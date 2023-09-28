#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct pilha {
	char elementos[MAX];
	int topo;
};

struct pilha * cria (void) {
	struct pilha *p;
	p = malloc(sizeof(struct pilha));
	if(!p) {
		perror(NULL);
		exit(1);
	}
	
	p->topo = 0;
	return p;
};

void empilha(struct pilha *p, char Numero) {
	p->elementos[p->topo] = Numero;
	p->topo = p->topo+1;
};

char desempilha(struct pilha *p) {
	p->topo = p->topo-1;
	return p->elementos[p->topo];
};

int main() {
	
	struct pilha * minhaPilha = cria();
	
	
	char expressao[20];
	int i, prod, soma, sub;
	float div, resultado, valor, resto;
	char operador, x, y;

	
	printf("Digite uma expressao (sem parenteses): ");
	fgets(expressao, sizeof(expressao), stdin);
	
	
	for (i=0; i<strlen(expressao); i++) {
	
		if(isdigit(expressao[i])) {
			empilha(minhaPilha, expressao[i]);
	
		} else {
			switch (expressao[i]) {
				case '+':
					empilha(minhaPilha, expressao[i]);
					break;
				case '-':
					empilha(minhaPilha, expressao[i]);
					break;
				case '*':
					
					x = desempilha(minhaPilha) - '0';
					y = expressao[i+1] - '0';
					
					prod = x*y;
					valor = prod;
					empilha(minhaPilha, valor + '0');
					
					
					i++;	
					
					
					break;
					
				case '/':
					x = desempilha(minhaPilha) - '0';
					y = expressao[i+1] - '0';
					
					
					div = (float)x/y;
					valor = div;
					
					resto = (div - floor(div))+resto;
					
					
					empilha(minhaPilha, valor + '0');
					
					
					i++;	
					
					
					break;
			}
		}	
	}
	
	
	
	for (i=0; i < minhaPilha->topo; i++) {
		x = desempilha(minhaPilha) - '0';
		operador = desempilha(minhaPilha);
		y = desempilha(minhaPilha) - '0';
		
		
		
		if (operador == '-') {
			sub = y-x;
			valor = sub;
			empilha(minhaPilha, valor + '0');
		} else if (operador == '+') {
			soma = y + x;
			valor = soma;
			
			
			empilha(minhaPilha, valor + '0');
			
		}
	}	
	
	printf("%f\n", ((float)desempilha(minhaPilha) - '0')+resto);
	return 0;
	
}

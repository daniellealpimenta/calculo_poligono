#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float X;
	float Y;
} Ponto;

float areaTriangulo(Ponto A, Ponto B, Ponto C) {
//essa função é responsável por calcular a area do triangulo, individualmente, ele pede por três parâmetros, todos os 3 são variaveis da struct Ponto

	
	float determinante = {(A.X * B.Y + A.Y * C.X + B.X * C.Y) - (C.X * B.Y + A.Y * B.X + A.X * C.Y)};
	
	if (determinante < 0) return - determinante / 2;
	else return determinante / 2;

	
}

float calcular_poligono(Ponto pontos[], int vertices) {
//essa função é responsável por calcular a area total do poligono, pedindo por dois parâmetros, os pontos do arquivo, e o número de vertices

	float area_total = 0;
	
//ela toma por ponto principal (de onde as retas vão sair para formar os triangulos) o ponto[0].x e ponto[0].y, que no caso, seria o ponto A
	Ponto ponto_principal = pontos[0];
	
//após isso temos uma estrutura de repetição, para calcular as áreas de todos os triangulos, em todos os polígono o numero de triangulos formados
//será igual a o número de vértices - 2, por isso ela se repete esse numero de vezes, começando a partir do 1, pois o ponto [0] já é o ponto principal
	for (int i = 1; i <= vertices - 2; i++) {
//		aqui é passada para a função "area_triangulo" os parâmetros, que são o ponto principal, ou ponto A(x,y), o ponto 1 ou B, e o ponto 2 ou C, e assim por diante.
        float area_triangulo = areaTriangulo(ponto_principal, pontos[i], pontos[i + 1]);
        area_total += area_triangulo;
    }
    return area_total;
	
	
	
};
	
	
int main(){
//	já no arquivo principal, é onde o arquivo dos polígonos é aberto, e é quando as informações são lidas e guardadas nas suas respectivas variáveis
	
	FILE *arquivo;
	int vertices;
	
	arquivo = fopen("poligono.txt", "r");
	
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
	} 
	
	fscanf(arquivo, "%d", &vertices);
	
//	Tratamento de erro, caso o usuário insira 2 vertices ou menos para o calculo do poligono
	if (vertices <= 2){
		printf("Quantidade de vertices insuficientes para a formacao de um poligono!\n");
	};
	
	Ponto pontos[vertices];
	
	for(int i = 0; i < vertices; i++){
		fscanf(arquivo, "%f %f", &pontos[i].X, &pontos[i].Y);
		
	};
	
	fclose(arquivo);
	
	float area;
	
//	aqui é quando a função "area_poligono" é chamada, e seus parâmetros são passados, no caso os pontos, e o número de vertices
	area = calcular_poligono(pontos, vertices);
	
	printf("A area do poligono: %.2f\n", area);

	
};


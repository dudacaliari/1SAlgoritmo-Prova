#include <stdio.h>

//Definição de constantes
#define COEF1 10
#define COEF2 15
#define COEF3 12


#define IMP_SB1 5 
#define IMP_SB2 3 
#define IMP_SB3 6
#define IMP_SB4 4

void main()
{
	float salario_min, horas_trab, coef_salario, salario_bruto, imposto_sb, auxilio_alim, salario_liq;
	int gratificacao;
	char turno, categoria;
	
//Pergunta Salario minimo
 printf("Qual o valor do seu salario? (em R$): \n");
 scanf("%f", &salario_min);
 
//Pergunta Salario minimo
 printf("Qual o seu numero de horas trabalhadas?: \n");
 scanf("%f", &horas_trab);

//Pergunta Categoria
 printf("Em qual turno voce trabalha? (N-noturno, M-matutino ou V-vespentino): \n");
 scanf(" %c", &turno); 
 
//Pergunta categoria
 printf("Em qual categoria voce trabalha? (O-operario, G-gerente): \n");
 scanf(" %c", &categoria);

 
//Cálculo Coeficiente do salario
if(turno == 'M')
 {
 	coef_salario= (salario_min*COEF1)/100;
 }
else if (turno == 'V')
 {
    coef_salario= (salario_min*COEF2)/100;
 }
else
 {
 	coef_salario= (salario_min*COEF3)/100;
 }

//Cálculo Salario bruto
 salario_bruto= horas_trab*coef_salario;

//Cálculo Imposto
if(categoria == 'O' && salario_bruto >= 3000)
 {
 	imposto_sb= ((salario_bruto*IMP_SB1)/100);
 }
else if (categoria == 'O' && salario_bruto < 3000)
 {
    imposto_sb= ((salario_bruto*IMP_SB2)/100);
 }
else if (categoria == 'G' && salario_bruto >= 4000)
 {
    imposto_sb= ((salario_bruto*IMP_SB3)/100);
 }
else
 {
 	imposto_sb= ((salario_bruto*IMP_SB4)/100);
 }

//Cálculo Gratificação
if(turno == 'N' && horas_trab > 80)
 {
 	gratificacao= 500;
 }
else 
 {
 	gratificacao= 300;
 }

//Cálculo Auxilio alimentação
if(categoria == 'O' || coef_salario <= 140)
 {
 	auxilio_alim= salario_bruto/3;
 }
else 
 {
 	auxilio_alim= salario_bruto/2;
 }

//Cálculo salario liquido
salario_liq= (salario_bruto-imposto_sb)+gratificacao+auxilio_alim;

//Classificação
if (salario_liq < 3500)
{
	printf("Voce eh Mal Remunerado.\n");
}
else if (salario_liq >= 3500 && salario_liq <= 6000)
{
	 printf("Voce eh Normalmente Remunerado.\n");
}
else 
  printf("Voce eh Bem Remunerado.\n");

}

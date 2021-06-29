let a = 10;
// a = "2";

/*
a) Não compila, pois quando a declaração a = 10 acontece, o Typecript
entende que a variável a é um number . Quando se declara a = "2" , está
tentando atribuir uma string e não um number .
*/


let b: any = 10;
b = 2;

/*
b) É compilado, pois o tipo any indica que a variável b pode receber qualquer
tipagem
*/


let c: number = 10;
c = 2;

/*
c) É compilado. Porque a tipagem é `number` e o valores atribuídos a `c`
são do tipo `number`.
*/

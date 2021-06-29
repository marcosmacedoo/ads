const numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];

const numeroEhPar = (numero: number) => numero % 2 === 0;

const numerosPares = numeros.filter((numero) => numeroEhPar(numero));

console.log(numerosPares);

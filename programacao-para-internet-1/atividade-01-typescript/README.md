# Atividade 01 de Typescript

1. a) Não compila, pois quando a declaração `a = 10` acontece, o Typecript entende que a variável `a` é um `number` . Quando se declara `a = "2"` , está tentando atribuir uma `string` e não um `number`.

    ```tsx
    let a = 10;
    a = "2";
    ```

    b) É compilado pois o tipo `any` indica que a variável `b` pode receber qualquer tipagem.

    ```tsx
    let b: any = 10;
    b = 2;
    ```

    c) É compilado. Porque a tipagem é `number` e o valores atribuídos a `c` são do tipo `number`.

    ```tsx
    let c: number = 10;
    c = 2;
    ```

---

2.  a) 

```tsx
function soma(x: number, y?: any): number {
  return x + y
}

console.log(soma(1, 2))

// 3
```

b)

```tsx
function soma(x: number, y?: any): number {
  return x + y
}

console.log(soma(1, '2'))

// 12
```

c)

```tsx
function soma(x: number, y?: any): number {
  return x + y
}

console.log(soma(1))

// NaN
```

---

3. a)

```tsx
enum Estados {
  PI = "PI",
  MA = "MA",
  CE = "CE"
}

for (let estado in Estados) {
  console.log(estado)
}
```

b)

```tsx
enum Estados {
  PI = "PI",
  MA = "MA",
  CE = "CE"
}

for (let i = 0; i < 3; i++) {
  console.log(Estados[i])
}

// undefined
```

---

4. 

```tsx
enum DiasDaSemanaEnum {
  Dom = "Domingo",
  Seg = "Segunda",
  Ter = "Terça",
  Qua = "Quarta",
  Qui = "Quinta",
  Sex = "Sexta",
  Sab = "Sábado"
}

namespace DiasDaSemana {
  export function isDiaUtil(diaDaSemana: string) {
    if (diaDaSemana === 'Sábado' || diaDaSemana === 'Domingo') {
      return false
    }

    return true
  }
}

const diasDaSemana = DiasDaSemanaEnum

const resultado = DiasDaSemana.isDiaUtil(diasDaSemana.Dom)

console.log(resultado)

// false
```

---

5. 

```tsx
function exibir(...values: string[]) {
  console.log(values)
}

exibir("Marcos")
exibir("Marcos", "Macedo")
exibir("Marcos", "Macedo", "de")
exibir("Marcos", "Macedo", "de", "Menezes")

/*
["Marcos"]
["Marcos", "Macedo"]
["Marcos", "Macedo", "de"]
["Marcos", "Macedo", "de", "Menezes"]
*/
```

---

6. 

```tsx
const ola = () => console.log("Olá")

ola()

// Olá
```

---

7.

```tsx
const numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];

const numeroEhPar = (numero: number) => numero % 2 === 0;

const numerosPares = numeros.filter((numero) => numeroEhPar(numero));

console.log(numerosPares);
// [2, 4, 6, 8, 10, 12, 14]
```

---

8. 

```tsx
class MeuNumero {
  private _numero: number

  constructor(numero: number) {
    this._numero = numero
  }

  getInteiro() {
    return Math.floor(this._numero)
  }

  getDecimal() {
    return Number(Math.fround(this._numero % 1).toFixed(2))
  }
}

const meuNumero = new MeuNumero(6.892)

console.log(meuNumero.getDecimal())
console.log(meuNumero.getInteiro())

// 0.89
// 6
```

---

9.

```tsx
class Transacao {
  private _valor: number
  private _desconto: number

  constructor(valor: number, desconto: number) {
    this._desconto = desconto
    this._valor = valor
  }

  get valor() : number {
    return this._valor
  }

  get desconto() : number {
    return this._desconto
  }

  calculaDesconto() {
    return this._valor - (this._valor * this._desconto)
  }
}

const transacao = new Transacao(10, 0.25)

console.log(transacao.calculaDesconto())
console.log(transacao.desconto)
console.log(transacao.valor)

// 7.5
// 0.25
// 10
```

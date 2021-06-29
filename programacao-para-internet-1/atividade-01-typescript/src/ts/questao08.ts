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

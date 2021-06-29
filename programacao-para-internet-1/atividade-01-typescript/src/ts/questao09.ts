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

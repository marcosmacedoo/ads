class Transacao {
    _valor;
    _desconto;
    constructor(valor, desconto) {
        this._desconto = desconto;
        this._valor = valor;
    }
    get valor() {
        return this._valor;
    }
    get desconto() {
        return this._desconto;
    }
    calculaDesconto() {
        return this._valor - (this._valor * this._desconto);
    }
}
const transacao = new Transacao(10, 0.25);
console.log(transacao.calculaDesconto());
console.log(transacao.desconto);
console.log(transacao.valor);
//# sourceMappingURL=questao09.js.map
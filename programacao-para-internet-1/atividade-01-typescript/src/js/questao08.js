class MeuNumero {
    _numero;
    constructor(numero) {
        this._numero = numero;
    }
    getInteiro() {
        return Math.floor(this._numero);
    }
    getDecimal() {
        return Number(Math.fround(this._numero % 1).toFixed(2));
    }
}
const meuNumero = new MeuNumero(6.892);
console.log(meuNumero.getDecimal());
console.log(meuNumero.getInteiro());
//# sourceMappingURL=questao08.js.map
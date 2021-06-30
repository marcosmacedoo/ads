interface Iteravel<T> {
  proximo: () => T;
  atual: (element: T) => T;
  ehPrimeiro: () => boolean;
  ehUltimo: () => boolean;
  irParaPrimeiro: () => T[];
}

class ColecaoArray<T> implements Iteravel<T> {
  private _colecao: T[] = [];
  private _elementoAtual: T;

  adicionarNovoElemento(novoElemento: T) {
    this._colecao.push(novoElemento);
    return this._colecao
  }

  get colecao(): T[] {
    return this._colecao
  }

  atual(elemento: T) {
    this._elementoAtual = elemento;
    return this._elementoAtual;
  }

  ehPrimeiro() {
    const primeiroElemento = this._colecao[0];

    return primeiroElemento === this._elementoAtual ? true : false;
  }

  ehUltimo() {
    const ultimoElemento = this._colecao[this._colecao.length - 1];

    return ultimoElemento === this._elementoAtual ? true : false;
  }

  irParaPrimeiro() {
    const colecaoSemOElementoAtual = this._colecao.filter(
      (elemento) => elemento !== this._elementoAtual
    );

    const colecaoComElementoAtualNoInicio = [
      this._elementoAtual,
      ...colecaoSemOElementoAtual,
    ];

    this._colecao = colecaoComElementoAtualNoInicio;

    return this._colecao;
  }

  proximo() {
    if (this.ehUltimo()) {
      console.warn("O elemento atual é o último da coleção, então não existe próximo elemento.")
      return undefined
    }

    const posicaoDoElementoAtual = this._colecao.findIndex(
      (elemento) => elemento === this._elementoAtual
    );

    if (posicaoDoElementoAtual === -1) {
      throw new Error("Elemento inexistente na coleção");
    }

    return this._colecao[posicaoDoElementoAtual];
  }
}

const colecao = new ColecaoArray<number>()

colecao.adicionarNovoElemento(1)
colecao.adicionarNovoElemento(2)
colecao.adicionarNovoElemento(3)

console.log(colecao.colecao)
console.log(colecao.atual(3))
console.log(colecao.ehPrimeiro())
console.log(colecao.ehUltimo())
console.log(colecao.proximo())
console.log(colecao.irParaPrimeiro())
console.log(colecao.ehPrimeiro())


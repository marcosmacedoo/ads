const DEFAULT_MAXIMO_ENERGIA = 100;
const DEFAULT_MINIMO_ENERGIA = 0;
class Personagem {
    constructor(id, name) {
        this._id = id;
        this._name = name;
        this._energia = DEFAULT_MAXIMO_ENERGIA;
    }
    estaVivo() {
        return this._energia > DEFAULT_MINIMO_ENERGIA ? true : false;
    }
    defenderAtaque(valorDoAtaque) {
        if (valorDoAtaque > this._energia) {
            this._energia = DEFAULT_MINIMO_ENERGIA;
        }
        else {
            this._energia -= valorDoAtaque;
        }
    }
}
class Soldado extends Personagem {
    constructor(id, name, forcaDeAtaque) {
        super(id, name);
        this._forcaDeAtaque = forcaDeAtaque;
    }
    defenderAtaque(valorDoAtaque) {
        const metadeDoValorDoAtaque = valorDoAtaque / 2;
        if (metadeDoValorDoAtaque > this._energia) {
            this._energia = DEFAULT_MINIMO_ENERGIA;
        }
        else {
            this._energia -= metadeDoValorDoAtaque;
        }
    }
    atacar(personagem) {
        personagem.defenderAtaque(this._forcaDeAtaque);
    }
    imprimirDados() {
        console.log(`Soldado {
      id: ${this._id}
      name: ${this._name}
      forcaDeAtaque: ${this._forcaDeAtaque}
      energia: ${this._energia}
    }`);
    }
}
class Cavaleiro extends Soldado {
    constructor(id, name, forcaDeAtaque) {
        super(id, name, forcaDeAtaque);
    }
    atacar(personagem) {
        const valorDoAtaque = this._forcaDeAtaque * 2;
        personagem.defenderAtaque(valorDoAtaque);
    }
    defenderAtaque(valorDoAtaque) {
        const valorDoAtaqueComResistencia = valorDoAtaque / 3;
        if (valorDoAtaqueComResistencia > this._energia) {
            this._energia = DEFAULT_MINIMO_ENERGIA;
        }
        else {
            this._energia -= valorDoAtaqueComResistencia;
        }
    }
}
class Jogo {
    constructor() {
        this._jogadores = [];
    }
    incluir(personagem) {
        const personagemConsultado = this.consultar(personagem._id);
        if (!personagemConsultado) {
            this._jogadores.push(personagem);
        }
        else {
            console.warn("Personagem possui id já existente");
        }
    }
    consultar(idDoPersonagem) {
        const [personagemFiltrado] = this._jogadores.filter((personagem) => personagem._id === idDoPersonagem);
        return personagemFiltrado;
    }
    atacar(idDoPrimeiroPersonagem, idDoSegundoPersonagem) {
        const primeiroPersonagem = this.consultar(idDoPrimeiroPersonagem);
        const segundoPersonagem = this.consultar(idDoSegundoPersonagem);
        if (primeiroPersonagem === undefined || segundoPersonagem === undefined) {
            throw new Error("Personagem não encontrado através do id");
        }
        if (primeiroPersonagem instanceof Soldado ||
            primeiroPersonagem instanceof Cavaleiro) {
            primeiroPersonagem.atacar(segundoPersonagem);
        }
        else {
            console.warn('Um Personagem não possui poder para atacar');
        }
    }
    exibirPersonagens() {
        console.table(this._jogadores);
    }
}
const jogo = new Jogo();
const personagem = new Personagem(1, "Marcos");
const soldado1 = new Soldado(2, "Luís", 10);
const soldado2 = new Soldado(3, "Tiago", 8);
const cavaleiro = new Cavaleiro(4, "Hilton", 9);
jogo.incluir(personagem);
jogo.incluir(soldado1);
jogo.incluir(soldado2);
jogo.incluir(cavaleiro);
jogo.exibirPersonagens();
jogo.atacar(2, 1);
jogo.exibirPersonagens();
jogo.atacar(2, 1);
jogo.exibirPersonagens();
//# sourceMappingURL=questao02.js.map
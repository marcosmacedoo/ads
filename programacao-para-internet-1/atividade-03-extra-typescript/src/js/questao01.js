class Questao01 {
    constructor(mediaDeCasosHa14Dias, mediaDeCasosHoje) {
        this._mediaDeCasosHa14Dias = mediaDeCasosHa14Dias;
        this._mediaDeCasosHoje = mediaDeCasosHoje;
    }
    get variacaoDaMediaDeCasos() {
        return this._variacaoDaMediaDeCasos;
    }
    set variacaoDaMediaDeCasos(variacao) {
        this._variacaoDaMediaDeCasos = variacao;
    }
    get classificacaoDaVariacao() {
        return this._classificacaoDaVariacao;
    }
    set classificacaoDaVariacao(classificacao) {
        this._classificacaoDaVariacao = classificacao;
    }
    set mediaDeCasosHoje(media) {
        this._mediaDeCasosHoje = media;
    }
    get mediaDeCasosHoje() {
        return this._mediaDeCasosHoje;
    }
    set mediaDeCasosHa14Dias(media) {
        this._mediaDeCasosHa14Dias = media;
    }
    get mediaDeCasosHa14Dias() {
        return this._mediaDeCasosHa14Dias;
    }
    calculaVariacaoDaMediaDeCasos() {
        this.variacaoDaMediaDeCasos =
            ((this.mediaDeCasosHoje - this.mediaDeCasosHa14Dias) /
                this.mediaDeCasosHa14Dias) *
                100;
    }
    defineClassificacaoDaVariacaoDaMediaDeCasos() {
        this.classificacaoDaVariacao = "Em alta";
        if (this.variacaoDaMediaDeCasos < 0) {
            this.classificacaoDaVariacao = "Em queda";
        }
        else if (this.variacaoDaMediaDeCasos <= 15) {
            this.classificacaoDaVariacao = "Em estabilidade";
        }
    }
}
const $formQuestao01 = document.querySelector("#form-questao01");
const $inputMediaDeCasosHa14Dias = document.querySelector("#media-de-casos-ha-14-dias");
const $inputMediaDeCasosHoje = document.querySelector("#media-de-casos-hoje");
$formQuestao01.addEventListener("submit", (event) => {
    event.preventDefault();
    const mediaDeCasosHa14Dias = Number($inputMediaDeCasosHa14Dias.value) || 0;
    const mediaDeCasosHoje = Number($inputMediaDeCasosHoje.value) || 0;
    const questao01 = new Questao01(mediaDeCasosHa14Dias, mediaDeCasosHoje);
    questao01.calculaVariacaoDaMediaDeCasos();
    questao01.defineClassificacaoDaVariacaoDaMediaDeCasos();
    alert(`${questao01.variacaoDaMediaDeCasos.toFixed(2)} - ${questao01.classificacaoDaVariacao}`);
    $inputMediaDeCasosHa14Dias.value = "0";
    $inputMediaDeCasosHoje.value = "0";
});
//# sourceMappingURL=questao01.js.map
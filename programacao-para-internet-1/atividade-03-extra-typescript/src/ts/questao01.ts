class Questao01 {
  private _mediaDeCasosHa14Dias: number;
  private _mediaDeCasosHoje: number;
  private _variacaoDaMediaDeCasos: number;
  private _classificacaoDaVariacao: string;

  constructor(mediaDeCasosHa14Dias: number, mediaDeCasosHoje: number) {
    this._mediaDeCasosHa14Dias = mediaDeCasosHa14Dias;
    this._mediaDeCasosHoje = mediaDeCasosHoje;
  }

  get variacaoDaMediaDeCasos(): number {
    return this._variacaoDaMediaDeCasos;
  }

  set variacaoDaMediaDeCasos(variacao: number) {
    this._variacaoDaMediaDeCasos = variacao;
  }

  get classificacaoDaVariacao(): string {
    return this._classificacaoDaVariacao;
  }

  set classificacaoDaVariacao(classificacao: string) {
    this._classificacaoDaVariacao = classificacao;
  }

  set mediaDeCasosHoje(media: number) {
    this._mediaDeCasosHoje = media;
  }

  get mediaDeCasosHoje() {
    return this._mediaDeCasosHoje;
  }

  set mediaDeCasosHa14Dias(media: number) {
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
    } else if (this.variacaoDaMediaDeCasos <= 15) {
      this.classificacaoDaVariacao = "Em estabilidade";
    }
  }
}

const $formQuestao01 = document.querySelector<HTMLFormElement>("#form-questao01");
const $inputMediaDeCasosHa14Dias = document.querySelector<HTMLInputElement>(
  "#media-de-casos-ha-14-dias"
);
const $inputMediaDeCasosHoje = document.querySelector<HTMLInputElement>(
  "#media-de-casos-hoje"
);

$formQuestao01.addEventListener("submit", (event) => {
  event.preventDefault();

  const mediaDeCasosHa14Dias = Number($inputMediaDeCasosHa14Dias.value) || 0;
  const mediaDeCasosHoje = Number($inputMediaDeCasosHoje.value) || 0;

  const questao01 = new Questao01(mediaDeCasosHa14Dias, mediaDeCasosHoje)

  questao01.calculaVariacaoDaMediaDeCasos()
  questao01.defineClassificacaoDaVariacaoDaMediaDeCasos()

  alert(
    `${questao01.variacaoDaMediaDeCasos.toFixed(
      2
    )} - ${questao01.classificacaoDaVariacao}`
  );

  $inputMediaDeCasosHa14Dias.value = "0";
  $inputMediaDeCasosHoje.value = "0";
});

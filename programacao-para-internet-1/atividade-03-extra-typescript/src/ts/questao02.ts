class Funcionario {
  private _nome: string;
  private _valorTotalDeVendasNoMes: number;
  private readonly _salarioFixo: number;
  private _salarioComComissao: number;

  constructor(nome: string, valorTotalDeVendasNoMes: number) {
    this._nome = nome;
    this._valorTotalDeVendasNoMes = valorTotalDeVendasNoMes;
    this._salarioFixo = 1100.0;
    this._salarioComComissao = this._salarioFixo;
  }

  get salarioFixo() {
    return this._salarioFixo;
  }

  set salarioComComissao(salarioComComissao: number) {
    this._salarioComComissao = salarioComComissao;
  }

  get salarioComComissao() {
    return this._salarioComComissao;
  }

  set nome(nome: string) {
    this._nome = nome;
  }

  get nome() {
    return this._nome;
  }

  set valorTotalDeVendasNoMes(valorTotalDeVendasNoMes: number) {
    this._valorTotalDeVendasNoMes = valorTotalDeVendasNoMes;
  }

  get valorTotalDeVendasNoMes() {
    return this._valorTotalDeVendasNoMes;
  }

  calculaSalarioComComissao() {
    if (
      this.valorTotalDeVendasNoMes >= 5000 &&
      this.valorTotalDeVendasNoMes < 10000
    ) {
      this.salarioComComissao += this.valorTotalDeVendasNoMes * 0.05;
    } else if (
      this.valorTotalDeVendasNoMes >= 10000 &&
      this.valorTotalDeVendasNoMes < 30000
    ) {
      this.salarioComComissao += this.valorTotalDeVendasNoMes * 0.1;
    } else if (this.valorTotalDeVendasNoMes > 30000) {
      this.salarioComComissao += this.valorTotalDeVendasNoMes * 0.2;
    }
  }

  mostraDadosDoFuncionario() {
    alert(
      `O funcionário(a) ${
        this.nome
      } vendeu no mês R$${this.valorTotalDeVendasNoMes.toFixed(
        2
      )} e então seu salário bruto é de R$${this.salarioComComissao.toFixed(2)}`
    );
  }
}

const $inputNomeDoFuncionario = document.querySelector<HTMLInputElement>(
  "#nome-do-funcionario"
);
const $inputValorTotalDeVendasNoMes = document.querySelector<HTMLInputElement>(
  "#valor-total-de-vendas-mes"
);
const $formQuestao02 =
  document.querySelector<HTMLFormElement>("#form-questao02");

$formQuestao02.addEventListener("submit", (event) => {
  event.preventDefault();

  const nomeDoFuncionario = $inputNomeDoFuncionario.value;
  const valorTotalDeVendasNoMes = Number($inputValorTotalDeVendasNoMes.value);

  const funcionario = new Funcionario(
    nomeDoFuncionario,
    valorTotalDeVendasNoMes
  );

  funcionario.calculaSalarioComComissao();
  funcionario.mostraDadosDoFuncionario();
});

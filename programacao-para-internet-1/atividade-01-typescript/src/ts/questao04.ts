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

var DiasDaSemanaEnum;
(function (DiasDaSemanaEnum) {
    DiasDaSemanaEnum["Dom"] = "Domingo";
    DiasDaSemanaEnum["Seg"] = "Segunda";
    DiasDaSemanaEnum["Ter"] = "Ter\u00E7a";
    DiasDaSemanaEnum["Qua"] = "Quarta";
    DiasDaSemanaEnum["Qui"] = "Quinta";
    DiasDaSemanaEnum["Sex"] = "Sexta";
    DiasDaSemanaEnum["Sab"] = "S\u00E1bado";
})(DiasDaSemanaEnum || (DiasDaSemanaEnum = {}));
var DiasDaSemana;
(function (DiasDaSemana) {
    function isDiaUtil(diaDaSemana) {
        if (diaDaSemana === 'Sábado' || diaDaSemana === 'Domingo') {
            return false;
        }
        return true;
    }
    DiasDaSemana.isDiaUtil = isDiaUtil;
})(DiasDaSemana || (DiasDaSemana = {}));
const diasDaSemana = DiasDaSemanaEnum;
const resultado = DiasDaSemana.isDiaUtil(diasDaSemana.Dom);
console.log(resultado);
//# sourceMappingURL=questao04.js.map
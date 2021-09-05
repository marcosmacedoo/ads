const linkTarefas = document.querySelector("#link-tarefas");
const linkGrupos = document.querySelector("#link-grupos");
const linkAlunos = document.querySelector("#link-alunos");
const linkImportar = document.querySelector("#link-importar");
const linkSorteio = document.querySelector("#link-sorteio");
const linkEventos = document.querySelector("#link-eventos");
const rotaAtual = window.location.pathname;

if (rotaAtual.indexOf("tarefa") != -1 || rotaAtual == "/") {
  linkTarefas.style = "background: #252526;";
} else {
  linkTarefas.style = "background: hidden;";
}

if (rotaAtual.indexOf("grupo") != -1) {
  linkGrupos.style = "background: #252526;";
} else {
  linkGrupos.style = "background: hidden;";
}

if (rotaAtual.indexOf("aluno") != -1) {
  linkAlunos.style = "background: #252526;";
} else {
  linkAlunos.style = "background: hidden;";
}

if (rotaAtual.indexOf("importar") != -1) {
  linkImportar.style = "background: #252526;";
} else {
  linkImportar.style = "background: hidden;";
}

if (rotaAtual.indexOf("sorteio") != -1) {
  linkSorteio.style = "background: #252526;";
} else {
  linkSorteio.style = "background: hidden;";
}

if (rotaAtual.indexOf("evento") != -1) {
  linkEventos.style = "background: #252526;";
} else {
  linkEventos.style = "background: hidden;";
}

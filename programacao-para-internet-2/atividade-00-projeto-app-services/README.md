# App Services
É uma aplicação para cadastro e acompanhamento de serviços (jobs) prestados.


## Requisitos 
- [ ] Arquitetura Rest
- [ ] Arquitetura Clean DDD no Backend
- [ ] Banco de Dados: Firebase ou MongoDB
- [ ] HTML, CSS e JavaScript


## Histórias de Usuário
- Eu como usuário desejo cadastrar um serviço;
- Eu como usuário desejo alterar o serviço;
- Eu como usuário desejo alterar o status do serviço para Conluído ou Cancelado;
- Eu como usuário desejo comentar em um serviço


## Regras de Negócio
- O serviço possui um status: Aberto, Concluído e Cancelado;
- O serviço poderá receber comentários enquanto estiver com o status Aberto;
 

## Entidades

### Serviço
| Atributo  | Tipo   |
| :-------  | :----- |
| id        | string | 
| title    | string | 
| description | string | 
| budget | number | 
| status    | string |
| created_at | date |
| updated_at | date |
| deadline | date |
| comments | string[ ] |









- Listagem de Serviços: Finalizados e Em andamento (Tabs)
- Filtragem de serviços por título
- Modal: Cadastrar novo serviço
- Mostrar detalhes de um serviço
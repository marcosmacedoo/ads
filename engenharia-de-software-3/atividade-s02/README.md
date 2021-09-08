# Atividade - S02

## Objetivo da Atividade

Deve-se escolher um código antigo (ou aberto) e alterar trechos de código seguindo os princípios de Coesão, Encapsulamento e Acoplamento

## Vídeo de Apresentação

[![Vídeo de Apresentação](https://img.youtube.com/vi/D-Yp8jg8HKE/0.jpg)](https://youtu.be/D-Yp8jg8HKE)

## Sobre o Código

O `codigo-antigo.js`foi retirado de uma aplicação pelo lado front-end. Nela consiste a requisição a uma [API](https://api.sampleapis.com/rickandmorty/characters) (sobre a série Rick and Morty) e o retorno de dados são personagens com alguns dados como `id`, `nome`, `avatar` e entre outros.

> Antes de entrar no assunto código, é importante avisar que o código antigo está em JavaScript e na refatoração para o código atual resolvi utilizar TypeScript - a Orientação a Objetos utilizando essa linguagem é melhor explorada. Também foquei a refatoração de código somente no consumo de dados a API.

### Coesão

A Coesão no `codigo-antigo.js` é praticamente inexistente, pois a `class App ` é responśavel por realizar consulta a API, listar os personagens de forma dinâmica na página e lidar com o evento de input text.

```javascript
class App {
    constructor() {
        this.characters = []
        this.characterSearch = ''
    }

    async loadDataApi(urlApi) { }

    writeDataCharactersHtml(data) { }

    handleInputCharacterSearch() { }

    filterCharactersByName(name) { }

    async init() {
        // Carregando dados da API
        await this.loadDataApi(
            'https://api.sampleapis.com/rickandmorty/characters'
        )
    }
}
```

Já no `codigo-atual.ts` cada `class` possui um "foco".

```typescript
// Validações de dados
class Utils {
    urlIsValid(url: string) { }
}

// Model
class Character {
    private _id: number
    private _name: string
    private _avatar: string
    private _utils = new Utils()

    set id(id: number) { }

   set name(name: string) { }

    set avatar(avatar: string) { }
}

// Lida com a API
class HandleApi {
    private _url: string
    private _utils = new Utils()

    set url(url: string) { }

    get url() { }

    async loadDataJson() { }
}

// A classe que executa as ações ou classe principal
class Application {
    private _characters: Character[]
    private _api = new HandleApi()

    async loadDataApiCharacters() { }

    async init() { }
}

```

> O método `urlIsValid(url: string)` não foi implementado pois é fora do foco dessa atividade. Contudo, imagine que ele detecta se uma URL é válida ou não.

### Encapsulamento

No `codigo-antigo.js` é fraco (para não dizer inexistente), os atributos não possuem proteção. A inserção de dados "estranhos" pode ser realizada a qualquer momento.

```javascript
class App {
    constructor() {
        this.characters = []
        this.characterSearch = ''
    }
}

```

Pode-ser tornar `characters` em um `number`:

```javascript
class App {
    constructor() {
        this.characters = []
        this.characterSearch = ''
    }

    hojeEhDiaDeMaldade() {
        this.characters = -1
    }
}
```

Enquanto no `codigo-atual.ts`  a `class Character` realiza uma verificação no valor passado por parâmetro. É uma boa prática de Encapsulamento.

```typescript
class Utils {
    urlIsValid(url: string) {
        return true
    }
}

class Character {
    private _id: number
    private _name: string
    private _avatar: string
    private _utils = new Utils()

    set id(id: number) {
        if (id < 0) {
            throw new Error('Id não pode ser um número negativo')
        }

        this._id = id
    }

    set name(name: string) {
        this._name = name
    }

    set avatar(avatar: string) {
        if (!this._utils.urlIsValid(avatar)) {
            throw new Error(`${this._avatar} é uma URL inválida`)
        }

        this._avatar = avatar
    }
}
```

Por exemplo, o atributo `avatar` deve ser uma URL com a foto do personagem. No entanto, antes de setar o valor de avatar é preciso verificar se a URL é válida - se possui http:// ou https:// e dentre outros requisitos que torna a URL válida.

```typescript
class Utils {
    urlIsValid(url: string) {
        return true
    }
}

class Character {
    // ...
    set avatar(avatar: string) {
        if (!this._utils.urlIsValid(avatar)) {
            throw new Error(`${this._avatar} é uma URL inválida`)
        }

        this._avatar = avatar
    }
}
```

### Acoplamento

No `codigo-atual.ts` o acoplamento é existente. Todas as classes se comunicam. Mas a `class Application` é o lugar que possui o maior comunicação.

```typescript
class Utils { }

class Character { }

class HandleApi { }

class Application {
    private _characters: Character[]
    private _api = new HandleApi()

    async loadDataApiCharacters() {
        const urlApi = 'https://api.sampleapis.com/rickandmorty/characters'
        this._api.url = urlApi

        this._characters = await this._api.loadDataJson()
    }

    async init() {
        await this.loadDataApiCharacters()
    }
}

const application = new Application()

application.init()

```

As classes `Character` e `HandleApi` estão acopladas a `Utils` . Que por sua vez, a classe `Application` está acoplada as classes  `Character` e `HandleApi` - e também implicitamente a `Utils` também.



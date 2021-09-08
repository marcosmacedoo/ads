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

class HandleApi {
    private _url: string
    private _utils = new Utils()

    set url(url: string) {
        if (!this._utils.urlIsValid(url)) {
            throw new Error(`A ${this.url} é inválida`)
        }

        this._url = url
    }

    get url() {
        return this._url
    }

    async loadDataJson() {
        let data: Character[]

        try {
            data = await fetch(this.url)
                .then((response) => response.json())
                .then((dataJson) => dataJson)
        } catch {
            throw new Error(`Erro ao realizar requisicao a ${this.url}`)
        }

        return data
    }
}

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

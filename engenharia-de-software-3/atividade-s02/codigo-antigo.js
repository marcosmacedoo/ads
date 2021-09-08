class App {
    constructor() {
        this.characters = []
        this.characterSearch = ''
    }

    async loadDataApi(urlApi) {
        const dataCharacters = await fetch(urlApi)
            .then((response) => response.json())
            .then((data) => data)

        // Filtrando dados que estão com dados completos
        // Os dados de id: 21 e 22 estão vindos incompletos da API
        this.characters = dataCharacters.filter((character) => character.name)
    }

    writeDataCharactersHtml(data) {
        let $listCharacters = document.querySelector('.list-characters')

        $listCharacters.remove()
        $listCharacters = document.createElement('ul')
        $listCharacters.classList.add('list-characters')

        data.forEach((character) => {
            const $li = document.createElement('li')

            $li.classList.add('item-character')
            $li.setAttribute('data-id', character.id)

            $li.innerHTML = `
          <button type="button">
            <article class="card-character">
              <img src=${character.image} alt=${character.name} />
              <h3>${character.name}</h3>
            </article>
          </button>
        `
            $listCharacters.appendChild($li)
        })

        document.querySelector('.characters').appendChild($listCharacters)

        if ($listCharacters.childElementCount === 0) {
            document.querySelector('.characters').innerHTML =
                '<h2>Infelizmente o personagem que você procura não está aqui</h2>'
        }
    }

    handleInputCharacterSearch() {
        const $input = document.querySelector('#input-character-search')

        $input.addEventListener('input', (event) => {
            this.characterSearch = event.target.value

            // Filtrando personagens através do nome
            const filteredCharacters = this.filterCharactersByName(
                this.characterSearch
            )
            this.writeDataCharactersHtml(filteredCharacters)
        })
    }

    filterCharactersByName(name) {
        return this.characters.filter((character) =>
            character.name.includes(name)
        )
    }

    async init() {
        // Carregando dados da API
        await this.loadDataApi(
            'https://api.sampleapis.com/rickandmorty/characters'
        )
    }
}

const app = new App()

app.init()

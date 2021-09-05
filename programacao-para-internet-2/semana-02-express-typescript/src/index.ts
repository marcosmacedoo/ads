import express, { Request, Response } from 'express'

const app = express()
const port = 3000

app.use(express.json())

type Filme = {
    id: number
    nome: string
    genero: string
    ano: number
    duracao: number
}

app.get('/filmes', (request: Request, response: Response) => {
    const filmes: Filme[] = []

    return response.status(200).json(filmes)
})

app.get('/filmes/:id', (request: Request, response: Response) => {
    const idParam = request.params.id

    const filme: Filme = {
        id: Number(idParam),
        nome: "Batman: O Cavaleiro das Trevas",
        genero: "Ação/Aventura",
        ano: 2008,
        duracao: 150
    }

    return response.status(200).json(filme)
})

app.post('/filmes', (request: Request, response: Response) => {
    const { id, nome, genero, ano, duracao }: Filme = request.body

    return response.status(201).json({ id, nome, genero, ano, duracao })
})

app.put('/filmes/:id', (request: Request, response: Response) => {
    // Utilizar o id para buscar o objeto dentro do banco de dados
    // Ao encontrar, atualiza seus dados
    const idParam = request.params.id

    const filme: Filme = {
        id: Number(idParam),
        nome: "Batman: O Cavaleiro das Trevas",
        genero: "Ação/Aventura",
        ano: 2008,
        duracao: 150
    }

    return response.status(200).json(filme)
})

app.delete('/filmes/:id', (request: Request, response: Response) => {})


app.listen(port, () => console.log(`App running in http://localhost:${port}`))

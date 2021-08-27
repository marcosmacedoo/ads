const { initializeApp } = require("firebase/app");
const {
    getFirestore,
    collection,
    getDocs,
    doc,
    getDoc,
    deleteDoc,
    addDoc,
    updateDoc
} = require("firebase/firestore/lite");

const express = require("express");

const { firebaseConfig } = require("./firebaseConfig");

const app = express();
const port = 3000;

// Validando a utilização de JSON na aplicação
app.use(express.json());

// Inicializando o Firebase e Firestore
const firebaseApp = initializeApp(firebaseConfig);
const db = getFirestore(firebaseApp);
const colecaoDePersonagens = collection(db, "personagens");

// Rotas
app.get("/personagens", async (req, res) => {
    const personagensSnapshot = await getDocs(colecaoDePersonagens);
    const listaDePersonagens = personagensSnapshot.docs.map((doc) => {
        return {
            id: doc.id,
            ...doc.data(),
        };
    });

    return res.json(listaDePersonagens);
});

app.get("/personagens/:id", async (request, response) => {
    const { id } = request.params;

    const personagemRef = doc(db, "personagens", id);
    const personagemDoc = await getDoc(personagemRef);
    const personagemBuscado = {
        id: personagemDoc.id,
        ...personagemDoc.data(),
    };

    return response.json(personagemBuscado);
});

app.post("/personagens", async (request, response) => {
    const { nome, genero } = request.body;

    await addDoc(colecaoDePersonagens, {
        nome,
        genero,
    });

    return response.json({ message: "Personagem adicionado com sucesso" });
});

app.delete("/personagens/:id", async (request, response) => {
    const { id } = request.params

    const personagemRef = doc(db, "personagens", id);
    await deleteDoc(personagemRef)

    return response.json({ message: 'Personagem deletado com sucesso' })
})

app.put("/personagens/:id", async (request, response) => {
    const { id } = request.params
    const { nome, genero } = request.body

    const personagemRef = doc(db, "personagens", id);
    await updateDoc(personagemRef, {
        nome,
        genero
    })

    return response.json({ message: 'Personagem atualizado com sucesso' })
})


// Rodando a aplicação na porta 3000
app.listen(port, () => console.log(`Running in http://localhost:${port}`));

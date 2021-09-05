class Navbar {
    constructor() {
        this.$navbar = document.querySelector("#navbar");
        this.$itensNavbar = Array.from(this.$navbar.childNodes);
        this.itens = this.mapearItensNavbar();
        this.NOMEDACLASSEDEITEMATIVO = "item--ativo";
        this.itemAtivo = this.itemAtivo;
    }

    mapearItensNavbar() {
        if (this.$itensNavbar.length === 0) {
            throw new Error("Itens da Navbar não foram carregados");
        }

        return this.$itensNavbar.map(($item) => {
            return {
                id: $item.id,
                $element: $item,
            };
        });
    }

    get itemAtivo() {
        if (this.$itensNavbar.length === 0) {
            throw new Error("Itens da Navbar não foram carregados");
        }

        const [itemAtivoFiltrado] = this.itens.filter((item) =>
            this.itemContemClasse(item.$element, this.NOMEDACLASSEDEITEMATIVO)
        );

        return {
            id: itemAtivoFiltrado.id,
            $element: itemAtivoFiltrado,
        };
    }

    set itemAtivo(itemAtivoParam) {
        this.itemAtivo = { id: itemAtivoParam.id, $element: itemAtivoParam };
    }

    itemContemClasse($item, nomeDaClasse) {
        return $item.classList.contains(nomeDaClasse);
    }

    adicionarClasseAoItem($item, nomeDaClasse) {
        // Caso o elemento ativo seja clicado novamente
        if (!this.itemContemClasse($item, nomeDaClasse)) {
            $item.classList.add(nomeDaClasse);
        }
    }

    removerClasseAoItem($item, nomeDaClasse) {
        if (this.itemContemClasse($item, nomeDaClasse)) {
            $item.classList.remove(nomeDaClasse);
        }
    }

    monitorarCliqueNavbar() {
        $navbar.addEventListener("click", (event) => {
            this.itemAtivo = {
                id: event.target.id,
                $element: event.target,
            };

            const itensFiltradosNaoAtivos = this.itens.filter(
                (item) => item.id !== this.itemAtivo.id
            );

            itensFiltradosNaoAtivos.forEach((item) =>
                this.removerClasseAoItem(
                    item.$element,
                    this.NOMEDACLASSEDEITEMATIVO
                )
            );

            this.adicionarClasseAoItem(
                this.itemAtivo.$element,
                this.NOMEDACLASSEDEITEMATIVO
            );
        });
    }
}

class App {
    main() {
        const navbar = new Navbar();

        navbar.monitorarCliqueNavbar()
    }
}

const app = new App()

app.main()
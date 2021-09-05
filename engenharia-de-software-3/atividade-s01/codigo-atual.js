class Navbar {
    constructor() {
        this.url = {
            origin: window.location.origin, 
            pathName: window.location.pathname,
            href: window.location.href
        }
        this.$navbar = document.querySelector("#navbar");
        this.$itensNavbar = Array.from(this.$navbar.childNodes);
        this.itens = this.mapearItensNavbar();
        this.itemAtivo = this.itemAtivo;
        this.NOMEDACLASSEDEITEMATIVO = "item--ativo";
    }

    get itemAtivo() {
        if (this.$itensNavbar.length === 0) {
            throw new Error("Itens da Navbar não foram carregados");
        }

        const [itemAtivoFiltrado] = this.itens.filter((item) =>
            this.urlPathName.includes(item.id)
        );

        return {
            id: itemAtivoFiltrado.id,
            $element: itemAtivoFiltrado,
        };
    }

    set itemAtivo(itemAtivoParam) {
        this.itemAtivo = { id: itemAtivoParam.id, $element: itemAtivoParam };
    }

    mapearItensNavbar() {
        // Fail fast
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

    monitorarCliqueNoItemDaNavbar() {
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

            this.atualizarUrl()
        });
    }

    atualizarUrl() {
        this.url.pathName = `/${this.itemAtivo.id}`
        this.url.href = `${this.url.origin}${this.url.pathName}`

        window.href = this.url.href
    }
}

class App {
    main() {
        const navbar = new Navbar();

        navbar.monitorarCliqueNoItemDaNavbar()
    }
}

const app = new App()

app.main()
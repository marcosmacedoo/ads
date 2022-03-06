const products = [
  { id: 1, name: "Notebook", price: 2999.9 },
  { id: 2, name: "Teclado", price: 249.9 },
  { id: 3, name: "Mouse", price: 149.9 },
  { id: 4, name: "Cadeira Gamer", price: 1999.9 },
  { id: 5, name: "Headset", price: 399.9 },
  { id: 6, name: "Monitor", price: 1599.9 },
];
const $productsList = document.querySelector("#products-list");
const $totalPrice = document.querySelector("#total-price");
let selectedProducts = [];

const formatMoney = (amount = 0) =>
  new Intl.NumberFormat("pt-BR", { style: "currency", currency: "BRL" }).format(
    amount
  );

const getProductHtml = (product) => `
    <input 
        type="checkbox" 
        name="products" 
        id="${product.id}" 
    />
    <label for="${product.id}">
        ${product.name} - ${formatMoney(product.price)}
    </label>
`;

const loadProducts = () =>
  products.forEach((product) => {
    const $li = document.createElement("li");
    const productHtml = getProductHtml(product);

    $li.innerHTML += productHtml;
    $productsList.appendChild($li);
  });

const updateSelectedProducts = (selectedProduct) => {
  const isProductInSelectedProducts = selectedProducts.some(
    (product) => product.id === selectedProduct.id
  );

  if (!isProductInSelectedProducts) {
    selectedProducts = [...selectedProducts, selectedProduct];
    return;
  }

  selectedProducts = selectedProducts.filter(
    (product) => product.id !== selectedProduct.id
  );
};

const calculateTotalPrice = () => {
    let totalPrice = 0

    for (let i = 0; i < selectedProducts.length; i++) {
        const product = selectedProducts[i];
        totalPrice += product.price
    }

    return totalPrice
}

const updateTotalPrice = () => {
    const totalPrice = calculateTotalPrice()
    $totalPrice.innerHTML = formatMoney(totalPrice)
};

const handleProductClick = (event) => {
  const { target } = event;
  const tagName = target.localName;

  if (tagName !== "input") return;

  const idProduct = Number(target.getAttribute("id"));

  const [selectedProduct] = products.filter(
    (product) => product.id === idProduct
  );

  updateSelectedProducts(selectedProduct);
  updateTotalPrice();
};


loadProducts();
$productsList.addEventListener("click", handleProductClick);

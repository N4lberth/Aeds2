function obterValorParametro(nomeParametro) {
  const urlParams = new URLSearchParams(window.location.search);
  return urlParams.get(nomeParametro);
}

const idProduto = obterValorParametro('id');
console.log('ID do Produto:', idProduto);

fetch(`https://fakestoreapi.com/products/${idProduto}`)
  .then(response => response.json())
  .then(data => exibirInformacoesProduto(data))
  .catch(error => console.log(error));

function exibirInformacoesProduto(produto) {
  const nomeElemento = document.getElementById('nome_prod');
  const precoElemento = document.getElementById('preco_prod');
  const descricaoElemento = document.getElementById('desc_prod');
  const imagemElemento = document.getElementById('img_prod');

  
  nomeElemento.textContent = produto.title;
  precoElemento.textContent = `$${produto.price}`;
  descricaoElemento.textContent = produto.description;
  imagemElemento.src = produto.image;
}
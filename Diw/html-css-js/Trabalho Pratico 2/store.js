const categorySelect = document.getElementById('category-select');
const produtosContainer = document.getElementById('produtos-display');
const searchInput = document.getElementById('search-input');

fetch('https://fakestoreapi.com/products')
  .then(response => response.json())
  .then(data => {
    const produtos = data.slice(0, 20);

    function exibirProdutos(produtos) {
      produtosContainer.innerHTML = '';

      for (let i = produtos.length - 1; i >= 0; i--) {
        const produto = produtos[i];
        const titulo = produto.title;
        const preco = produto.price;
        const nome = produto.category;
        const imagem = produto.image;
        const avaliacao = produto.rating.rate;

        const colElement = document.createElement('div');
        colElement.classList.add('col-6', 'col-md-4', 'col-lg-3', 'mb-4');
        colElement.style.padding = '20px';

        const cardElement = document.createElement('div');
        cardElement.classList.add('card', 'h-100');
        cardElement.style.borderRadius = '20px';
        cardElement.style.border = '4px solid black';

        const imagemElement = document.createElement('img');
        imagemElement.src = imagem;
        imagemElement.classList.add('card-img-top', 'img-fluid', 'prodCont');
        imagemElement.style.objectFit = 'contain';
        imagemElement.style.height = '200px';
        imagemElement.style.margin = 'auto';
        cardElement.appendChild(imagemElement);

        const infoElement = document.createElement('div');
        infoElement.classList.add('card-body', 'text-center');
        infoElement.innerHTML = `<h5 class="card-title">Nome do produto: ${titulo}</h5>
                                 <p class="card-text">Preço do produto: ${preco}</p>
                                 <p class="card-text">Avaliação do produto: ${avaliacao} / 5.0</p>
                                 <p class="card-text">Categoria do produto: ${nome}</p>`;
        cardElement.appendChild(infoElement);

        const buttonElement = document.createElement('button');
        buttonElement.classList.add('btn');
        buttonElement.textContent = 'Ver Detalhes';
        buttonElement.setAttribute('data-id', produto.id);
        buttonElement.addEventListener('click', () => {
          window.location.href = 'detalhes.html' + '?id=' + produto.id;
        });

        cardElement.appendChild(buttonElement);

        colElement.appendChild(cardElement);
        produtosContainer.appendChild(colElement);
      }
    }

    function filtrarProdutos(categoria, termoPesquisa) {
      let produtosFiltrados = produtos;

      if (categoria) {
        produtosFiltrados = produtosFiltrados.filter(produto => produto.category.toLowerCase() === categoria.toLowerCase());
      }

      if (termoPesquisa) {
        produtosFiltrados = produtosFiltrados.filter(produto => produto.title.toLowerCase().includes(termoPesquisa.toLowerCase()));
      }

      exibirProdutos(produtosFiltrados);
    }

    categorySelect.addEventListener('change', () => {
      const categoriaSelecionada = categorySelect.value;
      const termoPesquisa = searchInput.value;
      filtrarProdutos(categoriaSelecionada, termoPesquisa);
    });

    searchInput.addEventListener('input', () => {
      const categoriaSelecionada = categorySelect.value;
      const termoPesquisa = searchInput.value;
      filtrarProdutos(categoriaSelecionada, termoPesquisa);
    });

    filtrarProdutos('', '');
  })
  .catch(error => {
    console.error('Ocorreu um erro:', error);
  });

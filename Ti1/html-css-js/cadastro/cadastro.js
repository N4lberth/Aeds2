// Função para manipular o clique no botão de entrar
function handleEntrar() {
    var email = document.getElementById("email").value;
    var senha = document.getElementById("senha").value;
  
    // Cria um objeto JSON com os dados de login
    var dadosLogin = {
      email: email,
      senha: senha
    };
  
    // Exibe os dados de login no console (você pode fazer outras operações com os dados aqui)
    console.log(dadosLogin);
  }
  
  // Adiciona um evento de clique ao botão de entrar
  var btnEntrar = document.getElementById("btn-entrar");
  btnEntrar.addEventListener("click", handleEntrar);
  
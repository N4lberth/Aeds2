// Função para manipular o envio do formulário
function handleSubmit(event) {
    event.preventDefault(); // Impede o envio do formulário
  
    // Obtém os valores dos campos do formulário
    var nome = document.getElementById("nome").value;
    var email = document.getElementById("email").value;
    var telefone = document.getElementById("telefone").value;
    var genero = document.querySelector('input[name="genero"]:checked').value;
    var dataNascimento = document.getElementById("data_nascimento").value;
    var altura = document.getElementById("altura").value;
    var peso = document.getElementById("peso").value;
  
    // Cria um objeto JSON com os dados do cliente
    var cliente = {
      nome: nome,
      email: email,
      telefone: telefone,
      genero: genero,
      dataNascimento: dataNascimento,
      altura: altura,
      peso: peso
    };
  
    // Exibe os dados do cliente no console (você pode fazer outras operações com os dados aqui)
    console.log(cliente);
  }
  
  // Adiciona um evento de envio ao formulário
  var form = document.getElementById("form-cliente");
  form.addEventListener("submit", handleSubmit);
  
// script.js

// Dados iniciais
var userInfo = {
  name: "Fabio Andrade",
  weight: "75kg",
  height: "170 cm",
  gender: "Masculino"
};

// Função para exibir os dados na página
function displayUserInfo() {
  document.getElementById("name-value").textContent = userInfo.name;
  document.getElementById("weight-value").textContent = userInfo.weight;
  document.getElementById("height-value").textContent = userInfo.height;
  document.getElementById("gender-value").textContent = userInfo.gender;
}

// Função para habilitar a edição dos dados
function editUserInfo() {
  var elements = document.getElementById("user-info").getElementsByTagName("span");
  for (var i = 0; i < elements.length; i++) {
    elements[i].contentEditable = true;
  }
  document.getElementById("save-button").style.display = "block";
}

// Função para salvar os dados editados
function saveUserInfo() {
  var elements = document.getElementById("user-info").getElementsByTagName("span");
  for (var i = 0; i < elements.length; i++) {
    elements[i].contentEditable = false;
    userInfo[elements[i].id] = elements[i].textContent;
  }
  document.getElementById("save-button").style.display = "none";
}

// Chamar a função displayUserInfo para exibir os dados iniciais na página
displayUserInfo();

//Formulario e checkbox

const myForm = document.getElementById("registraUsuario");
const checkbox = document.getElementsByName("linguagens");

for (let i = 0; i < checkbox.length; i++) {
  checkbox[i].addEventListener("click", () => {
    checkCB(i);
  });
}

//Validação do formulário
myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  let user = new Object();
  const nome = document.getElementsByName("firstName")[0].value;
  const idade = checkAge(
    parseInt(document.getElementsByName("lastName")[0].value)
  );
  const email = checkEmail(document.getElementsByName("email")[0].value);
  const radioSelected = checkRadio(document.getElementsByName("notify"));
  const checkboxSelected = getCheckBox();

  if (nome === false || idade === false || email === false) {
    alert("Dados inválidos!! Tente novamente com os dados corretos");
  } else {
    user = {
      nome,
      idade,
      email,
      linguagens: checkboxSelected,
      frequencia: radioSelected,
    };

    console.log(user);

    myForm.submit();
    document.write(`
      Nome: ${user.nome}<br>
      Idade: ${user.idade}<br>
      Email: ${user.email}<br>
      Linguagens: ${user.linguagens}<br>
      Frequencia: ${user.frequencia}<br>
    `);
  }
});

//Funções

function checkName(name) {
  if (name.length === 0) {
    return false;
  }
}
function checkAge(age) {
  if (age > 10 && age < 90) {
    return age;
  } else {
    alert("Digite a idade entre 10 e 90 anos");
    return false;
  }
}

function checkEmail(email) {
  if (email.indexOf("@") !== -1) {
    return email;
  } else {
    alert("Digite corretamente o email");
    return false;
  }
}

function checkRadio(radio) {
  for (let i = 0; i < radio.length; i++) {
    if (radio[i].checked) {
      return radio[i].value;
    }
  }
}

function checkCB(index) {
  let count = 0;
  for (let i = 0; i < checkbox.length; i++) {
    if (checkbox[i].checked) {
      count += 1;
    }
  }

  if (count > 3) {
    alert("Por favor, selecione apenas 3 linguagens");
    checkbox[index].checked = false;
    return false;
  }
}

function getCheckBox() {
  const list = [];
  for (let i = 0; i < checkbox.length; i++) {
    if (checkbox[i].checked) {
      list.push(checkbox[i].value);
    }
  }
  if (list.length === 0) {
    return "Nenhuma linguagem";
  }
  return list;
}

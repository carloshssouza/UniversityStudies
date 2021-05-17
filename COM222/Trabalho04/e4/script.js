const myForm = document.getElementById("my-form");

myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  let salario = parseFloat(document.getElementById("salario").value);
  const resultado = checkSalary(salario);

  document.getElementById(
    "resultado"
  ).innerHTML = `O salário era ${salario}, recebeu um aumento de ${
    resultado.aumento * 100
  }% e agora é ${resultado.salarioAumento}`;
});

function checkSalary(salary) {
  let salarioAumento;
  let aumento;
  if (salario <= 280) {
    aumento = 0.2;
    salarioAumento = salario + salario * aumento;
  } else if (salario > 280 && salario <= 700) {
    aumento = 0.15;
    salarioAumento = salario + salario * aumento;
  } else if (salario > 700 && salario <= 1500) {
    aumento = 0.1;
    salarioAumento = salario + salario * aumento;
  } else if (salario > 1500) {
    aumento = 0.05;
    salarioAumento = salario + salario * aumento;
  }

  return { salarioAumento, aumento };
}

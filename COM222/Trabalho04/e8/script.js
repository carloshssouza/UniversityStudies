const myForm = document.getElementById("my-form");
const monthName = [
  "Janeiro",
  "Fevereiro",
  "Março",
  "Abril",
  "Maio",
  "Junho",
  "Julho",
  "Agosto",
  "Setembro",
  "Outubro",
  "Novembro",
  "Dezembro",
];

myForm.addEventListener("submit", (e) => {
  e.preventDefault();

  const inputDate = document.getElementById("input-date").value.split("-");
  const result = Object.assign({}, inputDate);

  const date = new Date(`${result[1]}/${result[2]}/${result[0]}`);
  if (date == "Invalid Date") {
    document.getElementById("resultado").innerHTML = "Erro na data";
  } else {
    const day = date.getDate();
    const month = monthName.filter((value, id) => id === date.getMonth());
    const year = date.getFullYear();

    document.getElementById(
      "resultado"
    ).innerHTML = `${day} de ${month} de ${year}`;
  }
});

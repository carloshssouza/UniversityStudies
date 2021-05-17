const myForm = document.getElementById("my-form");
const tableArea = document.getElementById("table-area");
table = document.createElement("table");

myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  const firstInput = parseFloat(document.getElementById("first-input").value);
  const secondInput = parseFloat(document.getElementById("second-input").value);

  const listOperation = [
    {
      operador: "+",
      valor: firstInput + secondInput,
    },
    {
      operador: "-",
      valor: firstInput - secondInput,
    },
    {
      operador: "*",
      valor: firstInput * secondInput,
    },
    {
      operador: "/",
      valor: firstInput / secondInput,
    },
    {
      operador: "%",
      valor: firstInput % secondInput,
    },
  ];

  for (let i = 0; i < 1; i++) {
    let tr = document.createElement("tr");

    tr.appendChild(document.createElement("th"));
    tr.appendChild(document.createElement("th"));

    tr.cells[0].appendChild(document.createTextNode("Operação"));
    tr.cells[1].appendChild(document.createTextNode("Valor"));

    table.appendChild(tr);
  }

  for (let i = 0; i < listOperation.length; i++) {
    let tr = document.createElement("tr");

    tr.appendChild(document.createElement("td"));
    tr.appendChild(document.createElement("td"));

    tr.cells[0].appendChild(
      document.createTextNode(
        `${firstInput} ${listOperation[i].operador} ${secondInput}`
      )
    );
    tr.cells[1].appendChild(document.createTextNode(listOperation[i].valor));

    table.appendChild(tr);
  }

  tableArea.appendChild(table);
});

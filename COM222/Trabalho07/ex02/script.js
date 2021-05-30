$(document).ready(function () {
  $("button").click((e) => {
    e.preventDefault();
    let novaLinha = $("<tr></tr>");
    $("input").each((index, element) => {
      let novoDado = $("<td></td>");
      novoDado.html(element.value);
      novaLinha.append(novoDado);
    });
    $("#tabela").append(novaLinha);
  });
});

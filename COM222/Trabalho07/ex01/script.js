$(document).ready(function () {
  $("#my-form").submit((e) => {
    e.preventDefault();

    const listElements = [];

    $("input").each((index, element) => {
      listElements.push(`<li>${element.value}</li>`);
      element.value = "";
    });

    $("ol").html(listElements);
    $("input").each((index, value) => {
      listElements.push(`<li>${value.value}</li>`);
    });
  });
});

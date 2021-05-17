const myForm = document.getElementById("my-form");
let span = document.getElementById("qtd");
const array = [];

myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  const inputName = document.getElementById("input-name");
  const inputHeight = document.getElementById("input-height");
  if (array.length < 5) {
    array.push({ name: inputName, height: inputHeight });
    document.getElementById("input-name").value = "";
    document.getElementById("input-height").value = "";
    span.textContent = parseInt(span.textContent) + 1;
  } else {
    const person = highestHeight(array);
    document.write(`Nome: ${person.name} e Altura ${person.altura}`);
  }
});
function highestHeight(array) {
  let result = 0;
  let name = "";
  for (let i = 0; i < array.length; i++) {
    if (array[i].height > result) {
      result = array[i].height;
      name = array[i].name;
    }
  }

  return { result, name };
}

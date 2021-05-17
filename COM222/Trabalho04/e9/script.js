const myForm = document.getElementById("my-form");
const array = [];

myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  let input = parseFloat(document.getElementById("input-number").value);
  if (input !== 0) {
    array.push(input);
    document.getElementById("input-number").value = "";
  } else {
    document.write(`A média é: ${media(array)}`);
  }
});

function media(array) {
  let result = 0;
  for (let i = 0; i < array.length; i++) {
    result += array[i];
  }
  return result / array.length;
}

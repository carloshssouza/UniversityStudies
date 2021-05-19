const myForm = document.getElementById("my-form");
let span = document.getElementById("qtd");
const array = [];

myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  const name = document.getElementById("input-name").value;
  const height = parseInt(document.getElementById("input-height").value);
  let str = ``;

  if (array.length < 2) {
    array.push({ name, height });
    console.log(array);
    document.getElementById("input-name").value = "";
    document.getElementById("input-height").value = "";
    span.textContent = parseInt(span.textContent) + 1;
  } else {
    array.push({ name, height });
    const bigHeight = highestHeight(array);
    const result = array.filter((value) => {
      if (value.height === bigHeight) {
        return value;
      }
    });

    for (let i = 0; i < result.length; i++) {
      str += `Nome: ${result[i].name}<br>
              Altura: ${result[i].height}<br><br>
      `;
    }
    document.write(str);
  }
});
function highestHeight(array) {
  let height = 0;
  for (let i = 0; i < array.length; i++) {
    if (array[i].height >= height) {
      height = array[i].height;
    }
  }

  return height;
}

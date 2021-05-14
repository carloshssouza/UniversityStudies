const frase = prompt("Digite uma frase");

function checkString(num) {
  const str = num.split(" ");
  let result = "";
  let maior = 0;
  for (let i = 0; i < str.length; i++) {
    if (str[i].length > maior) {
      result = str[i];
      maior = str[i].length;
    }
  }

  return document.write(`<h1>A maior string é: ${result}</h1>`);
}

checkString(frase);

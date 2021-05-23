const myForm = document.getElementById("my-form");

myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  const inputElements = document.getElementsByTagName("input");
  const listElements = [];
  for (let i = 0; i < inputElements.length; i++) {
    listElements.push(`<li>${inputElements[i].value}</li>`);
    inputElements[i].value = "";
  }
  document.getElementById("result").innerHTML = listElements.join("\n");
});

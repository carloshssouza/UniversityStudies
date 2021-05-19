const myForm = document.getElementById("my-form");
const inputDate = document.getElementById("input-date");

myForm.addEventListener("submit", (e) => {
  e.preventDefault();
  const myDate = inputDate.value.split(/[:-\s/T]/);
  const date = new Date();
  const currentYear = date.getFullYear();
  const currentMonth = date.getMonth();
  let age = 0;

  if (myDate[1] < currentMonth) {
    age = currentYear - myDate[0];
  } else {
    age = currentYear - myDate[0] - 1;
  }

  let months = age * 12;
  let days = age * 365;
  let hours = days * 24 + parseFloat(myDate[3]);
  let minutes = hours * 60 + parseFloat(myDate[4]);
  let seconds = minutes * 60;

  const user = {
    age,
    months,
    days,
    hours,
    minutes,
    seconds,
  };

  document.getElementById("resultado").innerHTML = `
    Anos: ${user.age}<br>
    Meses: ${user.months}<br>
    Dias: ${user.days}<br>
    Horas: ${user.hours}<br>
    Minutos: ${user.minutes}<br>
    Segundos: ${user.seconds}<br>
  `;
});

function dateCalculates() {}

const button = document.getElementsByTagName("button");
const input = document.getElementsByTagName("input");

const date = new Date();
const currentDate = {
  year: date.getFullYear(),
  month: date.getMonth() + 1,
  day: date.getDate(),
  hour: date.getHours(),
  minute: date.getMinutes(),
  second: date.getSeconds(),
};

button[0].addEventListener("click", (e) => {
  e.preventDefault();
  const inputDate = input[0].value.split(/[:-\s/T]/);
  const age = {
    year: inputDate[0],
    month: inputDate[1],
    day: inputDate[2],
    hour: inputDate[3],
    minute: inputDate[4],
  };
});

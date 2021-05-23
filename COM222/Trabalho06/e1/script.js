const columnPages = document.getElementsByClassName("column-pages");
const columnBook = document.getElementsByClassName("column-book");

columnPages[0].addEventListener("click", (e) => {
  e.preventDefault();
  for (let i = 0; i < columnPages.length; i++) {
    columnPages[i].style.backgroundColor = "lightgreen";
  }
});

columnBook[0].addEventListener("click", (e) => {
  e.preventDefault();
  for (let i = 0; i < columnBook.length; i++) {
    columnBook[i].style.backgroundColor = "lightblue";
  }
});

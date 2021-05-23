const containerImages = document.getElementById("container-images").children;

const zoomIn = document.getElementById("zoom-in");
const zoomOut = document.getElementById("zoom-out");

zoomIn.addEventListener("click", (e) => {
  for (let i = 0; i < containerImages.length; i++) {
    if (containerImages[i].classList.value === "img-anime") {
      containerImages[i].classList.remove("img-anime");
      containerImages[i].classList.add("imgZoom50");
    } else if (containerImages[i].classList.value === "imgZoom50") {
      containerImages[i].classList.remove("imgZoom50");
      containerImages[i].classList.add("imgZoom100");
    } else if (containerImages[i].classList.value === "imgZoom150") {
      containerImages[i].classList.remove("imgZoom100");
      containerImages[i].classList.add("imgZoom150");
    }
  }
});

zoomOut.addEventListener("click", (e) => {
  for (let i = 0; i < containerImages.length; i++) {
    if (containerImages[i].classList.value === "imgZoom150") {
      containerImages[i].classList.remove("imgZoom150");
      containerImages[i].classList.add("imgZoom100");
    } else if (containerImages[i].classList.value === "imgZoom100") {
      containerImages[i].classList.remove("imgZoom100");
      containerImages[i].classList.add("imgZoom50");
    } else if (containerImages[i].classList.value === "imgZoom50") {
      containerImages[i].classList.remove("imgZoom50");
      containerImages[i].classList.add("img-anime");
    }
  }
});

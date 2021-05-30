$(document).ready(function () {
  $("button").click((e) => {
    e.preventDefault();
    const cityName = $("input").val();
    //Key Openweathermap
    const key = "";
    const result = getWeathersData(cityName, key).then(returnWeather);

    result
      .then((data) => {
        $("#result-weather").html(
          `<p>Condição Atual: ${data.currentWeather}</p>
        <p>Temperatura Atual: ${data.currentTemperature}</p>
        <p>Temperatura máxima: ${data.maxTemperature}</p>
        <p>Temperatura minima: ${data.minTemperature}</p>
        `
        );
      })
      .catch((err) => {
        return $("#result-weather").html(
          `<p id="error">Cidade não encontrada</p>`
        );
      });
  });
});

function returnWeather(data) {
  const currentWeather = data.weather[0].description;
  const currentTemperature = (data.main.temp - 273.15).toFixed(2);
  const minTemperature = (data.main.temp_min - 273.15).toFixed(2);
  const maxTemperature = (data.main.temp_max - 273.15).toFixed(2);
  const result = {
    currentWeather,
    currentTemperature,
    minTemperature,
    maxTemperature,
  };
  return result;
}

function getWeathersData(cityName, key) {
  return new Promise((resolve, reject) => {
    const result = $.getJSON(
      `http://api.openweathermap.org/data/2.5/weather?q=${cityName}&appid=${key}&lang=pt_br`
    );
    if (result) {
      resolve(result);
    } else {
      reject();
    }
  });
}

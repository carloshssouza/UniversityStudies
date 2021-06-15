const express = require("express");
const router = require("./routes/clientes");

const app = express();
const PORT = 3000;

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(router);

app.listen(PORT, () => {
  console.log(`Server listening on ${PORT}`);
});

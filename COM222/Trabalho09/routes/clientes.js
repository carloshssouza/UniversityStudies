const express = require("express");
const Clientes = require("../models/Clientes");

const router = express.Router();

router.get("/", (req, res) => {
  res.json({ message: "Hello, world!!" });
});

//Register a user
router.post("/clientes", async (req, res) => {
  const cliente = new Clientes({
    nome: req.body.nome,
    cpf: req.body.cpf,
  });
  console.log(cliente);
  try {
    const savedCliente = await cliente.save();
    res.json(savedCliente);
  } catch (err) {
    res.json({ message: err });
  }
});

router.delete("/clientes/:_id", async (req, res) => {
  try {
    const removedCliente = await Clientes.remove({ _id: req.params.id });
    res.json(removedCliente);
  } catch (err) {
    res.json({ message: err });
  }
});

router.patch("/clientes/:id", async (req, res) => {
  try {
    const updatedCliente = await Clientes.updateOne(
      { _id: req.params._id },
      { $set: { title: req.body.title } }
    );
    res.json(updatedCliente);
  } catch (err) {
    res.json({ message: err });
  }
});

//Get All users
router.get("/clientes", async (req, res) => {
  try {
    const clientes = await Clientes.find();
    res.json(clientes);
  } catch (err) {
    res.json({ message: err });
  }
});

router.get("/clientes/:_id", async (req, res) => {
  try {
    const data = await Clientes.find({ _id: req.params._id });
    res.json(data);
  } catch (err) {
    res.json({ message: err });
  }
});

module.exports = router;

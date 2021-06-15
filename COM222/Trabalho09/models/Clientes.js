const mongoose = require("mongoose");

mongoose.connect(
  "mongodb://localhost:27017/nodeteste1",
  { useUnifiedTopology: true, useNewUrlParser: true },
  () => {
    console.log("mongodb connected");
  }
);

const ClienteSchema = mongoose.Schema(
  {
    nome: {
      type: String,
      required: true,
    },
    cpf: {
      type: String,
      required: true,
    },
    createdAt: {
      type: Date,
      default: Date.now,
    },
  },
  { collection: "usercollection" }
);

module.exports = mongoose.model("Clientes", ClienteSchema);

<?php
$server = "localhost";
$username = "root";
$password = "";
$db = "unityacess";

$nome = $_POST["nome"];
$cpf = $_POST["cpf"];
$endereco = $_POST["endereco"];
$data_nascimento = $_POST["data_nascimento"];
$email = $_POST["email"];
$senha = $_POST["senha"];

$connect = new mysqli($server, $username, $password, $db);

if(!$connect){
    die("Connection Failed". mysqli_connect_error());
}
$sql = "INSERT INTO usuarios (nome, cpf, endereco, data_nascimento, email, senha)
        VALUES ('".$nome."', '".$cpf."', '".$endereco."', '".$data_nascimento."', '".$email."', '".$senha."')";
$result = mysqli_query($connect, $sql);

if(!$result){
    echo"houve um erro";
}
else{
    echo"Cadastrado com sucesso";
}

?> 
<form action="index.php">
    <input type="submit" value="Voltar">
</form>
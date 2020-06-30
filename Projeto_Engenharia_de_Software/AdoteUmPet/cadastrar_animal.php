<?php
$server = "localhost";
$username = "root";
$password = "";
$db = "unityacess";

$nome = filter_input(INPUT_POST, "nome");
$porte = filter_input(INPUT_POST, "porte");
$descricao = filter_input(INPUT_POST, "descricao");
$foto = filter_input(INPUT_POST, "foto");


$connect = new mysqli($server, $username, $password, $db);

if(!$connect){
    die("Connection Failed". mysqli_connect_error());
}
$sql = "INSERT INTO animais (nome, porte, descricao, foto)
        VALUES ('".$nome."', '".$porte."', '".$descricao."', '".$foto."')";
$result = mysqli_query($connect, $sql);

if(!$result){
    echo"houve um erro";
}
else{
    echo"Animal cadastrado com sucesso";
}

?> 
<form action="tela_admin.php">
    <input type="submit" value="Voltar">
</form>
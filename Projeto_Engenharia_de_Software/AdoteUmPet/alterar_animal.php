<?php  
$server = "localhost";
$username = "root";
$password = "";
$db = "unityacess";

$nome = filter_input(INPUT_GET, "nome");
$porte = filter_input(INPUT_GET, "porte");
$descricao = filter_input(INPUT_GET, "descricao");
$foto = filter_input(INPUT_GET, "foto");


$connect = new mysqli($server, $username, $password, $db);
if(!$connect){
    die("Connection Failed". mysqli_connect_error());
}
$sql = "UPDATE animais SET nome='$nome', porte='$porte', descricao='$descricao, foto='$foto' WHERE id='$_GET[id]'";
$result = mysqli_query($connect, $sql);
if(!$result){
    echo"houve um erro";
    die("Erro:" . mysqli_error($sql));
}
else{
    echo"Alterado com sucesso";
}
?>
<form action="consultar_animalForms.php">
    <input type="submit" value="Pesquisar novamente">
</form>
<?php  
$server = "localhost";
$username = "root";
$password = "";
$db = "unityacess";

$conn = new mysqli($server, $username, $password, $db);


if(!$conn){
    die("Connection Failed". mysqli_connect_error());
}

$pesquisar = $_POST["pesquisar"];
$sql = "DELETE FROM usuarios WHERE cpf='$_GET[cpf]'";
if(mysqli_query($conn, $sql)){
    echo "Removido com sucesso";
}
else{
    echo "Não deletado";
}

?>
<form action="consultar_usuario.php">
    <input type="submit" value="Pesquisar novamente">
</form>
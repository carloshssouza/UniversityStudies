<?php  
$server = "localhost";
$username = "root";
$password = "";
$db = "unityacess";

$nome = filter_input(INPUT_GET, "nome");
$cpf = filter_input(INPUT_GET, "cpf");
$endereco = filter_input(INPUT_GET, "endereco");
$data_nascimento = filter_input(INPUT_GET, "data_nascimento");
$email = filter_input(INPUT_GET, "email");
$senha = filter_input(INPUT_GET, "senha");

$connect = new mysqli($server, $username, $password, $db);
if(!$connect){
    die("Connection Failed". mysqli_connect_error());
}
$sql = "UPDATE usuarios SET nome='$nome', cpf='$cpf', endereco='$endereco', data_nascimento='$data_nascimento', email='$email', senha='$senha' WHERE cpf='$_GET[cpf]'";
$result = mysqli_query($connect, $sql);
if(!$result){
    echo"houve um erro";
    die("Erro:" . mysqli_error($sql));
}
else{
    echo"Alterado com sucesso";
}
?>
<form action="consultar_usuario.php">
    <input type="submit" value="Pesquisar novamente">
</form>
<?php
//É ONDE CONFERE O LOGIN DO USUARIO FAZENDO LIGAÇÃO COM O BANCO DE DADOS
$servername = "localhost";
$username = "root";
$password = "";
$db = "unityacess";

$loginEmail = $_POST["email"];
$loginSenha = $_POST["senha"]; 


// Create connection
$conn = new mysqli($servername, $username, $password, $db);

// Check connection
if ($conn->connect_error) {
die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT senha FROM usuarios WHERE email = '".$loginEmail."'" ;
$result = $conn->query($sql);

if ($result->num_rows > 0) {
// output data of each row
while($row = $result->fetch_assoc()) {
    if($row["senha"] == $loginSenha){
        if(strpos($loginEmail, "@root") !== false){
            header("Location:tela_admin.php");
        }
        else{
            header("Location:tela_inicial.php");
        }
        
    }
    else{
        echo "Credenciais erradas";
        
    }
}
} else{
    echo "Esse email não existe";
}

?> 


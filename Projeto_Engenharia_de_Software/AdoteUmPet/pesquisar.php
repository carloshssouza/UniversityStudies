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
$sql = "SELECT * FROM usuarios WHERE cpf LIKE '".$pesquisar."'";
$result = mysqli_query($conn, $sql);
?>
<hmlt>
    <head>  
        <meta charset ="utf8">
    </head>
    <body>
        <table border="1">
            <tr>
                <td>Nome</td>
                <td>CPF</td>
                <td>Endereco</td>
                <td>Data de nascimento</td>
                <td>Email</td>
                <td>Ação</td>
                <td>
            </tr>
            <?php 
                if ($result->num_rows > 0){
                while($dado = $result->fetch_array()){ ?>
            <tr>
                <td><?php echo $dado["nome"] ?></td>
                <td><?php echo $dado["cpf"] ?></td>
                <td><?php echo $dado["endereco"] ?></td>
                <td><?php echo $dado["data_nascimento"] ?></td>
                <td><?php echo $dado["email"] ?></td>
                <td><a href="<?php echo "alterar_usuarioForm.php?cpf=" . $dado["cpf"] . "&nome=" . $dado["nome"] . "&endereco=" . $dado["endereco"] . "&data_nascimento=" . $dado["data_nascimento"] . "&email=" . $dado["email"] ?>">Editar | </a>
                    <a href="remover_usuario.php?cpf=<?php echo $dado["cpf"] ?>">Excluir</a></td>
            </tr>
            <?php } }
                else{
                    echo "Usuário não encontrado";
                }
            ?>
        
        </table>
    </body>
</hmlt>
<form action="consultar_usuario.php">
    <input type="submit" value="Voltar">
</form>
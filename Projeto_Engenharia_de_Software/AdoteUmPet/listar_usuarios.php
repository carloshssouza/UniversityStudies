<?php
//Busca no banco de dados e lista todos os usuarios cadastrados
$servername = "localhost";
$username = "root";
$password = "";
$db = "unityacess";
// Create connection
$conn = new mysqli($servername, $username, $password, $db);

// Check connection
if ($conn->connect_error) {
    die("Conexão falhou: " . $conn->connect_error);
}

$sql = "SELECT * FROM usuarios";
$result = $conn->query($sql);

?> 

<hmlt>
    <head>  
        <meta charset ="utf8">
    </head>
    <body>
        <table border="1">
            <tr>
                <td>Nome</>
                <td>CPF</td>
                <td>Endereco</td>
                <td>Data de nascimento</td>
                <td>Email</td>
                
                <td>
            </tr>

            <?php while($dado = $result->fetch_array()){ ?>
            <tr>
                <td><?php echo $dado["nome"] ?></td>
                <td><?php echo $dado["cpf"] ?></td>
                <td><?php echo $dado["endereco"] ?></td>
                <td><?php echo $dado["data_nascimento"] ?></td>
                <td><?php echo $dado["email"] ?></td>
            </tr>
            <?php } ?>
        
        </table>
    </body>

</hmlt>

<form action="tela_admin.php">
    <input type="submit" value="Pesquisar novamente">
</form>
<?php
//Busca no banco de dados e lista todos os animais cadastrados
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
echo "Conetado com sucesso<br>";

$sql = "SELECT * FROM animais";
$result = $conn->query($sql);

?> 
<html>
    <head>  
        <meta charset ="utf8">
    </head>
    <body>
        <table border="1">
            <tr>
                <td>ID</>
                <td>Nome</td>
                <td>Porte</td>
                <td>Descricao</td>
                <td>Foto</td>
                
                <td>
            </tr>

            <?php while($dado = $result->fetch_array()){ ?>
            <tr>
                <td><?php echo $dado["id"] ?></td>
                <td><?php echo $dado["nome"] ?></td>
                <td><?php echo $dado["porte"] ?></td>
                <td><?php echo $dado["descricao"] ?></td>
                <td><img src="<?php echo "./ImagensAnimal/".$dado["foto"]?>"width="260" height="200"/></td>
            </tr>
            <?php } ?>
        
        </table>
    </body>

</html>

<form action="tela_admin.php">
    <input type="submit" value="Pesquisar novamente">
</form>
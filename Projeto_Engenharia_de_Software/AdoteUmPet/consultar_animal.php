<?php
//Busca no banco de dados o id do animal e mostra na tela
//Dando opções de remover ou alterar
$server = "localhost";
$username = "root";
$password = "";
$db = "unityacess";
$conn = new mysqli($server, $username, $password, $db);

if(!$conn){
    die("Connection Failed". mysqli_connect_error());
}

$pesquisar = $_POST["pesquisar"];
$sql = "SELECT * FROM animais WHERE id LIKE '".$pesquisar."'";
$result = mysqli_query($conn, $sql);
?>
<hmlt>
    <head>  
        <meta charset ="utf8">
    </head>
    <body>
        <table border="1">
            <tr>
                <td>ID</td>
                <td>Nome</td>
                <td>Porte</td>
                <td>Descricao</td>
                <td>Foto</td>
                <td>Ação</td>
                <td>
            </tr>
            <?php 
                if ($result->num_rows > 0){
                while($dado = $result->fetch_array()){ ?>
            <tr>
                <td><?php echo $dado["id"] ?></td>
                <td><?php echo $dado["nome"] ?></td>
                <td><?php echo $dado["porte"] ?></td>
                <td><?php echo $dado["descricao"] ?></td>
                <td><img src="<?php echo "./ImagensAnimal/".$dado["foto"]?>"width="260" height="200"/></td>
                <td><a href="<?php echo "alterar_animalForms.php?id=" . $dado["id"] . "&nome=" . $dado["nome"] . "&porte=" . $dado["porte"] . "&descricao=" . $dado["descricao"] . "&foto=" . $dado["foto"] ?>">Editar | </a>
                    <a href="remover_animal.php?id=<?php echo $dado["id"] ?>">Excluir</a></td>
            </tr>
            <?php } }
                else{
                    echo "Animal não encontrado";
                }
            ?>
            <form  action="consultar_animalForms.php">
                <input type="submit" value="Voltar"><br><br>
            </form>
        </table>
    </body>
</hmlt>


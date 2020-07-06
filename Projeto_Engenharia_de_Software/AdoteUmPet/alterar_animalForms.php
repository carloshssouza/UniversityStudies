<html>
    <head>
        <meta charset="UTF-8">
        <title>Alterar</title>
        <link rel="styleshhet" href="estilo/estilo.css"/>
        <?php
            $nome = filter_input(INPUT_GET, "nome");
            $porte = filter_input(INPUT_GET,"porte");
            $descricao = filter_input(INPUT_GET,"descricao");
            $foto = filter_input(INPUT_GET,"foto");
            
        ?>
    </head>
    <body>
        <div cpf="conteudo">
            <h1>Alterar dados</h1>
            <p>
                <form action="alterar_animal.php">
                    Nome <input type="text" name="nome" value="<?php echo $nome?>"/><br><br>
                    Porte <input type="text" name="porte" value="<?php echo $porte?>"/><br><br>
                    Descricao <input type="text" name="descricao" value="<?php echo $descricao?>"/><br><br>
                    <td>
                        <img src="<?php echo "./Imagens/".$foto?>"width="260" height="200"/>
                    </td><br>
                    Foto <input type="file" name="foto"/><br><br>
                    
                    <input type="submit"value="Alterar"/>
                </form>
            </input>
        </div>
    </body>
</html>
<form action="consultar_animalForms.php">
    <input type="submit" value="Pesquisar novamente">
</form>
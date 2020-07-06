<html>
    <head>
        <meta charset="UTF-8">
        <title>Alterar</title>
        <link rel="styleshhet" href="estilo/estilo.css"/>
        <?php
            $nome = filter_input(INPUT_GET, "nome");
            $cpf = filter_input(INPUT_GET,"cpf");
            $endereco = filter_input(INPUT_GET,"endereco");
            $data_nascimento = filter_input(INPUT_GET,"data_nascimento");
            $email = filter_input(INPUT_GET,"email");
            $senha = filter_input(INPUT_GET,"senha");
        ?>
    </head>
    <body>
        <div cpf="conteudo">
            <h1>Alterar dados</h1>
            <p>
                <form action="alterar_usuario.php">
                    Nome <input type="text" name="nome" value="<?php echo $nome?>"/><br><br>
                    CPF <input type="text" name="cpf" value="<?php echo $cpf?>"/><br><br>
                    Endereço <input type="text" name="endereco" value="<?php echo $endereco?>"/><br><br>
                    Data de nascimento <input type="text" name="data_nascimento" value="<?php echo $data_nascimento?>"/><br><br>
                    Email <input type="text" name="email" value="<?php echo $email?>"/><br><br>
                    Senha <input type="text" name="senha"/><br><br>
                    <input type="submit"value="Alterar"/>
                </form>
            </input>
        </div>
    </body>
</html>
<form action="consultar_usuario.php">
    <input type="submit" value="Pesquisar novamente">
</form>
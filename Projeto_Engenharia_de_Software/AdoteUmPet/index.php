
<html>
<head>
    <!--TELA DE LOGIN-->
    <title>ADOTE UM PET</title>

</head>
    <body background="ImagensAleatorias/fundo1.jpeg">
</body>

<form id='login' action='conexao.php' method='POST' accept-charset='UTF-8'>
<fieldset >
    <center>
    <h1><legend>Login</legend></h1>
<input type='hidden' name='submitted' id='submitted' value='1'/>

<h3><label for='username' >Email*:</label>
<input type='text' name='email' id='email'  maxlength="50" /></h3>

<h3><label for='password' >Senha*:</label>
<input type='password' name='senha' id='senha' maxlength="50" /></h3>

<input type='submit' name='Logar' value='LOGAR' />

</form><br>
<form action="cadastrar_usuarioForm.php">
    <input type="submit" value="CADASTRAR">
    </center>

</form>
</fieldset>
</html>



from decimal import *
import psycopg2
from psycopg2.extensions import AsIs

class Produto():
    def __init__(self, productid, productname, supplierid, categoryid, quantityperunit, unitprice, unitsinstock, unitsonorder, reorderlevel, discontinued):
        self.id = productid
        self.nome = productname
        self.fornecedor = supplierid
        self.categoria = categoryid
        self.quantidadeEmbalagem = quantityperunit
        self.precoUnitario = unitprice
        self.estoque = unitsinstock
        self.vendas = unitsonorder
        self.nivel = reorderlevel
        self.descontinuado = discontinued


    def criaProduto(listaValores):
        return Produto(int(listaValores[0]), str(listaValores[1]), int(listaValores[2]), int(listaValores[3]),
             str(listaValores[4]), Decimal(listaValores[5]),
             int(listaValores[6]), int(listaValores[7]), int(listaValores[8]), str(listaValores[9]))


    def cadastraProduto(produto):
        string_sql = 'INSERT INTO northwind.products (productid, productname, supplierid, categoryid, quantityperunit, unitprice, ' \
                     'unitsinstock, unitsonorder, reorderlevel, discontinued) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s)'
        record_to_insert = (produto.id, produto.nome, produto.fornecedor, produto.categoria, produto.quantidadeEmbalagem, produto.precoUnitario, produto.estoque, produto.vendas, produto.nivel, produto.descontinuado)
        conn_string = "host='localhost' dbname='Northwind' user='postgres' password='root'"

        # iniciar a inserção do registro
        conn = None
        try:
            # abrir a conexão
            conexao = psycopg2.connect(conn_string)

            # abrir a sessão - a transação começa aqui
            sessao = conexao.cursor()

            # Executar a inserção na memória RAM
            sessao.execute(string_sql, record_to_insert)

            # Comitar a inserção - fechar a transação
            conexao.commit()

            # Encerrar a sessão
            sessao.close()

        except psycopg2.Error:
            print("error")
        finally:
            if conn is not None:
                print("O registro foi inserido com sucesso")
                conn.close()

    def deletaproduto(id):
        conn_string = "host='localhost' dbname='Northwind' user='postgres' password='root'"
        string_sql = 'DELETE FROM northwind.products WHERE productid = %s;'
        # iniciar a inserção do registro
        conn = None
        try:
            # abrir a conexão
            conexao = psycopg2.connect(conn_string)

            # abrir a sessão - a transação começa aqui
            sessao = conexao.cursor()

            # Executar a remoção na memória RAM
            sessao.execute(string_sql, [id])

            # Comitar a remoçao - fechar a transação
            conexao.commit()

            # Pegar a quantidade de registros afetados
            count = sessao.rowcount

            # Encerrar a sessão
            sessao.close()

        except psycopg2.errorcodes.lookup() as e:
            print(e)
        finally:
            print(count, "Registros Apagados!")
            if conn is not None:
                conn.close()

    def consultaproduto(id):
        conn_string = "host='localhost' dbname='Northwind' user='postgres' password='root'"
        string_sql = 'SELECT * FROM northwind.products WHERE productid = %s;'
        # iniciar a inserção do registro
        conn = None
        try:
            # abrir a conexão
            conexao = psycopg2.connect(conn_string)

            # abrir a sessão - a transação começa aqui
            sessao = conexao.cursor()

            # Executar a consulta
            sessao.execute(string_sql, [id])

            #Armazenar os resultados
            registros = sessao.fetchall()

            # Comitar para fechar a transação
            conexao.commit()

            # Encerrar a sessão
            sessao.close()

        except psycopg2.Error:
            print("error")
        else:
            if conn is not None:
                conn.close()
            prod = Produto.criaProduto(registros[0])
            return prod

    def atualizavaloresupdate(l):
        string_sql = """UPDATE northwind.products SET %s = %s WHERE productid = %s"""
        record_to_insert = ((AsIs(l[1])), int(l[2]), int(l[0]))
        conn_string = "host='localhost' dbname='Northwind' user='postgres' password='root'"
        # iniciar a atualização do registro
        conn = None
        try:
            # abrir a conexão
            conexao = psycopg2.connect(conn_string)

            # abrir a sessão - a transação começa aqui
            sessao = conexao.cursor()

            # Executar a remoção na memória RAM
            sessao.execute(string_sql, record_to_insert)

            # Comitar a remoçao - fechar a transação
            conexao.commit()

            # Pegar a quantidade de registros afetados
            count = sessao.rowcount

            # Encerrar a sessão
            sessao.close()

        except (Exception, psycopg2.DatabaseError) as error:
            print(error)
        finally:
            print("O registro foi atualizado com sucesso")
            if conn is not None:
                conn.close()


class Pedido():
    def consultarelatorio(id):
        if (id == -1):
            string_sql = """SELECT * FROM northwind.relatorio"""
        else:
            string_sql = """SELECT * FROM northwind.relatorio WHERE numpedido = %s"""

        conn_string = "host='localhost' dbname='Northwind' user='postgres' password='root'"

        # iniciar a consulta
        conn = None
        try:
            # abrir a conexão
            conexao = psycopg2.connect(conn_string)

            # abrir a sessão - a transação começa aqui
            sessao = conexao.cursor()

            # Executar a consulta
            if (id == -1):
                sessao.execute(string_sql)
            else:
                sessao.execute(string_sql, [id])

            # Armazenar os resultados
            registros = sessao.fetchall()
            colnames = [desc[0] for desc in sessao.description]

            # Comitar a inserção - fechar a transação
            conexao.commit()

            # Encerrar a sessão
            sessao.close()

        except psycopg2.Error:
            print("error")
        finally:
            if conn is not None:
                conn.close()
        return (colnames, registros)

    def cadastraVenda(dadospedido, listaprodutos):
        string_SQL_pedido = """INSERT INTO northwind.orders(orderid, customerid, employeeid, orderdate, requireddate, shippeddate, freight, shipname, shipaddress, shipcity, shipregion, shippostalcode, shipcountry, shipperid) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"""
        pedido_to_insert = (dadospedido)
        conn_string = "host='localhost' dbname='Northwind' user='postgres' password='root'"

        # iniciar a inserção do registro
        conn = None
        try:
            # abrir a conexão
            conexao = psycopg2.connect(conn_string)

            # abrir a sessão - a transação começa aqui
            sessao = conexao.cursor()

            # Executar a inserção do pedido na memória RAM - TABELA ORDERS
            sessao.execute(string_SQL_pedido, pedido_to_insert)

            # Executar a inserção dos produtos na memória RAM - TABELA ORDERDETAILS
            for i in listaprodutos:
                string_SQL_produto = """INSERT INTO northwind.order_details(orderid, productid, unitprice, quantity, discount) VALUES (%s, %s, %s, %s, %s);"""
                sessao.execute(string_SQL_produto, (i.idPedido, i.idProduto, i.preco, i.quantidade, i.desconto))

            # Comitar a inserção - fechar a transação
            conexao.commit()

            # Encerrar a sessão
            sessao.close()


        except (Exception, psycopg2.DatabaseError) as error:
            print(error)
        finally:
            print("A venda foi cadastrada com sucesso")
            if conn is not None:
                conn.close()

class OrderDetails():
    def __init__(self, orderid, productid, unitprice, quantity, discount):
        self.idPedido = orderid
        self.idProduto = productid
        self.preco = unitprice
        self.quantidade = quantity
        self.desconto = discount

    def alteraVenda(dadospedido):
        string_SQL = """UPDATE northwind.order_details SET quantity = %s WHERE orderid = %s AND productid = %s"""
        record_to_insert = (dadospedido[2],dadospedido[0], dadospedido[1])
        conn_string = "host='localhost' dbname='Northwind' user='postgres' password='root'"
        # iniciar a inserção do registro
        conn = None
        try:
            # abrir a conexão
            conexao = psycopg2.connect(conn_string)

            # abrir a sessão - a transação começa aqui
            sessao = conexao.cursor()

            # Executar a alteração do pedido na memória RAM
            sessao.execute(string_SQL, record_to_insert)
            # Comitar a inserção - fechar a transação
            conexao.commit()

            # Encerrar a sessão
            sessao.close()

        except (Exception, psycopg2.DatabaseError) as error:
            print(error)
        finally:
            print("O registro foi atualizado com sucesso")
            if conn is not None:
                conn.close()
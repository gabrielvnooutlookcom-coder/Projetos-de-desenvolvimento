begin;

insert into venda (idcliente, data, total) 
values (1, now(), 757.96);

insert into listaprodutovenda (idvenda, idproduto, quantidade) 
values (last_insert_id(), 1, 1.00);

insert into listaprodutovenda (idvenda, idproduto, quantidade) 
values (last_insert_id(), 2, 1.00);

commit;

START TRANSACTION;

begin;

insert into venda (idcliente, data, total) 
values (1, now(), 757.96);

insert into listaprodutovenda (idvenda, idproduto, quantidade) 
values (last_insert_id(), 1, 1.00);

-- como não inserio o segundo produto a transação não vai ser concluida

rollback;
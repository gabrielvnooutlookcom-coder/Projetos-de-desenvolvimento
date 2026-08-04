-- exercicio 3
alter table clientes
add column datadenascimento date after nome;

alter table clientes 
add column sexo enum('M' , 'F') after nome;


alter table clientes drop column total;


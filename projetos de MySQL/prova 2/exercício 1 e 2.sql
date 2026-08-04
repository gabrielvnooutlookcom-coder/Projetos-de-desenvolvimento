-- exercicio 1 e 2
create database empresa
default character set utf8mb3
default collate utf8mb3_general_ci;

use empresa;

create table clientes(
	id integer not null auto_increment,
	nome varchar(120),
    cpf char(14),
    rg varchar(20),
    telefone varchar(120),
    email varchar(120),
    primary key(id)
) default charset = utf8;
describe clientes;

create table venda(
	idvenda integer not null auto_increment,
    idcliente integer not null,
    data datetime,
    total decimal(10,2),
    primary key(idvenda),
    foreign key(idcliente) references clientes(id)
)default charset = utf8;

create table listaprodutovenda(
	idlistaprodutosvenda integer not null auto_increment,
    idvenda integer not null,
    idproduto integer not null,
    quantidade decimal,
    primary key(idlistaprodutosvenda),
	foreign key(idvenda) references venda(idvenda),
    foreign key(idproduto) references produtos(idproduto)
)default charset = utf8;

create table produtos(
	idproduto integer not null auto_increment,
    nome varchar(120),
    preco decimal(10,2),
    descricao text,
    primary key(idproduto)
)default charset = utf8;

insert into clientes values 
(default,'Carlos','098.345.291-09','345689','65 99163204','carlos.gim@gmail.com'),
(default,'Lucas','045.298.461-04','985721','65 99173208','lucas.gab@outlook.com'),
(default,'Bruno','037.891.371-03','763928','65 99238702','bruno.san@gmail.com'),
(default,'Arthur','073.872.194-05','473894','65 99184598','arthur.sim@outlook.com'),
(default,'Luan','082.765.473-02','343580','65 99348174','luan.sou@gmail.com');
select*from clientes;

insert into produtos values
(default,'tenis', '500', 'tenis de corrida'),
(default,'chinelo', '30.75', 'chinelo branco'),
(default,'cueca', '10.34', 'cueca box'),
(default,'camisa polo', '76.52', 'camisa polo branca e preta'),
(default,'calça', '140.35', 'calça reta preta'),
(default,'tenis', '734.68', 'air force 1'),
(default,'short', '100.45', 'short bag branco'),
(default,'camiseta ', '80.45', 'azul escuro marinho'),
(default,'camisa', '100', 'preta owersize'),
(default,'chinelo', '170.83', 'preto  slide da puma');

update produtos set nome = 'chinelo slide' where idproduto = 10;

select*from produtos;


insert into listaprodutovenda  values

(default,1, 1, 1.00),
(default,1, 2, 1.00),


(default,2, 3, 1.00),
(default,2, 4, 1.00),
(default,2, 5, 1.00),


(default,3, 7, 1.00),
(default,3, 8, 1.00),
(default,3, 9, 1.00),


(default,4, 6, 1.00),
(default,4, 10, 1.00),


(default,5, 7, 1.00),
(default,5, 8, 1.00);
select * from listaprodutovenda;

insert venda values
(default,1, '2026-07-12 14:30:00', 530.75),   
(default,2, '2026-07-12 15:00:00', 227.21),  
(default,3, '2026-07-12 15:45:00', 280.90),  
(default,4, '2026-07-12 16:20:00', 905.51),  
(default,5, '2026-07-12 17:10:00', 180.90);

select * from clientes;
update clientes set rg = '850278', telefone = '65 99349120', email = 'mateus.fag@outlook.com' where id = 6;
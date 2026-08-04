create database CADASTRO
default character set utf8
default collate utf8_general_ci;

use cadastro;

create table vinicius(
id int not null auto_increment,
nome varchar(30) not null,
nascimento date,
sexo enum('M', 'F'),
altura decimal(5,2),
peso decimal(3,2),
nacionalidade varchar(20) default 'Brasil',
primary key (id)
) default charset = utf8;
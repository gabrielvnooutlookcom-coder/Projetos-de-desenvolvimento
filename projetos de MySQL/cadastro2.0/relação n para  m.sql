#RELAÇÃO DE MUITOS PARA MUITOS
-- criação da tabela que vai representar a relção entre duas tabelas:
use cadastro;
create table g_assiste_c(
	id int not null auto_increment,
    data date,
    idgafanhoto int,
    idcursos int,
    primary key (id),
    foreign key (idgafanhoto) references gafanhotos(id),
    foreign key (idcursos) references cursos(idcurso)
) default charset = utf8;

insert into g_assiste_c values (default, '2014-03-04','1','2');

select * from g_assiste_c; 

select g.nome, c.idcurso from gafanhotos g join g_assiste_c g_
on g.id = g_.idgafanhoto 
join cursos c on c.idcurso = g_.idcursos 
order by g.nome;
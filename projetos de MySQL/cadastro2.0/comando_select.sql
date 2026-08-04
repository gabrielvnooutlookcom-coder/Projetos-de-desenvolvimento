select * from gafanhotos;
select * from cursos;

#filtrar as colunas
select ano, nome, totaulas from cursos
order by ano, nome;

#filtrar as linhas
select * from cursos
where ano = '2016'
order by nome;

#between = entre;
select nome, ano from cursos
where ano between 2014 and 2016 
order by ano desc, nome;

#in = dentro
select nome, descricao, ano from cursos
where ano in (2014,2018,2020)
order by ano desc, nome;

#dados relacionais (e, ou)
select nome, carga, totaulas from cursos 
where carga > 35 and totaulas <= 30;

# o like serve para pegegar dados semelhentes / o % serve para indicar qualquer valor ou nenhum valor antes ou depois da letra(ou palavra).
select * from cursos where nome like '%A%';

# o '_' serve para indicar que TEM que ter algo depois ou antes da letra( ou palavra).
select * from cursos where nome like 'ph%p_';

# os distintct vai mostrar apenas os dados uma vez cada, ou seja os dados que se repetem vao aparecer só uma vez;
select distinct carga from cursos;

-- AGREGAÇÃO:
# count, conta quantos elementos tem a tabela.
select count(*) from cursos;

# max, vai selecionar o maior dado de uma coluna da tabela.
select max(carga) from cursos;

# min, vai selecionar o menor dado de uma coluna da tabela.
select min(carga) from cursos;

# sum, soma os dados de uma coluna da tabela escolhida.
select sum(totaulas) from cursos;

# avg, faz a media dos dados de uma coluna da tabela escolhida.
select avg(totaulas) from cursos;

# Agrupamento(group by) e having:
-- ex1
select totaulas, count(*) from cursos group by totaulas order by totaulas;
-- ex2
select carga, count(nome) from cursos where totaulas = 30 group by carga;
-- ex3
select ano, count(*) from cursos where totaulas > 30 group by ano having ano > 2013 order by count(*) desc;

#select dentro de outro select:
select avg(carga) from cursos;
select carga, count(*) from crusos where ano > 2015 group by carga having carga > (select avg(carga) from cursos);



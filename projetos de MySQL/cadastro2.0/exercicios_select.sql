-- 1° lista de exercicios

#exercicio 1:
select nome from gafanhotos where sexo = 'f';

#exercicio 2:
select * from gafanhotos where nascimento between '2000-01-01' and '2015-12-31' order by nascimento;

#exercicio 3:
select nome,profissao,nascimento from gafanhotos where profissao = 'Programador' and sexo = 'm' order by nascimento,nome;

#exercicio 4:
select * from gafanhotos where nacionalidade = 'Brasil' and sexo = 'f' and nome like 'J%';

#exercicio 5:
select nome, nacionalidade from gafanhotos where sexo = 'm' and nome like '%Silva%' and peso < 100 and nacionalidade != 'Brasil';

#exercicio 6:
select max(altura) from gafanhotos where sexo = 'm';

#exercicio 7:
select avg(peso) from gafanhotos;

#exercicio 8:
select min(peso) from gafanhotos where nacionalidade != 'Brasil' and nascimento between '1990-01-01' and '2000-12-31';

#exercicio 9:
select count(*) from gafanhotos where sexo = 'm' and altura > 1.90;

-- 2° lista de exercicios

#exercicio 1:
select profissao, count(*) from gafanhotos group by profissao order by count(*);

#exercicio 2:
select sexo, count(*) from gafanhotos where nascimento > '2005-01-01' group by sexo order by sexo;

#exercicio 3:
 select nacionalidade, count(*) from gafanhotos where nacionalidade != 'Brasil' group by nacionalidade having count(nacionalidade) > 3 order by nacionalidade;
 
#exercicio 4:
select avg(altura) from gafanhotos;
select nome, peso, altura, count(*) from gafanhotos where peso > 100 group by altura having altura > (select avg(altura) from gafanhotos) order by altura; 

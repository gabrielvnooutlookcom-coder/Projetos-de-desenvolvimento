#JOIN
select nome, ano from cursos;

select nome, cursopreferido from gafanhotos;

#inner join:
-- as -> serve para colocar apelidos na tabela.
select g.nome, c.nome, c.ano from gafanhotos as g 
join cursos as c on c.idcurso = g.cursopreferido; 

#outer join:
-- com esse join eu posso priorizar a tabela da esquerda(left) ou a dá direita(right).
select g.nome, c.nome, c.ano from gafanhotos as g 
 left join cursos as c on c.idcurso = g.cursopreferido; 
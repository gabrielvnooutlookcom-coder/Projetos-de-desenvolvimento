-- exercicio 4
use empresa;

-- a)
select * from clientes;

-- b)
select * from produtos order by preco;

-- c)
select c.nome, v.idvenda, v.data from venda as v
join clientes as c on v.idcliente = c.id;

-- d)
select c.nome, sum(v.total) as total_vendas from venda as v
join clientes as c on v.idcliente = c.id
group by c.id, c.nome order by total_vendas desc;

-- e)
select p.nome, sum(l.quantidade) as quant from produtos as p
join listaprodutovenda as l on l.idproduto = p.idproduto
group by p.nome, p.idproduto order by quant desc
limit 5;

-- f)
select c.id, c.nome, c.email, c.telefone from clientes as c
left join venda as v on c.id = v.idcliente 
where v.idvenda is null;

-- g)
select date_format(data, '%Y-%m'),
sum(total) from venda 
group by date_format(data, '%Y-%m') 
order by date_format(data, '%Y-%m') asc;

-- h)
select idvenda, data,total from venda where total > 500;




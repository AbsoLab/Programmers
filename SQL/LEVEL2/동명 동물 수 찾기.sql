SELECT name, count(name) as cnt
from animal_ins
where name is not null
group by name
having cnt > 1
order by name

#if 0
其实不管什么数据库，index（索引）是在经常查询的column上建立的，虽然它可以加快查
询，但是如果表中经常有DML语句（增删改）的话，反而会成为数据库的负担，所以如果
笼统的来讲的话，就是你经常要去找，要去匹配的字段，比如姓名，员工编号啊等等。
索引：


使用索引可快速访问数据库表中的特定信息。索引是对数据库表中一列或多列的值进行排序
的一种结构，例如  employee 表的姓(name)列。如果要按姓查找特定职员，与必须搜索表中
的所有行相比，索引会帮助您更快地获得该信息。
索引是一个单独的、物理的数据库结构，它是某个表中一列或若干列值的集合和相应的指向
表中物理标识这些值的数据页的逻辑指针清单。
索引提供指向存储在表的指定列中的数据值的指针，然后根据您指定的排序顺序对这些指针
排序。数据库使用索引的方式与您使用书籍中的索引的方式很相似：它搜索索引以找到特定
值，然后顺指针找到包含该值的行。
在数据库关系图中，您可以在选定表的―索引/键‖属性页中创建、编辑或删除每个索引类型。
当保存索引所附加到的表，或保存该表所在的关系图时，索引将保存在数据库中。
注意：
并非所有的数据库都以相同的方式使用索引。作为通用规则，只有当经常查询索引列中的数
据时，才需要在表上创建索引。索引占用磁盘空间，并且降低添加、删除和更新行的速度。
在多数情况下，索引用于数据检索的速度优势大大超过它的不足之处。但是，如果应用程序
非常频繁地更新数据或磁盘空间有限，则可能需要限制索引的数量。
可以基于数据库表中的单列或多列创建索引。多列索引使您可以区分其中一列可能有相同值
的行。
如果经常同时搜索两列或多列或按两列或多列排序时，索引也很有帮助。例如，如果经常在
同一查询中为姓和名两列设置判据，那么在这两列上创建多列索引将很有意义。
确定索引的有效性：
  检查查询的  WHERE 和  JOIN 子句。在任一子句中包括的每一列都是索引可
以选择的对象。
  对新索引进行试验以检查它对运行查询性能的影响。
  考虑已在表上创建的索引数量。最好避免在单个表上有很多索引。
  检查已在表上创建的索引的定义。最好避免包含共享列的重叠索引。
  检查某列中唯一数据值的数量，并将该数量与表中的行数进行比较。比较的
结果就是该列的可选择性，这有助于确定该列是否适合建立索引，如果适合，
确定索引的类型。

MySQL何时使用索引
对一个键码使用>, >=, =, <, <=, IF NULL和BETWEEN
1.  SELECT * FROM table_name WHERE key_part1=1 and key_part2 > 5
;


2.  SELECT * FROM table_name WHERE key_part1 IS NULL;
当使用不以通配符开始的LIKE
1.  SELECT * FROM table_name WHERE key_part1 LIKE 'jani%'
在进行联结时从另一个表中提取行时
1.  SELECT * from t1,t2 where t1.col=t2.key_part
找出指定索引的MAX()或MIN()值
1.  SELECT MIN(key_part2),MAX(key_part2) FROM table_name where
key_part1=10
一个键码的前缀使用ORDER  BY或GROUP BY
1.  SELECT * FROM foo O RDER BY key_part1,key_part2,key_part3
在所有用在查询中的列是键码的一部分时间
1.  SELECT key_part3 FROM table_name WHERE key_part1=1


MySQL何时不使用索引
如果MySQL能估计出它将可能比扫描整张表还要快时，则不使用索引。例如如果key_part1
均匀分布在1和100之间，下列查询中使用索引就不是很好：
1.  SELECT * FROM table_name where key_part1 > 1 and key_part1 < 90

如果使用HEAP表且不用=搜索所有键码部分。
在HEAP表上使用ORDER BY。
如果不是用键码第一部分
1.  SELECT * FROM table_name WHERE key_part2=1
如果使用以一个通配符开始的LIKE


1.  SELECT * FROM table_name WHERE key_part1 LIKE '%jani%'
搜索一个索引而在另一个索引上做ORDER  BY
1.  SELECT * from table_name WHERE key_part1 = # ORDER BY key2

#endif

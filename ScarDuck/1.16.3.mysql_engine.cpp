
#if 0
mysql有多种存储引擎:MyIS AM、InnoDB、MERGE、MEMORY( HEAP)、BDB( BerkeleyDB)、
EXAMP LE、FEDERATED、ARCHI VE、CS V、BLACKHOLE。


MySQL支持数个存储引擎作为对不同表的类型的处理器。MySQL存储引擎包括处理事务
安全表的引擎和处理非事务安全表的引擎：
·          MyISAM管理非事务表。它提供高速存储和检索，以及全文搜索能力。MyISAM在所
有MySQL配置里被支持，它是默认的存储引擎，除非你配置MySQL默认使用另外一个引
擎。
·          MEMORY存储引擎提供―内存中‖表。MERGE存储引擎允许集合将被处理同样的
MyISAM表作为一个单独的表。就像MyIS AM一样，MEMORY和MERGE存储引擎处理
非事务表，这两个引擎也都被默认包含在MySQL中。
注释：MEMORY存储引擎正式地被确定为HEAP引擎。
·          InnoDB和BDB存储引擎提供事务安全表。BDB被包含在为支持它的操作系统发布
的MySQL-Max二进制分发版里。InnoDB也默认被包括在所有MySQL 5.1二进制分发版里，
你可以按照喜好通过配置MySQL来允许或禁止任一引擎。
·          EXAMPLE存储引擎是一个―存根‖引擎，它不做什么。你可以用这个引擎创建表，但
没有数据被存储于其中或从其中检索。这个引擎的目的是服务，在MySQL源代码中的一个
例子，它演示说明如何开始编写新存储引擎。同样，它的主要兴趣是对开发者。
·          NDB Cluster是被MySQL Cluster用来实现分割到多台计算机上的表的存储引擎。它
在MySQL-Max 5.1二进制分发版里提供。这个存储引擎当前只被Linux, Solaris, 和Mac OS
X 支持。在未来的MySQL分发版中，我们想要添加其它平台对这个引擎的支持，包括
Windows。
·          ARCHI VE存储引擎被用来无索引地，非常小地覆盖存储的大量数据。
·          CSV存储引擎把数据以逗号分隔的格式存储在文本文件中。
·          BLACKHOLE存储引擎接受但不存储数据，并且检索总是返回一个空集。
·          FEDERATED存储引擎把数据存在远程数据库中。在MySQL 5.1中，它只和MySQL
一起工作，使用MySQL C Client  API。在未来的分发版中，我们想要让它使用其它驱动器或
客户端连接方法连接到另外的数据源。
当年创建一个新表的时候，你可以通过添加一个ENGINE 或TYP E 选项到CREATE T ABLE
语句来告诉MySQL你要创建什么类型的表：
CREATE T ABLE t (i INT) ENGINE = INNODB;
CREATE T ABLE t (i INT) TYPE = MEMORY;
虽然TYPE仍然在MySQL 5.1中被支持，现在ENGINE是首选的术语。

如何选择最适合您的存储引擎呢？


下述存储引擎是最常用的：


·          MyISAM：默认的MySQL插件式存储引擎，它是在Web、数据仓储和其他应用环境
下最常使用的存储引擎之一。注意，通过更改STORAGE_ENGINE配置变量，能够方便地
更改MySQL服务器的默认存储引擎。
·          InnoDB：用于事务处理应用程序，具有众多特性，包括ACID事务支持。
·          BDB：可替代InnoDB的事务引擎，支持COMMIT、ROLLBACK和其他事务特性。
·          Memory：将所有数据保存在RAM中，在需要快速查找引用和其他类似数据的环境下，
可提供极快的访问。
·          Merge：允许MySQL DBA或开发人员将一系列等同的MyIS AM表以逻辑方式组合在
一起，并作为1个对象引用它们。对于诸如数据仓储等VLDB环境十分适合。
·          Archive：为大量很少引用的历史、归档、或安全审计信息的存储和检索提供了完美的
解决方案。
·          Federated：能够将多个分离的MySQL服务器链接起来，从多个物理服务器创建一个
逻辑数据库。十分适合于分布式环境或数据集市环境。
·          Cluster/NDB：MySQL的簇式数据库引擎，尤其适合于具有高性能查找要求的应用程
序，这类查找需求还要求具有最高的正常工作时间和可用性。
·          Other：其他存储引擎包括CSV（引用由逗号隔开的用作数据库表的文件），Blackhole
（用于临时禁止对数据库的应用程序输入），以及Example引擎（可为快速创建定制的插
件式存储引擎提供帮助）。
请记住，对于整个服务器或方案，你并不一定要使用相同的存储引擎，你可以为方案中的每
个表使用不同的存储引擎，这点很重要。


InnoDb 介绍:
InnoDb  存储引擎,支持事务,行锁,外键.InnoDb  设计用来处理大数据量时提供最好的
性能.
InnoDb  提供自己的缓存(buffer pool)  还缓存数据和索引.innodb  把数据和索引存放
到表空间(tablespace) ,表空间是几个磁盘文件或者是原是设备文件(raw disk).  它
不像MyISAM 存储引擎,每个表只是一个文件.(这样在某些系统下最大2G限制).  而Innodb
没有此限制,可以无限扩展.
Mysql4.0 的以后版本都支持innodb  存储.

InnoDb  配置:
innodb  管理的两个磁盘文件是表空间文件和日志文件.
表空间定义:
innodb_data_f ile_path=dataf ile_spec1[;datafile_spec2]...


文件声明格式: file_name:f ile_size[:autoextend[:max:max_f ile_size]]
innodb_data_home_dir  声明文件存放目录.

mysql 读取配置文件的顺序:
`/etc/my.cnf' Global options.
`DAT ADIR/my.cnf' Server-specific options.
`defaults-extra-file' The file specified with the --defaults-extra-file option.
`~/.my.cnf' User-specific options.

内存使用下面的加起来不要超过2G:

innodb_buffer_pool_size
+ key_buffer_size
+ max_connections*(sort_buffer_size+read_buffer_size+binlog_cache_size)
+ max_connections*2MB

InnoDb  参数说明:

innodb_additional_mem_pool_size
存储数据字典信息和内部结构信息,  如果你的表越多,这个需要的内存就越多,如果你预留的
空间不够,就开始象系统申请内存.errlog  会有错误.  缺省设置为1M.
innodb_autoextend_increment
当表空间满时字段扩展大小.

innodb_buffer_pool_size
数据和索引用的缓存大小.一般时系统物理内存的50~80%

#endif

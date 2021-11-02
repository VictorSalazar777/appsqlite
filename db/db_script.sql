create table `datos_personales` (
`id` integer primary key asc,
`nombres` text not null,
`apellidos` text not null,
`dni` text unique not null,
`fecha_de_inscripcion` real not null,
`fecha_de_inscripcion_iso8601_string` text 
);

create table `datos` (
`id` integer primary key autoincrement,
`nombres` text not null,
`apellidos` text not null,
`dni` text unique not null
);

insert into `cliente`(`nombres`, `apellidos`, `dni`) 
values("manuel", "salazar", "12345678");
insert into `cliente`(`nombres`, `apellidos`, `dni`) 
values("nacho", "salazar", "77777777");
select * from `cliente`;
delete from `cliente` where `id` = 7;
delete from `datos` where `id` = 14;
select * from `cliente` where `id` = 2;
create table `cliente` (
`id` integer primary key autoincrement,
`nombres` text not null,
`apellidos` text not null,
`dni` text unique not null
);
create table `cliente2` (
`id` integer primary key autoincrement,
`nombres` text not null,
`apellidos` text not null,
`dni` text  not null
);

insert into `cliente2`(`nombres`, `apellidos`, `dni`) 
values("manuel", "salazar", "12345678");
SELECT * FROM cliente;

select count(*) from `cliente2`;

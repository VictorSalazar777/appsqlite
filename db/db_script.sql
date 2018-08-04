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
values("manuel", "salazar", "40562639");
insert into `cliente`(`nombres`, `apellidos`, `dni`) 
values("felipe", "salazar", "77777777");
select * from `datos`;
delete from `datos` where `id` = 14;

create table `cliente` (
`id` integer primary key autoincrement,
`nombres` text not null,
`apellidos` text not null,
`dni` text unique not null
);

insert into `cliente`(`nombres`, `apellidos`, `dni`) 
values("manuel", "salazar", "40562639");
SELECT * FROM cliente;
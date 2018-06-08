#create database SearchEngine;

use SearchEngine;

create table urllist
(
    id int NOT NULL auto_increment,
    url varchar(200) not null,
	PRIMARY KEY (id)
);

create table wordlist
(
    id int NOT NULL auto_increment,
    word varchar(200) not null,
	PRIMARY KEY (id)
);

create table wordlocation
(
    urlid  int NOT NULL,
    wordid int NOT NULL,
    location int not null
);

create table link
(
    id int NOT NULL auto_increment,
    fromid  int NOT NULL,
    toid    int NOT NULL,
	PRIMARY KEY (id)
);

create table linkwords
(
    linkid int NOT NULL,
    wordid int NOT NULL
);

create index wordidx on wordlist(word);
create index urlidx on urllist(url);
create index wordurlidx on wordlocation(wordid);
create index urltoidx on link(toid);
create index urlfromidx on link(fromid);



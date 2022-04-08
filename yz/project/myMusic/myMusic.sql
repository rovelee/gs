SET NAMES UTF8;
DROP DATABASE IF EXISTS music;
CREATE DATABASE music CHARSET=utf8;
USE music;

/*** 管理员信息 ***/
CREATE TABLE admin(
    aid INT PRIMARY KEY AUTO_INCREMENT,
    aname VARCHAR(32) UNIQUE,
    apwd VARCHAR(32),
    a_email VARCHAR(64),
    a_phone VARCHAR(32)
);

/*** 用户 ***/
CREATE TABLE user(
    uid INT PRIMARY KEY AUTO_INCREMENT,
    uname VARCHAR(32) UNIQUE,
    upwd VARCHAR(32),
    user_name VARCHAR(32),
    email VARCHAR(64) UNIQUE,
    phone VARCHAR(16),
    gender INT,             #0-女 1-男 -1-保密
    vip BOOLEAN,            #0-不是会员 1-是会员
    avatar VARCHAR(128)     #头像图片路径
);

/*** 歌手 ***/
CREATE TABLE singer(
    si_id INT PRIMARY KEY AUTO_INCREMENT,
    sname VARCHAR(32) UNIQUE,    #歌手名
    song_name VARCHAR(32),       #歌曲名
    album VARCHAR(32)            #专辑
);

/*** 专辑 ***/
CREATE TABLE album(
    al_id INT PRIMARY KEY AUTO_INCREMENT,
    album_id INT UNIQUE,
    album_name VARCHAR(32),     #专辑名
    atitle VARCHAR(256),        #专辑介绍
    issue_date DATE,            #发行时间
    song_name VARCHAR(32),      #歌曲名
    song_style VARCHAR(32),      #歌曲风格
    is_charge BOOLEAN,          #专辑是否付费
    FOREIGN KEY(album_id) REFERENCES singer(si_id)
);

/*** 歌曲 ***/
CREATE TABLE song(
    so_id INT PRIMARY KEY AUTO_INCREMENT,
    song_id INT,
    stitle VARCHAR(32) UNIQUE,    #歌曲名
    stime TIME,                   #歌曲时长
    singer_name VARCHAR(32),      #歌手名
    album_id INT,                 #专辑ID
    song_style VARCHAR(32),       #歌曲风格
    is_vip BOOLEAN,               #0-非会员歌曲 1-会员歌曲
    FOREIGN KEY(song_id) REFERENCES singer(si_id),
    FOREIGN KEY(album_id) REFERENCES album(al_id)
);

/*** 创建的歌单 ***/
CREATE TABLE user_create(
    cr_id INT PRIMARY KEY,
    user_id INT,
    is_index BOOLEAN,               #0-不在首页推荐 1-首页推荐
    list_name VARCHAR(32) UNIQUE,   #歌单名
    avatar VARCHAR(128),            #歌单封面图片路径
    FOREIGN KEY(user_id) REFERENCES user(uid)
);

/*** 歌单详情 ***/
CREATE TABLE song_list(
    sl_id INT PRIMARY KEY AUTO_INCREMENT,
    list_id INT,                    #歌单ID,指向创建者
    list_name VARCHAR(32) UNIQUE,   #歌单名
    song_id INT,                    #歌曲ID,指向歌曲
    avatar VARCHAR(128),            #歌单封面图片路径
    FOREIGN KEY(list_id) REFERENCES user_create(cr_id),
    FOREIGN KEY(song_id) REFERENCES song(so_id)
);

/*** 收藏的歌单 ***/
CREATE TABLE user_collect(
    cl_id INT PRIMARY KEY,
    user_id INT,
    list_id INT,                    #歌单ID,指向歌单详情   
    list_name VARCHAR(32) UNIQUE,   #歌单名
    avatar VARCHAR(128),            #歌单封面图片路径
    FOREIGN KEY(user_id) REFERENCES user(uid),
    FOREIGN KEY(list_id) REFERENCES song_list(sl_id)
);

/*** 热歌榜 ***/
CREATE TABLE hotsong_list(
    hot_id INT PRIMARY KEY AUTO_INCREMENT,
    hlist_name VARCHAR(32) UNIQUE
);

/*** 榜单详情 ***/
CREATE TABLE list_details(
    details_id INT PRIMARY KEY AUTO_INCREMENT,
    hot_list_id INT UNIQUE,
    song_id INT,
    details_name VARCHAR(32),
    dtitle VARCHAR(128),
    classify VARCHAR(32),
    FOREIGN KEY(hot_list_id) REFERENCES hotsong_list(hot_id),
    FOREIGN KEY(song_id) REFERENCES song(so_id)
);

/***  ***/

/*** 管理员信息 ***/
INSERT INTO admin VALUES
(NULL,"admin","12138","super@gly.com","13616264656"),
(NULL,"root","12345","super@gly.com","13666768696")
;

/*** 用户信息 ***/
INSERT INTO user VALUES
(NULL,"liang","666666","亮哥","666@163.com","16666666666",1,1,NULL),
(NULL,"taosang","666666","涛哥","999@163.com","16666666666",1,0,NULL),
(NULL,"zhangsan","123456","张三","123@163.com","13635373645",1,0,NULL),
(NULL,"lisi","123456","李四","321@163.com","13634578243",1,0,NULL),
(NULL,"wangwu","123456","王五","132@163.com","13973542731",-1,0,NULL)
;
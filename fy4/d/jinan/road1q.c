inherit ROOM;
void create()
{
  set("short","яТ╧ь╢С╣ю");
  set("long",@LONG
уБйгр╩лУ╤╚нВ╢С╣юё╛╠йж╠©Мю╚ё╛╣юетйгблсмсм╣дбСлОё╛оРдо©иртрЧт╪©╢╣╫╥Гтф
Ёг╣дЁгцеё╛оР╠╠йг╢сг╟╣д[33m║╨л╘╟╡╩╗т╟║╩[32mё╛тЬйгснюЗ╥Гтф╣доюе╝ж╬й©цг╫╗╪рпку╛╣дкЫ
тзё╛©ио╖хГ╫Яря╠╩Ё╞м╒рС╢Схкртн╔уб╢Н╦гн╙си╡ПЁир╩ф╛╥опФ║ё╤╚╠ъм╗оРх╙Ёг╪цдоё╛
ряйги╫╤╚╣ь╫Г║ё
LONG
  );
  	set("exits",([
         "west" :AREA_LAOWU"road2",
         "east" :__DIR__"shanjiao",
               ]));

        set("outdoors", "jinan");
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}


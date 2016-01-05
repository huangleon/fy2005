// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "гЕ╬╡б╔");
        set("long", @LONG
р╩╪ДжЯб╔ё╛╣м╣м╣дё╛ьр╤Нио╣╜╣╜╣да╫╦Жвж║╟гЕ╬╡║╠ё╛б╔дзр╩уе╨Лд╬вюё╛╠йм╡жп
о║йХ╣д╡Еве╪╦ж╩юг╨аё╛р╩ж╩╩╗ф©╢МбДспжб╣д╡Еве╪╦╤Дой╩╗ё╛ЁЩ╢кртмБё╛тынч╠ПнО║ё
нВг╫иор╩лУ╨А╥Ыё╨

			[37mйм╫л╬╩ма[32m

LONG
        );
        set("exits", ([ 
  			"south" : __DIR__"diyuan",
		]));
        set("objects", ([
                __DIR__"npc/girlfi" : 1,
       ]) );
		set("coor/x",-20);
		set("coor/y",130);
		set("coor/z",20);
		setup();
        replace_program(ROOM);
}

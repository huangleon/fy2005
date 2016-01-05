// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "иыйрЦз");
        set("long", @LONG
иыйрЦзйгАти╫ож╢ФхЩ╨╨Цзжп╣др╩©Иё╛╣Я©ло╦жбё╛вжлЕф╝рщё╛╧ЩиыйрЦз╠ЦхКакиы
йри╫ё╛ЦзиоцЗндоЙо╦╪гйЖ╣шмУ╥Биыйр╣джжжжрщйбё╛ртиыйрЦзё╛иыаж╨сн╙╫Гё╛нВтРн╙
[33mиыйри╫[32mё╛╤╚тРн╙[33mл╚йри╫[32mё╛си╢кушоРнВцФё╛╠ЦйгнецШлЛоб╣дЛЬвзвФм╔ё╛нДя╖╥╒т╢╣ь
----- иыажкб║ё
LONG
        );
        set("exits", ([ 
  "northwest" : AREA_SHAOLIN"ent",
  "southwest" : __DIR__"qimu",
  "east" : __DIR__"shuyuan", 
]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

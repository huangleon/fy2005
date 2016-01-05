// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "╣г╥БоьЁг");
        set("long", @LONG
гЮй╞╫ж╣юкФвет╫ю╢т╫╫с╫Эи╫гЬ╠Д╣ц©╡©юфПю╢ё╛сисзю╢ю╢мЫмЫ╣дсн©м╪╚╤Юё╛кЫрт
вВн╙╣гиыйри╫╠ь╬╜ж╝б╥╣д╣г╥БоьЁг╥жмБ╣дххджё╛╣юб╥а╫╠ъ╣Йфлажа╒ё╛иои╫кЫпХ╣др╩
гпё╛уБюОс╕сп╬║сп║ё╣юб╥╣ддоцФспр╩╪рлЗфл╨мр╩╪р╡╪фл║ёнВ╠╠╠Цйгиои╫╣юё╛╨э╢С╣д
б╥ефиоп╢ве[33m║╨Ати╫иыажкб║╩[32mси╢кг╟пп║ё
LONG
        );
        set("exits", ([ 
  		"east" : "/d/fycycle/fywest",
  		"west" : __DIR__"xiaodao1",
  		"northwest" : AREA_SONGSHAN"qimu",
  		"southeast" : __DIR__"bupu",
  		"southwest" : __DIR__"tiepu",
]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",-600);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

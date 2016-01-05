inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "À¥ÂØÉ½Î÷");
        set("long", @LONG
À¥ÂØÉ½µÄÎ÷Â´£¬É½ÂÍÆğ·ü£¬·ç¾°ĞãÀö£¬Ïò±±ÓĞÖøÃûµÄ[33m¶şÀÉÉ½[32m£¬ÉñÏÉ¸ó¡£¾İËµÉ½
Àï»¹×¡×ÅÒ»¸öÈË£¬Õâ¸öÈË°®»¨£¬Ëû×¡µÄµØ·½¾ÍÊÇ×ù»¨º££¬Ò»Æ¬»¨³Ç¡£ÔÚ²»Í¬µÄ¼¾½Ú
ÖĞ£¬ÄÇÀï×ÜÓĞ²»Í¬µÄ»¨Ê¢¿ª£¬Ëû×ÜÊÇ×¡ÔÚ»¨¿ªµÃ×îÊ¢µÄÄÇ¸öµØ·½¡£
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"yuzhu",
		"west" : __DIR__"wild2",
		"north": __DIR__"erlang",
		"south": __DIR__"mroom",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	
}

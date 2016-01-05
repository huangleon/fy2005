inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "¶«²à·å");
        set("long", @LONG
¶«²à·å£¬µ±µØÈË½Ğ¡°ÏÄÅµ¶à¼ª¡±£¬Ë®¾§Ê¯°ãµÄÉ½·å°ÁÈ»ËÊÖÅ£¬ÏñÉÙÄê£¬ĞÛ½¡¸Õ
Òã£¬Éñ²ÊŞÈŞÈ¡£Ñ©ÏßÏÂ±ù´¨Ö±²å±ÌÂÌµÄÔ­Ê¼É­ÁÖ¡£Ñ©É½¡¢ÇÍ±Ú¡¢¶¸ÑÂ¡¢º£×Ó¡¢±ù´¨¡¢
²İ³¡¡¢É­ÁÖ¡¢ÏªÁ÷£¬Ò»Æ¬¾²Ú×¡¢°²Ïê¡£É½½ÅÏÂÓĞÒ»Æ¬Ô°ÁÖ£¬µ±µØÈË½ĞËü[33m¿ì»îÁÖ[32m¡£
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"nianqing",
		"northeast":  __DIR__"mugecuo",
		"southdown": __DIR__"happywood",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1680);
        set("coor/y",620);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}

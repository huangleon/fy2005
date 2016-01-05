inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ÓñÁú·å");
        set("long", @LONG
ÖÕÓÚÀ´µ½ÓñÁú·åÏÂ£¬¾Ş´óµÄÉ½Ó°£¬³ÁÖØµØÑ¹ÔÚ¹ıÍùµÄ³µÂíÉÏ¡£·çÔÚºôºÅ£¬È´Ò²
´µ²»¿ªÄÇÒõÉ­ÆàÃÔµÄÔÆÎí¡£É½Â´ÒõÓ°ÖĞ£¬ÓĞ¼¸¸ö¿ÍÉÌÕıÔÚĞªÏ¢¡£ÏòÎ÷£¬Ò»Ìõ´óµÀ»Æ
ÍÁ·ÉÑï£¬Í¨Ïò[33m±ß³Ç[32m¡£Ïò±±ÔòÊÇÍ¨Ïò[33mÓñÁú·å¶¥[32mµÄÉ½Â·£¬Æéá«¶øòêÑÑÏòÉÏ¡£
LONG
        );
        set("exits", ([ 
		"southeast" : __DIR__"kunlun3",
		"northup" :   AREA_EREN"road0",
		"west":		__DIR__"wild1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-1100);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}

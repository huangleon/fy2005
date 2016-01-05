inherit ROOM;

void create()
{
	set("short", "É½¼äĞ¡Â·");

	set("long", @LONG
ÕâÊÇÌõ²»ÖªÍ¨ÍùºÎ´¦µÄÉ½¼äĞ¡Â·£¬Â·ÅÔµã×º×ÅĞ©»ò»Æ£¬»ò°×£¬»òºì£¬»ò×ÏµÄ
Ğ¡»¨£¬É·ÊÇÈôÈËÏ²°®£¬²»Ô¶´¦µÄ[37mÉ½½§[32mÇá¿ìµÄÁ÷ÌÊ×Å£¬Ï¯Ï¯µÄÇï·çËÍÀ´Ô¶´¦Ğ¡ÕòÉÏ
ÈË¼Ò´¶»ğµÄÏãÆø£¬Äã²»½ûÓĞĞ©¼¢³¦ê¤ê¤£¬²»ÖªµÀºÎ´¦ÄÜÃÙµÃĞ©ºÃ³ÔµÄ·¹²Ë¡£
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"southeast":__DIR__"shanlu1",
		"northwest":__DIR__"shanlu3",
	]) );
	        set("objects", ([
                __DIR__"obj/flower1" : 1,
                __DIR__"obj/brook" : 1,
        ]) );
        set("resource/water",1);
		set("liquid/name","É½½§Ë®");
		set("liquid/type", "water");
		
	set("coor/x",0);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

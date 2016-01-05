inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "É½µÀ");
        set("long", @LONG
É½Â·òêÑÑÇúÕÛ£¬×ªÁË¼¸¸öÍä×ß½ø¹È¿Ú£¬¾°É«ºöÈ»Ò»±ä£¬Ææ·å¹ÖÊ¯£¬²ÔËÉÇàÌÙ£¬
É½É«µş´ä£¬ÖØáÖÇ§·å£¬Ö±ÁîÈËÁªÏëµ½ÖĞÔ­µÄ·ç¹â¡£À¥ÂØÉ½É½ÊÆËäÏÕ¾ø£¬µ«ÕâÌõÂ·È´
ÇÉÃîµØ´©¹ıÈºÉ½¡£ÄÇ[37m¶ñÈË¹È[32m±ãÒş²ØÔÚÕıÊÇÈºÉ½Î§ÈÆµÄ¹Èµ×£¬Èô²»ÊÇÏ¸ĞÄÑ°ÕÒ£¬ÍòÍò
·¢ÏÖ²»ÁË¡£
LONG
        );
        set("exits", ([ 
	"southup" : __DIR__"valleyentry",
	"northdown" : __DIR__"road4",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",40);
	set("map","eren");
	setup();
	replace_program(ROOM);
}

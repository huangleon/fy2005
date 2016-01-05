inherit ROOM;
void create()
{
    set("short", "ÆÕÉúÌÃ");
    set("long", @LONG
ÆÕÉúÌÃ±¾ÊÇÒ»ÔÆÓÎ¸ßÉ®Â·¾­·çÔÆ³Ç¶ºÁôÊ±ËùÉè£¬¸ßÉ®Í¯ĞÄÎ´ãı£¬ÓĞ¸Ğ´ËµØ·çÍÁ
ÈËÇé£¬Ò»Áô¾ÍÊÇÈıÄê¡£Ç×ÊÚÒ»µÜ×Ó¡£¸ßÉ®»ÛÑÛÊ¶Öé£¬´ËµÜ×ÓÄËÈËÖĞÖ®Áú£¬²»µ½ÈıÄê
ÒÑ¾¡Ñ§É®ÈËÒ½Êõ¡£ÌÃÖĞĞüØÒÒ»¿é£º [31m
        		    ÃîÊÖ»Ø´º
[32m
LONG
    );

    set("exits", ([
	"east"    	: __DIR__"swind5",
	"north"		: __DIR__"yangsheng",
      ]) );
    set("objects", ([
	__DIR__"npc/hosowner" : 1,
		"/d/loulan/npc/yao" : 1,

      ]) );
    set("coor/x",-20);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}

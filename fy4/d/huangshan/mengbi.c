// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ÃÎ±ÊÉú»¨");
        set("long", @LONG
Ô¶¼ûËÉº£ÖĞËÊÁ¢×ÅÒ»¸ù¶ÀÌØµÄÊ¯Öù£¬ÏÂ²¿Ö±Èç±Ê¸Ë£¬ÉÏ¶Ë¿áËÆ±Ê¼â£¬±Ê¸ËºÍ±Ê
¼âÖ®¼ä¼ĞÒ»Ê¯·ì£¬¸üÏÔµÃÏóÒ»Ö»×ÔÈ»Ã«±Ê£¬±Ê¼âÖ®ÉÏ¸üÓĞÒ»Öê¹ÅËÉ£¬ÅÌĞıÇúÕÛ£¬Éú
»ú°»È»£¬Õâ¾ÍÊÇÊ¯±ÊËùÉúÖ®»¨¡£Ïà´«µ±ÄêÌ«°×ÔøÔÚ´ËÒ÷Ê«£¬ÓÚÊÇ¹ÖÊ¯Ò²¾ÍÒò¡°ÀîÌ«
°×ÉÙÊ±£¬ÃÎËùÓÃÖ®±ÊÍ·ÉÏÉú»¨£¬ºóÌì²ÅÕ°Òİ£¬ÃûÎÅÌìÏÂ¡±¶ø±»³Æ×÷¡°[33mÃÎ±ÊÉú»¨[32m¡±¡£
LONG
        );
	set("exits", ([ 
  		"south" : __DIR__"sanhua",
	]));
    set("objects", ([
        __DIR__"obj/meng" : 1,
    ]) );
    
    set("outdoors", "huangshan");
	set("coor/x",-90);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

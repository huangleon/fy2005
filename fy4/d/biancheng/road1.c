inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "±ß³Ç¶«ÃÅ");
        set("long", @LONG
Ğ¡³ÇµÄÒ»¶Ë£¬ÊÇÎŞ±ßÎŞ¼ÊµÄ²İÔ­£¬Ğ¡³ÇµÄÁíÒ»¶Ë£¬Ò²ÊÇÎŞ±ßÎŞ¼ÊµÄ²İÔ­¡£Õâ¸ö
[33m±ßÔ­Ğ¡Õò[32m£¬·Â·ğ¾ÍÊÇÌìµØ¼äÎ¨Ò»µÄÒ»Á£Ã÷Öé£¬Ò»Á£Õ³ÂúÁËÊÀË×³¾»ÒµÄÃ÷Öé¡£½ÖµÀËä
²»³¤£¬Ò²²»¿í£¬È´Ò²ÓĞ¼¸Ê®»§µêÈË¼Ò¡£Ì«ÑôÕÕÔÚ½ÖÉÏ£¬ÉÁ×Å½ğ¹â£¬Ğ¡ÕòÔÚÔç´ºµÄº®
·çÖĞ´­Ï¢¡£
LONG
        );
        set("exits", ([ 
	"southeast" : AREA_ZANGBEI"wild7",
	"west" : __DIR__"road2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
	setup();
	replace_program(ROOM);
}

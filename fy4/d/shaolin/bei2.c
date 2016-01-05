// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "±®ÁÖ");
        set("long", @LONG
±®ÁÖ´ÓÓ°±ÚÖ±ÖÁÌìÍõµî£¬ÕâÀïµÄ±®¶àÎªÍâÉ®ËùÁ¢£¬×îÖøÃûµÄµ±ÊôÈÕÉ®ÉÛÔª×«µÄ
¡°[33mÏ¢âÖìøÊ¦µÀĞĞÖ®±®[32m¡±¡£Òæ¼ªÏé×ë¶î£¬·¨È»Êéµ¤¡£¼ÇÊöÁËÃûÉ®Ï¢âÖµÄÉúÆ½£¬Ñ§·ğÖ®
ÈËµ±¿ÉĞ§·ÂÏ¢âÖËùÎª£¬±ØÄÜ³ÉÒ»´ú´óÊ¦¡£
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"bei1",
  		"southeast" : __DIR__"yingbi",
	]));
        set("objects", ([
               BOOKS"skill/xiaocheng_50" : 1,
       	]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "Ã§ÁÖ±ßÔµ");
        set("long", @LONG
³ÁÏãÕòµÄ¶«Ê×ÊÇÒ»Æ¬Ã§ÁÖ£¬Ô½×ßÊ÷ÁÖÔ½ÃÜ£¬Ê÷·ìÖĞÈ÷ÏÂÀ´µÄÑô¹âÒ²±äµÃ°ß°ßµã
µã¡£Ã©²İ½¥ºñ£¬¹àÄ¾´ÔÉú£¬´µÀ´µÄ·çÒ²Ô½·¢µÄÒõÀä³±Êª¡£Ô¶·½ÃÜÁÖµÄÌì¿ÕÉÏÓĞ¼¸Ö»
ÅÌĞıµÄÍºÓ¥£¬·¢³öËºĞÄÁÑ·ÎµÄ½ĞÉù£¬ÁîÈËÃ«¹ÇËÊÈ»¡£ÁÖ±ßÍáÍáÅ¤Å¤µØ¹Ò×ÅÕÅ¸æÊ¾£º
		[33m¡ºÏò¶«Ã§ÁÖ£¬ÃÍÊŞ³öÃ»£¬ÏĞÈËÄªÈë¡»[32m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"groupw1",
  		"west" : AREA_CHENXIANG"cxe3",
	]));
        set("outdoors", "manglin");
	set("NONPC",1);
	set("coor/x",-410);
	set("coor/y",-100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

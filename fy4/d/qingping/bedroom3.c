//XXDER
inherit ROOM;
void create()
{
        set("short", "ÇÞÊÒ");
        set("long", @LONG
ÕâÀïÊÇ·½±¦ÓñµÄ×¡Ëù£¬ÒòÎª°×¼ÒÉÏÏÂÖ»´ËÒ»Âö£¬ËùÒÔ·ÖÍâ³è°®£¬ÎÝÄÚ³ÂÉè½ÔÊÇ
ÉÏÉÏÖ®Ñ¡£¬¸üÓÐ[33mÊé¹ñ[32mÒ»¸ö£¬ÄÚ²ØÖî×Ó°Ù¼Ò£¬´Ë×ÓÄê²»¹ýÊ®¶þ£¬¿É¶ÁÊéÈç´ËÖ®¶à£¬Óë
Ò»°ãº¢Í¯åÄÒì£¬ÈÕºó±Ø³É´óÆ÷¡£Êé¹ñÅÔÊÇÒ»ÉÈ´°×Ó£¬´°Ì¨ÉÏ°ÚÁËÒ»¸ö°×Óñ[33m»¨Æ¿[32m¡£
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "down" : __DIR__"xting",
   ]));

   set("objects", ([
      __DIR__"obj/bookcase": 1,
      __DIR__"obj/vase": 1,
   ]) );
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
	
}

void reset()
{
   	object *inv;
   	object item1, item2, bookcase;
   	::reset();

   	bookcase = present("bookcase", this_object());
   	inv = all_inventory(bookcase);
   	if( !sizeof(inv)) {
      		item1 = new(BOOKS"literate_75");
      		item1->move(bookcase);
      		item2 = new(BOOKS"literate_75");
      		item2->move(bookcase);
   	}
}

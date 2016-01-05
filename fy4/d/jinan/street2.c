// street2.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","¹Û´¨Í¤");
  set("long",@LONG
¼ÃÄÏ´ó½ÖÉÏÕâ¸ö¸»ÀöÌÃ»ÊµÄÍ¤×Ó£¬¾İËµÊÇµ±ÄêØ¤°ïÀÏ°ïÖ÷ÈÎ´È³ö×ÊĞŞİİ¶ø³É£¬
ÒÔ±ãÀ´ÍùÂ·ÈËÕÚ·çµ²Óê¡£Á¢ÓÚ´ËÍ¤£¬¿´×ÅÔ¶·½ãéãéÁ÷¶¯µÄ½­ºÓ£¬ÎÄÈËÑÅ¿ÍÍ»·¢ÆæÏë£¬
Ãû´ËÍ¤Îª¡°¹Û´¨Í¤¡±£¬È¡Òâ×Ô·ò×ÓµÄ¡ºÊÅÕßÈçË¹·ò¡»¡£Î÷Ãæ¼¸´±¸ñµ÷ÇåÑÅµÄ±ğÊûÊÇ
[33mØ¤°ï[32mÔÚ¼ÃÄÏ³ÇĞŞ½¨µÄ×ÜÌÃ¡£Ïò¶«ÈÆ¹ı´óÃ÷ºş£¬±ãÊÇÍ¨ÏòÎåÔÀÖ®Ê×[33m¡ºÌ©É½¡»[32mµÄÉ½µÀ¡£
LONG
  );
  set("exits",([
         "north":__DIR__"street1",
         "southup":__DIR__"street3",
         "west":__DIR__"shungeng",
         "east":__DIR__"lake"
               ]));
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",80);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}


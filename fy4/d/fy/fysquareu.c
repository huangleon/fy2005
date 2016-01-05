#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", HIR"Ìì»ú¸ó"NOR);
    set("long", @LONG
´Óó´ÁúÄ¦ÌìÊ¯ÖùÍùÉÏÒ»²½£¬±ãÊÇ·çÔÆ³ÇÄÚ×îÈÈÄÖ¡¢Ò²ÊÇ×îÁîÈËÏòÍùµÄµØ·½£¬Õâ
ÀïÔ­À´Ö»ÊÇÒ»¸öÆÕÆÕÍ¨Í¨µÄÐ¡Â¥¸ó£¬×Ô´ÓÄÇÒ»ÌìÀ´ÁËÒ»¸öÆÕÆÕÍ¨Í¨µÄÀÏÍ·¶ù£¬Ò»ÇÐ
±ãÈ«±äÁË£¬¾ÍÁ¬ÃûÕðÌìÏÂµÄÐ¡ÀîÌ½»¨£¬ÐÛ°ÔËÄ·½µÄÉÏ¹Ù½ðºç£¬¼ûÁËËûÒ²ÊÇ¹§¹§¾´¾´£¬
ÒòÎª£¬Ëû±ãÊÇ°ÙÏþÉú±øÆ÷Æ×ÉÏÅÅÃûµÚÒ»µÄÌì»úÀÏÈË£¡ÔÚÌì»úÀÏÈËÉí±ß£¬ÎõÎõÈÁÈÁµØ
Î§Âú¸÷É«ÎäÁÖÈËÊ¿£¬¸ÒÇé¶¼ÔÚÏòËûÇë½Ì[0;37m£¨quest£©[0;32mÀ´×Å¡£

  	ÏÐÔÆÒ°º× [0;1;33mÌì»úÀÏÈË[0;32m(Tian ji)

LONG
    );
    set("exits", ([ /* sizeof() == 4 */
		"down" : __DIR__"fysquare",
      ]));
		set("tianji_square",1);
	
    set("objects", ([
			__DIR__"npc/half_god" : 1,
//			__DIR__"npc/center_soldier" : 1,
      ]) );

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",10);
    set("no_fly",1);
    set("no_dazuo",1);
    set("no_study",1);
    set("no_fight",1);
    set("no_magic",1);
    set("brief_objects",0);
    setup();
}

int valid_leave(object who, string dir) {
	if (dir == "down") {
		if (who->query("env/checkbrief") == 0) { 
			who->set("env/brief",0);
		}
	}
	return ::valid_leave(who,dir);
}
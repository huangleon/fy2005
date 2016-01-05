#include <ansi.h>
#include <room.h>
inherit ROOM;

int count;

void create()
{
    set("short",HIR"·çÔÆÌìÏÂ"NOR);
    set("long", @LONG
·ç·çÓêÓê£¬·çÔÆ³ÇµÄÖÐÐÄ¹ã³¡ÒÀ¾ÉÏÊÁÁÈçÐÂ¡£·çµÀÌì½ÖºÍÔÆ½ÖµØÏïÔÚÕâÀï½»»á£¬
ËÄ·½Á¢ÆðÁËºêÎ°µÄ·çÔÆÌìµØËÄ¸ö¼ÀÌ³£¬ÎôÈÕµÄ¹ã³¡È´²¢ÎÞ¶àÉÙ±ä»¯£¬ËäÈ»ÖÐÑëµÄË®
³ØÒÑ¾­¸ÉºÔ£¬ËäÈ»µ±Äê±ÌÂÌµÄ³ØË®ºÍÎ²Î²½ðÓã²»¸´´æÔÚ£¬ÁôÏÂµÄÊÇ¸ö¼¸ÕÉ·½Ô²£¬Éî
²»¼ûµ×µÄ´ó¶´¡£Ë®³ØÅÔµÄó´ÁúÄ¦ÌìÊ¯Öù±¥¾­ËêÔÂ²×É££¬ÒÀÈ»²»Çü²»ÄÓµØËÊÁ¢£¬Ê¯Öù
ÉÏ¾ÅÌõ·ÉÁúÕÅÑÀÎè×¦£¬Ö±Óû³åÌì¶øÈ¥¡£Íù¸ß´¦×ßÒ»²½£¬±ãÊÇÌìÏÂÎÅÃûµÄ[1;31mÌì»ú¸ó[0;32m¡£
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"tiandoor",
	"south" : __DIR__"yundoor",
	"east" : __DIR__"didoor",
	"west" : __DIR__"fengdoor",
	"up":	__DIR__"fysquareu",

//	"down" : "/d/pk/entry",
	//		"up" : "/obj/dungeon/standardmaze/mingyue/entry",
	//		"up2" : "/obj/dungeon/standardmaze/blanche/entry",

      ]));
    set("outdoors", "fengyun");
	set("tianji_square",1);
	
    set("objects", ([
		
//	"/d/bashan/npc/so":1,
      ]) );

    set("coor/x",0);
    set("coor/y",0);
    set("coor/z",0);
    set("no_dazuo",1);
    set("no_study",1);
    
    count=0;
    set("time",time());
    setup();
    // To "load" the board, don't ever "clone" a bulletin board.
    call_other( "/obj/board/fysquare_b", "ÅÌÁúÄ¦ÌìÖù");
}

void reset(){
	::reset();
	set("time",time());
	count++;
}


int refresh(){
	int x;	
	x= 900+query("time")-time();
	if (count>1)
		return x;
	else
		return 99999;
}

int valid_leave(object who, string dir) {
	if (dir == "up") {
		if (who->query("env/checkbrief") == 0) { 
			who->set("env/brief",1);
		}
	}
	return ::valid_leave(who,dir);
}
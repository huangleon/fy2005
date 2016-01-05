//mac's chansi.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","ĞË¹úìøËÂ");
  set("long",@LONG
ÇàÊ¯ÆöÆğµÄÉ½ÃÅÉÏ¿Ì×Å£º[33mĞË¹úìøËÂ[32m¡£ËÂÄÚÆ®À´µÄÕóÕó·ğÏãÈÃµÇÉ½µÄÓÎÈËÏã¿Í¾«Éñ
Ò»Õñ£¬»Øµ´µÄÖÓ¹ÄÖ®ÒôÓÖ¸øÈËÒ»ÖÖËàÄÂµÄ¸Ğ¾õ¡£É½ÃÅÁ½ÅÔµÄ¶ÔÁª¸ñÍâÒıÈË×¢Ä¿£º
[0;1;31m
		Äº¹Ä³¿ÖÓ  ¾ªĞÑÊÀ¼äÃûÀû¿Í
		¾­Éù·ğºÅ  »½»Ø¿àº£ÃÎÃÔÈË		
[0m
LONG
  );
        set("objects", ([
                __DIR__"npc/bonze2" : 2,
		__DIR__"npc/greeting" : 2,
       	]) );
  	set("exits",([
         	"southdown":__DIR__"fudi.c",
         	"north"    :__DIR__"jinggang.c"
       ]));
   
        set("outdoors", "qianfo");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}

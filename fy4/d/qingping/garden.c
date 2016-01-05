inherit ROOM;
#include <command.h>
#include <ansi.h>

void create()
{
        set("short", "ºó»¨Ô°");
        set("long", @LONG
ÕâÀïÊÇÇåÆ½É½×¯µÄºó»¨Ô°£¬»¨Ô°²»´ó£¬¿ÉÊÇ´ËÊ±Õýµ±°Ù»¨Ê¢¿ªÖ®¼Ê£¬Ô°ÖÐÒ»Æ¬
ÀÃÂþ£¬ºûµûôæôæ¡£¿¿½üÔºÇ½´¦³¤ÁËÒ»¿Ã[37mÀÏ»±Ê÷[32m£¬¼´Ê¹ÊÇÔÚÑ×ÈÈµÄÏÄ¼¾£¬Ê÷ÒõÏÂÒ²Á¹
·çË¬Ë¬¡£´ºÌìµÄÊ±ºò£¬ÀÏ»±Ê÷¸üÊÇ¿ªÂúÁËÒ»´®´®½à°×µÄ»¨¶ä£¬Î¢·ç·÷¹ýÄÇ×íÈËµÄ»¨
Ïã¾ÍÆ®ÂúÁËÕû¸öÇåÆ½É½×¯¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"studyroom",
  "south" : __DIR__"xting",
  "east" : __DIR__"pond",
  "west" : __DIR__"neiyuan",
   ]));

   set("item_desc", ([
      "tree" : "Å¨ÃÜµÄÀÏ»±Ê÷½ô¿¿×ÅÔºÇ½£¬Ò»Ö»´Ö´ÖµÄÖ¦¸ÉÒÑÉìµ½ÁËÇ½Íâ¡£\n",
      "ÀÏ»±Ê÷" : "Å¨ÃÜµÄÀÏ»±Ê÷½ô¿¿×ÅÔºÇ½£¬Ò»Ö»´Ö´ÖµÄÖ¦¸ÉÒÑÉìµ½ÁËÇ½Íâ¡£\n",
   ]) );

   set("objects", ([
      __DIR__"npc/yan" : 1,
   ]) );
   	set("outdoors","qingping");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int mlvl;
   
   me = this_player();
   if(!arg || arg != "ÀÏ»±Ê÷" && arg != "tree") return 0; 
   mlvl = (int)me->query_skill("move");
   if(mlvl < 50)
      message_vision("$NÊÔÁËÊÔÀÏ»±Ê÷£¬¿´À´Ã»Ï£ÍûÅÀÉÏÈ¥¡£\n", me);
   else{
      message_vision("$NÉíÊÖ½Ã½¡µØÅÀÉÏÁËÀÏ»±Ê÷¡£\n", me);
      room = find_object(__DIR__"midtree");
      if(!objectp(room)) room=load_object(__DIR__"midtree");
      me->move(room);
   }
   return 1;
}
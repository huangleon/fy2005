// XXDER@fy
inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "»±Ê÷ÉÏ");
        set("long", @LONG
ÄãÏÖÔÚÒÑ¾­ÒþÉíÔÚÀÏ»±Ê÷ÉÏ£¬ÔÚÕâÀïÑô¹âÒ²Í¸²»¹ýÃ¯ÃÜµÄ[33mÊ÷¹Ú[32m¡£ÏòÇ°ÍûÄã¿ÉÒÔ
Çå³þµØ¿´µ½°Ë´óµÜ×Ó¾Ó×¡µÄÔºÂä£¬ÏòºóÍû£¬Õû¸öºó»¨Ô°»¹ÓÐ³ØÌÁ¶¼ÂäÈëÄãµÄÑÛµ×£¬
ÔÙÍùºó£¬Ò»Ìõ¼¸ºõ±»»Ä²ÝÑÍÃ»µÄÐ¡Â·²»ÖªÍ¨ÏòºÎ·½¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "down" : __DIR__"garden",
   ]));

   set("item_desc", ([
   		"treetop" : "Ê÷¹ÚÃ¯ÃÜµÃ¿´²»µ½Ìì¿Õ£¬ÀïÃæËÆºõÓÐÒ»¿éºÚºõºõµÄ¶«Î÷£¬²»¹ýÒªÔÙÍùÉÏÅÀ²Å¿´µÃÇå³þ¡£\n",
		"Ê÷¹Ú" : "Ê÷¹ÚÃ¯ÃÜµÃ¿´²»µ½Ìì¿Õ£¬ÀïÃæËÆºõÓÐÒ»¿éºÚºõºõµÄ¶«Î÷£¬²»¹ýÒªÔÙÍùÉÏÅÀ²Å¿´µÃÇå³þ¡£¡£\n",
   ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",10);
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
   if(!arg || (arg != "ÀÏ»±Ê÷" && arg != "tree" && arg!= "up")) return 0; 
   
   mlvl = (int)me->query_skill("move");
   if(mlvl < 70)
      message_vision("$NÌ§Í·ÏòÉÏÍûÁËÍû£¬ÐÄÀï²»ÓÉµÄÓÐÐ©·¢»Å¡£\n", me);
   else{
      message_vision("$NºÁ²»·ÑÁ¦µÃÍùÉÏÅÀÈ¥¡£\n", me);
      room = find_object(__DIR__"treetop");
      if(!objectp(room)) room=load_object(__DIR__"treetop");
      me->move(room);
   }
   return 1;
}

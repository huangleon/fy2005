//XXDER
inherit ROOM;
void create()
{
        set("short", "³ØÌÁ");
        set("long", @LONG
Ò»¿Ã[33m´¹Áø[32m°ëºáÔÚ³ØÌÁÉÏ£¬ÁøÌõ¼¸ºõÅöµ½ÁËË®Ãæ¡£Ù¼´óµÄÒ»¿ÃÊ÷È´Ö»ÔÚ°¶±ßÁôÏÂ
ºÜĞ¡Ò»¿éÒõÁ¹£¬´ó²¿·ÖµÄÒõÓ°¶¼Í¶ÔÚÁË³ØÌÁÉÏ£¬Ê÷ÅÔÉ¢ÂäµØ·Å×Å¼¸¿éĞÎ×´ÆæÌØµÄÌ«
ºşÊ¯¡£Ò»ÌõĞ¡Â·´ÓÊ÷ºóÈÆµ½ÁË³ØÌÁµÄÁíÒ»Ãæ¡£
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "southeast" : __DIR__"backdoor",
   "southwest" : __DIR__"pond",
   ]));

   set("item_desc", ([
      "tree" : "ÁøÊ÷¼¸ºõºáÎÔÔÚË®ÃæÉÏ£¬ÓÉÓÚÀëË®Ì«½ü£¬Ê÷¸ÉÉÏ³¤ÂúÁËÇàÌ¦¡£\n",
      "´¹Áø" : "ÁøÊ÷¼¸ºõºáÎÔÔÚË®ÃæÉÏ£¬ÓÉÓÚÀëË®Ì«½ü£¬Ê÷¸ÉÉÏ³¤ÂúÁËÇàÌ¦¡£\n",
   ]) );
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
   set("outdoors", "qingping");
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int llvl;
   
   me = this_player();
   if(!arg || arg != "´¹Áø" && arg != "tree") 
      return notify_fail("ÄãÒªÅÀÊ²Ã´ ? \n");
   llvl = (int)me->query("kar");
   if(random(100)<llvl) {
      	message_vision("\n\n$NÑØ×ÅÊ÷¸ÉÂıÂıÅÀÁËÉÏÈ¥£¬×øµ½ÁËºáÔÚºşÃæµÄÁøÊ÷¸ÉÉÏ¡£\n", me);
      	room = find_object(__DIR__"liutree"); 
      	if(!objectp(room)) room=load_object(__DIR__"liutree");
      	me->move(room);
      	message("vision", me->name()+"ÑØ×ÅÊ÷¸ÉÂıÂıÅÀÁËÉÏÀ´£¬×øµ½ÁËÁøÊ÷¸ÉÉÏ¡£\n", environment(me),me);
   }
   else{
      message_vision("\n\n$NÑØ×ÅÊ÷¸ÉĞ¡ĞÄÒíÒíµØÍùÇ°ÅÀ£¬£®£®£®


Í»È»½ÅÏÂÒ»»¬£¬ÆËÍ¨Ò»Éùµô½øÁËË®Àï¡£\n\n", me);
      room = find_object(__DIR__"pond1"); 
      if(!objectp(room)) room=load_object(__DIR__"pond1");
      me->move(room);
      message("vision",me->name()+"ÆËÍ¨Ò»Éù´ÓÉÏÃæµôÁËÏÂÀ´¡£\n",environment(me), me);
   }
   return 1;
}

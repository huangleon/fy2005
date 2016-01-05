#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "É½·å±³ºó");
        set("long", @LONG
·å»ØÊ¯×ª£¬ÄãÑÛÇ°Í»È»Ò»ÁÁ£¬É½ÊÆÔÚ´ËİëÈ»¿ªÀÊ£¬ÉíºóÊÇ°ë±Ú¿´À´²»ÉõÀÎ¿¿µÄ
[36mÇàÊ¯[32m£¬ÑÛÇ°Ò»ÌõĞ¡Â·²»ÖªºÎÊ±×ê³ö£¬ÇÄÎŞÉùÏ¢£¬òêÑÑ½ÅÏÂ£»Ô¶´¦°×ÔÆçÔÈÆ£¬ËÆÓĞÈË
¼Ò£»¶øÄã¶ú±ßÓÖËÆºõÓĞï£ï£ÇÙÉù£¬´ıÒª×¤×ãÏ¸Ìı£¬ÄÇÇÙÉùÈ´ÓÖÎŞÓ°ÎŞ×Ù¡£
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"valley2",
	]) );

	set("item_desc", ([
		"stone" : "ÇàÊ¯ÉÏ¹ÒÂúÌÙÂû£¬È´²»Éõ¼áÀÎ£¬ËÆºõÇáÇáÒ»ÍÆ¾Í¿ÉÒÔ¿ªÁË¡£\n",
		"rock" : "ÇàÊ¯ÉÏ¹ÒÂúÌÙÂû£¬È´²»Éõ¼áÀÎ£¬ËÆºõÇáÇáÒ»ÍÆ¾Í¿ÉÒÔ¿ªÁË¡£\n",
		"ÇàÊ¯" : "ÇàÊ¯ÉÏ¹ÒÂúÌÙÂû£¬È´²»Éõ¼áÀÎ£¬ËÆºõÇáÇáÒ»ÍÆ¾Í¿ÉÒÔ¿ªÁË¡£\n",
		"north" : "Ğ¡É½¶´ÖĞºÚÆáÆáµÄ£¬ÄãÊ²Ã´Ò²¿´²»Çå³ş¡£\n",
	]) );
	set("no_magic", 1);	
	set("no_fly", 1);	

   	set("outdoors","taoyuan");
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init ()
{
	add_action("do_push", "push");

   add_action("do_listen", "listen");
   add_action("do_southeast", "go");
}

int do_southeast(string arg)
{
   object me, room;
   me = this_player();

   if (arg == "southeast")
   if(me->query_temp("marks/listen")) {
/*      if (ANNIE_D->check_buff(me,"fugitive")>0) {
   			tell_object(me,"ÄãÖØ°¸ÔÚÉí£¬»¹ÊÇ²»ÒªÈ¥´ò½ÁÄÇ¸öÊÀÍâÌÒÔ´Ö®µØÁË°É¡£\n");
      		return 1;
      }*/
      tell_object(me, "ÄãÑØ×ÅĞ¡Â·£¬×ßÏòÄÇ°×ÔÆçÔÈÆÖ®´¦¡£\n\n");
      message("vision", me->name(me)+"ÑØ×ÅòêÑÑµÄÉ½Â·×ªÁË¼¸×ª¾ÍÊ§È¥ÁË×ÙÓ°¡£\n", environment(me),me );
      room = find_object(__DIR__"taovillage");
      if(!objectp(room)) room=load_object(__DIR__"taovillage");
      me->move(room);
      return 1;
   }
   return 0;
}

int do_listen(string arg)
{
   object me, room;
   me = this_player();

   tell_object(me,"ÇÙÉùÈôÓĞÈôÎŞ£¬Äã×ĞÏ¸ÔÙÌıÁËÌı£¬ºÃÏóÒşÒşÔ¼Ô¼´Ó¶«ÄÏ±ß´«À´¡£\n");
   message("vision",me->name(me)+"Í»È»×¡×ã£¬ËÆºõÔÚ²à¶úÇãÌı×ÅÊ²Ã´¡£\n", environment(me),me);
   tell_object(me, HIG"\nÒôÀÖÆ½ºÍÊæ»º£¬Ò»Ï´Äã¾Ã´¦½­ºşµÄÉ±·¥Ö®Æø£¬ÄãºöÈ»¸ĞÊÜµ½ÉúÃüµÄÕä¹ó¡£\n\n"NOR);
   tell_object(me, "ÄãÔÙ×ĞÏ¸¿´ÁË¿´ÄÇ¸ö·½Ïò£¬ËÆºõÓĞÒ»ÌõĞ¡Â·´ÓÄÇÀïòêÑÑÉìÏò°×ÔÆçÔÈÆÖ®´¦¡£\n", me);
   me->set_temp("marks/listen", 1);	

   return 1;
}
void close_path()
{
	if( query("exits/north") ) {
    message("vision","ÌÙÂûÇ£×ÅÇàÊ¯ÂıÂıµØºÏÉÏÁË¡£\n",this_object() );
    delete("exits/north");
    }
}

int do_push(string arg)
{
	object me;
    me = this_player();
    if( arg=="stone" || arg =="ÇàÊ¯" || arg == "rock") {
    	message_vision("$NÍùÇàÊ¯ÉÏÇáÇáµØÒ»ÍÆ£¬ÇàÊ¯ÂıÂıµØ×ª¶¯ÆğÀ´£¬Õ¹ÏÖ³öÒ»´¦É½¶´¡£\n", me);
		set("exits/north", __DIR__"treasure");
		call_out("close_path", 3);
	}
	else {
		write("ÄãÒªÍÆÊ²Ã´ÄØ£¿\n");
	}
	return 1;	
 }

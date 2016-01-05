inherit ROOM;
void create()
{
    set("short", "É½¹È");
    set("long", @LONG
Ê÷ÁÖµ½ÁË´Ë´¦Öð½¥±äµÃÏ¡ÊèÆðÀ´£¬ÑÛÇ°ºÕÈ»³öÏÖÒ»×ùÇ§²ãµþ´ä¡¢ÍòÀïµã²ÔµÄÉ½
·å£¬Î§³ÉÒ»´¦ÓÄ¹È£¬ÖÐÓÐÒ»ãüÇåÌ¶£¬ÈªË®´Ó·å¼ä±¼Á÷¶øÏÂ£¬ÅçÖéÐ¹Óñ£¬Ö±ÈëÇåÌ¶¡£
¼¸Ö»°×Î²°ÍµÄÒ°ÍÃ£¬ÕýÔÚÌ¶±ßÓÆÏÐµÄºÈË®¡£´Ë´¦¿ÕÆøÇåÁ¹ÊªÈó£¬ÇßÈËÐÄ·Î£¬ËÄÖÜÈ´
¿´²»¼ûÈÎºÎÃ÷ÏÔµÄ³öÂ·£¬¿´À´£¬ÄãÖ»ºÃËÄ´¦[33m×ª×ª[32m¿´ÁË¡£
LONG
    );
    set("item_desc", ([
    	"ÇåÌ¶":  "ÇåÌ¶Ã÷³º¼ûµ×£¬²»Ê±µÄÓÐÐ¡ÓãÔ½³öË®Ãæ¡£\n",
        "pond":  "ÇåÌ¶Ã÷³º¼ûµ×£¬²»Ê±µÄÓÐÐ¡ÓãÔ½³öË®Ãæ¡£\n",
 		"×ª×ª":	 "×ª×ª¡£¡£¡£¡£Ó¦¸ÃÓÃÊ²Ã´¶¯´ÊÄØ£¿\n",
    ]));
    set("exits", ([ /* sizeof() == 4 */
   		"south" : __DIR__"taolin1",
	]));
    set("outdoors","taoyuan");
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
void init()
{
   add_action("do_around", "around");
}

int do_around(string arg)
{
   object me, room;
   int i;
   
   string *rooms = ({"valley", "valley1", "valley2", "valley3"});
   i = random(4);
   me = this_player();
   tell_object(me, "Äã×ªÀ´×ªÈ¥£¬Ò²Ã»ÕÒµ½³ö¿Ú£¬ÄãÃÔÁËÂ·£¡£¡\n\n");
   room = find_object(__DIR__ + rooms[i]);
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]);
   me->move(room);

   return 1;
}


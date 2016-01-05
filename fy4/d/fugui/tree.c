inherit ROOM;

void create()
{
        set("short", "éªÄ¾Ê÷ÉÏ");
        set("long", @LONG
´ÓÕâÀïÍùËÄÖÜ¿´£¬¼ªÏéÕòµÄÒ»ÇĞ¶¼¾¡À¿ÑÛµ×¡£Ê÷ÏÂËÆºõÊÇ¸ö[37mÔº×Ó[32m¡£
LONG
        );
        set("outdoors", "fugui");
        set("objects", ([
        	__DIR__"npc/bird":2,
        ]) );
        set("exits", ([ 
  		"down" : __DIR__"shilu1",
	]));
	set("item_desc", ([
        "Ê÷": "Ê÷Ò¶µ²×¡ÁËÄãµÄÊÓÏß£¬Ê÷ÏÂËÆºõÊÇ¸öÔº×Ó¡£\n",
        "tree": "Ê÷Ò¶µ²×¡ÁËÄãµÄÊÓÏß£¬Ê÷ÏÂËÆºõÊÇ¸öÔº×Ó¡£\n",
        "Ôº×Ó": "Ê÷Ò¶µ²×¡ÁËÄãµÄÊÓÏß£¬Ö»ÄÜÊ©Õ¹Çá¹¦×²×²ÔËÆøÁË¡££¨£ê£õ£í£ğ£ô£ï£©\n",
        "yard": "Ê÷Ò¶µ²×¡ÁËÄãµÄÊÓÏß£¬Ö»ÄÜÊ©Õ¹Çá¹¦×²×²ÔËÆøÁË¡££¨£ê£õ£í£ğ£ô£ï£©\n",
	]) );
	set("coor/x",30);
	set("coor/y",80);
	set("coor/z",10);
        setup();
}

void init ()
{
        add_action ("do_jumpto", "jumpto");
}

int do_jumpto (string arg)
{
        object me,room;
		int dodge;
		if (!arg || (arg != "yard" && arg != "Ôº×Ó"))
			return notify_fail("ÄãÒªÏòÄÄÀïÌø£¿\n");
		
		me = this_player();
		dodge = me->query_skill("move",1);
		message_vision("\n$NºáÏÂĞÄÀ´£¬±ÕÉÏÑÛ¾¦£¬ÃÍµØÏòÍâÌøÁË³öÈ¥....\n",me); 
		if(!room)
			room = find_object(__DIR__"jinyuan");
			room=load_object(__DIR__"jinyuan");
		if (dodge < 50)
		{
			message_vision("\nÖ»ÌıÒ»ÕóÒÂÉÀËºÁÑºÍÊ÷Ö¦ÕÛ¶ÏµÄÉùÒô£¬È»ºó$NÖØÖØµØË¤µ½ÁËµØÉÏ...\n\n",me);
			me->move(room);
			me->unconcious();
		}
		else
		{
			message_vision("\n$N½è×ÅÊ÷Ö¦·´µ¯Ö®Á¦£¬·ÉÔ½ÁË´Ô´ÔÊ÷Ò¶£¬Ò»ÏÂÌø½øÁË½ğ¸®´óÔº¡£\n\n",me);
	        me->move(room);
	        me->start_busy(1);
		}
		return 1;
}

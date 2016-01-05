/*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "±ù´¨");
        set("long", @LONG
µÚÒ»´Îµ½ÕâÀïµÄÈËÒ»¶¨²»¸ÒÏàĞÅÕâÊÇÕæµÄ£¬¾Ş´óÎŞ±ÈµÄ±ù´¨ÈıÃæ»·É½£¬·ÖÎªÁ½
Ö§£¬ĞÎÎª±ù¶·£¬ÖÜÎ§µÄÉ½Ñ©Ó³Èë[37m±ù´¨[32m£¬Í¸×ÅËµ²»³öµÄ¹ÖÒì¡£Ô¶Ô¶¿´È¥£¬¼òÖ±¾ÍÏóÒ»
¸ö³õÉæÈËÊÀµÄÉÙÅ®Ò»Ñù£¬ÕÀ·Å³öÃÔÈË¶øÓÖÄêÇáµÄ¹â²Ê£¡
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"baiyang",
]));
        set("item_desc", ([
                "±ù´¨": "ÄãÎ§×Å±ù´¨¿´ÁËÓÖ¿´£¬·¢ÏÖ±ù´¨ÀïËÆºõÓĞ×Å¹Å¹Ö£¡»÷£¨£â£ò£å£á£ë£©¿ªËü£¡\n",
                "ice": "ÄãÎ§×Å±ù´¨¿´ÁËÓÖ¿´£¬·¢ÏÖ±ù´¨ÀïËÆºõÓĞ×Å¹Å¹Ö£¡»÷£¨£â£ò£å£á£ë£©¿ªËü£¡\n",
        ]) );
        set("frozen",10);
        //set("no_pk",1);
                
        set("outdoors", "xinjiang");
		set("coor/x",10);
		set("coor/y",-70);
		set("coor/z",0);
		setup();
}

void init()
{
        add_action("do_pour", "pour");
		add_action("do_break", "break");
}

int do_pour(string arg)
{
        object me;
        object con;
        me = this_player();
        if(!arg) return 0;
        if(!objectp(con=present(arg, me)))
        return 0;
        if(!con->query("liquid"))
        return 0;
        if(!con->query("liquid/remaining"))
        	return notify_fail( con->name() + "ÊÇ¿ÕµÄ¡£\n");
        con->add("liquid/remaining", -1);
        message_vision("$NÄÃÆğ" + con->name() + "µ¹ÁËÒ»Ğ©" +
        	con->query("liquid/name")  + "ÔÚº®±ùÉÏ¡£\n",me);
        if(con->query("liquid/name") == "ÈÈË®")
        	tell_object(me,"º®±ù¸Õ¸Õ»¯¿ªÁËÒ»µã¶ù¾ÍÓÖ¶³ÉÏÁË£¡£¡\n");
        if(con->query("liquid/name") == "ÑÎË®")
        {
        	tell_object(me,"Ææ¹ÖµÃºÜ£¬º®±ùÒ»ÓöÑÎË®¾Í¿ªÊ¼½â¶³ÁË£¡£¡\n");
        	add("frozen",-1);
        }
        if( query("frozen") <= 0 )
        {
        	tell_object(me,"º®±ùÖÕÓÚ»¯¿ªÁËÒ»¸öĞ¡¶´£®£®£®\n");
        	if(!query("exits/southwest"))
                set("exits/southwest",__DIR__"gela");
        	call_out("close_path",10);
        }
        return 1;
}

void close_path()
{
        if( !query("exits/southwest") ) return;
        message("vision",
"Æ®¹ıÀ´µÄË®ÆøÕ£ÑÛ¼ä¶³³É±ùÖé£¬½¥½¥µØ·â×¡ÁË¶´¿Ú£®£®\n",
                this_object() );
        delete("exits/southwest");
        set("frozen",30+random(5));
}

int do_break()
{
		object me;
		me = this_player();
		if(me->query("force") < 50)
			return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¡\n");
		me->add("force",-50);
			return notify_fail("Äã·ÉÆğÒ»ÕÆ£¬ÖØÖØµØ»÷ÔÚ±ù´¨ÉÏ£¡É²ÄÇ¼ä±ùĞ¼ºá·É£¬±ù´¨ÉÏµÄÁÑºÛ¸üÉîÁË£¡\n");
}




inherit ROOM;
void create()
{
        set("short", "°×Ñî¹µ");
        set("long", @LONG
°×Ñî¹µÎ»ÓÚÌìÉ½Ö§Âö¿¦À­ÎÚ³ÉÉ½±±Â´ÖĞµ×É½¹ı¶É´ø£¬¹µÖĞ¹ÅÊ÷´ĞÓô£¬³¤Âú¸ß´ó
Í¦°ÎµÄ[37mÓÜÊ÷[32m¡¢[37mÑîÊ÷[32m¡¢[37m»±Ê÷[32m¼°Ëµ²»³öÃû×ÖµÄ[37m¹àÄ¾[32m¡¢ÏÊ»¨¡£¾ÍÊÇÔÚÊ¢ÏÄµÄÑô¹âÏÂ£¬ÕâÀï
»¹ÊÇÇåÁ¹ÎŞ±È£¬ÁîÈË¸Ğµ½ÎŞÏŞÊæ³©¡£
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"chairong",
  		"south" : __DIR__"bingchuan",
  		"east" :  __DIR__"goudi",
	]));

        set("outdoors", "xinjiang");
		set("coor/x",10);
		set("coor/y",-60);
		set("coor/z",0);
		setup();
}

void init()
{
   	add_action("do_look", "look");
}

int do_look(string arg)
{
   	object me;

   	me = this_player();

   	if (arg == "ÓÜÊ÷" || arg == "»±Ê÷" || arg == "¹àÄ¾") {
   		tell_object(me, "°×Ñî¹µÀïËäÈ»¶àµÄÊÇ°×ÑîÊ÷£¬" + arg + "ÒÀÈ»³¤µÃÓôÓô´Ğ´Ğ¡£\n");
   		return 1;
   	}
   		
   	if (arg == "ÑîÊ÷" || arg == "°×ÑîÊ÷" || arg == "yangshu") {
   	  	tell_object(me, "»Ò°×É«µÄÑîÊ÷¸ÉÉÏ½áÂúÁËÒ»¸ö¸öÏóÑÛ¾¦ËÆµÄ°ÌºÛ£¬ÓĞµÄÏóÔÚĞ¦£¬ÓĞ
µÄËÆÔÚ¿Ş£®£®Ä¿¹âËÆºõÕıÂäÔÚµØÉÏÒ»¶ÑĞÂÍÁÉÏ¡£\n");
		me->set_temp("marks/xj_noticed_yangshu",1);
		return 1;
	}

	if ( (arg == "ĞÂÍÁ" || arg == "dirt") && me->query_temp("marks/xj_noticed_yangshu")){
		tell_object(me,"Ò»¶ÑºÖÉ«µÄÄàÍÁ£¬ÏñÊÇ×î½üÓĞÈËÔÚÕâÀïÍÚ¹ıÊ²Ã´¡£\n");
		me->set_temp("marks/xj_noticed_dirt",1);
		return 1;
	}
	
	return 0;
}
	
	
void dig_notify()
{
	object me, box;
	int llvl;
		
	me = this_player();
	llvl = (int)me->query("kar");
	
	box = present("iron box", this_object());
	
	if (!me->query_temp("marks/xj_noticed_dirt")){
		tell_object(me,"ÄãºúÂÒÔÚµØÉÏÍÚÁËÆğÀ´£¬ÍÚ±éÁËÕû¸öÉ½¹µ£¬ÀÛµÃ°ëËÀ¿ÉÊ²Ã´Ò²Ã»ÓĞÕÒµ½¡£\n");
		return;
	}		
		
	if(llvl > 12 ) {
		tell_object(me,"ÄãË³×ÅÄÇĞÂÍÁµÄÎ»ÖÃÍÚÁËÏÂÈ¥¡£\n");
		if (query("already")) {
			tell_object(me,"µØÉÏ³öÏÖÁËÒ»¸öÍÁ¿Ó£¬³ıÁË¸¯ĞàµÄÖ¦Ò¶£¬ÄãÊ²Ã´¶¼Ã»ÓĞ·¢ÏÖ¡£\n",me);  
			return;
		}
		message_vision("îõ£®£®µÃÒ»Éù£¬$NµÄ¸äËÆºõÇÃÔÚÁËÒ»¸öÌú¶«Î÷ÉÏ¡£\n", me);
	    tell_object(me, "µÍÍ·Ò»¿´£¬ÍÁ¿ÓÀïÂ¶³öÁËÒ»¸öÌúºĞ¡£\n");
	    if(!objectp(box)) {
	         box = new(__DIR__"obj/box");
	         box->move(this_object());
			 set("already",1);
	    }
	}
	else
		tell_object(me,"ÄãÔÚµØÉÏ¿ñÂÒµØÍÚÁËÆğÀ´£¬¿ÉÊÇÄãµÄÔËÆøÌ«²îÁË£¬Ê²Ã´Ò²Ã»ÓĞÕÒµ½¡£\n");
	
	return;	
}

void reset(){
	::reset();
	if (!random(8))
		set("already",0);
}

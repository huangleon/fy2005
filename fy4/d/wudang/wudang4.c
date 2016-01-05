
inherit ROOM;

void create()
{
	object	con, item;

	set("short", "Ïá·¿");
	set("long", @LONG
Îäµ±µÜ×ÓĞİÏ¢µÄµØ·½¡£×îÀïÃæ¿¿Ç½ÊÇÒ»ÅÅÄ¾´²£¬´óÔ¼ÓĞÊ®¼¸¸ö¡£·¿×ÓÖĞÑëÊÇÒ»
ÕÅ³¤·½ĞÎµÄÄ¾×À£¬ÉÏÃæ°ÚÖøÒ»Ö»²èºø£¬¼¸Ö»²è±­¡£×óÃæ¿¿Ç½ÊÇÒ»Ö»Êé¼Ü£¬ÕûÕûÆëÆë
µØ°ÚÖøĞí¶àÊé¼®¡£ÆäÖĞ×îÒıÈË×¢Ä¿µÄÊÇÕÆÃÅÊ¯ÑãĞÂÖøµÄ[33mÕÆ·¨ÈëÃÅ[32mÓë[33m½£·¨ÈëÃÅ[32m¡£ÓÒÃæ
Ç½ÉÏÔò¹ÒÖø¼¸°Ñ³¤½£¡£
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"wudang3",
	]));
	set("objects", ([ 
		__DIR__"npc/taoist" : 2,
		__DIR__"obj/table" : 1,
		__DIR__"obj/wall" : 1,
		BOOKS"sword_50" : 1,
		BOOKS"unarmed_50" : 1,

	]));
	set("coor/x",50);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset()
{
        object 		*inv;
        object 		con, item;
	int		i;	

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 5) {
	        for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
        	item = new(__DIR__"obj/teapot");
        	item->move(con);
        	item = new(__DIR__"obj/cup");
        	item->move(con);
        	item = new(__DIR__"obj/cup");
        	item->move(con);
        }
        con = present("wall", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 3) {
	        for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
        	item = new(__DIR__"obj/sword");
        	item->move(con);
	}
/*      con = present("book shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) ==0) {
        	item = new(__DIR__"obj/book");
        	item->move(con);
	} */
}

/*

void init(){
        add_action("do_get", "get");
}


int do_get(string arg)
{
	string 		obj, from;
	object		me, wall, shelf, table, target, taro;

	if(!arg) {
		return notify_fail("ÄãÒªÄÃÊ²Ã´£¿\n");
	}
	if(sscanf(arg, "%s from %s", obj, from)==2 ) {
		if(obj == "all") {
			write("Ò»´ÎÄÃÌ«¶à¶«Î÷»áÌ«Ã÷ÏÔ¡£\n");
			return 1;
		}
		table =  present("table",this_object());
		wall =  present("wall",this_object());
		shelf =  present("shelf",this_object());
		target =  present(from,this_object());
		me = this_player();
		if(target == table || target == wall || target == shelf) {
			taro =  present(obj, target);
			if(taro && random(10) > 4) {
				message_vision("$N³ÃÃ»ÈË×¢ÒâµÄÊ±ºò£¬¹í¹íËîËîµØÄÃÁËµãÊ²Ã´£¬·Å½ø»³Àï£¡\n", me);
				me->set_temp("marks/ÍµÊé", 1); 
			}
		}
	}
	return 0;
}

int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

        if( userp(me) && me->query_temp("marks/ÍµÊé")) {
                if( dir == "south"  && ob=present("li", this_object())) {
			return notify_fail(ob->name()+"ÏòÄãºÈµÀ£º´óµ¨£¡¾¹¸ÒÔÚÎäµ±Íµ¶«Î÷£¡\n");
                }
        }

        return 1;
}

*/
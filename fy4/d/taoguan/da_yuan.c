#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ÈýÇå¹¬´óÔº");
	set("long", @LONG
°×Ê¯°åÆÌ³ÉµÄµØÃæ´òÉ¨µÃ¸É¸É¾»¾»¡£×óÃæÊÇÏá·¿£¬µÀÊ¿ÃÇÆð¾ÓµÄµØ·½¡£ÓÒÃæÊÇ
³ø·¿£¬Æ®³öÕóÕó·¹Ïã¡£ÔºÄÚ¹ÅÄ¾²ÎÌì±ÎÈÕ£¬ÏòÇ°×ßÊÇÒ»×ù´óµî£¬½ðÉ«µÄ´óØÒÉÏÐ´×Å
[33m¡ºÉÏÇåµî¡»[32mÈý¸ö´ó×Ö¡£ºÚ³Á³ÁµÄ´óÃÅÕûÈÕ¹Ø×Å¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"da_dian",
  		"east" : __DIR__"kitchen",
  		"west" : __DIR__"xiang_fang",
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
    add_action("do_pull", ({"pull","open"}));
    if(query("exits/south")) {
	        set("item_desc", ([
	                "door": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¿ª×ÅµÄ¡£\n",
	                "ÃÅ": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¿ª×ÅµÄ¡£\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
	                "door": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¹Ø×ÅµÄ£¬Äã¿ÉÒÔÀ­(pull/open)ÃÅ¡£\n",
	                "ÃÅ": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¹Ø×ÅµÄ£¬Äã¿ÉÒÔÀ­(pull/open)ÃÅ¡£\n",
	        ]) );      	
	}
}

int do_pull(string arg)
{
        object room, me;

        if( arg=="door" || arg == "ÃÅ") {
                me = this_player();
                if(query("exits/south")) {
                        write("ÃÅÊÇ¿ª×ÅµÄ£¡\n");
		}
		else {
                set("exits/south", __DIR__"taoguan");
	        set("item_desc", ([
	       	         "door": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¿ª×ÅµÄ¡£\n",
	       	         "ÃÅ": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¿ª×ÅµÄ¡£\n",
       		 ]) );
                message_vision("$N´ò¿ª´óÃÅ¡£\n", me);
                if( room = find_object(__DIR__"taoguan") ) {
                        message("vision", "´óÃÅ´ÓÀïÃæ´òÁË¿ªÀ´¡£\n", room);
	                room->set("exits/north", __FILE__);
			call_out("closedoor", 5, room);
                }
		}
	}
	else {
                 write("ÄãÒª¿ªÊ²Ã´£¿\n");
	}
	return 1;
}

int closedoor(object room)
{
	message("vision", "´óÃÅÓÖ±»¹ØÉÏÁË¡£\n", room);
	message("vision", "´óÃÅÓÖ±»¹ØÉÏÁË¡£\n", this_object());
        set("item_desc", ([
                "door": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¹Ø×ÅµÄ£¬Äã¿ÉÒÔÀ­(pull)ÃÅ¡£\n",
                "ÃÅ": "Í­¶¤µÄ´óÃÅ£¬ÃÅÊÇ¹Ø×ÅµÄ£¬Äã¿ÉÒÔÀ­(pull)ÃÅ¡£\n",
        ]) );
	room->delete("exits/north");
	delete("exits/south");
}

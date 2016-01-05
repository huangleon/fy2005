inherit ROOM;
void create()
{
        set("short", "ÓĞ·ïÀ´ÒÇ");
        set("long", @LONG
ÕâÊÇÒ»¼äÎÔÊÒ£¬ËäÈ»²¢²»¸»ÀöÌÃ»Ê£¬¸÷Ñù¶«Î÷È´¶¼Ê®·Ö¾«ÖÂµÃÌå£¬¿¿ÄÏÊÇÒ»Ãæ
ÆÁ·ç£¬¿¿Î÷±ßÓĞÒ»ÕÅ·ïÎ²ÇÙ¡£¶«ÃæÇ½ÉÏ¹Ò×ÅÒ»¸±¶ÔÁª£º
[1;36m
                        ÏÒ¸èÖªÑÅÒâ£¬
                        ±­¾ÆĞ»Á¼Åó¡£

[2;37;0m
LONG
        );
		set("exits", ([ 
  			"west" : __DIR__"huashi",
		]));
        set("objects", ([
       		__DIR__"npc/yuan": 1,
        ]) );
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",0);
		set("NONPC",1);
		setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("ÄãÒª´ò¿ªÊ²Ã´£¿\n");
                return 1;
        }
        if( arg == "ÆÁ·ç" || arg == "ping feng" || arg == "pingfeng")
        {
        me = this_player();
        message_vision("$NĞÅÊÖ°´ÔÚÆÁ·çÉÏ£¬ÆÁ·çÎ¢Î¢Ò»¶¯£¬¹ıµÃÆ¬¿Ì£¬ÆÁ·ç
¾¹È»Ïò×óÒÆ¿ªÀ´£¬Â¶³öÒ»µÀ°µÃÅ¡£ \n", me);
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"secret");
        call_out("close_path", 6);
        }
        return 1;
        }
        else
        {
                write("Äã²»¿ÉÒÔ´ò¿ª"+arg+"\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/south") ) return;
        message("vision","ÆÁ·ç×ÔĞĞÒÆÁË»ØÀ´¡£\n",this_object() );
        delete("exits/south");
}




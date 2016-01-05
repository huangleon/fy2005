inherit ROOM;
void create()
{
        set("short", "¶«Æ«Ìü");
        set("long", @LONG
´ËÌüÎÞ´°£¬¾¡ÒÔ¶ù±ÛºìÖòÕÕÒ«¡£ÌüÖÐÒ»ÕÅÐ¡Ä¾Ì¨£¬Ì¨ÉÏÒ»ºø¾Æ£¬¾ÆÉÐÓÐÓàÎÂ¡£
ÓÒ½ÇÒ»Ð¡·½[33mµØÌº[32m£¬ÌºÉ«ÏÊºì¡£×ó±ßÊÇÖ§Ä¾¼Ü£¬¼ÜÉÏÓÐ³ÂÄêÀÏ¾Æ¡£»¹ÓÐÒ»ÕÅÐ¡´²£¬ËÆ
ºõÓÐÈË³¤Äê×¡ÔÚÕâÀïµÄÑù×Ó¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"tading",
	]));
        set("item_desc", ([
                "carpet": "Õâ¿éÐ¡·½µØÌºËÆºõ¿ÉÒÔÀ­¿ª(pull)¡£\n",
                "ditan": "Õâ¿éÐ¡·½µØÌºËÆºõ¿ÉÒÔÀ­¿ª(pull)¡£\n",
                "µØÌº": "Õâ¿éÐ¡·½µØÌºËÆºõ¿ÉÒÔÀ­¿ª(pull)¡£\n",

        ]) );
	set("NONPC",1);
        set("objects", ([
        __DIR__"npc/guard" : 1,
                        ]) );

	set("coor/x",-60);
	set("coor/y",15);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_pull", "pull");
}

int do_pull(string arg)
{
	object ob;
	object sect;
	if ( !arg && arg != "carpet" && arg != "ditan" && arg != "µØÌº")
                return 0;
        if( ob = present("boater", this_object()))
         if (ob->query("name")=="´ò¸üµÄ")
        {
        	message_vision("$N¶Ô$nËµ£ºÀ´£¬±ðÏ¹Ã¦£¬ºÈ£¡\n", ob, this_player());
        	return 1;
        }
        if( !query("exits/down") ) {
        message_vision("$N°ÑµØÌºÀ­¿ª·¢ÏÖÁËÒ»ÌõÃÜµÀ£®\n", this_player());
      
        set("exits/down", __DIR__"secret_room");
		sect = find_object(__DIR__"secret_room");
		if( ! sect)
        	sect = load_object(__DIR__"secret_room");
		if( sect )
        	sect->set("exits/up", __FILE__);
			call_out("close_path",15);
        }
        else
        {
       		message_vision("$N°ÑµØÌºÀ­¹ýÀ´ÑÚ¸Ç×¡ÃÜµÀ£®\n", this_player());
        	delete("exits/down");
        	sect = find_object(__DIR__"secret_room");
        	if( ! sect)
        	sect = load_object(__DIR__"secret_room");
		if (sect)
        	sect->delete("exits/up");
        }
        return 1;
}

void close_path()
{
	object sect;
        if( !query("exits/down") ) return;
                delete("exits/down");
        sect = find_object(__DIR__"secret_room");
        if( ! sect)
        sect = load_object(__DIR__"secret_room");
        if (sect)
        sect->delete("exits/up");

}


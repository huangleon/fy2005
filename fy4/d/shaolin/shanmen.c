// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ÉÙÁÖÉ½ÃÅ");
        set("long", @LONG
Ò»×ù¸ß´óµÄµ¥éÜ½¨Öş£¬ÔÚ¸ß¸ßµÄ×©Ì¨ÉÏºÍÁ½±ßÒ´ÃÅÏàºôÓ¦£¬ÃÅ¶îÉÏĞü×ÅÒ»¿é½ğ
×ÖµÄºÚÆá·½ØÒ£º
[0;31m
                 ;,           ;,   ;,          ;;
              ,  ;;  ,        ;; , ;; ,     ,,,;;,,;,
             ,;' ;;   ';,  ''';;''';;'''       ;;     ,
            ,;'  ;;  , ';'   ;;;; ;;;;   ''''''''';;''''
           '     ;' ;;'     ;;;; ;;;;';   ,,,,,,,,;;,;,
                  ,;'      ;' ;;,' ;; ';,   ;,    ;;
                ,;'       '   ;;   ;;  '     ;' , ;;
           ,,,''              ;'   ;'            ';'
	

[0;32m
LONG
        );
        set("exits", ([ 
	  "down"   : __DIR__"shandan",
	  "north" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"npc/monk4" : 2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-10);
	setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
        if( me->query("class") != "shaolin" && dir == "north" && ob=present("shaolin monk", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if(inv[i]->query("shaolin_cloth") && (int)inv[i]->query("equipped"))
	                        return 1;
                return notify_fail(ob->name()+"ÏòÄã¹°ÊÖµÀ£ºÃ»ÓĞÓÎÉ½ÅÆ£¬·ÇÉÙÁÖµÜ×Ó²»¿ÉÈëÄÚ£¡£¡\n");
        }
        return 1;
        }
        else return 1;
}


void reset()
{
	object *inv, ob;
	int i;
	string *sname=({"Ô²Ã÷","Ô²Áß"});
	::reset();
	ob=present("shaolin monk", this_object());
	if(ob) ob->set("name","Ô²Ã÷");
	if(ob) ob->set("chat_chance_combat",50);
	inv = all_inventory();
	if(ob)	{
		ob->dismiss_team();
		for(i=0;i<sizeof(inv);i++)
	        	if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
	        	if(i<=1) {
	        	ob->add_team_member(inv[i]);
	        	inv[i]->set("name",sname[i]);
        	        inv[i]->set("chat_chance", 2);
        		inv[i]->set("chat_msg", ({
                		inv[i]->name()+"ËµµÀ£ºÌıËµ×òÌìÓÖÓĞÈË´ÓÄ¾ÈËÏï´òÏÂÉ½È¥ÁË£¡\n",
        		}) );
        	}
	}
}


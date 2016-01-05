#include <room.h>
inherit ROOM;
void create()
{
        set("short", "²Ø±¦ÊÒ");
        set("long", @LONG 
ËÄÃæÇ½±Ú¾ùÊÇÓÃÓñ×ö³É£¬Õı¶Ô×ÅÄãµÄÊÇÒ»¿é¼«´óµÄ[37mÓñ±Ú[32m¡£¶ø·¿ÖĞ±ÚÉÏ°¸Í·¸ü¶¼
°ÚÂúÁËÆæÕäÒì±¦£¬ÎŞÒ»¼ş²»ÊÇÃÀµ½¼«´¦£¬»ª¹óÖ®¼«µÄ¾«Æ·£¬ÆäÖĞÒ»±ú½£ÇÊÇ¶ÂúÖé±¦
µÄ[37m³¤½£[32mËÆºõÒÑ¾­³öÇÊ£¬½£¹â¾§Ó¨¶áÄ¿£¬²»¿É·½Îï¡£
LONG
        );
         
       set("exits", ([ /* sizeof() == 2 */
  			"north" : __DIR__"gu5",
		]));
         
        set("item_desc", ([
                "sword": "ÕâÒ»¿´¾ÍÊÇÒ»°Ñ¼ÛÖµÁ¬³ÇµÄ±¦½££¬½£ÉíÊÇÍäµÄ£¨pull sword£©\n",
                "±¦½£": "ÕâÒ»¿´¾ÍÊÇÒ»°Ñ¼ÛÖµÁ¬³ÇµÄ±¦½££¬½£ÉíÊÇÍäµÄ£¨pull sword£©\n",
				"Óñ±Ú": "Ò»Õû¿é¾§Ó¨µÄÃÀÓñ£¬·Â·ğ¾­³£ÓĞÈËÓÃÊÖ´¥Ãş£¨pull sword£©\n", 
                "jade": "Ò»Õû¿é¾§Ó¨µÄÃÀÓñ£¬·Â·ğ¾­³£ÓĞÈËÓÃÊÖ´¥Ãş£¨pull sword£©\n",
                "Óñ±Ú":"Óñ±ÚÏñÒ»ÉÈĞ¡ÃÅ£¬ÕÚ×¡ÁËºóÃæµÄ¾°É«£¨push jade£©\n",
                "jade":"Óñ±ÚÏñÒ»ÉÈĞ¡ÃÅ£¬ÕÚ×¡ÁËºóÃæµÄ¾°É«£¨push jade£©\n",	
        ]) );

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
      
}
 
 void init()
{
   add_action("do_open","push"); 
   add_action("do_pull","pull");
}

         


int do_open(string arg)
{
	object room;
         object me;  
	me=this_player();
	if(!objectp(room = find_object(__DIR__"girlroom")))
	room = load_object(__DIR__"girlroom");
	switch (arg)
         {
         case "jade":
         case "Óñ±Ú":
             if(query("exits/east")) return notify_fail("ÃÅÒÑ¾­ÊÇ¿ªµÄÁË¡£");
             message_vision("$NÉìÊÖÔÚÓñ±ÚÉÏÒ»°´£¬Óñ±ÚÉÏ³öÏÖÒ»ÉÈĞ¡ÃÅ¡£\n",this_player());
             set("exits/east",__DIR__"girlroom");
			room->set("exits/west",__DIR__"goldroom");
	     	call_out("closepath",5,room);
             return 1;
         }
}

void closepath(object room)
{
	tell_object(this_object(),"Ğ¡ÃÅ£¢Ö¨£¢µÄÒ»ÉùÓÖ¹ØÉÏÁË¡£\n");
	delete("exits/east");
	room->delete("exits/west");
}
int do_pull(string arg)
{
        object swo;
		string *limbs;
		if( query_temp("mark/been_get")) return notify_fail("½£ÒÑ±»°Î×ßÁË¡£\n");
		if(random(this_player()->query_kar()) > 19 && random(100)>90)
        { 
			swo=new(__DIR__"obj/leavehook");
			swo->move(this_player());
			set_temp("mark/been_get",1);
			write("Äã´ÓÇ½ÉÏ°ÎÏÂÁËÒ»±úÀë±ğ¹³¡£\n" );
		}
		else
        { 
			limbs=this_player()->query("limbs");
			write("ÄãÊÔ×ÅÈ¥°Î½££¬½£¹âÒ»ÉÁ£®£®£®\n");
			write("ÄãµÄ"+limbs[random(sizeof(limbs))]+"±»½£ÆøËùÉË¡£\n");
        	this_player()->receive_damage("kee",random(100)+1);
			this_player()->set_temp("last_damage_from","ÔÚ´óÆì¹ÈÒâÍ¼½Ù±¦²»É÷ÀÛËÀ¡£");
			COMBAT_D->report_status(this_player(),0);
		}
        
        return 1;

}

void reset()
{
    	::reset();
		delete_temp("mark/been_get");
}

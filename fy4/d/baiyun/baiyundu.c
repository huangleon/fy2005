#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW"°×ÔÆ¶É"NOR);
    set("long", @LONG
°×ÔÆÓÄÓÄ£¬º£ÌìÒ»Ïß¡£ÕâÀï£¬¾ÍÊÇ°×ÔÆµºÁË£¬µ«¼ûÑô¹â²ÓÀÃ£¬µº±ßÉ³Ì²½à°×ÈáÏ¸£¬
º£Ë®Õ¿À¶Èç±Ì£¬ÀËÌÎ´ø×ÅĞÂÏÊÃÀÀöµÄ°×Ä­ÇáÅÄ×Åº£°¶£¬Çç¿ÕÍòÀïÎŞÔÆ£¬µºÉÏÂúÑÛ´äÂÌ¡£
Ò»ÇĞÓĞÈçÏÉ¾³Ò»°ã¡£¿¿×Å°¶±ßÊÇ¸ö²»´óµÄ[37mÂëÍ·[32m£¬Í£¿¿×ÅÀ´Íù°×ÔÆµºµÄ´¬Ö»£¬àÚÁÁµÄºô
Éù´ËÆğ±ËÂä£¬Ô­À´À´ÍùµÄÓÎÈËÖ»Òªºô»½ÂëÍ·µÄ´¬¼Ò¼´¿É¹Í´¬Àëµº¡£
LONG
    );    
    set("exits",       
      ([        
	"south" : __DIR__"huangsha1",
      ]));
    set("objects",
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ])); 
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y", 0);
    set("coor/z",0);
    set("item_desc", ([
	"ÂëÍ·": "°×ÔÆµºµÄÂëÍ·²»´ó£¬Ò²¸ñÍâµÄ·±Ã¦£¬ÈıÁ½¸ö°×·¢µÄÀÏ²®£¬Á½ÈıÒ¶¼òÒ×µÄÄ¾·¤£¬Äã\n
Èç¹ûÏë´î³Ë£¬²»·ÁÕĞºô£¨yell£©ÀÏ²®ÃÇÒ»Éù¡£\n",
               "matou": "°×ÔÆµºµÄÂëÍ·²»´ó£¬Ò²¸ñÍâµÄ·±Ã¦£¬ÈıÁ½¸ö°×·¢µÄÀÏ²®£¬Á½ÈıÒ¶¼òÒ×µÄÄ¾·¤£¬Äã\n
Èç¹ûÏë´î³Ë£¬²»·ÁÕĞºô£¨yell£©ÀÏ²®ÃÇÒ»Éù¡£\n",
               "dock": "°×ÔÆµºµÄÂëÍ·²»´ó£¬Ò²¸ñÍâµÄ·±Ã¦£¬ÈıÁ½¸ö°×·¢µÄÀÏ²®£¬Á½ÈıÒ¶¼òÒ×µÄÄ¾·¤£¬Äã\n
Èç¹ûÏë´î³Ë£¬²»·ÁÕĞºô£¨yell£©ÀÏ²®ÃÇÒ»Éù¡£\n",
        ]) );

	setup();
}

void init()
{               
        add_action("do_yell","yell");
}

void boat_come(object who)
{
	object byboat;
	object oldman;
	object *inv;
	int i;

	if (environment(who)!= this_object())	return;
		
	if (!objectp(byboat=find_object(__DIR__"boat2")))
		byboat=load_object(__DIR__"boat2");
	 message_vision(CYN"´¬¼ÒÀÏ²®Ğ¦ÃĞÃĞµØÓ¦ÁËÒ»Éù£¬³¤¸İÇáµã£¬Ä¾·¤Ğ¡ÖÛ±ãÒÑ¿¿ÔÚÂëÍ·±ßÉÏ¡£\n"NOR,who);
	message_vision(WHT"´¬¼ÒÀÏ²®ÌøÉÏº£°¶£¬Ğ¦ºÇºÇµÀ£º¡°¿Í¹Ù£¬ÉÏ´¬°É£¡¡±\n"NOR,who);
	set("exits/down",__DIR__"boat2");
	call_out("boat_leave",3,byboat);
}


void boat_leave(object byboat)
{
	if (query("exits/down")) 
	delete("exits/down");
	if (byboat->query("exits/up")) 
                byboat->delete("exits/up");
	message("vision","´¬¼ÒÀÏ²®ËÉ¿ªÁËÀÂÉş£¬º£Ë®½«Ğ¡ÖÛ»º»ºÍÆÀë°¶±ß£®£®£®\n",this_object()); 
    byboat->set_temp("mark/dest","island");
	message("vision","´¬¼ÒÀÏ²®ËÉ¿ªÁËÀÂÉş£¬º£Ë®½«Ğ¡ÖÛ»º»ºÍÆÀë°¶±ß£®£®£®\n",byboat);
}



int do_yell()
{
	object me;
	object room;
	me = this_player();
	message_vision(CYN"$NÏò´¬¼ÒÀÏ²®¸ßÉùÕĞºôµÀ£¬¡°´¬¼Ò£¬»ØÄÏº££¡¡±\n"NOR , me );
	call_out("boat_come",1,me);
	return 1;
}


/*
 
               (\~~~/)            
               ( £®£®)        

               (_____)~£®      
   
¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 10.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/

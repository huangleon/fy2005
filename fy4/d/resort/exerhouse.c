
inherit ROOM;

void create()
{
        set("short", "Á·¹¦ÊÒ");
        set("long", @LONG
¸É¸É¾»¾»µÄÇ½ÉÏ¹Ò×ÅÒ»·ù×Ö»­£¬ÉÏÃæĞ´µ½¡°ÊéÉ½ÓĞÂ·ÇÚÎª¾¶£¬Ñ§º£ÎŞÑÄ¿à×÷ÖÛ¡£¡±
Áú·É·ïÎèµÄ×ÖÌå£¬·ÖÃ÷ÊÇ×¯Ö÷ÌúÉÙËùÊé¡£Ç½½Ç¶Ñ×ÅºÜ¶àÖñµ¶Öñ½££¬µØÉÏ´òÉ¨µÄÒ»³¾
²»È¾£¬ÖĞ¼äÎ¢Î¢ÓĞĞ©°¼ÏÂ£¬ËÆºõÊÇ¾­³£ÓĞÈËÔÚ´ËÁ·¹¦¡£Èëµ½´ËÊÒÖ®ÈË£¬ÑÛ¹âÎŞ²»Îª
Ç½ÉÏµÄ[33mÒ»µ¶Ò»½£[32mËùÎüÒı×¡¡£
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"back_yard",
		]));
		
		set("item_desc", ([
			"Ò»µ¶Ò»½£":		"ÏàË¼µ¶	Ïú»ê½£\n",
			"Ò»µ¶":			"µ¶ÏàË¼£¬ÈËÏàÒÀ\n",
			"Ò»½£":			"½£Ïú»ê£¬ËêÎŞºÛ\n",
		]));
		
       set("objects", ([
                __DIR__"obj/bsword" : 3,
                __DIR__"obj/bblade" : 4,
        ]) );

		set("coor/x",-10);
		set("coor/y",10);
		set("coor/z",0);
		setup();
}


void init()
{
	add_action("do_gets", "get");
}

int do_gets(string arg)
{
	object me, sword, blade;
	int ability;
	
	me = this_player();
	
	if(arg == "all")	{
		write("ÄãÌ«Ì°ĞÄÁË¡£\n");
		return 1;	
	}
	
	if (arg == "ÏàË¼µ¶") {
		if (me->query("class")!="legend") {
			tell_object(me,"ÔÚ±ğÈË×¯Ô°Àï×ö¿Í£¬»¹ÊÇ²»ÒªÂÒÄÃÂÒ¶¯µÄºÃ¡£\n");
			return 1;
		}
		if (me->query_skill("dormancy",1) < 300
			|| me->query_skill("six-sense",1)<300) {
			tell_object(me,"Ñ©Èï¶ùËµ£ºÄãµÄÌúÑ©Îä¹¦ÉĞÎ´³ÉÊì£¬È¡Ö®ÓĞº¦ÎŞÒæ¡£\n");
			return 1;
		}
		if (me->query("gender")=="ÄĞĞÔ") {
			tell_object(me,"Ñ©Èï¶ùËµ£ºÏàË¼µ¶ÊÇ¸øÅ®µÜ×ÓÅå´øµÄ¡£\n");
			return 1;
		}
		seteuid(getuid());
		blade = new("/obj/specials/legend/mblade");
		if (blade->move(me)) {	
			ability = F_ABILITY->check_ability(me,"parry_add");
			blade->set("block_rate", 5 + ability/2);
			message_vision("$NÇáÇáµØ´ÓÇ½ÉÏÈ¡ÏÂÁËÏàË¼µ¶¡£\n", me);
		} else
			destruct(blade);	
		return 1;
	}	
	
	if (arg == "Ïú»ê½£") {
		if (me->query("class")!="legend") {
			tell_object(me,"ÔÚ±ğÈË×¯Ô°Àï×ö¿Í£¬»¹ÊÇ²»ÒªÂÒÄÃÂÒ¶¯µÄºÃ¡£\n");
			return 1;
		}
		if (me->query_skill("dormancy",1) < 300
			|| me->query_skill("six-sense",1)<300) {
			tell_object(me,"ÌúÉÙËµ£ºÄãµÄÌúÑ©Îä¹¦ÉĞÎ´³ÉÊì£¬È¡Ö®ÓĞº¦ÎŞÒæ¡£\n");
			return 1;
		}
		if (me->query("gender")=="Å®ĞÔ") {
			tell_object(me,"ÌúÉÙËµ£ºÏàË¼µ¶ÊÇ¸øÅ®µÜ×ÓÅå´øµÄ¡£\n");
			return 1;
		}
		seteuid(getuid());
		blade = new("/obj/specials/legend/msword");
		if (blade->move(me)) {	
			ability = F_ABILITY->check_ability(me,"parry_add");
			blade->set("block_rate", 5 + ability/2);
			message_vision("$NÇáÇáµØ´ÓÇ½ÉÏÈ¡ÏÂÁËÏú»ê½£¡£\n", me);
		} else
			destruct(blade);	
		return 1;
	}
	
	return 0;
			
}

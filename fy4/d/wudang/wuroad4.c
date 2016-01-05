#include <command.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ºóÔºÃÅ");
	set("long", @LONG
ÇàÊ¯Ğ¡Â·´©¹ıÁË»¨´Ô£¬µ½ÕâÀïÎªÖ¹¡£Ò»¸öĞ¡Ğ¡µÄÔÂĞÎÃÅÁ¢ÔÚ´Ë´¦¡£ÃÅÉÏµÄÇ½±Ú
ÉÏ¿ÌÖø¡°ºóÔº¡±Á½¸ö×Ö¡£ÃÅÅÔ¹ÒÖøÒ»¿éÄ¾ÅÆ£¬ÉÏĞ´  [1;37m·ÇÎäµ±µÜ×Ó£¬ÇëÎğÉÃÈë[0;32m
LONG
	);
	set("exits", ([ 
		"enter" : __DIR__"wudang3",
  		"west" : __DIR__"wuroad3",
	]));
	set("outdoors", "wudang");
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
	
	
int valid_leave(object me, string dir)
{
        int i;
        object *inv, ro;

        if( dir != "enter" ) return 1;
		if (!userp(me))	return 1;
		
        if (me->query("family/family_name")=="Îäµ±ÅÉ" || me->name()=="Åí³¤¾»" )
        	return 1;
		
		if (REWARD_D->riddle_check(me,"ĞÂÊÖÈëÃÅ"))
			return notify_fail("Ê¯ÑãÕæÈËÔÚ×ÏÏö¹¬£¬Ïò»Ø×ß²Å¶Ô¡£\n");
		
		message_vision(HIY "ºöÈ»ÉíááÓĞ¼¸¸öÉùÒô´ó½Ğ£º£¢ÓĞÔôÑ½£¡À´×¥ÔôÑ½£¡£¢\n"NOR, me);
    	message_vision(HIR "½ÓÖø¡¸ßË¡¹µØÒ»Éù£¬$NµÄÄÔºó±»ÈËÖØÖØµØ´òÁËÒ»¹÷¡£\n"NOR, me);
    	me->unconcious();
    	message_vision(HIY "Á½¸öÎäµ±µÀÊ¿°Ñ$NËùÓĞµÄ¶«Î÷ËÑÁËÒ»±é£¬°Ñ$NÖØÖØµØË¤ÔÚÁËµØÉÏ£¬È»ºó×ªÉíÀë¿ªÁË¡£\n"NOR, me);	
    	inv = all_inventory(me);
    	for(i=0; i<sizeof(inv); i++) {
    		if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
			destruct(inv[i]);
        }
        return notify_fail("");
}


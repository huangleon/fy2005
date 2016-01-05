#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "Ç°Ôº");
        set("long", @LONG
Ç°ÔºÊµÔòÊÇÒ»Æ¬´ó²İÆº£¬²İÆºÖĞÑë£¬ÓĞÒ»×ùÅçË®Èª£¬ÓÃ°×´óÀíÊ¯Öş³É£¬ÉÏÃæïÎ
×Å¾«ÖÂµÄµñ¿Ì¡£Ò»×ğÊ¯Ïñ£¬ÓÉÔ²×ùÍĞ×Å£¬´£Á¢ÔÚ³Ø×ÓÖĞĞÄ£¬°ÑË®»¨ÅçÉäµ½°ë¿Õ¡£×¯
Ô°µÄÕıÃÅ½ô½ô¹Ø±Õ×Å£¬×ó²àÓĞÒ»ÉÈ¹©ÏÂÈË½ø³öµÄ[33m±ßÃÅ[32m¡£ÓÉÇ°ÔºÍùÀï£¬°×Óñ°ãµÄÈıÖØ
Ê¯½×¾¡´¦£¬Ò»×ù´óÌÃ¡£´óÌÃÖĞµÆ»ğÍ¨Ã÷£¬¹âÈç°×Öç¡£
LONG
        );
        set("exits", ([ 
		"south": __DIR__"village2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"door": "´óÃÅ¹ØµÄËÀËÀµÄ£¬×ó²àµÄ±ßÃÅËÆºõ¿ÉÒÔÍÆ¿ª¡£\n",
		"ÃÅ": "´óÃÅ¹ØµÄËÀËÀµÄ£¬×ó²àµÄ±ßÃÅËÆºõ¿ÉÒÔÍÆ¿ª¡£\n",	    
		"±ßÃÅ": "´óÃÅ¹ØµÄËÀËÀµÄ£¬×ó²àµÄ±ßÃÅËÆºõ¿ÉÒÔÍÆ¿ª¡£\n",	    
	]));
	set("coor/x",70);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
       	add_action("do_push", "push");
}


void close_passage()
{
        object room;
        message("vision", "±ßÃÅÎŞÉùÎŞÏ¢µØÓÖ¹ØÉÏÁË¡£\n", this_object() );
        delete("exits/north");
}

int do_push(string arg)
{
        object obj, room;
        if(!arg || (arg != "±ßÃÅ" && arg != "door" && arg !="ÃÅ")) {
                return 0;
        }
		if (query("exits/north"))
		return notify_fail("±ßÃÅÒÑ¾­´ò¿ªÁË¡£\n");
		message_vision(WHT"$NÓÃÁ¦Ò»ÍÆ£¬Ö¨Ñ½Ò»Éù±ßÃÅ´ò¿ªÁË¡£\n"NOR, this_player());
		set("exits/north",__DIR__"gate");
        call_out("close_passage", 10);
        return 1;
}


void reset()
{
        ::reset();
        delete("exits/north");
}
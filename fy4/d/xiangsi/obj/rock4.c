// annie 07.2003
// dancing_faery@hotmail.com
//ÏôÇàÏæ
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("Ê¯ÅÆ", ({ "Ê¯ÅÆ" , "ÅÆ", "·åÉÏ","É½ÑÒ"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¿é");
//		set("long", "Ê¯ÅÆÉÏÔäµÄÊÇ£º\n[34mÉ½¸ßÄ¦ÊÀ½ç\nË®ÉîÁ÷¹Å½ñ\n¹«ºò½«Ïà½ñºÎÔÚ\n°ÙÄêÎ¨ÓĞÉ½Ë®´æ\nÈôÀë¿ª¾ÆÉ«²ÆÆø\n±ã¿°Îªµ±ÊÀÉñÏÉ\n\n[32m");
		set("long", "Ê¯ÅÆÉÏÔäµÄÊÇ£º\n\n"MAG"¡¡¡¡¡¡¡¡Ë®¡¡¡¡É½\n¡¡¡¡¡¡¡¡Á¬¡¡¡¡½Ó\n¡¡¡¡¡¡¡¡Çà¡¡¡¡Ô¶\n¡¡¡¡¡¡¡¡·å¡¡¡¡Ìì\n¡¡¡¡¡¡¡¡Ò»¡¡¡¡ÎŞ\n¡¡¡¡¡¡¡¡Âö¡¡¡¡Çî\n¡¡¡¡¡¡¡¡ÓÄ¡¡¡¡±Ì\n\n"NOR);
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"��÷"NOR, ({"lamei","wintersweet" }) );
	set_weight(100);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "֦");
	    set("long", "�����÷ʢ���������˱ǡ�\n");
	    set("value", 10);
	}
	::init_item();
}




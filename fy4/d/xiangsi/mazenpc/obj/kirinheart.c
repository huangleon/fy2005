// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"������"NOR, ({ "kirin heart","heart" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "ice");
            set("long", "һ�����亱���������ġ�\n");
			set("real",1);
			set("value",1000);
			set("lore",1);
          }
	::init_item();
}

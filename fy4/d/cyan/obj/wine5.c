#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"������"NOR, ({ "cang qiong" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��������\n");
		set("unit", "��");
        set("liquid", ([
        "type": "water",
        "name": "û��һ���ζ��ˮ",
        "remaining": 8,
        "drunk_apply": 5,
        ]) );	
	}
	 ::init_item();
}


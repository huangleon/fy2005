// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIW"�ײ�ͷ"NOR, ({ "whitetowel" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ��������Ѫ���İײ�ͷ��\n");
		set("value", 700);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
    ::init_head();
}


#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(RED"��贺��"NOR, ({ "red coat","coat" }) );
	set_weight(3000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("value", 10);
        set("armor_prop/armor", 6);
		set("long", "һ����ɫ�·�������һ�ֺ��ҫ�ۣ�������������Ĺ⡣\n");
          set("female_only", 1);
	}
	::init_cloth();
}

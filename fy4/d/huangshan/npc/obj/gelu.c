// TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIR  "��¹��" NOR, ({ "gelu" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��ʧ��¹�����¹���Ψʤ�ߵ�¹����֮����
Ψ�����µĵ�һӢ�۲��ܵõ��ı�����\n");
		set("value", 500);
		set("rigidity",2500);	
		set("material", "steel");
		set("max_enchant",5);
		set("for_create_weapon",1);
	}
	::init_blade(30);
}

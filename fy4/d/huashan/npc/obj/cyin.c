#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(RED"ϦӰ��"NOR, ({ "cyin blade","blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "flex");	// :>>....flex blade
		set("no_get",1);
	}
	::init_blade(77);
}

int query_autoload() { return 1; }
/*
int protection() {
	object me = environment(this_object());
	int result;

	if (!me)
		return 0;
	if (me->query("kee") < 1)
		return 0;
	
	result = random(4) ? 1 : 0;
	set("protected", result);
	return result;
}

string protection_msg() {
	object me = environment(this_object());

	if (!me)
		return "";
	if (me->query("kee") < 1)
		return "";
	
	return query("protected") ? HIR BLK"ϦӰ��ӳ��һƬ�������ʵĵ�ϼ���⣬������"+me->name()+HIR BLK"��Χ����ס"+me->name()+HIR BLK"��\n$N"HIR BLK"����"+me->name()+HIR BLK"��ߣ��ͱ��⻪���ˡ�\n"NOR
			: "";
}
*/
// Copyright (C) Apstone, Inc.
#include <armor.h>
inherit FINGER;
void create()
{
	set_name("�����ָ", ({ "engagement ring","ring"}) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����Ÿ�����������ʯ�Ľ�ָ���㻹������������֣�carve��\n");
		set("unit", "��");
		set("value", 700000);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n������ָ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n����ָ�ϳ���������\n");


	}
	::init_item();
}
void init()
{
	if(environment()==this_player() && !query("carved"))
	add_action("do_carve","carve");

}
int do_carve(string arg)
{
set("long","һ����������Ķ�����䣬������ţ�\n"+
arg+"\n");
set("carved",1);
tell_object(this_player(),"�ϣ�\n");
return 1;
}

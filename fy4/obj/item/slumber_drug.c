// slumber_drug.c

inherit POWDER;

void create()
{
	set_name("�ɺ�ҩ", ({ "slumber drug", "drug" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"����Ѱ�������ֵ��������������ɺ�ҩ������԰�����(pour)��\n"
			"��ˮ֮��ʹ�á�\n" );
		set("unit", "��");
		set("base_value", 20);
		set("base_unit", "��");
		set("base_weight", 30);
	}
	set_amount(1);
}

int drink_drug(object ob)
{
	this_player()->apply_condition("slumber_drug",
		(int)this_player()->query_condition("slumber_drug") + 100 );
	return 0;
}



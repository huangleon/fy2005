
inherit COMBINED_ITEM;
void create()
{
	set_name("��ľ��", ({ "woods", "dry woods" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
}

inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("���ɢ", ({ "mijiaosan" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ���൱�����Ĳ��ȣ���˵�ԣ���������û������\n");
		set("unit", "��");
        set("value", 1200);
		set("food_remaining", 3);
		set("food_supply", 16);
	}
	::init_item();
}

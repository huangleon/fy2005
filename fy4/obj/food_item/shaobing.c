// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("�ձ�", ({ "shaobing" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ��������������ձ���֥����ζ�˱Ƕ�����\n");
		set("unit", "��");
        set("value", 50);
        set("food_remaining", 10);
		set("food_supply", 60);
	}
	::init_item();
}

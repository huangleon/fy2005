// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("�̶���", ({ "bean geng", "geng" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ��������ʵ��̶����������������޷���\n");
        set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}

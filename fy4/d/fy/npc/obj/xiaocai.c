inherit F_FOOD;
inherit ITEM;

void create()
{
	string *name = ({"����","С�ƹ�","�޲���"});
	set_name(name[random(sizeof(name))], ({ "small dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��С�ˡ�\n");
		set("unit", "��");
		set("value", 2);
		set("food_remaining", 5);
		set("food_supply", 6);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
	if( random(2))
        set_name("���˿ڵ�С����", ({"diezi"}));
	else
        set_name("С����", ({"diezi"}));
	set("no_stack",1);
	set("value",0);
        set("long", "һֻС���ӡ�\n");
        return 1;
}

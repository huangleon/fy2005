inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("��ͷ", ({ "yangtou", "tou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��븯�õ���ͷ\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 5);
		set("food_supply", 60);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
	object qu;
        set_name("��ͷ��", ({"bone"}));
	set("no_stack",1);
	set("value",0);
        set("long", "һ���еøɸɾ�������ͷ��\n");
        set_max_encumbrance(10);
	qu = new(__DIR__"qu");
	qu->move(this_object());
        return 1;
}

int is_container()
{
	if(this_object()->query("name") == "��ͷ��" )
			return 1;
	else  return 0;
}

// TIE @ FY3

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("�Ϲ�", ({ "pumpkin" }) );
    set_weight(8000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "һ��ԲԲ�ģ�Ӳ���Ĵ��Ϲ�\n");
        set("unit", "��");
        set("value", 15);
        set("food_remaining", 3);
        set("food_supply", 300);
    }
    ::init_item();
}

int do_eat(string arg)
{
    int foo;
    foo=::do_eat(arg);
    if (!foo) return 0;

	this_player()->set_temp("can_pass_wall",1);
    return 1;
}


//

inherit ITEM;
inherit F_LIQUID;
void init()
{
        if(environment()==this_player())
        add_action("do_drink", "drink");
}

void create()
{
	set_name("�����Ȳ�", ({ "tea" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵĲ�ˮ�������������˱ǡ�\n");
		set("unit", "��");
		set("value", 5);
        set("liquid", ([
        "type": "water",
        "name": "��ˮ",
        "remaining": 8,
        "drunk_apply": 5,
        ]) );	
	}
	 ::init_item();
}

int finish_eat()
{
	set_name("����", ({"bowl"}) );
	set("value", 10);
	set("long", "һֻ����һ�ǵ��롣\n");
	return 1;
}

	
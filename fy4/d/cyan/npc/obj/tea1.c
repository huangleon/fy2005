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
	set_name("��ˮ", ({ "water" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ˮ��\n");
		set("unit", "��");
		set("value", 100);
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
	set("long", "һֻ�Ƶ����롣\n");
	return 1;
}

	
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
	set_name("����", ({ "tea" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "��������ˮûʲô������һ��衣\n");
		set("unit", "��");
		set("value", 300);
        set("liquid", ([
        "type": "water",
        "name": "���ú���ζ���Ĳ�",
        "remaining": 8,
        "drunk_apply": 5,
        ]) );	
	}
	 ::init_item();
}

int finish_eat()
{
	set_name("ȱ��һ�ǵ���", ({"bowl"}) );
	set("value", 10);
	set("long", "һֻȱ��һ�ǵ��롣\n");
	return 1;
}

	
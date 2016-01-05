inherit F_LIQUID;
inherit ITEM;

void create()
{
	set_name("�������ڵ�������", ({ "hot soup" ,"soup"}) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵ���������\n");
		set("unit", "��");
		set("value", 90);
		set("max_liquid", 50);
	}
        set("liquid", ([
                "type": "soup",
                "name": "������",
                "remaining": 5,
                "drunk_apply": 0,
        ]) );

	::init_item();
}
int finish_drink()
{
        set_name("����", ({"bowl"}));
	set("value",10);
        set("long", "һֻ�ִɴ��롣\n");
        return 1;
}
void init()
{
	::init();
	call_out("cold",100+random(100));
}

void cold()
{
	set_name("�����������", ({ "cold soup" ,"soup"}) );
	set("long", "һ���Ѿ����˵���������\n");
}

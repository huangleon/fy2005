// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
    set_name("��Ʒ���ϴ��ƴ�", ({ "spring wineskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "һ��ţƤ��Ĵ�ƴ���װ���˳����ز����ϴ��ơ�\n");
		set("unit", "��");
        set("value", 20000);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
        "name": "���ϴ�",
		"remaining": 15,
        "drunk_apply": 30,
	]) );
	::init_item();
}

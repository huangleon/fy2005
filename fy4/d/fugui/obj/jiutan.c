// jiutan.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��̳��", ({ "jiutan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɾ�̯�����ƾ�ϸ����������װ��Ҳ�����ơ�\n");
		set("unit", "��");
		set("value", 5000);
		set("max_liquid", 2000);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "zhuyeqing",
		"name": "��Ҷ��",
		"remaining": 2000,
		"drunk_apply": 6,
	]) );
	::init_item();
}

inherit ITEM;

void create()
{
    set_name("���", ({ "jian zi" , "���" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��С��������������ë���ɵ���ӡ�\n");
		set("marks/toy", 1);
		set("value", 100);
	}
	::init_item();
}

void init() {
	add_action("do_play", "play");
}

int do_play(string arg) {
	object me;
	
	me = this_player();
	
	if(!arg || arg != "jian zi" && arg != "jianzi" && arg != "���") return 0;
	if( me->is_busy() ) return notify_fail("������æ��\n");
	if( me->is_fighting() ) return 0;
	message_vision("$N�������ţ���ʼ����ӡ������ë���ɵ��������$N���ɡ�\n", me);
	me->start_busy(2);
	return 1;	
}




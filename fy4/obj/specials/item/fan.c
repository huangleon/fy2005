
inherit ITEM;
void create()
{
	set_name("�Ѳ�С����" , ({ "little fan" , "fan"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ʮ�־��µ��Ѳ�С���ӣ����滹���ŵ�����������\n");
		set("value", 2000);
		set("holiday", "���");
	}
	::init_item();
}

void init(){
	add_action("do_use", "use");
}

int do_use(string arg){
	object me;
	int i;
	me = this_player();
	if(!arg || (arg != "little fan" && arg != "fan")){
		return 0;
	}
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("������æ��\n");
	}
	i = NATURE_D->get_season();
	if(i == 2){
		message_vision("$N�ó��Ѳ�С���������ҡ�ţ�������Ư���ŵ�����������\n", me);
		tell_object(me, "��ֻ����һ��������΢�����������������\n");
	} else if( i == 4) {
		message_vision("$Nһ�߶�����һ��ҡ���Ѳ�С���ӡ�\n", me);
		tell_object(me, "�ۡ�������ѽ��\n");
	} else {
		message_vision("$N�ó��Ѳ�С���������ҡ�ţ�������Ư���ŵ�����������\n", me);
	}
	return 1;
}

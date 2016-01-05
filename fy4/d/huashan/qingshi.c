
inherit ROOM;

void create()
{
        set("short", "����ʯ");
        set("long", @LONG
һ���������ʯ�������Ǹ��¶��ľ��˴����������ʯ�ϻ������֡�����
���������Ŀ�����Ů��ȫ����������������ΰͦ�ε�����塣�������ʯ��û��
����ȴ��һ����̵Ĳݣ��Ȼ�����������仹�̣��������𡡣����󣩡�
LONG
        );

	set("no_magic", 1);    
    set("outdoors", "huashan");

	set("coor/x",-12);
	set("coor/y",-58);
	set("coor/z",47);
	setup();
}

void init(){
	add_action("do_pickup", "pickup");
}

int do_pickup(string arg){
	object me, grass, room;
	
	me = this_player();
	if(!arg || (arg != "grass" && arg != "wang you")){
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("������æ��\n");
	}
	grass = new(__DIR__"obj/grass");
	message_vision("$NС�ĵذ����ǲ��������\n", me);
	grass->move(me);
	message_vision("$N����һ������������׹ȥ��\n", me); 
	room = find_object(__DIR__"yunv");
	if(!objectp(room)){
		room = load_object(__DIR__"yunv");
	}
	me->move(room);
	message("vision", "ֻ��" + me->name() + "����Ӱ����ʯ�Ϲ�����������\n", 
			environment(me), me);
	me->start_busy(2);
	environment(me)->eagle_come(me);
	return 1;
}

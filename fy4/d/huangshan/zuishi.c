// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
��˵��������������֮����ʯ��������ϡ�ɼ���������״ǡ�ƾ���������ʯ
������ʯ���֣������پ������������Ʒ�һ���������������ֽ��ڴ˴�������ʯ��
�����б����Խ�ʯ��
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"shijian",
  "northeast" : __DIR__"qingluan",
  "westdown" : __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone2" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}

/*
void init() {
	add_action("do_laydown", "laydown");
	add_action("do_getup", "getup");
}

int do_laydown(){
	
	object me, walnut,who;
	int i, j;
	
	me = this_player();
	i = NATURE_D->get_season();
	j = random(10);

	
	who=query("laydown_person");
	
	if(me==who) return  notify_fail("���Ѿ�������ѽ����\n");		
	if(who&&present(who,this_object()))
		return notify_fail("�Ѿ��������ڴ�ʯ���ˡ�����\n");
	message_vision("$Nת���ɵ���ʯͷ�ϡ�\n", me);
	return 1;
}*/

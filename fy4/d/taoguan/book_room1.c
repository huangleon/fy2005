
inherit ROOM;

void create()
{
        set("short", "̫���");
        set("long", @LONG
̫���ԭ������������ղ��鼮�ĵط�������������������ͳ��˶���������
���Եľ��������ƹ�����Ӽ����������������״�����˭����׼���롣���ܵ���
���϶����������飬��Щ�Ѿ��ɵ�ֽ�Ŷ������ˣ�������һ��СС��ľ��ͨ����¥��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"up" : __DIR__"book_room2",
  		"south" : __DIR__"stoneroad2",
	]));
        set("objects", ([
		__DIR__"npc/jing2" : 1,
 	]) );
 	
        set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}


int valid_leave(object who, string dir) {
	object guard;
	guard = present("qingyi",this_object());

	if (dir == "up" && guard && !REWARD_D->check_m_success(who,"�������")) {
		if (who->query("gender") != "Ů��")
			return notify_fail(guard->name()+"˵�������ƹ����������ͣ�ʩ����ֹ������\n");
	}
	return 1;
}

	
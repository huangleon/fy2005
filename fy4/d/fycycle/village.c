inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������橣���������ʯ��������̦���Ե�ƽ���������С�����ͨ������ʯ
��֮ǰ����ǰ�ݺ��߰������ز�ø�ͦ���ڵ��������������ġ�ʯ����һ�����ã�
���Ҹ�ֲһ����÷��֦�����������ǲԾ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east":      __DIR__"lake",
	]));
	set("objects", ([
        	__DIR__"npc/meida": 1,
        ]) );
	
	set("coor/x",-120);
	set("coor/y",-320);
	set("coor/z",0);
        setup();
}


int valid_leave(object who, string dir) {
	object ob;
	
	if (dir == "east") {
		if (who->query_temp("marks/cheat_meida")+ 120 > time()
			&& ob = present("mei da", this_object()))
			return notify_fail("÷�����������˵��û���������ߣ��������ʡһ��ɡ�\n");
	}
	return ::valid_leave(who, dir);	
}

// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��÷�ٲ�");
        set("long", @LONG
�ٲ��Ӱ�������ֱк���£��������뱼������ǧ��֮��׹����У�����ǧ���
�ˡ���ɫ����ĭ��������ף��þò����ٲ��ߵ���ʯ����ù���羵���������֡�
�ٲ�ֱк�������һ��ʯ��ʯ������һ�����ڴ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lake",
]));
        set("item_desc", ([
                "��ʯ": "
���ʯ���ƺ��ָ���ӡ����Ҳ����Խ�һ̤֮����������壩�����ٲ���\n",
        ]) );
	set("outdoors","wanmei");
	set("coor/x",40);
	set("coor/y",110);
	set("coor/z",5);
	setup();
}
void init()
{
	add_action("do_charge","charge");
}

int do_charge()
{
	object me,room;
	me = this_player();
	message_vision("$N����ȫ�����������ٲ���ȥ������\n",me);
	if((int) me->query("max_force") < 300 )
	{
	message_vision("�����뱼������ǧ��֮�����ٲ���$N������ף�ת�۾ͱ������ˣ���\n",me);
	room = load_object(__DIR__"river");
        me->move(room);
	return 1;
	}
	message_vision("$N���ξ�Ȼ�����˼�����\n",me);
	room = load_object(__DIR__"outcave");
	me->move(room);
	return 1;
}

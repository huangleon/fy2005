inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "������");
        set("long", @LONG
�����½�������ڱ�κ��ƽԪ��������Ԫ�꣬ԭ���о��£������Ǳ�κ����
��һ���빬����Ľ�Ϊ���¡�����������������������Ϊ��������ʽש����ȫ��
����ʮ����ʨ�ӣ��������ԣ�������죬�����۽���ֻ�ǽ�������������Χɽ��
��û���������˥�䣬ɮ���Ѿ��ߵ�һ����ʣ�ˡ�
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"shike",
	]));
        set("objects", ([
        	__DIR__"obj/tower1": 	1,
        	__DIR__"obj/stonelion": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",-550);
        set("coor/y",650);
        set("coor/z",0);
	set("map","zbeast");
	setup();

}

void init() {
	add_action("do_jump","climb");
}

int	do_jump(string arg) {
	object room, me= this_player();
	if (arg == "tower" || arg == "��������" || arg == "��" || arg == "ta" || arg =="up") {
		if (this_player()->query_skill("move")>= 100) {
			message_vision("$Nʩչ�Ṧ��ƽ�ذ������ɣ����ȵ�����������������\n",this_player());
			room = find_object(__DIR__"songyue2");
			if (!room) room = load_object(__DIR__"songyue2");
			me->move(room);
			return 1;
		}else
			return notify_fail("��������˵̫���ˣ��������ɼ�ѽ��\n");
		
	}	
	if (query_verb() == "jump") return notify_fail("�������Ƕ�����\n");
	else return notify_fail("�����ʵ�ʲô��\n");
}

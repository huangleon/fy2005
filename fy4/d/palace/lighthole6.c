
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
�������еĹ������㿴��������ܵľ�ɫ��ֻ����ʯ��������·���۸��ӣ���
�Ѿ���ʧ�˷��򡣼�ֻС��������ű�������ȥ�������������ֲ��嶫��������
����������������˵��Ҳû���κ����塣����������ֻ��������������
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"lighthole1",
		"west" : __DIR__"lighthole2",
		"north" : __DIR__"holeopen2",
		"south" : __DIR__"lighthole4",
	]));
	set("coor/x",-50);
	set("coor/y",60);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	int	kar;
	object	box, pearl;

	if(!arg && !this_player()->query_temp("marks/boxp")) {
		kar = this_player()->query("kar");
		if(random(kar+70) < kar) {
			message_vision(BLU "\n�ںڰ���$N�Ĵ�������ͻȻ$N������һ��ͻ����ʯ���ϣ�\n�����ƺ��и����ӡ�\n"NOR, this_player());
			seteuid( geteuid(this_player()));
			box = new(__DIR__"obj/box");
			pearl = new(__DIR__"obj/pearl");
			pearl->move(box);
			box->move(this_object());
			this_player()->set_temp("marks/boxp", 1);
			return 1;
		}
	}
        return notify_fail("\n���ںڰ����Ĵ�������ȴ���ᶼû���֡�\n");
}


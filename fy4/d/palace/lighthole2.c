
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
		"west" : __DIR__"lighthole",
		"north" : __DIR__"lighthole3",
		"south" : __DIR__"lighthole4",
	]));
	set("coor/x",-50);
	set("coor/y",80);
	set("coor/z",40);
	setup();
}

void init()
{
	add_action("do_search", "search");
}


int do_search(string arg)
{
	int	kar;
	object	box, pearl, nroom;

	if(!arg ) {
		kar = this_player()->query("kar");
		if(random(kar + 270) < kar) {
			message_vision(BLU "\n�ںڰ���$N�Ĵ�������ͻȻ$N������ʯ���ϵ�һ��ͻ����\n"NOR, this_player());
			message_vision(BLU "\n$N�Ľ����ѿ���һ���󶴣�\n"NOR, this_player());
			message_vision(BLU "\n$N�����һ����������ȥ��\n"NOR, this_player());
			nroom = find_object(__DIR__"dating");
			if(!objectp(nroom)) nroom = load_object(__DIR__"dating");
			this_player()->move(nroom);
                 message_vision(YEL "\n$N�Ӵ����ݶ�����������\n"NOR, this_player());
			message_vision( YEL"\n$N�ܵ���̫��ľ��ţ����˹�ȥ��\n"NOR, this_player());
			this_player()->unconcious();
			return 1;
		}
		else if(random(kar + 70) < kar && !this_player()->query_temp("marks/boxp")) {
			message_vision(BLU "\n�ںڰ���$N�Ĵ�������ͻȻ$N������һ��ͻ����ʯ���ϣ�
�����ƺ��и����ӡ�\n"NOR, this_player());
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



inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��Ѩ");
        set("long", @LONG
�Ž���ʯ���������ʧ�˷��򣬱��ޱߵĺڰ�����ʳ���������߾�Ŀ��Ҳ
�������Լ������Ļ��������ƺ����������ϤϤ���µ��������о���С����������
ȥ����ʱ���㣬�Ƕ����ϣ�������������Ķ�����
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"darkhole1",
		"west" : __DIR__"darkhole",
		"north" : __DIR__"darkhole3",
		"south" : __DIR__"darkhole4",
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
	object	nroom;

	if(!arg) {
		kar = this_player()->query("kar");
		if(random(kar+ 70) < kar) {
			message_vision(HIY "\n�ںڰ���$N�Ĵ�������ͻȻ$N������ʯ���ϵ�һ��ͻ����\n"NOR, this_player());
			message_vision(HIR "\n$N�Ľ����ѿ���һ���󶴣�\n"NOR, this_player());
			message_vision(HIR "\n$N�����һ����������ȥ��\n"NOR, this_player());
			nroom = find_object(__DIR__"yadi");
			if(!objectp(nroom)) nroom = load_object(__DIR__"yadi");
			this_player()->move(nroom);
			message_vision(HIY "\n$N�ܵ���̫��ľ��ţ����˹�ȥ��\n"NOR, this_player());
			this_player()->unconcious();
			return 1;
		}
	}
        return notify_fail("\n���ںڰ����Ĵ�������ȴ���ᶼû���֡�\n");
}

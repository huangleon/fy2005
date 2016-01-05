// Room: /d/oldpine/cliff1.c

inherit ROOM;

void create()
{
        set("short", "ɽ���ϵ�խѨ");
        set("long", @LONG
��������������һ��ɽ������ǿ��������һ������Ϣ��СѨ�У�������������
Ҫ������������������һ�β���̵ľ��룬�����ЪһЪ�����������ߡ�
LONG
        );
        set("outdoors", "oldpine");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        if( !arg || (arg!= "up" && arg!="down") )
                return notify_fail("��Ҫ����(up)������������(down)��\n");

        if( arg=="up" ) {
                message_vision("$N�����Խűߵ���ʯ�Ȳ��ȣ���ʼС�����������������\n",
                        this_player() );
                this_player()->move(__DIR__"cliffside");
        } else if( arg=="down" ) {
                message_vision("$N�����Խűߵ���ʯ�Ȳ��ȣ���ʼС���������ɽ����������ȥ��\n",
                        this_player() );
                this_player()->move(__DIR__"riverbank1");
        }
        return 1;
}


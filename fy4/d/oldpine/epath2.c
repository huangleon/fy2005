// Room: /d/oldpine/epath2.c

inherit ROOM;

void create()
{
        set("short", "Сʯ��");
        set("long", @LONG
��������վ��һ��������̦�Ĺ����ϣ�������һ��ɽ����������Ȫ����ʯ֮��
��ɽ�±������ű��߲�Զ����һ��[37m�ٲ�[32m����ɽ��������һ�������㴹���������ٲ�
���Ե�ʯ��ʮ�ֶ��ͣ��߶Ⱥ�ɽ���Ե���������˽�������ʮ�ɡ�
LONG
        );
        set("item_desc", ([
                "waterfall":
                        "����ٲ��������ɸߵ�ɽ���ϳ弤���£�����һ��ɽ���׵�Сˮ̶��\n"
                        "ˮ̶���ߵ�ʯ�ڴ�������[37m����[32m(vine)����ע�⵽�ٲ������ƺ�\n"
                        "��ʲ�ᶫ���ڷ����⡣\n",
                "�ٲ�":
                        "����ٲ��������ɸߵ�ɽ���ϳ弤���£�����һ��ɽ���׵�Сˮ̶��\n"
                        "ˮ̶���ߵ�ʯ�ڴ�������[37m����[32m(vine)����ע�⵽�ٲ������ƺ�\n"
                        "��ʲ�ᶫ���ڷ����⡣\n",
                "vine":
                        "������һ������������ȽϽ������������ץס(hold)����������\n"
                        "�ܲ��ܵ���ȥ��Ҳ�����֪���ٲ�������ʲ�᣿\n"
                        "���ˣ�������һ�㣬����ʯ�������Ǹ�Լ���ɵ�ɽ�����....��\n"
        ]) );
        set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"epath1",
	  "east" : __DIR__"epath3",
	]));
        set("outdoors", "oldpine");

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_hold_vine", ({ "hold", "grab" }) );
}

int do_hold_vine(string arg)
{
        if( !arg || arg!= "vine" )
                return notify_fail("��Ҫץסʲ�᣿\n");
        message_vision("$N����ʯ�ŵĻ�������������Զ����һ������ץȥ....\n",
                this_player());
        if( random((int)this_player()->query_skill("dodge")) < 5 ) {
                message_vision("\nֻ����һ��ɱ���ĲҽУ�$N�Ѿ���ɽ����׹����ȥ��\n\n", this_player());
                tell_room(__DIR__"waterfall",
                        "���������˸������У�һ����Ӱ���Ϸ���������������ͨ��һ������̶�С�\n");
                this_player()->move(__DIR__"waterfall");
        } else {
                message_vision("$N�ֽ�������ʸ�������������������ɽ��....��\n",
                        this_player() );
                tell_room(__DIR__"passage",
                        "��Ȼһ����Ӱ���ϱߵ���Ļ���˳�����\n");
                this_player()->move(__DIR__"passage");
        }
        return 1;
}

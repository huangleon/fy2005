inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ʯ���ĳ�ԫ�᲼�ڲ���������ǡ�˲���ɽ֮�䣬�������������[33m������[32m�Ͱ˽�
�֣������С·��ͨ����ʵ�[33mɽ��[32m���������������де�[33m����[32m��������һ������
���£��������������ɮ�ķ�Ǻ��������������Ĵ�˵���񻰡�
LONG
        );

        set("exits", ([ 
		"west" : __DIR__"octostreet",
		"east" : __DIR__"grassland4",
		"up"   : __DIR__"topoftower",
	        "northup": "/d/resort/smallroad",
	        "south" : "/d/ghost/lroad1",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/cityguard" : 2,
        ]) );

	set("coor/x",45);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir) {
	object ob;
	ob = present("city guard",this_object());
	
	if (ob)
	if ( dir == "west" && me->is_naked())   {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"����üͷ˵��С���ӹ���ƨ��������ȥ����ʲô���ӣ�\n\n");
			else
				return notify_fail(ob->name()+"����ȵ�������������ҡ���У��ɺ���ͳ����\n");
		}

	return 1;
}
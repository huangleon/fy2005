// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ȼ��");
        set("long", @LONG
���ţ�̧ͷһ���Ҷ���о����������������ˣ�һ��ɮ�ھ����ҽ��룬����
һ�����У�Ҳ��Ȩ���룬�����ס�Ķ����������ݻ᷽�ɵľ������ˡ����г���
һ��һ����ֻ��һ����С��¯��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"fang",
]));
        set("objects", ([
                __DIR__"npc/baixiaoshen" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}


void init()
{
    call_out("close_path", 5);
}

void opengate()
{
	set("exits/east", __DIR__"tongren");
//    call_out("close_path", 5);
}

void close_path()
{
        if( !query("exits/east") ) return;
        message("vision","ʯ��ש�߷׷����£���ס��ǽ�ϵĶ��ڡ�\n",this_object() );
                delete("exits/east");
}


int passing()
{
	object room;
	room = find_object(__DIR__"tongren");
	if (!room)
		room=load_object(__DIR__"tongren");
	return room->usr_in();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" & passing())
	// һ��һ������һ��һ��ȥ
       	return notify_fail("�㿴�����ڣ������һ����������᲻��������ȥ��\n");

//  	if( dir == "west" && !me->query("annie/demon_gao"))
//       	return notify_fail("�㿴�����ڣ������һ����������᲻��������ȥ��\n");
	return 1;
}


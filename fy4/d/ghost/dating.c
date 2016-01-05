
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ɽ�ȵ�Ҫ������Ȼ��һ�����ݣ�����С����ס��ȥ·���������ڻ�¯�ϣ���
¯���ڸ�̨ǰ����̨���ڴ�������������ɣ�ʯ̨���߳ߣ�����Ҳ�����߶�ߡ�
¯���������������������ڵ�һ���⣬��ü�ֱ���԰�ʮ��֮�ڵ��˺͹���������
LONG
	);
	set("exits", ([
                "west" : __DIR__"groad3",
                "east" : __DIR__"groad4",
	]));
	set("objects", ([
                __DIR__"npc/jiangjun" : 1,
                __DIR__"obj/meat" : 1,
	]));
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        int i;
		
		if (dir == "east") {
			if( (ob=present("jiang jun", this_object())) && present("stewed meat", this_object())) {
				return notify_fail(ob->name()+"����ȵ���û�����⣬�����ߣ�\n");
	        }
	        if( (ob=present("jiang jun", this_object())) && present("stewed meat", me)) {
	                return notify_fail(ob->name()+"����ȵ���û�����⣬�����ߣ�\n");
	        }
        }
        return 1;
}

void reset()
{
        object          item, meat;

        ::reset();
        item = present("big pot", this_object());
	if(objectp(item)) {
		destruct(item);
		meat = new(__DIR__"obj/meat"); 
		meat->move(this_object());
	}
}

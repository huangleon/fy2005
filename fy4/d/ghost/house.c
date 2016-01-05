
inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�����濴�������Ѿ�С�ÿ����ˣ��߽�ȥ֮�󣬸������߽�������������Ǹ�
����С�������ȫ��������Ҳһ�������˼�����ʲô���������Ｘ��Ҳһ����ȱ��
�������и�������Ͱ������עĿ�ط����������ࡣ
LONG
	);
	set("exits", ([
                "south" : __DIR__"ghost",
	]));
	set("objects", ([
                __DIR__"npc/yeling" : 1,
                __DIR__"obj/toilet" : 1,
	]));
	set("coor/x",-70);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("toilet", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 2) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/butterfly");
                item->move(con);
                item = new(__DIR__"obj/yanzi");
                item->move(con);
	}
}


inherit ROOM;

void create()
{
	object		con, item;

	set("short", "ũ��");
	set("long", @LONG
��ש���ɵķ��ӣ�������߿�ǽ��һ�Ŵ󿻣�����һ������Ϣ���м�һ�ųԷ�
��������������̲ˡ�һ���ϸ������ں���ĳ�����æµ����ʱ��������Ӻ�Ʈ
����ʹ���뵽����Щ���������ڽ����������������Ѻܾ�û�úõس�һ�ټ�������
�����ˡ�
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"xzroad2",
		"east" : __DIR__"xzh1k",
	]));
	set("objects", ([
		__DIR__"obj/table": 1,
	]));
	set("coor/x",10);
	set("coor/y",80);
	set("coor/z",-50);
	setup();

}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 6) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/rice");
                item->move(con);
                item = new(__DIR__"obj/rice");
                item->move(con);
                item = new(__DIR__"obj/chopstick");
                item->move(con);
                item = new(__DIR__"obj/chopstick");
                item->move(con);
                item = new(__DIR__"obj/vege");
                item->move(con);
                item = new(__DIR__"obj/vege");
                item->move(con);
	}
}


inherit ROOM;

void create()
{
	object 	con, item;

	set("short", "��ʯС·");
	set("long", @LONG
С·����ɫ�Ķ���ʯ�̳ɡ�·����ÿ���������������裬�ֵ��Ǹ��ֲ軨��
�軨����ֻ�����Ϸ��������������ﾹȻҲ�����������١�
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"wuroad2",
		"southwest" : __DIR__"wudang1",
		"south" : __DIR__"dishuiyan",
	]));
	set("objects", ([ 
		__DIR__"obj/pot" : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",10);
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
        con = present("pot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 2) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/flower");
                item->move(con);
                item = new(__DIR__"obj/flower");
                item->move(con);
	}
}

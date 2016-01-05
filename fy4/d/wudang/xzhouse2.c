
inherit ROOM;

void create()
{
	object con, item;

	set("short", "ũ��");
	set("long", @LONG
����������Ա���Χ��Ҫ�ƾ�һЩ���������������ڰ���ǳ����ӣ�ֻ�м���
�������Ʒ���ݽǶ��ŵ�ũ���ϻ����˻ҳ����ƺ��Ѿ��ܾ�û�˶����ˡ�[33mǽ[32m�Ϲ���
һ������������Ŀ��ʹ���̲�ס��ʼ����������˵�������
LONG
	);
	set("exits", ([
		"east" : __DIR__"xzroad3",
	]));
	set("objects", ([
		__DIR__"obj/wall": 1,
		__DIR__"npc/dahanwife": 1,
	]));
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",-50);
	setup();
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("wall", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword2");
                item->move(con);
	}
}


inherit ROOM;

void create()
{
	object		con, item;

	set("short", "������");
	set("long", @LONG
����ǽ�Ϲ����䵱��ɽ��ʦ��������Ļ��񡣻�����һ�Ź�̨�ϣ�����һֻͭ
¯����ֻ����ð�����̵Ĺ���������С���������ǽ�Ϲ���̫��ȭ������ͼ��ͼ��
���Ǳ����ܣ����и�ʽ���У����Խ�Ϊ�ࡣ�����䵱��������������
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"wudang3",
	]));
        set("objects", ([
                __DIR__"npc/taoist" : 2,
                __DIR__"obj/wshelf" : 1,
                BOOKS"skill/taiji_50" : 1,
                
        ]));
	set("coor/x",50);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}


void reset()
{
        object          *inv;
        object          con, item;
        int             i;
        ::reset();
        con = present("weapon shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/sword");
                item->move(con);
  	}
}

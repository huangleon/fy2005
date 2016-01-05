inherit ROOM;

void create()
{
        set("short", "�س��ϲ�");
        set("long", @LONG
���Ҳҵ�ҹɫ�����������ҲҵĴ�أ���������������ʮ�׼����ķ�ڣ����
����ʯ��ʯ����Ȼ�����Ǹ����ĸ��𡣵�������ʯ��ʯ���Ѿ�ȱͷ���ȣ���ͷ��
�����˻Ĳݣ������߽�����ֻ��ѻ���ɵ�һ���ɢ��
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",0);
	set("no_lu_letter",1);
	set("objects", ([
        	__DIR__"npc/tiehen" : 1,
        	__DIR__"obj/tomb2":	1,
                        ]) );
	set("exits", ([
		"north" : __DIR__"cemetery6",
	]));

	setup();
}


void reset(){
	object item, coffin;
	object *inv, *players;
	::reset();
	if (!objectp(coffin=present("tomb",this_object()))) return;
	inv=all_inventory(this_object());
	players=filter_array(inv,(: userp($1) :));
	if (sizeof(players)) return;
	
	if (!present("paper",coffin)) {
		item=new(__DIR__"obj/paper2");
		item->move(coffin);
	}
	return;
}
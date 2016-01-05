inherit ROOM;

void create()
{
        set("short", "�س�����");
        set("long", @LONG
���Ҳҵ�ҹɫ�����������ҲҵĴ�أ���������������ʮ�׼����ķ�ڣ����
����ʯ��ʯ����Ȼ�����Ǹ����ĸ��𡣵�������ʯ��ʯ���Ѿ�ȱͷ���ȣ�����ͷ
Ҳ���򿪡�һ��ո�µĹײģ�����������Ľ����һ��վ�ŵ��ˡ���������������
�ʣ��·��в�����˵�������ˣ������ǻ�����������������������
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-90);
		set("coor/y",30);
		set("coor/z",0);
		set("no_lu_letter",1);
		set("objects", ([
        	__DIR__"npc/guoyi" : 1,
        	__DIR__"obj/coffin2": 1,
        ]) );
	
		set("exits", ([
			"south" : __DIR__"cemetery12",
		]));

	setup();
}


void reset(){
	object item, coffin;
	object *inv, *players;
	::reset();
	if (!objectp(coffin=present("coffin",this_object()))) return;
	inv=all_inventory(this_object());
	players=filter_array(inv,(: userp($1) :));
	if (sizeof(players)) return;
	
	if (!present("paper",coffin)) {
		item=new(__DIR__"obj/paper1");
		item->move(coffin);
	}
	return;
}
	

inherit ROOM;

void create()
{
	set("short", "ԭʼ����");
	set("long", @LONG
�ޱ��޼ʵĴ�����һƬ�ڰ����������ҵ��չ�Ҳ����͸�����ܵ���Ҷ���ڰ���
�����˸�ʽ������Σ�գ�ÿһ�ֶ�������������Ҷ��ʪ�ģ�����Ҳ��ʪ�ġ�������
��һ���˵�����Ҷʪ���У�ȫ������ʹ���Ť����
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest6",
		"south" : __DIR__"forest2",
		"east" : __DIR__"forest3",
		"west" : __DIR__"forest1",
	]));
	set("objects", ([
		__DIR__"npc/gudumei" : 1,
	]));
	set("outdoors", "ghost");
	set("no_lu_letter",1);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}

void init(){
	add_action("do_go","go");
}

int do_go(string dir){
	object who = this_player();
	
	if (dir == "east" && userp(who) && who->query_temp("marks/gudumei_route")){
		who->move(__DIR__"forest_c");
		return 1;
	}
	
	return 0;
}

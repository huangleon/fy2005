
inherit ROOM;

void create()
{
	set("short", "ׯ�ڵ�");
	set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭���е��㣬������
��֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,������Ȼ���¡�
LONG
	);
	set("exits", ([
  		"north" : __DIR__"farm1",
  		"south" : __DIR__"farm5",
  		"east" : __DIR__"farm7",
  		"west" : __DIR__"farm5",
	]));
	set("outdoors", "wudang");
	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}

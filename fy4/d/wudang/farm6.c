
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
		"north" : __DIR__"farm4",
  		"south" : __DIR__"farm6",
	  	"east" : __DIR__"farm2",
  		"west" : __DIR__"farm4",
	]));
	set("objects", ([ 
  		__DIR__"npc/bird" : 4,
	]));
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",60);
	set("coor/z",-50);
	setup();
replace_program(ROOM);

}

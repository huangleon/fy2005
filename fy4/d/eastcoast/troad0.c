
inherit ROOM;

void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
·������һ��ʯ��������д��������׭�֣�[33m������ȡ�[32m�������п�ȥ��һ����
��������С·���������һΣ��ǰͻȻ�жϡ�
LONG
        );
        set("exits", ([ 
 		 "west" : __DIR__"troad0a",
  		"eastdown" : __DIR__"troad1",
]));
	set("outdoors","tieflag"); 	
        
	set("coor/x",400);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}

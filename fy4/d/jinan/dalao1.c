
inherit ROOM;
#include <room.h>
void create()
{
    set("short", "����");
	set("long", @LONG
�����ǹ�Ѻ���˵ĵط�����̨������������һ��ͨ����ͨ��������ʯǽ��ľդ
�����ɵ�С���䣬�����Ѻ��һЩ���̴����ﷸ�����Ķ�ͷ���н���ͨ�����档
��֪������Ʈ���ĸ���֮������������η���
LONG
	);
    	set("exits", ([ /* sizeof() == 3 */
        	"west" : __DIR__"dayu",
        	"north" : __DIR__"laofang1",
        	"south" : __DIR__"laofang2",
        	"eastdown" : __DIR__"andao1",
    	]));
	set("locked", 1);
    	set("indoors", "jinan");
	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir){
	if((dir == "south" || dir == "north") && query("locked")) {
		return notify_fail("��������������û�а취��ȥ��\n");
	}
	return 1;
}

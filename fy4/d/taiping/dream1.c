#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��һ���ĵط�");
        set("long", @LONG
ֻ����ǰһ�����ֿ����˹⡣�����Ĺ�â����������Ϸ�������ͣ������һ
��ɴ�����з硣�紵���������ǡ���ɭɭ����磬��������ȴû�к���ĸо�����
�����Եİ���Ʈ���������Χ��ȴû���谭������ߡ�
LONG
        );
        set("exits", ([ 
		"up":  __DIR__"dream2",
	]));
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}



inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��������");
        set("long", @LONG
·�Եİ�����������ʮ�����������������֣�һ���Ű�Ȼ��ͦ������ͬ
���ڵ�ʿ��������ͨ�����ɰѸߣ����Ǽ����˹��Ƶģ���ֱ���ϣ�������֦����֦
Ҳ�Ǳ�ֱ���ϣ����ҽ�����£��Ҳ���Ǿ����˹��Ƶģ���Ϊһ�������޺�б�ݳ���
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"wild3",
		"south" : __DIR__"forest1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1600);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���ϰ�����");
        set("long", @LONG
СС�����̣�ǽ���ѱ���Ѭ�ڡ�һ��С�����������ŷ��㡣¯�����ܵط��
վ����ǰ���һ����ͷ���ƺ��ѱ����ɡ��������������߹Ǹ���������������
���Ǹ�ʬһ�����Ұ׵��뷢���������Ҳ��֪��������ˣ�������Ϊ�������°�
�Ż�¯����������������һֻ��������������һֻ�����Ż�ǯ�����ڴ���һ��
���ι�״�Ķ�����
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"vroad4",
	]));
        set("objects", ([
		__DIR__"npc/du":1,
	]) );
	set("coor/x",80);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}

inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����������");
        set("long", @LONG
����˭��һ�ۿ����������������Ҫ��һ����������Ȼֻ������ʮ���ɿ���
ֱ���������޷�����һ������Ҫ���ſ��ߵ���һ��ȥ��˵����Ҫ����һ��ǧ����
�����ұߵķ�ǽ�ϣ�д���������˻��ߵĴ��֡������á���ī�����죬���ɷ��衣
LONG
        );
        set("exits", ([ 
	"west": __DIR__"hall3",
	]));
        set("objects", ([
	]) );
        set("coor/x",-5);
        set("coor/y",120);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}

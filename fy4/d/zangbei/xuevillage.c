inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ú�ׯ");
        set("long", @LONG
���ߺ춥��������������еĺú�ׯ����Ѧ��ׯ��ׯ�����ǵ���һ������п�
��ٵ��̹��񸫺�ɨ��̫��ɽ��Ѧ��ʮ����ǰ��Ѧ��ͻȻ�˳�����������ԭ�Ĳ�
ҵ��������Ѧ�󺺣��Լ����ż������˵��ˡ����²����ۣ�����������һ�����ú�
ׯ�Ѿ��������ӡ�ǽ�����ֳ����ƣ������ᶼ�������ε�ס���紵�Ŵ���ʱ����ͣ
�ء���񡱷��졣
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"valley2",
		"west": __DIR__"xuevillage2",
	]));
        set("objects", ([
		
	]) );
	set("coor/x",-2070);
        set("coor/y",580);
        set("coor/z",20);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}

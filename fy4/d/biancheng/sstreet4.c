inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�Ͻ־�ͷ");
        set("long", @LONG
С�ֵķ����ܿ�͵��˾�ͷ�����Ͽ���ԶԶ�ɼ�һ���ļ��ĺ��������������
���ɳ��һ��о��ڷ�ɳ�д��Ź����Ȳ�֪�Ǵ����ﴵ���ģ�Ҳ��֪Ҫ����������
ȥ���������Ҳ���������о�һ��������˭��Ԥ֪�Լ������ˣ�
LONG
        );
        set("exits", ([ 
		"north": __DIR__"sstreet3",
		"southeast": AREA_ZANGBEI"bank",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",-40);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}

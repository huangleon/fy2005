inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�Ͻ�");
        set("long", @LONG
С�ֵķ����ܿ�͵��˾�ͷ����Զ������������һ���ļ��ĺ�����һ����è��
�Ų�������ȴ��ʧȥ����ԭ�еĻ���������Ϣ�ţ������������֣���������
�Ѳ�����һ��è��·����һ�ҵ��̣�������д�š�����ӻ��̡��������֡�
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"zahuopu",
		"north": __DIR__"sstreet2",
		"south": __DIR__"sstreet4",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",-30);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}

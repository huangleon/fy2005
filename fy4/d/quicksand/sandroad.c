
inherit ROOM;

void create()
{
        set("short", "ɳ��С��");
        set("long", @LONG
����ĵ�����һ�ֻƺ�ɫ�����ɫ��ʯ����Ƕ��ϸϸ�Ļ�ɳ֮�У������Լ���
����ĸо������������������ԭ���м�ش�������ķ����������޺ۼ���������
���Ǳ������ޱ��޼ʵĴ�ɳĮ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"huangyie1",
  "west" : __DIR__"saikou",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1020);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


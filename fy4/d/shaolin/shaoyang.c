// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����ơ�������Ĺȣ���Ϫ�����֡�����Ϫָ�ı�������Ϫ����������Կ�ױ�
���������ţ�Ҳ����Ϫ�ţ�ʯ�����͵��ţ�����ʯ�������е�һ���ף�����������
�ഫ�˴����������ڣ����ֺ���֮��������ǧ�������ɲ�ֹ��������ȥ����һ����
�ߵ����֡�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"shandan",
]));
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}

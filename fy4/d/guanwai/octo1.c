
inherit ROOM;

void create()
{
        set("short", "�˽ǽ�");
        set("long", @LONG
�������⣬Χ������Ժ�İ˽ǽ��ǲ���������������ֵĵط�����������
��ջ���̺Ŷ����������ϡ�Զ��������ʱ��������һ���������Ʈ���������ļ�
����̫�������Ž�⣬��������ʥׯ�����µľ���
LONG
        );
       
        set("exits", ([ 
		"north" : __DIR__"octostreet",
		"south" : __DIR__"octo2",
		"east" : __DIR__"inn",
	]));
        set("outdoors", "guanwai");
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
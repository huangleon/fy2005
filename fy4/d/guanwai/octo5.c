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
		"east" : __DIR__"octo4",
		"west" : __DIR__"octo6",
		"south" : __DIR__"work",
	]));
        set("outdoors", "guanwai");
set("objects", ([
                __DIR__"npc/lama" : 2,
        ]) );
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
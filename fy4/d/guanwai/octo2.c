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
		"north" : __DIR__"octo1",
		"west" : __DIR__"octo3",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama" : 1,
        ]) );
	set("coor/x",30);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
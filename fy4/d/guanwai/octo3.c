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
		"north" : __DIR__"shop2",
		"east" : __DIR__"octo2",
		"west" : __DIR__"octo4",
	]));
        set("outdoors", "guanwai");
	set("coor/x",20);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

// ���p��dancing_faery@hotmail.com

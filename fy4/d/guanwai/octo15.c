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
		"west" : __DIR__"octo14",
		"south" : __DIR__"octo16",
		"east" : __DIR__"shop",
	]));
        set("outdoors", "guanwai");
	set("coor/x",30);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}
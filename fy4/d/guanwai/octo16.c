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
		"north" : __DIR__"octo15",
		"south" : __DIR__"octostreet",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama2" : 5,
        ]) );
	set("coor/x",30);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
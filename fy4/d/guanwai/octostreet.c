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
		"west" : __DIR__"dazhaotemple",
		"east" : __DIR__"citygate",
		"north" : __DIR__"octo16",
		"south" : __DIR__"octo1",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama" : 3,
                __DIR__"npc/biglama" :1,
        ]) );
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
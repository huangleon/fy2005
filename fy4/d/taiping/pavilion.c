inherit ROOM;
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
��ɽ����һ������ͤ������Ϊ�����ܽ������չ�ᣬͤ�⻨���ݺᣬ�򶫱���
���ĸ�����ƻ����ǣ�������԰��������������Ů����������裬�������Ƿ�ͼ
��������ͤ���м���������Ҳ������Ů���ӡ��������ǲ�̫���ᣬ���ٿ��������ϣ�
���㲻̫�������ٶ���ĳ����������
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"garden",
		"south": __DIR__"garden2",
	]));
        set("outdoors", "taiping");
        set("objects", ([
        	__DIR__"npc/sanye": 1,
        	__DIR__"npc/girl3": 1,
        	__DIR__"npc/girl4": 1,
        	__DIR__"npc/girl2": 1,
        	__DIR__"npc/girl1": 1,
        ]));
	set("item_desc", ([
	        
	]));
	set("coor/x",-100);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

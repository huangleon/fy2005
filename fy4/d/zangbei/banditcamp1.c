inherit ROOM;

void create()
{
        set("short", "����Ӫ��");
        set("long", @LONG
�����ת�˼�Ȧ����ǰ��һ��յأ��յ������˼������𣬿������ζ�˱Ƕ�
����������������ĺ�������ɢɢ�ؿ�������ߣ��������Ÿ�ʽ����������������
�������ƾɲ�������Ұ�ķ紵�����������졣
LONG
        );
        set("exits", ([ 
	  	"southeast" : __DIR__"deserted",
	  	"north" : __DIR__"camp",
	  	"northwest": __DIR__"banditcamp2",
			]));
	set("objects", ([
		__DIR__"npc/bandit3" : 1,
	]));
	set("outdoors", "zangbei");

        set("coor/x",-440);
	set("coor/y",610);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

